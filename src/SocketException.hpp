#ifndef SOCKET_EXCEPTION_1526C759255B4BD7907718024DCD7306
#define SOCKET_EXCEPTION_1526C759255B4BD7907718024DCD7306 1

#include <errno.h>
#include <stdexcept>
#include <string>
#include "SocketTypeDefs.hpp"
#include "OsPlatform.hpp"

namespace AbcdEFramework
{
    namespace Sockets
    {
        /**
         * @brief Exception thrown by socket wrapper classes.
         */
        class SocketException : public std::runtime_error
        {
            private:
                int _errorCode; // Error code

            public:
                /**
                 * @brief Construct an exception object with an error code.
                 * @param errorCode The error code that was returned by \c SocketException::GetErrNo()
                 */
                inline SocketException(int errorCode);

                /**
                 * @brief Construct an exception object with an error code and a message.
                 * @param errorCode The error code that was returned by \c SocketException::GetErrNo()
                 * @param what Error description
                 */
                inline SocketException(int errorCode, const std::string& what);

                /**
                 * @brief Construct an exception object with an error message. The error code is set to -1.
                 * @param what Error description
                 */
                inline SocketException(const std::string& what);

                /**
                 * @brief Destructor
                 */
                virtual inline ~SocketException();

            public:
                inline int GetErrorCode() const;

            public:
                /**
                 * @brief Get the error number in an OS independent way.
                 * @returns Returns the last error that occurred.
                 */
                static inline int GetErrNo();
        }; // class SocketException

        inline SocketException::SocketException(int errorCode)
            :   std::runtime_error(nullptr),
                _errorCode(errorCode)
        {
        }

        inline SocketException::SocketException(int errorCode, const std::string& what)
            :   std::runtime_error(what),
                _errorCode(errorCode)
        {
        }

        inline SocketException::SocketException(const std::string& what)
            :   std::runtime_error(what),
                _errorCode(-1)
        {
        }

        inline SocketException::~SocketException()
        {
        }

        inline int SocketException::GetErrorCode() const
        {
            return this->_errorCode;
        }

        inline int SocketException::GetErrNo()
        {
            #if (AEFRAMEWORK_OS_PLATFORM == PLATFORM_GNU_LINUX)
                return errno;
            #elif (AEFRAMEWORK_OS_PLATFORM == PLATFORM_WINDOWS)
                return ::WSAGetLastError();
            #else
                return -1;
            #endif
        }

    } // namespace Sockets
} // namespace AbcdEFramework

#endif // SOCKET_EXCEPTION_1526C759255B4BD7907718024DCD7306
