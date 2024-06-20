#ifndef STAGER_INSTANCE_H
#define STAGER_INSTANCE_H

#include "./Costume.hh"
namespace Stager
{
class Actor
{
    friend class Stage;
    Costume _costume;

  protected:
    void initialize( );
    void process( float delta );
    void draw( float delta );
    void terminate( );
};
} // namespace Stager

#endif // STAGER_INSTANCE_H
