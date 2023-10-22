//Tom Kannenberg 2023, C++17

#include "TKCursor.h"

namespace TKCursor {
    using namespace TKUtility;

    CursorBlock::CursorBlock() : action(nullptr), exists(false), star(false) {
        //Default constructor for array's
    }

    CursorBlock::CursorBlock(unsigned char start, unsigned char row, string text)
        : start(start), row(row), text(text), action(nullptr), exists(true), star(false) {
        //Constructor for no Action CursorBlocks
    }

    CursorBlock::CursorBlock(unsigned char start, unsigned char row, string text, Cursor* action)
        : start(start), row(row), text(text), action(action), star(action), exists(action) {
        //Constructor for Action CursorBlocks
    }

    void CursorBlock::update(bool selected) {
        COutColoredAt(this->text, this->row, this->start, selected ? blinkColor : defaultColor);
    }

    void CursorBlock::removeStar() {
        star = false;
        this->hide(); // Otherwise it will only hide -2 of the original length and the Star won't be removed
        text.erase(text.length() - 2);
    }

    void CursorBlock::hide() {
        std::string spaces(this->text.length(), ' ');
        COutColoredAt(spaces, this->row, this->start, 0);
    }

    const string& CursorBlock::getText() const {
        return this->text;
    }

    Cursor*& CursorBlock::getAction() {
        return this->action;
    }

    Cursor*& CursorBlock::getParent() {
        return this->parent;
    }

    bool CursorBlock::doesExist() {
        return exists;
    }

    void CursorBlock::setParent(Cursor*& parent) {
        this->parent = parent;
    }

    Cursor::Cursor(const unsigned char(&size)[2], const bool cursorBlink) : size{ size[0], size[1] }, cursorBlink(cursorBlink) {
        this->cursorBlocks = new CursorBlock * [size[0]];

        for (int i = 0; i < size[0]; i++) {
            this->cursorBlocks[i] = new CursorBlock[size[1]];
        }

        this->currentBlock = &this->cursorBlocks[this->xpos][this->ypos];
    }

    Cursor::~Cursor() {
        delete[] this->cursorBlocks;
    }

    void Cursor::setParent(Cursor* parent) {
        this->parent = parent;

        for (int i = 0, size0 = this->size[0]; i < size0; ++i) {

            for (int j = 0, size1 = this->size[1]; j < size1; ++j) {

                this->cursorBlocks[i][j].setParent(parent);
            }
        }
    }

    void Cursor::setAssociate(CursorBlock* block) {
        this->associatedBlock = block;
    }


    void Cursor::addBlock(const int& column, const int& row, const string& text, Cursor* action) {
        int c_column = column * 2 + minval_x;
        int c_row = row * 2 + minval_y;

        if (column != 0) {
            c_column += offsetx * column;
        }

        CursorBlock& tempBlock = this->cursorBlocks[column][row];

        !action ? tempBlock = CursorBlock(c_column, c_row, text) : tempBlock = CursorBlock(c_column, c_row, text, action);

        if (action) {
            tempBlock.getAction()->setAssociate(&this->cursorBlocks[column][row]);
        }

    }

    void Cursor::move(const bool& axis, const int& direction) {

        if (this->cursorBlocks[this->xpos][this->ypos].doesExist()) {
            this->cursorBlocks[this->xpos][this->ypos].update(unmark);

        } else {
            ThrowError("CURRENT CursorBlock does not exist!");
            return;
        }

        unsigned char new_xpos = this->xpos;
        unsigned char new_ypos = this->ypos;

        (axis ? new_ypos : new_xpos) += direction;
        CheckBounds(new_xpos, new_ypos, size);

        if (cursorBlocks[new_xpos][new_ypos].doesExist()) {
            this->xpos = new_xpos;
            this->ypos = new_ypos;
        }

        if (cursorBlink) {
            update = true;
        }
        currentBlock = &cursorBlocks[xpos][ypos];
    }

