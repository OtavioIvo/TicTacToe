#ifndef WINNINGSTATES_H
#define WINNINGSTATES_H

#include <functional>

#include "board.h"
#include "player.h"

class WinningStates
{
    using Moves = std::array<std::function<bool(const Board&, const Player&)>, 4>;

    static const Moves _allStates;

    static bool CheckMainDiagonal(const Board& board, const Player& player) noexcept;
    static bool CheckAntiDiagonal(const Board& board, const Player& player) noexcept;
    static bool CheckAllRows(const Board& board, const Player& player) noexcept;
    static bool CheckAllColumns(const Board& board, const Player& player) noexcept;
    static bool CheckColumn(const Board& board, const Player& player, const std::size_t column) noexcept;
    static bool CheckRow(const Board& board, const Player& player, const std::size_t row) noexcept;
public:
    static bool AnyWinner(const Board& board, const Player& player) noexcept;
};


#endif // WINNINGSTATES_H
