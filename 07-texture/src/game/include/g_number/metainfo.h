#ifndef INC_03_GUESS_NUMBER_G_NUMBER_METAINFO_H
#define INC_03_GUESS_NUMBER_G_NUMBER_METAINFO_H

#include <unordered_map>

#include "engine/pep.h"

namespace GuessNumber {
inline const std::unordered_map<Culture::Language,
                                GameDescriptionStrings>
    game_description_strings = {  // NOLINT(cert-err58-cpp)
        {Culture::kEn,
         {{"Guess The FNumber"}, {"$"}, {"Bye-bye! See you later!"}}},
        {Culture::kRu, {{"Угадай БЧисло"}, {"@"}}}};

inline const GameDescriptionInfo gdi{{"guess_num"}, {0, 1, 2}, 0, 4};
}  // namespace GuessNumber

#endif  // INC_03_GUESS_NUMBER_G_NUMBER_METAINFO_H