    void Cursor::CheckBounds(unsigned char& newx, unsigned char& newy, const int* size) {

        if (newx > 250) {
            newx = size[0] - 1;
        }

        if (newx > size[0] - 1) {
            newx = 0;
        }

        if (newy > 250) {
            newy = size[1] - 1;
        }

        if (newy > size[1] - 1) {
            newy = 0;
        }
    }

    unsigned char Cursor::getPos(const bool& axis) {
        return axis ? this->ypos : this->xpos;
    }

    unsigned char Cursor::getSize(const bool& axis) {
        return this->size[axis];
    }

    CursorBlock* Cursor::getCurrent() {
        return this->currentBlock;
    }

    const bool Cursor::isBlinking() const {
        return this->cursorBlink;
    }

    const bool Cursor::hasUpdate() const {
        return this->update;
    }

    const bool Cursor::isActive() const {
        return this->active;
    }

    void Cursor::unsetUpdate() {
        this->update = false;
    }

    void Cursor::setCheck(const unsigned char &checks) {
        this->check = true;
        this->checks = checks;
    }

    void Cursor::removeCheck(bool external) {

        if (checks > 1 && (external || uniquecheck)) {
            checks--;
            uniquecheck = false;

        } else if (checks == 1 && (external || uniquecheck)) {
            if (!external) {
                uniquecheck = false;
            }
            associatedBlock->removeStar();
            check = false;
            checks--;

            if (parent != nullptr) {
                parent->removeCheck(true);
            }

        } else {
            return;
        }

    }

    CursorBlock** Cursor::getCursorBlocks() {
        return this->cursorBlocks;
    }

    bool Cursor::hitAction() {
        CursorBlock& tempBlock = this->cursorBlocks[this->xpos][this->ypos];
        Cursor* target = tempBlock.getAction();

        if (tempBlock.doesExist()) {
            std::wstring link;
            std::wstring imageName;

            string tempText = tempBlock.getText();

            if (tempText == "SoloLearn *") {
                link = L"https://www.sololearn.com/certificates/CT-DHFQCNYZ";
                imageName = L"Sololearn: Learn to Code";
                tempBlock.removeStar();
                this->removeCheck(true);
                this->update = true;

            } else if (tempText == "Erw. Sekundarabschluss I - 2021 *") {
                link = L"https://i.ibb.co/1zPgp8p/20230509-203641.jpg";
                imageName = L"20230509-203641.jpg";

            }

            if (!link.empty()) {
                OpenLinkAndWait(link, imageName);
                SetFocus(console);
                SetActiveWindow(console);
                SetForegroundWindow(console);
            }

            if (target) {
                target->removeCheck();
                switchTo(target);
                return true;
            }
        }

        return false;
    }

    void Cursor::OpenLinkAndWait(const std::wstring& link, const std::wstring& imageName) {
        SHELLEXECUTEINFO ShExecInfo = { 0 };
        ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
        ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
        ShExecInfo.hwnd = NULL;
        ShExecInfo.lpVerb = NULL;
        ShExecInfo.lpFile = link.c_str();
        ShExecInfo.lpParameters = NULL;
        ShExecInfo.lpDirectory = NULL;
        ShExecInfo.nShow = SW_SHOW;
        ShExecInfo.hInstApp = NULL;

        ShellExecuteEx(&ShExecInfo);
        WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
        CloseHandle(ShExecInfo.hProcess);

        while (true) {
            HWND hwnd = GetForegroundWindow();
            const int titleLength = GetWindowTextLengthW(hwnd) + 1;
            std::wstring title(titleLength, L'\0');
            const int actualLength = GetWindowTextW(hwnd, &title[0], titleLength);
            title.resize(actualLength);

            if (imageName.empty()) {

                if (title.find(link) != std::wstring::npos) {
                    break;
                }

            } else {

                if (title.find(imageName) != std::wstring::npos) {
                    break;
                }
            }
        }
    }


    
    void Cursor::switchTo(Cursor* other) {
        this->hideAll();
        other->showAll();
    
        switch (cursormode) {
            
            case remembering:
                break;
            
            case keeping:
                other->xpos = min(other->getSize(x) -1, this->xpos);
                other->ypos = min(other->getSize(y) -1, this->ypos);
                break;
            
            case resetting:
                other->xpos = 0;
                other->ypos = 0;
                break;
        }

        other->currentBlock = &other->cursorBlocks[other->xpos][other->ypos];
    }

