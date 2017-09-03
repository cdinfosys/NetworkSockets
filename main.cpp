/**
 * Program entry point.
 */

#include "targetver.hpp"

#include <iostream>
#include <WinSock.hpp>
#include <SocketAddressIp4.hpp>
#include <SocketException.hpp>

using std::cout;
using std::endl;

using AbcdEFramework::Sockets::WinSock;
using AbcdEFramework::Sockets::SocketAddressIp4;
using AbcdEFramework::Sockets::SocketException;

int main(int /*argc*/, char** /*argv[]*/)
{

    try
    {
        WinSock winSock(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        SocketAddressIp4 bindAddress("127.0.0.1", 48483);
    }
    catch (SocketException& ex)
    {
        cout << "SocketException " << ex.GetErrorCode() << " (" << ex.what() << ")" << endl;
        return ex.GetErrorCode();
    }

    return 0;
}
