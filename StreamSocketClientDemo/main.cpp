/**
 * @brief Demo IPv4 stream sockets app for connecting to a remote server.
 */
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <string.h>
#include <vector>

#include "targetver.hpp"

#include <NetworkSocketsLib.hpp>
#include <SocketSendBuffer.hpp>

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

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::exception;

using AbcdEFramework::Sockets::SocketAddressIp4;
using AbcdEFramework::Sockets::SocketException;
using AbcdEFramework::Sockets::IPv4StreamSocketCreationParam;
using AbcdEFramework::Sockets::SocketSendBuffer;

void RunTest(const string& ipAddr, int port);

/**
 * @brief Program entry point.
 * @param argc Number of command line arguments passed to the program.
 * @param argv Array of null-terminated strings containing the arguments passed to the program via the command line.
 * @retval 0 Success.
 * @retval others An error occured during execution of the program.
*/
int main(int argc, char* argv[])
{
    bool showHelp(false);
    for (int argIndex = 1; argIndex < argc; ++argIndex)
    {
        if 
        (
            (_stricmp(argv[argIndex], "-h") == 0) ||
            (_stricmp(argv[argIndex], "--help") == 0)
        )
        {
            showHelp = true;
            break;
        }
    }

    if (argc != 3)
    {
        showHelp = true;
    }

    if (showHelp)
    {
        cout << endl << "USAGE: " << argv[0] << " <ip-addr> <port> [-h | --help]" << endl;
        cout << "WHERE <ip-addr> Server IP address (dotted notation, e.g. 127.0.0.1)" << endl;
        cout << "      <port> Port number" << endl << endl;
        exit(0);
    }

    try
    {
        char* lastChar;
        int portNumber = strtol(argv[2], &lastChar, 10);
        if (*lastChar != '\0')
        {
            throw std::exception("Non-numeric port number");
        }

        RunTest(argv[1], portNumber);
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

void RunTest(const string& ipAddr, int port)
{
    IPv4StreamSocketCreationParam socketCreationParam;
    Socket socket(socketCreationParam);
    SocketAddressIp4 remoteAddress(ipAddr, port);
    socket.Connect(remoteAddress);

    SocketSendBuffer sendBuffer(vector<uint8_t> { 'F', 'o', 'o' });
    socket.Send(sendBuffer);
}
