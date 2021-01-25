/**
 * File: color.h
 *
 * About: Description
 * This file implements cross-platform support for coloring text. It
 * is adapted from rlutil.h by Tapio Vierros,
 * https://github.com/tapio/rlutil.
 *
 * About: Copyright
 * Some parts (C) 2010 Tapio Vierros
 *
 * About: Licensing
 * This software my be modified or distributed in any way.
 * See https://github.com/tapio/rlutil/blob/master/docs/License.txt
 * for the rlutil.h license.
 */

#include "color.h"

using namespace std;

bool color_enabled(bool toggle, bool enable) {
    static bool enable_coloration = false;
    if (toggle) {
        enable_coloration = enable;
    }
    return enable_coloration;
}

void set_color(int code) {
    if (color_enabled(false, false)) {
#if defined(_WIN32)
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, static_cast<WORD>(code));
#else
        cout << ANSI_COLOR_STRINGS[code];
#endif
    }
}

void reset_color() {
    if (color_enabled(false, false)) {
#if defined(_WIN32)
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, static_cast<WORD>(WHITE_CODE));
#else
        cout << ANSI_COLOR_STRINGS[RESET_CODE];
#endif
    }
}
