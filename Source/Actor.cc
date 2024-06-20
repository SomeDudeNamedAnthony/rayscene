#include "./../Include/Stager/Actor.hh"

namespace Stager
{

void Actor::initialize( )
{
    this->_costume._enter( );
}

void Actor::process( float delta )
{
    this->_costume._process( delta );
}

void Actor::draw( float delta )
{
    this->_costume._render( delta );
}

void Actor::terminate( )
{
    this->_costume._exit( );
}
} // namespace Stager