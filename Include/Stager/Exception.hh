#pragma once

#include <exception>
#include <memory>
#include <string>
#include <string_view>
namespace Stager
{
/// @brief An exception with custom formatting.
class Exception : public std::exception
{
  private:
    /// @brief The message to display.
    std::string _message;

  public:
    /// @brief Creates an exception with a default message.
    Exception( );

    /**
     * @brief Creates an exception with a defined message.
     *
     * @param message The message to display.
     */
    explicit Exception( std::string_view message );

    [[nodiscard]] const char *what( ) const noexcept override;
};

inline Exception::Exception( std::string_view message )
{
    _message.append( "[Stager] " );
    _message.append( "[Error]: " );
    _message.append( message );
}

inline const char *Exception::what( ) const noexcept
{
    return _message.c_str( );
}
} // namespace Stager
