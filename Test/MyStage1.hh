#include "Stager/Stage.hh"
class MyStage1 : public Stager::Stage
{
  public:
    MyStage1( )
        : Stager::Stage( "MyStage1" )
    {
    }
};