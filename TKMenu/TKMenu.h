//Tom Kannenberg 2023, C++17

#pragma once
#include "../TKUtility/TKUtility.h"
#include "../TKCursor/TKCursor.h"
#include <unordered_map>

namespace TKMenu {
    using namespace TKCursor;
    using namespace TKUtility;
    
    class Menu {
    
        private:
    
            Cursor* main = nullptr;                             // Cursor at the top of the Parent hierarchy
            Cursor* current;                                    // Cursor that is currently displayed
            std::unordered_map<string, Cursor*> cursors;        // Map of all Cursors
            std::unordered_map<string, string> parentmap;       // Map of who is whose Parent
    
        public:
    
            Menu();
            ~Menu();
            
            void initialize(const unsigned char (&size)[2], const string* values, const bool* actions, const string* actionNames);
            void addCursor(const string &name, Cursor* cursor);
            void addParent(string name, string parentName);
            Cursor* getCursor(const string &name);
            void run();
    };

    class MenuBuilder {
    
        private:
    
            Menu* menu;                                         // Menu to build

        public:
    
            MenuBuilder();
            ~MenuBuilder();
            
            void addCursor(const string &name, const string &parentName, const CursorInfo &info);
            void initialize(const CursorInfo &info);
    };
}
