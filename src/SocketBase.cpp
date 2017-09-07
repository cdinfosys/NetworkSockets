#include "SocketBase.hpp"
#include "SocketException.hpp"

namespace AbcdEFramework
{
    namespace Sockets
    {
        void SocketBase::Bind(const SocketAddress& sockaddr)
        {
            int result = ::bind(this->mSocketHandle, sockaddr.GetSocketAddress(), sockaddr.GetAddressLength());
            if (result == -1)
            {
                throw SocketException(SocketException::GetErrNo());
            }
        }

        void SocketBase::Listen(int backlog)
        {
            int result = ::listen(this->mSocketHandle, backlog);
            if (result == -1)
            {
                throw SocketException(SocketException::GetErrNo());
            }
        }

        void SocketBase::Connect(const SocketAddress& sockaddr)
        {
            int result = ::connect(this->mSocketHandle, sockaddr.GetSocketAddress(), sockaddr.GetAddressLength());
            if (result == -1)
            {
                throw SocketException(SocketException::GetErrNo());
            }
        }
    } // namespace Sockets
} // namespace AbcdEFramework
