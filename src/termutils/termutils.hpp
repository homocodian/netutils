#pragma once

#include <cstdio>

#ifdef _WIN32
#include <io.h>
#define isatty _isatty
#define fileno _fileno
#else
#include <unistd.h>
#endif

namespace termutils {
inline bool isPiped() { return !isatty(fileno(stdin)); }
} // namespace termutils
