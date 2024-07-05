#include "playermachine.h"

PlayerMachine::PlayerMachine() : Player(MarkMachine::Create())
{}


bool PlayerMachine::MakeAPlay(Board& board)
{

    //FindWinnablePlay
    //if WinnablePlayeFound
    //Do the WinnablePlay
    //if not, decrease player possibility of winning
}

PlayerMachine::Win PlayerMachine::FindWinnablePlay(const Board& board)
{
    GetMarker();
}
