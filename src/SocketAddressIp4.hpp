#ifndef SOCK_ADDR_IN4_2714F9A3F0244D41B53B22D5B359333E
#define SOCK_ADDR_IN4_2714F9A3F0244D41B53B22D5B359333E 1

#include <memory.h>
#include <string>
#include "SocketTypeDefs.hpp"
#include "SocketAddress.hpp"

namespace AbcdEFramework
{
    namespace Sockets
    {
        /**
         * @brief Socket address for IPv4 addresses.
         */
        class SocketAddressIp4 : public SocketAddress
        {
            private:
                sockaddr_in _address; ///< Structure returned by GetSocketAddress()

            public:
                /**
                 * @brief Construct an object with an IP address and a port number.
                 * @param ipAddress IP address.
                 * @param port Port number.
                 * @note The address must be a standart IPv4 dotted address (e.g. 127.0.0.1)
                 */
                SocketAddressIp4(const std::string& ipAddress, unsigned int port);

                /**
                 * @brief Copy constructor.
                 * @param src Object from where the values are copied.
                 */
                //SocketAddressIp4(const SocketAddressIp4& src);

                /**
                 * @brief Move constructor.
                 * @param src Object from where the values are copied.
                 */
                //SocketAddressIp4(SocketAddressIp4&& src);
                
                /**
                 * @brief Destructor
                 */
                virtual inline ~SocketAddressIp4();

            public:
                /**
                 * @brief Copy assignment operator
                 * @param src Object from where the values are copied.
                 * @returns Returns a reference to this object.
                 */
                //SocketAddressIp4 operator=(const SocketAddressIp4& src);

                /**
                 * @brief Move assignment operator
                 * @param src Object from where the values are copied.
                 * @returns Returns a reference to this object.
                 */
                //SocketAddressIp4 operator=(SocketAddressIp4&& src);

            public:
                /**
                 * @brief Return the socket address.
                 * @returns Returns a pointer to a socket address structure. The underlying structure type is defined
                 *      by the type of address and is handled by the derive class.
                 */
                virtual inline const AEF_SOCKET_ADDR* GetSocketAddress() const;

                /**
                 * @brief Return the length of the address structure.
                 * @returns Returns the size of the object returned by the \c GetSocketAddress() method.
                 */
                virtual inline socklen_t GetAddressLength() const; 

        }; // class SocketAddressIp4

        inline SocketAddressIp4::~SocketAddressIp4()
        {
        }

        inline const AEF_SOCKET_ADDR* SocketAddressIp4::GetSocketAddress() const
        {
            return (AEF_SOCKET_ADDR*)&this->_address;
        }

        inline socklen_t SocketAddressIp4::GetAddressLength() const
        {
            return (socklen_t) sizeof(_address);
        }

    } // namespace Sockets
} // namespace AbcdEFramework

#endif // SOCK_ADDR_IN4_2714F9A3F0244D41B53B22D5B359333E
