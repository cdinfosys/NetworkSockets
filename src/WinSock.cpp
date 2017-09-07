#include "WinSock.hpp"
#include "SocketException.hpp"

// This code will not compile on GNU/Linux
#if (AEFRAMEWORK_OS_PLATFORM == PLATFORM_WINDOWS)

namespace AbcdEFramework
{
    namespace Sockets
    {
        AEF_HSOCKET WinSock::CreateSocket(const SocketCreationParam& createParam)
        {
            WSADATA wsaData;

            int result = ::WSAStartup(MAKEWORD(2, 2), &wsaData);
            if (result != 0)
            {
                throw SocketException(result);
            }

            AEF_HSOCKET socketFD = (AEF_HSOCKET)::socket(createParam.GetDomain(), createParam.GetType(), createParam.GetProtocol());
            if (socketFD == -1)
            {
                throw SocketException(SocketException::GetErrNo());
            }

            return socketFD;
        }

        WinSock::~WinSock()
        {
            ::closesocket(GetSocketHandle());
            ::WSACleanup();
        }

        WinSock WinSock::Accept()
        {
            AEF_HSOCKET fdSocket = ::accept(this->GetSocketHandle(), nullptr, nullptr);
            if (fdSocket == INVALID_SOCKET)
            {
                throw SocketException(SocketException::GetErrNo());
            }
            return std::move(WinSock(fdSocket));
        }

        WinSock WinSock::Accept(SocketAddressResult& peerAddress)
        {
            AEF_HSOCKET fdSocket = ::accept
            (
                this->GetSocketHandle(), 
                peerAddress,
                &(peerAddress.AddressLength())
            );
            if (fdSocket == INVALID_SOCKET)
            {
                throw SocketException(SocketException::GetErrNo());
            }
            return std::move(WinSock(fdSocket));
        }

        void WinSock::Send(const SocketSendBuffer& buffer, int flags)
        {
            SSIZE_T result = ::send(this->GetSocketHandle(), (const char*)(const void*)buffer, (int)buffer.GetBufferLengthBytes(), flags);
            if (result == -1)
            {
                throw SocketException(SocketException::GetErrNo());
            }
        }
    } // namespace Sockets
} // namespace AbcdEFramework

#endif // AEFRAMEWORK_OS_PLATFORM
