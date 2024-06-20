#include <utility>

#include "./../Include/Stager/Costume.hh"
#include "./../Include/Stager/Stage.hh"

namespace Stager
{
Costume::Costume( std::string name )
    : _name( std::move( name ) )
{
}

std::string_view Costume::getName( ) const
{
    return this->_name;
}

Stage *Costume::getStage( ) const
{
    return this->_stage;
}

} // namespace Stager