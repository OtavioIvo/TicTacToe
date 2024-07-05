#include <memory>

#include "player.h"
#include "playermark.h"
#include "playermachine.h"
#include "playeruser.h"

Player::Player(std::shared_ptr<Mark> mark) : _marker(mark->MakeMark())
{}

const std::shared_ptr<Mark>& Player::GetMarker() const
{
    return _marker;
}




PlayerManager::PlayerManager()
    : _players(
        {
            std::make_unique<PlayerMachine>(),
            std::make_unique<PlayerUser>()
        })
{

}

const std::unique_ptr<Player>& PlayerManager::PickNextPlayer() noexcept
{
    std::swap(_players.front(), _players.back());
    return _players.front();
}

const Player& PlayerManager::GetCurrentPlayer() const noexcept
{
    return *_players.front();
}
