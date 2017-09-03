#include "SocketBase.hpp"
#include "SocketException.hpp"

namespace AbcdEFramework
{
    namespace Sockets
    {
        void SocketBase::Bind(const SocketAddress& sockaddr)
        {
            int result = bind(this->_socketHandle, sockaddr.GetSocketAddress(), sockaddr.GetAddressLength());
            if (result < 0)
            {
                throw SocketException(SocketException::GetErrNo());
            }
        }
    } // namespace Sockets
} // namespace AbcdEFramework
