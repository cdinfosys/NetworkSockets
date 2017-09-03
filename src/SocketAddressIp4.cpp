#include <cstdint>
#include "SocketException.hpp"
#include "SocketAddressIp4.hpp"

namespace AbcdEFramework
{
    namespace Sockets
    {
        SocketAddressIp4::SocketAddressIp4(const std::string& ipAddress, unsigned int port)
        {
            memset(&this->_address, 0, sizeof(this->_address));
            this->_address.sin_family = AF_INET;

            int ptonResult;
            if ((ptonResult = inet_pton(AF_INET, ipAddress.c_str(), &(this->_address.sin_addr)) != 1))
            {
                if (ptonResult == 0)
                {
                    throw SocketException(ipAddress);
                }
                else
                {
                    throw SocketException(EAFNOSUPPORT);
                }
            }

            // Store the port number in network byte order.
            this->_address.sin_port = htons((uint16_t)port);
        }
    } // namespace Sockets
} // namespace AbcdEFramework
