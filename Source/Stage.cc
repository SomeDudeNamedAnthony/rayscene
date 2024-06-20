#include "./../Include/Stager/Stage.hh"

namespace Stager
{

Stage::Stage( std::string_view name )
    : _name( name )
{
}

std::string_view Stage::getName( ) const
{
    return this->_name;
}

void Stage::load( )
{
    this->_onLoad( );
}

void Stage::unload( )
{
    this->_actors.clear( );
}

} // namespace Stager