/**
 * Defines a preprocessor macro for identifying the platform on which the source is being compiled.
 */
#ifndef OS_PLATFORM_CEE6DC3B4EE24F06954FF61A52AF3EB7
#define OS_PLATFORM_CEE6DC3B4EE24F06954FF61A52AF3EB7 1

#define PLATFORM_GNU_LINUX 1
#define PLATFORM_WINDOWS 2

#ifndef AEFRAMEWORK_OS_PLATFORM
    #ifdef _MSC_VER
        #define AEFRAMEWORK_OS_PLATFORM PLATFORM_WINDOWS
    #elif __GNUC__
        #define AEFRAMEWORK_OS_PLATFORM PLATFORM_GNU_LINUX
    #endif 
#endif // AEFRAMEWORK_OS_PLATFORM

#endif // OS_PLATFORM_CEE6DC3B4EE24F06954FF61A52AF3EB7