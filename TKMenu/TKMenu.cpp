//Tom Kannenberg 2023, C++17

#include "TKMenu.h"

#include <algorithm>
#include <windows.h>

namespace TKMenu {
    using namespace TKCursor;

    Menu::Menu() {
    }

    Menu::~Menu() {
        delete main;
    }

    void Menu::initialize(const unsigned char (&size)[2], const string* values, const bool* actions, const string* actionNames) {
        main = new Cursor(size);

        for (int i = 0; i < size[0]; i++) {

            for (int j = 0; j < size[1]; j++) {

                if (values[i * size[1] + j] != "") {

                    if (actions == nullptr) {
                        main->addBlock(i, j, values[i * size[1] + j]);

                    } else {
                        main->addBlock(i, j, values[i * size[1] + j], cursors[actionNames[i * size[1] + j]]);
                    }
                }
            }
        }

        addCursor("main", main);
        
        for (std::pair<const string, string> &name : parentmap) {
            cursors[name.first]->setParent(cursors[name.second]);
        }


        current = main;
        current->showAll();
    }

    void Menu::addCursor(const string &name, Cursor* cursor) {
        cursors[name] = cursor;
    }

    void Menu::addParent(string name, string parentName) {
        //pmainList.push_back(name);
        parentmap[name] = parentName;
    }

    Cursor* Menu::getCursor(const string &name) {
        return cursors[name];
    }

    void Menu::run() {

        ThrowError("To navigate, use the arrow keys, enter and escape.", true);

        std::thread blinker([&] {
            using namespace std::chrono_literals;
            constexpr std::chrono::duration<long long, std::milli> blinkInterval = 530ms;
            std::chrono::steady_clock::time_point lastUpdate = std::chrono::steady_clock::now();
            bool marked = false;

            while (true) {
                
                if (!marked) {
                    
                    if (current->hasUpdate() || std::chrono::steady_clock::now() - lastUpdate > blinkInterval) {
                        current->unsetUpdate();
                        lastUpdate = std::chrono::steady_clock::now();
                        current->getCurrent()->update((current->isBlinking() ? mark : unmark));
                        marked = true;
                        continue;
                        
                    } else {
                        continue;
                    }
                    
                } else {
                    
                    if (current->hasUpdate() || std::chrono::steady_clock::now() - lastUpdate > blinkInterval) {
                        lastUpdate = std::chrono::steady_clock::now();
                        current->getCurrent()->update(unmark);
                        marked = false;
                    }
                }
            }
        });

        while (1) {
            
            if (GetForegroundWindow() == console) {
                if (GetAsyncKeyState(VK_UP) & 1) {
                    current->move(y, down);
                    std::this_thread::sleep_for(std::chrono::milliseconds(keypressdelay));
                }

                if (GetAsyncKeyState(VK_DOWN) & 1) {
                    current->move(y, up);
                    std::this_thread::sleep_for(std::chrono::milliseconds(keypressdelay));
                }

                if (GetAsyncKeyState(VK_LEFT) & 1) {
                    current->move(x, down);
                    std::this_thread::sleep_for(std::chrono::milliseconds(keypressdelay));
                }

                if (GetAsyncKeyState(VK_RIGHT) & 1) {
                    current->move(x, up);
                    std::this_thread::sleep_for(std::chrono::milliseconds(keypressdelay));
                }
            
                if (GetAsyncKeyState(VK_RETURN) & 1) {
                    
                    if (current->hitAction()) {
                        current = current->currentBlock->getAction(); // Action is a Cursor*
                        std::this_thread::sleep_for(std::chrono::milliseconds(keypressdelay));
                    }
                }
                
                if (GetAsyncKeyState(VK_ESCAPE) & 1) {
                    
                    if (current->escape()) {
                        current = current->parent;
                        std::this_thread::sleep_for(std::chrono::milliseconds(keypressdelay));
                    }
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(idledelay));
            } else {
                std::this_thread::sleep_for(std::chrono::milliseconds(unfocusseddelay));;
            }
        }
    }

    MenuBuilder::MenuBuilder() {
        menu = new Menu();
    }

    MenuBuilder::~MenuBuilder() {
        delete menu;
    }

    void MenuBuilder::addCursor(const string &name, const string &parentName, const CursorInfo &info) {
        Cursor* cursor = new Cursor(info.getSize(), info.getCursorBlink());
        
        menu->addParent(name, parentName);
            
        for (int i = 0; i < info.getSize()[0]; i++) {
            
            for (int j = 0; j < info.getSize()[1]; j++) {
                
                if (info.getActions() != nullptr && info.getActions()[i*info.getSize()[1]+j]) {
                    cursor->addBlock(i, j, info.getValues()[i *info.getSize()[1]+j], menu->getCursor(info.getActionNames()[i*info.getSize()[1]+j]));
                    
                } else {
                    cursor->addBlock(i, j, info.getValues()[i*info.getSize()[1]+j]);
                }
            }
        }

        if (info.getCheck()) {
            cursor->setCheck(info.getChecks());
        }

        menu->addCursor(name, cursor);
    }

    void MenuBuilder::initialize(const CursorInfo &info) {
        menu->initialize(info.getSize(), info.getValues(), info.getActions(), info.getActionNames());
        menu->run();
    }
}
