#ifndef STAGER_ENTITY_H
#define STAGER_ENTITY_H

#include <string>
#include <string_view>
namespace Stager
{
class Stage;

/// @brief A property to define how an actor should "act".
class Costume
{
    friend class Stage;

    /// @brief The name of the costume.
    std::string _name;

    /// @brief A reference to the stage that's being occupied.
    Stage *_stage = nullptr;

    /// @brief Undefined, define it yourself.
    Costume( Costume && ) noexcept;

    /// @brief Undefined, define it yourself.
    Costume( Costume & );

    /// @brief Undefined, define it yourself.
    Costume &operator=( Costume && ) noexcept;

    /// @brief Undefined, define it yourself.
    Costume &operator=( Costume & );

  protected:
    /// @brief The name of the costume.
    [[nodiscard]] std::string_view getName( ) const;

    /// @brief A reference to the stage that's being occupied.
    [[nodiscard]] Stage *getStage( ) const;

    /**
     * @brief Sets the stage that will be occupied.
     *
     * @param stage A reference to the stage.
     */
    void setStage( Stage const &stage );

  public:
    explicit Costume( std::string name );
    virtual ~Costume( ) = default;

    virtual void _enter( ){ /* Fill implementation. */ };
    virtual void _process( float delta ){ /* Fill implementation. */ };
    virtual void _render( float delta ){ /* Fill implementation. */ };
    virtual void _exit( ){ /* Fill implementation. */ };
};
} // namespace Stager

#endif // STAGER_ENTITY_H
