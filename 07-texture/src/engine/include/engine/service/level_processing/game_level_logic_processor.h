//
// Created by vito on 30.10.20.
//

#ifndef INC_03_GUESS_NUMBER_GAME_LEVEL_LOGIC_PROCESSOR_H
#define INC_03_GUESS_NUMBER_GAME_LEVEL_LOGIC_PROCESSOR_H

#include <engine/engine_assets.h>

#include <chrono>
#include <memory>
#include <vector>

#include "engine/service/text_world/text_world_object_processor.h"
#include "engine/service/variable_processing/game_variables.h"
#include "level.h"

// TODO: factory
class GameLevelLogicProcessor {
 public:
  static void Init();
  // TODO: hide this
  static GameLevelLogicProcessor& GetSingleton();

  void ProcessLevel(size_t level_id);

  size_t getCurrentProcessingLevelId() const;

  void LoadTextWorldObject(size_t level_based_two_id) const;

  static void BreakMainLoop();

  void SetNextLevel(size_t i);

  static bool isNotLastLevel();

  void ProcessNextLevel();

    static void setNotLastLevel(bool b);

private:
  inline static std::unique_ptr<GameLevelLogicProcessor> singleton_;
  inline static bool is_inited_;
  inline static bool is_continuing_;
  inline static bool is_transition_;
  size_t current_processing_level_id_{0};
  std::chrono::milliseconds frame_delta_;
  size_t next_processing_level_id{0};
};

#endif  // INC_03_GUESS_NUMBER_GAME_LEVEL_LOGIC_PROCESSOR_H