    void Cursor::hideAll() {
        active = false;

        for (int i = 0, size0 = this->size[0]; i < size0; ++i) {

            for (int j = 0, size1 = this->size[1]; j < size1; ++j) {
                CursorBlock& block = this->cursorBlocks[i][j];

                if (block.doesExist()) {
                    block.hide();
                }
            }
        }
    }

    void Cursor::showAll() {
        update = true;
        active = true;

        for (int i = 0, size0 = this->size[0]; i < size0; ++i) {

            for (int j = 0, size1 = this->size[1]; j < size1; ++j) {
                CursorBlock& block = this->cursorBlocks[i][j];

                if (block.doesExist()) {
                    block.update(unmark);
                }
            }
        }
    }


    bool Cursor::escape() {

        
        if (this->parent != nullptr) {
            switchTo(this->parent);
            return true;
        }
        //ThrowError("No parent cursor!");
        return false;
    }

    const bool& Cursor::getCheck() {
        return check;
    }

    CursorInfo::CursorInfo(const std::initializer_list<char>& size, const std::initializer_list<string>& values, const std::initializer_list<bool>& actions,
                           const std::initializer_list<string>& actionNames, const bool& actionCheck, const int& actionChecks) {

        this->initialize(size, values, actions, actionNames, actionCheck, actionChecks, true);
    }

    CursorInfo::CursorInfo(const std::initializer_list<char>& size, const std::initializer_list<string>& values, const bool& cursorBlink, const bool& actionCheck,
        const int& actionChecks, const std::initializer_list<bool>& actions, const std::initializer_list<string>& actionNames) {

        this->initialize(size, values, actions, actionNames, actionCheck, actionChecks, cursorBlink);
    }

    void CursorInfo::initialize(const std::initializer_list<char>& size, const std::initializer_list<string>& values, const std::initializer_list<bool>& actions,
                                const std::initializer_list<string>& actionNames, const bool& actionCheck, const int& actionChecks, const bool& cursorBlink) {


        if (size.size() != 2) {
            ThrowError("CursorInfo size must be 2!");
        }

        this->size[0] = *(size.begin());
        this->size[1] = *(size.begin() + 1);

        this->values = new string[values.size()];
        std::copy(values.begin(), values.end(), this->values);

        this->actions = new bool[actions.size()];
        this->actionNames = new std::string[actionNames.size()];

        this->check = actionCheck;
        this->checks = actionChecks;

        (actions.size() == 0) ? this->actions = nullptr : std::copy(actions.begin(), actions.end(), this->actions);
        (actionNames.size() == 0) ? this->actionNames = nullptr : std::copy(actionNames.begin(), actionNames.end(), this->actionNames);

        if (values.size() != this->size[0] * this->size[1]) {
            ThrowError("CursorInfo values size must be equal to the product of the size!");
        }

        this->cursorBlink = cursorBlink;
    }

    CursorInfo::~CursorInfo() {
        delete[] this->actions;
        delete[] this->actionNames;
    }

    const unsigned char (&CursorInfo::getSize() const)[2] {
        return this->size;
    }
  
    const string* CursorInfo::getValues() const {
        return this->values;
    }
  
    const bool* CursorInfo::getActions() const {
        return this->actions;
    }
  
    const string* CursorInfo::getActionNames() const {
        return this->actionNames;
    }

    const bool CursorInfo::getCursorBlink() const {
        return this->cursorBlink;
    }

    const bool CursorInfo::getCheck() const {
        return this->check;
    }

    const unsigned char CursorInfo::getChecks() const {
        return this->checks;
    }
}