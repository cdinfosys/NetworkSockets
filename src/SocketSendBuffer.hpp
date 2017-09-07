#ifndef SOCK_SEND_BUFFER_F5ABAA247F6414EA750A955E6E40952
#define SOCK_SEND_BUFFER_F5ABAA247F6414EA750A955E6E40952 1

#include <cstdint>
#include <vector>

namespace AbcdEFramework
{
    namespace Sockets
    {
        /**
         * @brief Encapsulates a byte bufffer for sending
         */
        class SocketSendBuffer
        {
            private:
                std::vector<uint8_t> mByteBuffer; ///< Storage for the buffer.

            public:
                /**
                 * @brief Construct a buffer from a vector
                 */
                inline SocketSendBuffer(const std::vector<uint8_t>& src);

                /**
                 * @brief Destructor
                 */
                virtual inline ~SocketSendBuffer();

            public:
                /**
                 * @brief Returns the number of bytes in the buffer.
                 * @returns The number of bytes in the buffer.
                 */
                inline size_t GetBufferLengthBytes() const;

                /**
                 * @brief Get a pointer to the buffer;
                 * @returns Returns a pointer to the buffer storage.
                 */
                inline operator const void*() const;
        }; // class SocketSendBuffer

        inline SocketSendBuffer::SocketSendBuffer(const std::vector<uint8_t>& src)
            :   mByteBuffer(src)
        {
        }

        inline SocketSendBuffer::~SocketSendBuffer()
        {
        }

        size_t SocketSendBuffer::GetBufferLengthBytes() const
        {
            return this->mByteBuffer.size();
        }

        inline SocketSendBuffer::operator const void* () const
        {
            return &(this->mByteBuffer[0]);
        }
    } // namespace Sockets
} // namespace AbcdEFramework

#endif // SOCK_SEND_BUFFER_F5ABAA247F6414EA750A955E6E40952
