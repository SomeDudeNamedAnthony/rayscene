#pragma once

#include "./../Exception.hh"
#include <string_view>

namespace Stager::Exceptions
{
class NonExistentStageException : public Exception
{
  public:
    explicit NonExistentStageException( std::string_view theatreName,
                                        std::string_view stageName );
};

inline NonExistentStageException::NonExistentStageException(
    std::string_view theatreName, std::string_view stageName )
    : Exception( std::string{ "Theatre \"" }
                     .append( theatreName )
                     .append( "\" " )
                     .append( "has no stage called \"" )
                     .append( stageName )
                     .append( "\"." ) )
{
}
} // namespace Stager::Exceptions
