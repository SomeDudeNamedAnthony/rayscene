#include "Stager/Stage.hh"
class MyStage2 : public Stager::Stage
{
  public:
    MyStage2( )
        : Stager::Stage( "MyStage2" )
    {
    }
};