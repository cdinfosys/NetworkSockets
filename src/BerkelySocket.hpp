#ifndef BERKELY_SOCKET_42CD8795472A45C7A1D75B6E2FB56FE8
#define BERKELY_SOCKET_42CD8795472A45C7A1D75B6E2FB56FE8 1

#include "OsPlatform.hpp"

// This code will not compile on Windows
#if (AEFRAMEWORK_OS_PLATFORM == PLATFORM_GNU_LINUX)

#include <sys/socket.h>
#include "SocketBase.hpp"
#include "SocketCreationParam.hpp"

namespace AbcdEFramework
{
    namespace Sockets
    {
        /**
         * @brief Base class for Berkely sockets wrappers
         */
        class BerkelySocket : public SocketBase
        {
            public:
                /**
                 * @brief Construct a socket object.
                 * @param createParam Reference to an object derived from \c SocketCreationParam that supplies the creation parameters for the socket.
                 */
                inline BerkelySocket(const SocketCreationParam& createParam);

                /**
                 * @brief Destructor
                 */
                virtual inline ~BerkelySocket();

            protected:
                /**
                 * @brief Hidden constructor to construct a socket object from a socket handle.
                 * @param fdSocket Handle of the socket.
                 * @note This constructor overload exists for the convenience of the \c Accept() method and should not be used by other methods.
                 */
                inline BerkelySocket(AEF_HSOCKET fdSocket);

            public:
                /**
                 * @brief Accepts a socket connection and returns a new socket for the connection.
                 * @returns Returns a socket object for the connection.
                 */
                BerkelySocket Accept();

                /**
                 * @brief Accepts a socket connection and returns a new socket for the connection.
                 * @param peerAddress Reference to a \c SocketAddressResult object that receives the address of the peer soc
                 * @returns Returns a socket object for the connection.
                 */
                BerkelySocket Accept(SocketAddressResult& peerAddress);

                /**
                 * @brief Send the contents of the buffer to the peer socket.
                 * @param buffer Reference to an object derived from \c SocketSendBuffer that supplies the data.
                 * @param flags Send flags.
                 */
                void Send(const SocketSendBuffer& buffer, int flags = 0);

            private:
                /**
                 * @brief Helper for the constructor to create a socket.
                 */
                static AEF_HSOCKET CreateSocket(const SocketCreationParam& createParam);

            private:
                /**
                 * @brief Copy constructor.
                 * @param src Object from where the values are copied.
                 * @remarks The copy constructor is not available.
                 */
                BerkelySocket(const BerkelySocket& src) = delete;

                /**
                 * @brief Copy assignment operator
                 * @param src Object from where the values are copied.
                 * @returns Returns a reference to this object.
                 * @remarks The copy assignment operator is not available.
                 */
                BerkelySocket operator=(const BerkelySocket& src) = delete;
        }; // class BerkelySocket

        inline BerkelySocket::BerkelySocket(const SocketCreationParam& createParam)
            :   SocketBase(BerkelySocket::CreateSocket(domain, type, protocol))
        {
        }

        inline BerkelySocket::BerkelySocket(AEF_HSOCKET fdSocket)
            :   SocketBase(fdSocket)
        {
        }

        inline BerkelySocket::~BerkelySocket()
        {
        }
    } // namespace Sockets
} // namespace AbcdEFramework

#endif // AEFRAMEWORK_OS_PLATFORM

#endif // BERKELY_SOCKET_42CD8795472A45C7A1D75B6E2FB56FE8
