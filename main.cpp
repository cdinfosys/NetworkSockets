/**
 * Program entry point.
 */

#include "targetver.hpp"

#include <iostream>
#include <SocketAddressIp4.hpp>
#include <SocketException.hpp>

#include "OsPlatform.hpp"

using std::cout;
using std::endl;

#if (AEFRAMEWORK_OS_PLATFORM == PLATFORM_WINDOWS)
    #include <WinSock.hpp>
    using Socket = AbcdEFramework::Sockets::WinSock;
#elif (AEFRAMEWORK_OS_PLATFORM == PLATFORM_GNU_LINUX)
    #include <BerkelySocket.hpp>
    using Socket = AbcdEFramework::Sockets::BerkelySocket;
#endif // AEFRAMEWORK_OS_PLATFORM

using AbcdEFramework::Sockets::SocketAddressIp4;
using AbcdEFramework::Sockets::SocketException;


/**
 * @brief Program entry point.
 * @param argc Number of command line arguments passed to the program
 * @param argv Collection of command line arguments.
 *
 */
int main(int /*argc*/, char** /*argv[]*/)
{
    return 0;
}
