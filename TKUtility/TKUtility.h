//Tom Kannenberg 2023, C++17

#pragma once
#include <iostream>
#include <string>
#include <mutex>
#include <windows.h>
#include <conio.h>

namespace TKUtility {

    inline HWND console = GetForegroundWindow(); //GetConsoleWindow(); is broken, returns a different HWND than GetForegroundWindow()
    
    void DisableCursor();
    void ThrowError(std::string error, const bool &info = false);
    void SetColoredConsoleCursorPosition(const unsigned char &row, const unsigned char &column, const unsigned char &color);
    void COutAt(const std::string &outputString, const unsigned char &row, const unsigned char &column);
    void COutColoredAt(const std::string &outputString, const unsigned char &row, const unsigned char &column, const unsigned char &color);
    void SetCursorPosition(const unsigned char &y, const unsigned char &x);

    constexpr bool unmark = 0;                          // To put text in defaultColor
    constexpr bool mark = 1;                            // To put text in blinkColor
    constexpr bool x = 0;                               // Tonstant for
    constexpr bool y = 1;                               // Constant for y
    constexpr signed char up = 1;                       // Tonstant for up
    constexpr signed char down = -1;                    // Constant for down
    constexpr unsigned char minval_y = 2;               // Const offset of y
    constexpr unsigned char minval_x = 5;               // Const offset of x
    constexpr unsigned char offsetx = 20;               // Offset of x in between CursorBlocks
    constexpr unsigned char blinkColor = 3;             // Color when text is marked
    constexpr unsigned char defaultColor = 11;          // Color when text is unmarked
    constexpr unsigned char errorColor = 4;             // Color for error, debugging
    constexpr unsigned char infoColor = 1;              // Color for info
    constexpr unsigned char keypressdelay = 150;        // Delay for how long to wait after pressing key
    constexpr unsigned char idledelay = 1;              // Delay for how long to wait when not pressing key
    constexpr unsigned char unfocusseddelay = 250;      // Delay for how long to wait when window is not focussed

    constexpr unsigned char remembering = 0;            // Remembering the position where we left the Cursor
    constexpr unsigned char keeping = 1;                // Keeping the position of the previous Cursor, if x or y are to high it goes to size -n until fit
    constexpr unsigned char resetting = 2;              // Resetting the Cursor Position to (0|0) everytime the Cursor changes

    constexpr char cursormode = remembering;            // Mode in which the cursor position transitions to for the 3 options above

}
