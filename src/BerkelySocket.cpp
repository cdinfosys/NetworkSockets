#include "BerkelySocket.hpp"

// This code will not compile on Windows
#if (AEFRAMEWORK_OS_PLATFORM == PLATFORM_GNU_LINUX)

namespace AbcdEFramework
{
    namespace Sockets
    {
        inline AEF_HSOCKET BerkelySocket::CreateSocket(const SocketCreationParam& createParam)
        {
            AEF_HSOCKET socketFD = (AEF_HSOCKET)::socket(createParam.GetDomain(), createParam.GetType(), createParam.GetProtocol());
            if (socketFD == -1)
            {
                throw SocketException(SocketException::GetErrNo());
            }

            return socketFD;
        }

        BerkelySocket BerkelySocket::Accept()
        {
            AEF_HSOCKET fdSocket = ::accept(this->GetSocketHandle(), nullptr, nullptr);
            if (fdSocket == INVALID_SOCKET)
            {
                throw SocketException(SocketException::GetErrNo());
            }
            return std::move(BerkelySocket(fdSocket));
        }

        BerkelySocket BerkelySocket::Accept(SocketAddressResult& peerAddress)
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
            return std::move(BerkelySocket(fdSocket));
        }

        void BerkelySocket::Send(const SocketSendBuffer& buffer, int flags)
        {
            ssize_t result = ::send(GetSocketHandle(), (const void*)buffer, buffer.GetBufferLengthBytes(), flags);
            if (result == -1)
            {
                throw SocketException(SocketException::GetErrNo());
            }
        }

    } // namespace Sockets
} // namespace AbcdEFramework

#endif // AEFRAMEWORK_OS_PLATFORM
