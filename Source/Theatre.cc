#include "./../Include/Stager/Theatre.hh"
#include "./../Include/Stager/Exceptions/DuplicateStageException.hh"
#include "Stager/Exceptions/NonExistentStageException.hh"
#include "Stager/Stage.hh"
#include <cstddef>
#include <utility>

namespace Stager
{
Theatre::Theatre( std::string_view name )
    : _name( name )
{
}

Theatre::Theatre( std::string_view name, std::vector<Stage> stages )
    : _name( name )
    , _stages( std::move( stages ) )
{
    for ( Stage const &check : _stages )
    {
#ifdef __llvm__
#pragma unroll 1
#endif
        for ( Stage const &against : _stages )
        {
            if ( check.getName( ) == against.getName( ) )
            {
                throw Exceptions::DuplicateStageException( _name,
                                                           check.getName( ) );
            }
        }
    }
}

void Theatre::addStage( Stage &stage )
{
#if __llvm__
#pragma unroll 1
#endif
    for ( Stage const &against : this->_stages )
    {
        if ( against.getName( ) == stage.getName( ) )
        {
            throw Exceptions::DuplicateStageException( _name,
                                                       stage.getName( ) );
        }
    }
    this->_stages.push_back( std::move( stage ) );
}

void Theatre::removeStage( std::string_view name )
{
#ifdef __llvm__
#pragma unroll 1
#endif
    for ( std::size_t stageIndex = 0; stageIndex < this->_stages.size( );
          stageIndex++ )
    {
        Stage const &stage = this->_stages.at( stageIndex );
        if ( stage.getName( ) == name )
        {
            this->_stages.erase( this->_stages.begin( )
                                 + static_cast<long>( stageIndex ) );
        }
    }
}

std::string_view Theatre::getName( ) const
{
    return this->_name;
}

void Theatre::changeStage( std::string_view name, bool autoLoad )
{
#ifdef __llvm__
#pragma unroll 1
#endif
    for ( Stage &stage : this->_stages )
    {
        if ( stage.getName( ) == name )
        {
            if ( this->_currentStage != nullptr )
            {
                this->_currentStage->unload( );
            }

            this->_currentStage = &stage;

            if ( autoLoad )
            {
                this->_currentStage->load( );
            }
        }
    }

    throw Exceptions::NonExistentStageException( this->_name, name );
}

} // namespace Stager