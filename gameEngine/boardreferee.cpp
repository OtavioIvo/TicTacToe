#include "boardreferee.h"
#include "board.h"
#include "winningstates.h"


BoardReferee::BoardReferee() {}

bool BoardReferee::CheckIfPlayerWins(const Board& board, const Player& player) noexcept
{
    return WinningStates::AnyWinner(board, player);
}

