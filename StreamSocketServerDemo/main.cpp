/**
 * Program entry point.
 */

#include "targetver.hpp"

#include <iostream>
#include <stdexcept>
#include <NetworkSocketsLib.hpp>

#ifndef AEFRAMEWORK_OS_PLATFORM
    // If you see this error you must define AEFRAMEWORK_OS_PLATFORM somewhere in the build environment. ! == GNU/Linux target, 2 == Windows target.
    #error "AEFRAMEWORK_OS_PLATFORM precompiler macro is not defined."
#else
    #if (AEFRAMEWORK_OS_PLATFORM == PLATFORM_GNU_LINUX)
        using Socket = AbcdEFramework::Sockets::BerkelySocket;
    #elif (AEFRAMEWORK_OS_PLATFORM == PLATFORM_WINDOWS)
        using Socket = AbcdEFramework::Sockets::WinSock;
    #endif
#endif

using std::cout;
using std::cerr;
using std::endl;

using AbcdEFramework::Sockets::SocketAddressIp4;
using AbcdEFramework::Sockets::SocketException;
using AbcdEFramework::Sockets::IPv4StreamSocketCreationParam;

/**
 * @brief Program entry point.
 * @param argc Number of command line arguments passed to the program.
 * @param argv Array of null-terminated strings containing the arguments passed to the program via the command line.
 * @retval 0 Success.
 * @retval others An error occured during execution of the program.
 */
int main(int argc, char* argv[])
{
    try
    {
        IPv4StreamSocketCreationParam socketCreationParam;
        Socket socket(socketCreationParam);
        //SocketAddressIp4 bindAddress("192.168.0.17", 555);
        SocketAddressIp4 bindAddress("192.168.0.17", 555);
        socket.Bind(bindAddress);
        socket.Listen(5);
        socket.Accept();

        cout << "Connect start" << endl;
    }
    catch (SocketException& ex)
    {
        cerr << "SocketException " << ex.GetErrorCode() << " (" << ex.what() << ")" << endl;
        exit(ex.GetErrorCode());
    }
    catch (std::exception& ex)
    {
        cerr << "Exception: " << ex.what() << endl;
        exit(0x7FFF);
    }
    catch (...)
    {
        cerr << "Unknown exception caught" << endl;
        exit(0x7FFF);
    }

    exit(0);
}

