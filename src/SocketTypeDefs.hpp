/**
 * Some type aliasing to make porting between GNU/Linux and Windows easier.
 */
#ifndef SOCKET_TYPE_DEF_4BCD29D72EAC49FC9D0580AE479EA8C6
#define SOCKET_TYPE_DEF_4BCD29D72EAC49FC9D0580AE479EA8C6 1

#include "../OsPlatform.hpp"

// The sockets header file location differs for Windows and Linux
#if (AEFRAMEWORK_OS_PLATFORM == PLATFORM_GNU_LINUX)
    #include <sys/socket.h>
#elif (AEFRAMEWORK_OS_PLATFORM == PLATFORM_WINDOWS)
    #include <WinSock2.h>
    #include <ws2tcpip.h>
#endif

namespace AbcdEFramework
{
    namespace Sockets
    {
        #if (AEFRAMEWORK_OS_PLATFORM == PLATFORM_GNU_LINUX)
            using AEF_HSOCKET = int; ///< HSOCKET is of type int
            const int AEF_NULL_SOCKET_HANDLE = -1;
            using AEF_SOCKET_ADDR = sockaddr; ///< Socket address base type
        #elif (AEFRAMEWORK_OS_PLATFORM == PLATFORM_WINDOWS)
            using AEF_HSOCKET = SOCKET; ///< HSOCKET is of type SOCKET
            using AEF_SOCKET_ADDR = sockaddr; ///< Socket address base type
            const SOCKET AEF_NULL_SOCKET_HANDLE = INVALID_SOCKET;
        #endif
    } // namespace Sockets
} // namespace AbcdEFramework

#endif // SOCKET_TYPE_DEF_4BCD29D72EAC49FC9D0580AE479EA8C6
