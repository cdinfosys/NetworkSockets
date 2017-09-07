/**
 * Parent header file for the NetworkSocketsLib project.
 */
#ifndef NET_SOCK_LIB_58EC6BF3AE0049CDBB5774D9C2711B01
#define NET_SOCK_LIB_58EC6BF3AE0049CDBB5774D9C2711B01 1

#include "OsPlatform.hpp"
#include "SocketTypeDefs.hpp"
#include "SocketException.hpp"
#include "SocketBase.hpp"

#if (AEFRAMEWORK_OS_PLATFORM == PLATFORM_GNU_LINUX)
    #include "BerkelySocket.hpp"
#elif (AEFRAMEWORK_OS_PLATFORM == PLATFORM_WINDOWS)
    #include "WinSock.hpp"
#endif

#include "SocketAddress.hpp"
#include "SocketAddressIp4.hpp"

#include "SocketCreationParam.hpp"
#include "IPv4StreamSocketCreationParam.hpp"

#endif // NET_SOCK_LIB_58EC6BF3AE0049CDBB5774D9C2711B01
