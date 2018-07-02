////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2018 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFMLJOY_CONFIG_HPP
#define SFMLJOY_CONFIG_HPP


////////////////////////////////////////////////////////////
// Define the SFML version
////////////////////////////////////////////////////////////
#define SFMLJOY_VERSION_MAJOR 2
#define SFMLJOY_VERSION_MINOR 5
#define SFMLJOY_VERSION_PATCH 0


////////////////////////////////////////////////////////////
// Identify the operating system
// see http://nadeausoftware.com/articles/2012/01/c_c_tip_how_use_compiler_predefined_macros_detect_operating_system
////////////////////////////////////////////////////////////
#if defined(_WIN32)

    // Windows
    #define SFMLJOY_SYSTEM_WINDOWS
    #ifndef NOMINMAX
        #define NOMINMAX
    #endif

#elif defined(__APPLE__) && defined(__MACH__)

    // Apple platform, see which one it is
    #include "TargetConditionals.h"

    #if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR

        // iOS
        #define SFMLJOY_SYSTEM_IOS

    #elif TARGET_OS_MAC

        // MacOS
        #define SFMLJOY_SYSTEM_MACOS

    #else

        // Unsupported Apple system
        #error This Apple operating system is not supported by SFML library

    #endif

#elif defined(__unix__)

    // UNIX system, see which one it is
    #if defined(__ANDROID__)

        // Android
        #define SFMLJOY_SYSTEM_ANDROID

    #elif defined(__linux__)

         // Linux
        #define SFMLJOY_SYSTEM_LINUX

    #elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)

        // FreeBSD
        #define SFMLJOY_SYSTEM_FREEBSD

    #elif defined(__OpenBSD__)

        // OpenBSD
        #define SFMLJOY_SYSTEM_OPENBSD

    #else

        // Unsupported UNIX system
        #error This UNIX operating system is not supported by SFML library

    #endif

#else

    // Unsupported system
    #error This operating system is not supported by SFML library

#endif


////////////////////////////////////////////////////////////
// Define a portable debug macro
////////////////////////////////////////////////////////////
#if !defined(NDEBUG)

    #define SFMLJOY_DEBUG

#endif


////////////////////////////////////////////////////////////
// Define helpers to create portable import / export macros for each module
////////////////////////////////////////////////////////////
// Static build doesn't need import/export macros
#define SFMLJOY_API_EXPORT
#define SFMLJOY_API_IMPORT

////////////////////////////////////////////////////////////
// Cross-platform warning for deprecated functions and classes
//
// Usage:
// class SFMLJOY_DEPRECATED MyClass
// {
//     SFMLJOY_DEPRECATED void memberFunc();
// };
//
// SFMLJOY_DEPRECATED void globalFunc();
////////////////////////////////////////////////////////////
#if defined(SFMLJOY_NO_DEPRECATED_WARNINGS)

    // User explicitly requests to disable deprecation warnings
    #define SFMLJOY_DEPRECATED

#elif defined(_MSC_VER)

    // Microsoft C++ compiler
    // Note: On newer MSVC versions, using deprecated functions causes a compiler error. In order to
    // trigger a warning instead of an error, the compiler flag /sdl- (instead of /sdl) must be specified.
    #define SFMLJOY_DEPRECATED __declspec(deprecated)

#elif defined(__GNUC__)

    // g++ and Clang
    #define SFMLJOY_DEPRECATED __attribute__ ((deprecated))

#else

    // Other compilers are not supported, leave class or function as-is.
    // With a bit of luck, the #pragma directive works, otherwise users get a warning (no error!) for unrecognized #pragma.
    #pragma message("SFMLJOY_DEPRECATED is not supported for your compiler, please contact the SFML team")
    #define SFMLJOY_DEPRECATED

#endif


////////////////////////////////////////////////////////////
// Define portable fixed-size types
////////////////////////////////////////////////////////////
namespace sfmljoy
{
    // All "common" platforms use the same size for char, short and int
    // (basically there are 3 types for 3 sizes, so no other match is possible),
    // we can use them without doing any kind of check

    // 8 bits integer types
    typedef signed   char Int8;
    typedef unsigned char Uint8;

    // 16 bits integer types
    typedef signed   short Int16;
    typedef unsigned short Uint16;

    // 32 bits integer types
    typedef signed   int Int32;
    typedef unsigned int Uint32;

    // 64 bits integer types
    #if defined(_MSC_VER)
        typedef signed   __int64 Int64;
        typedef unsigned __int64 Uint64;
    #else
        typedef signed   long long Int64;
        typedef unsigned long long Uint64;
    #endif

} // namespace sfmljoy


#endif // SFMLJOY_CONFIG_HPP
