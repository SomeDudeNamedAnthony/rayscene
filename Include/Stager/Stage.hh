#pragma once

#include <string_view>
#include <vector>

class Theatre;
class Actor;
namespace Stager
{
class Stage
{
    friend class Theatre;

    std::string_view _name;
    std::vector<Actor *> _actors;

  protected:
    void load( );

    /**
     * @brief Unloads all actors from DRAM.
     *
     */
    void unload( );

  public:
    virtual ~Stage( ) = default;
    explicit Stage( std::string_view name );

    [[nodiscard]] std::string_view getName( ) const;

    virtual void _onLoad( ){ /* Fill implementation. */ };

    Stage( Stage && ) noexcept = default;

    /// @brief Unused, why would you copy a scene?
    Stage( Stage const & ) = delete;

    /// @brief
    Stage &operator=( Stage && ) noexcept = default;

    /// @brief Unused, why would you copy a scene?
    Stage &operator=( Stage const & ) = delete;
};
} // namespace Stager
