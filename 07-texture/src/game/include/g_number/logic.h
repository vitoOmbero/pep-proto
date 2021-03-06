#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#ifndef INC_03_GUESS_NUMBER_G_NUMBER_LOGIC_H
#define INC_03_GUESS_NUMBER_G_NUMBER_LOGIC_H

#include "engine/pep.h"

// TODO: chaiscript embedded

namespace GuessNumber::Logic {

namespace intro_level {

void OnLoad();

void Body();

void Transition();

inline text_world_objects::Stand welcome{{"@@game_title"}};

inline const Level data{
    // LEVEL
    {0},
    {{welcome}},
    {intro_level::OnLoad, intro_level::Body, intro_level::Transition}};
}  // namespace intro_level

namespace difficulty_level {
void OnLoad();

void Body();

void Transition();

inline text_world_objects::DialogNaturalInput choose_diff{
    {"@difficulty_level"}, 0, 1, true, "@diff_interval"};

inline const Level data{{{1, 2}},
                        {{choose_diff}},
                        {difficulty_level::OnLoad, difficulty_level::Body,
                         difficulty_level::Transition}};
}  // namespace difficulty_level

namespace lobby_level {
void OnLoad();

void Body();

void Transition();

inline text_world_objects::Stand number{
    {{"@number_max"}}, false, text_world_objects::Stand::Layout::kPureText, 0};
inline text_world_objects::Stand attempts{
    {{"@attempts_max"}},
    false,
    text_world_objects::Stand::Layout::kPureText,
    1};
inline text_world_objects::Stand ready{
    {{/*no*/}}, true, text_world_objects::Stand::Layout::kPureText, 2};
inline text_world_objects::Stand spoiler{
    {{"@secret_number"}},
    true,
    text_world_objects::Stand::Layout::kFixedDefaultBordered,
    3};

inline const Level data{
    // LEVEL
    {{3, 4, 5, 6}},
    {{number, attempts, ready, spoiler}},
    {lobby_level::OnLoad, lobby_level::Body, lobby_level::Transition}};
}  // namespace lobby_level

namespace game_core_loop_level {
void OnLoad();

void Body();

void Transition();

inline text_world_objects::DialogNaturalInput guess_dialog{
    "@effort_val", 0, 1, false, "@num_interval"};

inline text_world_objects::Stand bigger_info{
    /*no args*/ {{}},
    /*no input*/ false, text_world_objects::Stand::Layout::kPureText, 2};

inline text_world_objects::Stand smaller_info{
    /*no args*/ {{}},
    /*no input*/ false, text_world_objects::Stand::Layout::kPureText, 3};

inline text_world_objects::Stand guessed_number_info{
    {{"@secret_number"}},
    /*no input*/ true,
    text_world_objects::Stand::Layout::kPureText,
    4};

inline text_world_objects::Stand tries_left{
    {{"@attempts_left"}},
    /*no input*/ false,
    text_world_objects::Stand::Layout::kPureText,
    5};

inline text_world_objects::Stand no_more_tries{
    /*no args*/ {{}},
    /*no input*/ true, text_world_objects::Stand::Layout::kPureText, 6};

inline const Level data{
    // LEVEL
    {{7, 8, 9, 10, 11, 12, 13}},
    {{guess_dialog, bigger_info, smaller_info, guessed_number_info, tries_left,
      no_more_tries}},
    {game_core_loop_level::OnLoad, game_core_loop_level::Body,
     game_core_loop_level::Transition}};
}  // namespace game_core_loop_level

namespace game_result_level {
void OnLoad();

void Body();

void Transition();

inline text_world_objects::Stand finished{
    /*no args*/ {{}},
    /*no input*/ false, text_world_objects::Stand::Layout::kPureText, 0};
inline text_world_objects::Stand spoiler_endgame{
    {{"@secret_number"}},
    /*no input*/ false,
    text_world_objects::Stand::Layout::kPureText,
    1};
inline text_world_objects::Stand attempts_result{
    {{"@attempt_counter"}},
    /*no input*/ false,
    text_world_objects::Stand::Layout::kPureText,
    2};
inline text_world_objects::Stand good_result{
    /*no args*/ {{}},
    /*no input*/ true, text_world_objects::Stand::Layout::kPureText, 3};
inline text_world_objects::Stand bad_result{
    /*no args*/ {{}},
    /*no input*/ true, text_world_objects::Stand::Layout::kPureText, 4};

inline const Level data{
    // LEVEL
    {{14, 15, 16, 17, 18}},
    {{finished, spoiler_endgame, attempts_result, good_result, bad_result}},
    {game_result_level::OnLoad, game_result_level::Body,
     game_result_level::Transition}};
}  // namespace game_result_level

namespace GlobalVariables {

inline std::vector<VariableDeclaration> declaration{
    {VariableType::kNaturalInterval, "@diff_interval", "1-3"},
    {VariableType::kNatural, "@number_max", "100500"},
    {VariableType::kNatural, "@attempts_max"},
    {VariableType::kNatural, "@secret_number"},
    {VariableType::kNatural0, "@effort_val"},
    {VariableType::kNatural0, "@attempt_counter"},
    {VariableType::kNatural0, "@attempts_left"},
    {VariableType::kNatural, "@difficulty_level"},
    {VariableType::kBool, "@finished"},
    // TODO: refactoring + game objects usage and engine API description
    {VariableType::kNaturalInterval, "@num_interval", "1-200"},
    {VariableType::kNatural, "@number_min", "1"},
    // TODO: built-in variables
    {VariableType::kString, "@@game_title", "Guess FNumber"},
};

}  // namespace GlobalVariables

inline const std::vector<Level> guess_number_levels{
    intro_level::data, difficulty_level::data, lobby_level::data,
    game_core_loop_level::data, game_result_level::data};

}  // namespace GuessNumber::Logic
#endif  // INC_03_GUESS_NUMBER_G_NUMBER_LOGIC_H

#pragma clang diagnostic pop