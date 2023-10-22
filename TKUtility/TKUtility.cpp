//Tom Kannenberg 2023, C++17

#include "TKUtility.h"

namespace TKUtility {

    int previousErrorLength = 0;
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    std::mutex mtx;

    void DisableCursor() {
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(hcon, &cursorInfo);
        cursorInfo.bVisible = false;
        SetConsoleCursorInfo(hcon, &cursorInfo);
    }

    void ThrowError(std::string error, const bool &info) {
        COutColoredAt(std::string(previousErrorLength, ' '), 0, 0, 0);
        error = (!info ? "Error: " : "Info: ") + error;
        COutColoredAt(error, 0, 0, (info ? infoColor : errorColor));
        previousErrorLength = error.length();
    }

    void COutInternal(const std::string &outputString, const unsigned char &row, const unsigned char &column, const unsigned char &color) {
        std::lock_guard<std::mutex> lock(mtx);
        SetCursorPosition(row, column);
        if (color != -1) {
            SetConsoleTextAttribute(hcon, color);
        }
        std::cout << outputString;
        SetConsoleTextAttribute(hcon, 15);
        DisableCursor();
    }

    void COutAt(const std::string &outputString, const unsigned char &row, const unsigned char &column) {
        COutInternal(outputString, row, column, -1);
    }

    void COutColoredAt(const std::string &outputString, const unsigned char &row, const unsigned char &column, const unsigned char &color) {
        COutInternal(outputString, row, column, color);
    }

    void SetCursorPosition(const unsigned char &y, const unsigned char &x) {
        std::cout.flush();
        COORD coord = { (SHORT)x, (SHORT)y };
        SetConsoleCursorPosition(hcon, coord);
    }
    
}
