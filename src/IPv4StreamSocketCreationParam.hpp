#ifndef SOCK_CPARAM_IPV4_STREAM_EFC8C5BFE01A4DF5AD2FE48858D18E45
#define SOCK_CPARAM_IPV4_STREAM_EFC8C5BFE01A4DF5AD2FE48858D18E45 1

#include "SocketCreationParam.hpp"

namespace AbcdEFramework
{
    namespace Sockets
    {
        /**
         * @brief Socket creation parameter for creating an IPv4 stream socket
         * @remarks The domain used is AF_INET and the type is SOCK_STREAM.
         */
        class IPv4StreamSocketCreationParam : public SocketCreationParam
        {
            public:
                /**
                 * @brief Construct a creation parameters object for an IPv4 stream socket.
                 * @param protocol Protocol to use. A value of 0 specifies the default protocol
                 */
                inline IPv4StreamSocketCreationParam(int protocol = 0);

                /**
                 * @brief Destructor
                 */
                virtual inline ~IPv4StreamSocketCreationParam();
        }; // class IPv4StreamSocketCreationParam

        inline IPv4StreamSocketCreationParam::IPv4StreamSocketCreationParam(int protocol)
            :   SocketCreationParam(AF_INET, SOCK_STREAM, protocol)
        {
        }

        inline IPv4StreamSocketCreationParam::~IPv4StreamSocketCreationParam()
        {
        }
    } // namespace Sockets
} // namespace AbcdEFramework

#endif // SOCK_CPARAM_IPV4_STREAM_EFC8C5BFE01A4DF5AD2FE48858D18E45
