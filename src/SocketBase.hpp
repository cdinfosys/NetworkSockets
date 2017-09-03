#ifndef SOCKET_BASE_709ADD2B710C45718EBEE0BAC41209A7
#define SOCKET_BASE_709ADD2B710C45718EBEE0BAC41209A7 1

#include "../OsPlatform.hpp"
#include "SocketTypeDefs.hpp"
#include "SocketAddress.hpp"

#if (AEFRAMEWORK_OS_PLATFORM == PLATFORM_GNU_LINUX)
    #include <sys/socket.h>
#elif (AEFRAMEWORK_OS_PLATFORM == PLATFORM_WINDOWS)
    // link with Ws2_32.lib
    #pragma comment(lib,"Ws2_32.lib")

    #include <WinSock2.h>
    #include <ws2tcpip.h>
#endif

namespace AbcdEFramework
{
    namespace Sockets
    {
        /**
         * @brief Base class for socket wrappers.
         */
        class SocketBase
        {
            private:
                AEF_HSOCKET _socketHandle; ///< Stores the socket handle / file descriptor

            protected:
                /**
                 * @brief Construct a socket object.
                 * @param socketHandle Handle of the socket.
                 */
                inline SocketBase(AEF_HSOCKET socketHandle);

            private:
                /**
                 * @brief Copy constructor.
                 * @param src Object from where the values are copied.
                 */
                SocketBase(const SocketBase& src) = delete;

            public:
                /**
                 * @brief Move constructor.
                 * @param src Object from where the values are copied.
                 */
                inline SocketBase(SocketBase&& src);

            public:
                /**
                 * @brief Destructor
                 */
                virtual inline ~SocketBase();

            private:
                /**
                 * @brief Copy assignment operator
                 * @param src Object from where the values are copied.
                 * @returns Returns a reference to this object.
                 */
                SocketBase& operator=(const SocketBase& src) = delete;

            public:
                /**
                 * @brief Move assignment operator
                 * @param src Object from where the values are copied.
                 * @returns Returns a reference to this object.
                 */
                inline SocketBase& operator=(SocketBase&& src);

            public:
                /**
                 * @brief Bind to a socket.
                 * @param sockaddr Reference to a \c SocketAddress derived socket address object.
                 */
                void Bind(const SocketAddress& sockaddr);

            protected:
                /**
                 * @brief Returns the handle of the socket that was passed to the constructor.
                 */
                inline AEF_HSOCKET GetSocketHandle() const;

        }; // class SocketBase

        inline SocketBase::SocketBase(AEF_HSOCKET socketHandle)
            :   _socketHandle(socketHandle)
        {
        }

        inline SocketBase::~SocketBase()
        {
            this->_socketHandle = AEF_NULL_SOCKET_HANDLE;
        }

        inline SocketBase::SocketBase(SocketBase&& src)
            :   _socketHandle(src._socketHandle)
        {
            src._socketHandle = AEF_NULL_SOCKET_HANDLE;
        }

        inline SocketBase& SocketBase::operator=(SocketBase&& src)
        {
            this->_socketHandle = src._socketHandle;
            src._socketHandle = AEF_NULL_SOCKET_HANDLE;
            return *this;
        } 

        inline AEF_HSOCKET SocketBase::GetSocketHandle() const
        {
            return this->_socketHandle;
        }
    } // namespace Sockets
} // namespace AbcdEFramework

#endif // SOCKET_BASE_709ADD2B710C45718EBEE0BAC41209A7
