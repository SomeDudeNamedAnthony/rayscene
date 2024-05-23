#ifndef RAYSCENE_H
#define RAYSCENE_H

#define RAYLIB_VERSION_MAJOR 1
#define RAYLIB_VERSION_MINOR 0
#define RAYLIB_VERSION_PATCH 0
#define RAYLIB_VERSION "1.0.0-dev"

// Function specifiers in case library is build/used as a shared library
// NOTE: Microsoft specifiers to tell compiler that symbols are
// imported/exported from a .dll NOTE: visibility("default") attribute makes
// symbols "visible" when compiled with -fvisibility=hidden
#if defined( _WIN32 )
#if defined( __TINYC__ )
#define __declspec( x ) __attribute__( ( x ) )
#endif
#if defined( BUILD_LIBTYPE_SHARED )
#define RCAPI                                                                  \
    __declspec(                                                                \
        dllexport ) // We are building the library as a Win32 shared library
                    // (.dll)
#elif defined( USE_LIBTYPE_SHARED )
#define RCAPI                                                                  \
    __declspec( dllimport ) // We are using the library as a Win32 shared
                            // library (.dll)
#endif
#else
#if defined( BUILD_LIBTYPE_SHARED )
#define RCAPI                                                                  \
    __attribute__( (                                                           \
        visibility( "default" ) ) ) // We are building as a Unix shared library
                                    // (.so/.dylib)
#endif
#endif

#ifndef RCAPI
#define RCAPI // Functions defined as 'extern' by default (implicit specifiers)
#endif

//----------------------------------------------------------------------------------
// Some basic Defines
//----------------------------------------------------------------------------------

// Allow custom memory allocators
// NOTE: Require recompiling rayscene sources
#ifndef RS_MALLOC
#define RS_MALLOC( sz ) malloc( sz )
#endif
#ifndef RS_CALLOC
#define RS_CALLOC( n, sz ) calloc( n, sz )
#endif
#ifndef RS_REALLOC
#define RS_REALLOC( ptr, sz ) realloc( ptr, sz )
#endif
#ifndef RS_FREE
#define RS_FREE( ptr ) free( ptr )
#endif

// Some compilers (mostly macos clang) default to C++98,
// where aggregate initialization can't be used
// So, give a more clear error stating how to fix this
#if !defined( _MSC_VER ) && ( defined( __cplusplus ) && __cplusplus < 201103L )
#error "C++11 or later is required. Add -std=c++11"
#endif

//----------------------------------------------------------------------------------
// Structures Definition
//----------------------------------------------------------------------------------
// Boolean type
#if ( defined( __STDC__ ) && __STDC_VERSION__ >= 199901L ) ||                  \
    ( defined( _MSC_VER ) && _MSC_VER >= 1800 )
#include <stdbool.h>
#elif !defined( __cplusplus ) && !defined( bool )
typedef enum bool
{
    false = 0,
    true = !false
} bool;
#define RL_BOOL_TYPE
#endif

/// @brief An object that is processed in a scenes.
typedef struct Entity Entity;

/// @brief A
typedef struct Scene Scene;

typedef struct Entity
{
    /// @brief A reference to the scene the entity is occupying
    Scene *scene;

    /// @brief Called during a scene
    void ( *Enter )( struct Entity *self );

    /// @brief Called every frame for logic handling.
    void ( *Process )( struct Entity *self, float *delta );

    /// @brief Called every frame for graphical purposes.
    void ( *Render )( struct Entity *self, float *delta );

    /// @brief Called during the exiting of a scene.
    void ( *Exit )( struct Entity *self );

    unsigned int id;
} Entity;

typedef void ( *EntityEnterFunc )( Entity *self );
typedef void ( *EntityProcessFunc )( Entity *self, float *delta );
typedef void ( *EntityRenderFunc )( Entity *self, float *delta );
typedef void ( *EntityExitFunc )( Entity *self );

/// @brief An alias for an entity.
typedef Entity Object;

/// @brief An alias for an entity.
typedef Entity Actor;

/// @brief Manages entities for a scene.
typedef struct EntityManager
{
    /// @brief An array of pointers to entities.
    Entity **entities;

    /// @brief ...
    unsigned int entityCount;
} EntityManager;

typedef struct Scene
{
    EntityManager entityManager;
} Scene;

/// @brief Manages scenes.
typedef struct SceneManager
{
    /// @brief
    Scene **scenes;

    /// @brief Self-explanitory, a pointer to the current scene.
    Scene *currentScene;
} SceneManager;

//------------------------------------------------------------------------------------
// Functions Definition
//------------------------------------------------------------------------------------

#if defined( __cplusplus )
extern "C"
{ // Prevents name mangling of functions
#endif

    //------------------------------------------------------------------------------------
    // Entity Definition
    //------------------------------------------------------------------------------------

    /// @brief Creates a entity manager.
    RCAPI EntityManager CreateEntityManager( void );

    /**
     * @brief Adds an entity to a entity manager.
     *
     * @param entityManager The entity manager to add the entity to.
     * @note ENTITIES WILL NOT BE COPIED.
     */
    RCAPI void AddEntityToEntityManager( EntityManager *entityManager,
                                         Entity *entity );

    /**
     * @brief Remove an entity from a entity manager.
     *
     * @param entityManager The entity manager to remove the entity from.
     */
    RCAPI void RemoveEntityToEntityManager( EntityManager *entityManager,
                                            Entity *entity );

#if defined( __cplusplus )
}
#endif

#endif // RAYSCENE_H
