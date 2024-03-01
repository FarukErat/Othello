#pragma once
#ifndef OS_DEPENDENT_FUNCTIONS
#define OS_DEPENDENT_FUNCTIONS

#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)
#include <windows.h>
inline void sleep(unsigned ms) {
    Sleep(ms);
}

inline void clearScreen() {
    system("cls");
}

#else // presume POSIX
#include <unistd.h>
inline void sleep(unsigned ms) {
    usleep(ms);
}

inline void clearScreen() {
    system("clear");
}
#endif

#endif // OS_DEPENDENT_FUNCTIONS