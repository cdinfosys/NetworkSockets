#ifndef BERKELY_SOCKET_42CD8795472A45C7A1D75B6E2FB56FE8
#define BERKELY_SOCKET_42CD8795472A45C7A1D75B6E2FB56FE8 1

namespace AbcdEFramework
{
    namespace Sockets
    {
        /**
         * @brief Base class for Berkely sockets wrappers
         */
        class BerkelySocket
        {
            public:
                /**
                 * @brief
                 */
                inline BerkelySocket();

                /**
                 * @brief Copy constructor.
                 * @param src Object from where the values are copied.
                 */
                //BerkelySocket(const BerkelySocket& src);

                /**
                 * @brief Move constructor.
                 * @param src Object from where the values are copied.
                 */
                //BerkelySocket(BerkelySocket&& src);
                
                /**
                 * @brief Destructor
                 */
                virtual inline ~BerkelySocket();

            public:
                /**
                 * @brief Copy assignment operator
                 * @param src Object from where the values are copied.
                 * @returns Returns a reference to this object.
                 */
                //BerkelySocket operator=(const BerkelySocket& src);

                /**
                 * @brief Move assignment operator
                 * @param src Object from where the values are copied.
                 * @returns Returns a reference to this object.
                 */
                //BerkelySocket operator=(BerkelySocket&& src);

        }; // class BerkelySocket

        inline BerkelySocket::BerkelySocket()
        {
        }

        inline BerkelySocket::~BerkelySocket()
        {
        }
    } // namespace Sockets
} // namespace AbcdEFramework

#endif // BERKELY_SOCKET_42CD8795472A45C7A1D75B6E2FB56FE8
