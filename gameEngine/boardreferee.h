#ifndef BOARDREFEREE_H
#define BOARDREFEREE_H

#include "board.h"
#include "player.h"

class BoardReferee
{
public:
    BoardReferee();

    bool CheckIfPlayerWins(const Board& board, const Player& player) noexcept;

};


#endif // BOARDREFEREE_H
