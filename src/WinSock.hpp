#ifndef WINSOCK_00D32D06F33446DA915F20FB163B057B
#define WINSOCK_00D32D06F33446DA915F20FB163B057B 1

#include <utility>
#include "SocketBase.hpp"

namespace AbcdEFramework
{
    namespace Sockets
    {
        /**
         * @brief WinSock wrapper
         */
        class WinSock : public SocketBase
        {
            public:
                /**
                 * @brief Construct a socket object.
                 */
                inline WinSock(int domain, int type, int protocol);

                /**
                 * @brief Copy constructor.
                 * @param src Object from where the values are copied.
                 */
                WinSock(const WinSock& src) = delete;

                /**
                 * @brief Move constructor.
                 * @param src Object from where the values are copied.
                 */
                inline WinSock(WinSock&& src);
                
                /**
                 * @brief Destructor
                 */
                virtual inline ~WinSock();

            public:
                /**
                 * @brief Copy assignment operator
                 * @param src Object from where the values are copied.
                 * @returns Returns a reference to this object.
                 */
                WinSock operator=(const WinSock& src) = delete;

                /**
                 * @brief Move assignment operator
                 * @param src Object from where the values are copied.
                 * @returns Returns a reference to this object.
                 */
                inline WinSock& operator=(WinSock&& src);

            private:
                /**
                 * @brief Helper for the constructor to create a socket.
                 * @param domain 
                 * @param type
                 * @param protocol
                 */
                inline AEF_HSOCKET CreateSocket(int domain, int type, int protocol);
        }; // class WinSock

        inline WinSock::WinSock(int domain, int type, int protocol)
            :   SocketBase(CreateSocket(domain, type, protocol))
        {
        }

        inline WinSock::~WinSock()
        {
            closesocket(GetSocketHandle());
        }

        inline WinSock::WinSock(WinSock&& src)
            :   SocketBase(std::move(src))
        {
        }

        inline WinSock& WinSock::operator=(WinSock&& src)
        {
            SocketBase::operator=(std::move(src));
            return *this;
        } 

        inline AEF_HSOCKET WinSock::CreateSocket(int domain, int type, int protocol)
        {
            return (AEF_HSOCKET)socket(domain, type, protocol);
        }
    } // namespace Sockets
} // namespace AbcdEFramework

#endif // WINSOCK_00D32D06F33446DA915F20FB163B057B
