#ifndef _COLOR_H_
#define _COLOR_H_

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

#include <iostream>
#include <string>
#include <sstream>

#ifdef _WIN32
    #include <windows.h>  // for WinAPI and Sleep()
    #define _NO_OLDNAMES  // for MinGW compatibility
#endif

/**
 * Enums: Color codes
 *
 * BLACK - Black
 * BLUE - Blue
 * GREEN - Green
 * CYAN - Cyan
 * RED - Red
 * MAGENTA - Magenta / purple
 * BROWN - Brown / dark yellow
 * GREY - Grey / dark white
 * DARKGREY - Dark grey / light black
 * LIGHTBLUE - Light blue
 * LIGHTGREEN - Light green
 * LIGHTCYAN - Light cyan
 * LIGHTRED - Light red
 * LIGHTMAGENTA - Light magenta / light purple
 * YELLOW - Yellow (bright)
 * WHITE - White (bright)
 */
enum {
    BLACK_CODE,
    BLUE_CODE,
    GREEN_CODE,
    CYAN_CODE,
    RED_CODE,
    MAGENTA_CODE,
    BROWN_CODE,
    GREY_CODE,
    DARKGREY_CODE,
    LIGHTBLUE_CODE,
    LIGHTGREEN_CODE,
    LIGHTCYAN_CODE,
    LIGHTRED_CODE,
    LIGHTMAGENTA_CODE,
    YELLOW_CODE,
    WHITE_CODE,
    RESET_CODE
};

/**
 * Consts: ANSI color strings
 *
 * BLACK - Black
 * BLUE - Blue
 * GREEN - Green
 * CYAN - Cyan
 * RED - Red
 * MAGENTA - Magenta / purple
 * BROWN - Brown / dark yellow
 * GREY - Grey / dark white
 * DARKGREY - Dark grey / light black
 * LIGHTBLUE - Light blue
 * LIGHTGREEN - Light green
 * LIGHTCYAN - Light cyan
 * LIGHTRED - Light red
 * LIGHTMAGENTA - Light magenta / light purple
 * YELLOW - Yellow (bright)
 * WHITE - White (bright)
 */
const std::string ANSI_COLOR_STRINGS[] = {
    "\033[22;30m",
    "\033[22;34m",
    "\033[22;32m",
    "\033[22;36m",
    "\033[22;31m",
    "\033[22;35m",
    "\033[22;33m",
    "\033[22;37m",
    "\033[01;30m",
    "\033[01;34m",
    "\033[01;32m",
    "\033[01;36m",
    "\033[01;31m",
    "\033[01;35m",
    "\033[01;33m",
    "\033[01;37m",
    "\033[01;0m"
};

/**
 * Requires: Nothing.
 * Modifies: whether or not coloration is enabled
 * Effects: Modify coloration setting to value of enable if toggle is
 *          true. Return coloration setting.
 */
bool color_enabled(bool toggle, bool enable);

/**
 * Requires: code is a value between BLACK_CODE and RESET_CODE.
 * Modifies: cout
 * Effects: Change output text color to that specified by the given
 *          code according to the color codes enum above.
 */
void set_color(int code);

/**
 * Requires: Nothing.
 * Modifies: cout
 * Effects: Reset output text color initial color. This is assumed to
 *          be white on Windows.
 */
void reset_color();

#endif // _COLOR_H_
