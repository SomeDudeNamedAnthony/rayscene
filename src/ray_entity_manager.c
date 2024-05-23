#include "./rayscene.h"
#include <malloc/_malloc.h>
#include <raylib.h>
#include <stdlib.h>
#include <string.h>

EntityManager CreateEntityManager( void )
{
    return ( EntityManager ){ ( void * )0, 0 };
}

void AddEntityToEntityManager( EntityManager *entityManager, Entity *entity )
{
    if ( !entityManager )
    {
        TraceLog( LOG_ERROR, "Entity manager is NULL." );
        return;
    }

    if ( !entity )
    {
        TraceLog( LOG_ERROR, "Can't add NULL entity to entity manager<%p>.",
                  entityManager );
        return;
    }

    if ( !entityManager->entityCount )
    {
        entityManager->entities = RS_CALLOC( 1, sizeof( Entity * ) );
        if ( !entityManager->entities )
        {
            TraceLog( LOG_ERROR,
                      "Failed to allocate data for entity pointer in entity "
                      "manager<%p>.",
                      entityManager );
            return;
        }
        entityManager->entities[entityManager->entityCount] = entity;
    }
    else
    {

        Entity **buffer = RS_REALLOC(
            entityManager->entities,
            ( sizeof( Entity * ) * ( entityManager->entityCount + 1 ) +
              sizeof( Entity * ) ) );

        if ( !buffer )
        {
            TraceLog( LOG_ERROR, "Failed to resize entity resize " );
        }
    }
    entityManager->entityCount++;
}
