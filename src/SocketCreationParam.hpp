#ifndef SOCK_CREATE_PARAM_24D84BBB17674C23ACF62571A96D6B79
#define SOCK_CREATE_PARAM_24D84BBB17674C23ACF62571A96D6B79 1

namespace AbcdEFramework
{
    namespace Sockets
    {
        /**
         * @brief Base class for objects that supply socket creation parameters. Objects that supply creation parameters for
         *  stream sockets, datagram sockets, etc. derive from this class.
         */
        class SocketCreationParam
        {
            private:
                int mDomain; ///< Socket communications domain
                int mType; ///< Socket type (SOCK_STREAM or SOCK_DGRAM)
                int mProtocol; ///< Protocol type.

            protected:
                /**
                 * @brief Default constructor is hidden
                 * @param domain Socket communications domain
                 * @param type Socket type (SOCK_STREAM or SOCK_DGRAM)
                 * @param protocol Protocol type. Usually zero.
                 */
                inline SocketCreationParam(int domain, int type, int protocol = 0);

            public:
                /**
                 * @brief Destructor
                 */
                virtual inline ~SocketCreationParam();

            public:
                /**
                 * @brief Get the communications domain
                 */
                inline int GetDomain() const;

                /**
                 * @brief Get the socket type
                 */
                inline int GetType() const;

                /**
                 * @brief Get the protocol type
                 */
                inline int GetProtocol() const;
        }; // class SocketCreationParam

        inline SocketCreationParam::SocketCreationParam(int domain, int type, int protocol)
            :   mDomain(domain),
                mType(type),
                mProtocol(protocol)
        {
        }

        inline SocketCreationParam::~SocketCreationParam()
        {
        }

        int SocketCreationParam::GetDomain() const
        {
            return this->mDomain;
        }

        int SocketCreationParam::GetType() const
        {
            return this->mType;
        }

        int SocketCreationParam::GetProtocol() const
        {
            return this->mProtocol;
        }
    } // namespace Sockets
} // namespace AbcdEFramework

#endif // SOCK_CREATE_PARAM_24D84BBB17674C23ACF62571A96D6B79
