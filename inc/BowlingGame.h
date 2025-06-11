#pragma once
#include "Player.h"
#include <vector>
#include <string>

class BowlingGame {
public:
    void addPlayer(const std::string& name);
    void roll(const std::string& name, int pins);
    int getScore(const std::string& name) const;

private:
    std::vector<Player> players;
};
