#include "BowlingGame.h"
#include <stdexcept>

void BowlingGame::addPlayer(const std::string& name) {
    players.emplace_back(name);
}

void BowlingGame::roll(const std::string& name, int pins) {
    for (auto& player : players) {
        if (player.getName() == name) {
            try
            {
                player.roll(pins);
            }
            catch(const std::exception& e)
            {
                throw std::runtime_error("Cannot roll more than 10 frames.");
            }
            return;
        }
    }
    throw std::runtime_error("Player not found.");
}

int BowlingGame::getScore(const std::string& name) const {
    for (const auto& player : players) {
        if (player.getName() == name) {
            return player.getScore();
        }
    }
    throw std::runtime_error("Player not found.");
}
