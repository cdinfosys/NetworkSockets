#ifndef WINSOCK_00D32D06F33446DA915F20FB163B057B
#define WINSOCK_00D32D06F33446DA915F20FB163B057B 1

#include "OsPlatform.hpp"
// This code will not compile on GNU/Linux
#if (AEFRAMEWORK_OS_PLATFORM == PLATFORM_WINDOWS)
#include <utility>
//#include <Windows.h>

#include "SocketBase.hpp"
#include "SocketCreationParam.hpp"

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
                inline WinSock(const SocketCreationParam& createParam);

                inline WinSock(WinSock&& src);

                /**
                 * @brief Destructor
                 */
                virtual ~WinSock();

            protected:
                /**
                 * @brief Hidden constructor to construct a socket object from a socket handle.
                 * @param fdSocket Handle of the socket.
                 * @note This constructor overload exists for the convenience of the \c Accept() method and should not be used by other methods.
                 */
                inline WinSock(AEF_HSOCKET fdSocket);

            public:
               /**
                * @brief Accepts a socket connection and returns a new socket for the connection.
                * @returns Returns a socket object for the connection.
                */
                WinSock Accept();

                /**
                 * @brief Accepts a socket connection and returns a new socket for the connection.
                 * @param peerAddress Reference to a \c SocketAddressResult object that receives the address of the peer socket.
                 * @returns Returns a socket object for the connection.
                 */
                WinSock Accept(SocketAddressResult& peerAddress);

                /**
                 * @brief Send the contents of the buffer to the peer socket.
                 * @param buffer Reference to an object derived from \c SocketSendBuffer that supplies the data.
                 * @param flags Send flags.
                 */
                void Send(const SocketSendBuffer& buffer, int flags = 0);

            private:
                /**
                 * @brief Helper for the constructor to create a socket.
                 * @param domain 
                 * @param type
                 * @param protocol
                 */
                static AEF_HSOCKET CreateSocket(const SocketCreationParam& createParam);

            private:
                /**
                 * @brief Copy constructor.
                 * @param src Object from where the values are copied.
                 */
                WinSock(const WinSock& src) = delete;

                /**
                 * @brief Copy assignment operator
                 * @param src Object from where the values are copied.
                 * @returns Returns a reference to this object.
                 */
                WinSock operator=(const WinSock& src) = delete;
        }; // class WinSock

        inline WinSock::WinSock(AEF_HSOCKET fdSocket)
            :   SocketBase(fdSocket)
        {
        }

        inline WinSock::WinSock(const SocketCreationParam& createParam)
            :   SocketBase(CreateSocket(createParam))
        {
        }

        inline WinSock::WinSock(WinSock&& src)
            :   SocketBase(std::move(src))
        {
        }
    } // namespace Sockets
} // namespace AbcdEFramework

#endif // AEFRAMEWORK_OS_PLATFORM

#endif // WINSOCK_00D32D06F33446DA915F20FB163B057B
