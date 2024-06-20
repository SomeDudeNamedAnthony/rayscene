#pragma once

#include "./Stage.hh"
#include <string_view>
#include <vector>

class Logger;
namespace Stager
{
class Theatre
{
    std::string_view _name;
    std::vector<Stage> _stages{ };

    Stage *_currentStage = nullptr;

  public:
    /// @brief Creates a theatre no stages.
    explicit Theatre( std::string_view name );

    /**
     * @brief Creates a theatre with defined stages.
     * @note The array passed will be moved instead of copied.
     * @param stages An array of stages.
     * @throws DuplicateSceneException If there are duplicate stages.
     */
    explicit Theatre( std::string_view name, std::vector<Stage> stages );

    /**
     * @brief Adds a new stage.
     *
     * @param stage
     * @throws DuplicateSceneException If a stage of that name already exists.
     */
    void addStage( Stage &stage );

    /**
     * @brief Removes an existing stage.
     *
     * @param name The name of the stage to remove.
     */
    void removeStage( std::string_view name );

    /**
     * @brief Set the current stage.
     *
     * @param name The stage to choose.
     * @param autoLoad
     */
    [[noreturn]] void changeStage( std::string_view name, bool autoLoad );

    [[nodiscard]] std::string_view getName( ) const;
};

} // namespace Stager
