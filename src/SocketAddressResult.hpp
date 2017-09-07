#ifndef SOCK_ADDRESS_RESULT_D8FB7569F0AE4AC0A4F2C362C3335F2B
#define SOCK_ADDRESS_RESULT_D8FB7569F0AE4AC0A4F2C362C3335F2B 1

#include <vector>
#include <cstdint>
#include "SocketTypeDefs.hpp"

namespace AbcdEFramework
{
    namespace Sockets
    {
        class SocketBase;

        /**
         * @brief Stores a socket address that is received from a call to \c accept()
         * @remarks This class is a security nightmare because it exposes the internal address buffer. Handle with care!
         */
        class SocketAddressResult
        {
            private:
                std::vector<uint8_t> mAddressBuffer; ///< Buffer where the resulting address will be stored.
                socklen_t mAddressLength; ///< Length of the address stored in \c mAddressBuffer.

            public:
                /**
                 * @brief Default constructor. Initialises the address buffer to 8KiB storage.
                 */
                inline SocketAddressResult();

                /**
                 * @brief Destructor
                 */
                inline ~SocketAddressResult();

            public:
                /**
                 * @brief Gets a reference to the variable that holds the length of the address stored in the buffer.
                 * @retval Reference to the internal address length variable.
                 */
                inline socklen_t& AddressLength();

                /**
                 * @brief Gets a reference to the variable that holds the length of the address stored in the buffer.
                 * @retval Reference to the internal address length variable.
                 */
                inline const socklen_t& AddressLength() const;

                /**
                 * @brief Get a pointer to the address buffer.
                 */
                inline operator const sockaddr*() const;

                /**
                 * @brief Get a pointer to the address buffer.
                 */
                inline operator sockaddr*() const;
        }; // class SocketAddressResult

        inline SocketAddressResult::SocketAddressResult()
            :   mAddressBuffer((size_t)(8 * 1024), 0u),
                mAddressLength((socklen_t)mAddressBuffer.size())
        {
        }

        inline SocketAddressResult::~SocketAddressResult()
        {
            this->mAddressLength = 0u;
        }

        inline socklen_t& SocketAddressResult::AddressLength()
        {
            return this->mAddressLength;
        }

        inline const socklen_t& SocketAddressResult::AddressLength() const
        {
            return this->mAddressLength;
        }

        inline SocketAddressResult::operator const sockaddr*() const
        {
            return (sockaddr*)(&(this->mAddressBuffer[0]));
        }

        inline SocketAddressResult::operator sockaddr*() const
        {
            return (sockaddr*)(&(this->mAddressBuffer[0]));
        }
    } // namespace Sockets
} // namespace AbcdEFramework

#endif // SOCK_ADDRESS_RESULT_D8FB7569F0AE4AC0A4F2C362C3335F2B
