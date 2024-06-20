#pragma once

#include "./../Exception.hh"
#include <string_view>

namespace Stager::Exceptions
{
class DuplicateStageException : public Exception
{
  public:
    explicit DuplicateStageException( std::string_view theatreName,
                                      std::string_view stageName );
};

inline DuplicateStageException::DuplicateStageException(
    std::string_view theatreName, std::string_view stageName )
    : Exception( std::string{ "Theatre \"" }
                     .append( theatreName )
                     .append( "\" " )
                     .append( "has a duplicate stage called \"" )
                     .append( stageName )
                     .append( "\"." ) )
{
}
} // namespace Stager::Exceptions
