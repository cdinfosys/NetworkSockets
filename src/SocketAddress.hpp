#ifndef SOCKET_ADDR_4BCD29D72EAC49FC9D0580AE479EA8C6
#define SOCKET_ADDR_4BCD29D72EAC49FC9D0580AE479EA8C6 1

#include "SocketTypeDefs.hpp"

namespace AbcdEFramework
{
    namespace Sockets
    {
        /**
         * @brief Base class for classes that provide addresses for the bind() function.
         */
        class SocketAddress
        {
            protected:
                /**
                 * @brief Default constructor is hidden.
                 */
                inline SocketAddress();

            private:
                /**
                 * @brief Copy constructor.
                 * @param src Object from where the values are copied.
                 */
                SocketAddress(const SocketAddress& src) = delete;

                /**
                 * @brief Move constructor.
                 * @param src Object from where the values are copied.
                 */
                SocketAddress(SocketAddress&& src) = delete;

            public:
                /**
                 * @brief Destructor
                 */
                virtual inline ~SocketAddress();

            private:
                /**
                 * @brief Copy assignment operator
                 * @param src Object from where the values are copied.
                 * @returns Returns a reference to this object.
                 */
                SocketAddress& operator=(const SocketAddress& src) = delete;

                /**
                 * @brief Move assignment operator
                 * @param src Object from where the values are copied.
                 * @returns Returns a reference to this object.
                 */
                SocketAddress& operator=(SocketAddress&& src) = delete;

            public:
                /**
                 * @brief Return the socket address.
                 * @returns Returns a pointer to a socket address structure. The underlying structure type is defined
                 *      by the type of address and is handled by the derive class.
                 */
                virtual const AEF_SOCKET_ADDR* GetSocketAddress() const = 0;

                /**
                 * @brief Return the length of the address structure.
                 * @returns Returns the size of the object returned by the \c GetSocketAddress() method.
                 */
                virtual socklen_t GetAddressLength() const = 0; 
        }; // class SocketAddress

        inline SocketAddress::SocketAddress()
        {
        }

        inline SocketAddress::~SocketAddress()
        {
        }
    } // namespace Sockets
} // namespace AbcdEFramework

#endif // SOCKET_ADDR_4BCD29D72EAC49FC9D0580AE479EA8C6
