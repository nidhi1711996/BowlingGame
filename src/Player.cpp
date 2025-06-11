#include <iostream>
#include "Player.h"
#include <stdexcept>

using namespace std;

Player::Player(const std::string& name) : name(name) {}

void Player::roll(int pins) {
    if (frames.empty() || frames.back().isComplete()) {
        cout << "Frames size: " << frames.size() << endl;
        if (frames.size() >= 10)
            throw std::runtime_error("Cannot roll more than 10 frames.");
        frames.emplace_back(frames.size());
    }
    frames.back().addRoll(pins);
}

int Player::getScore() const {
    int total = 0;
    for (size_t i = 0; i < frames.size(); ++i) {
        total += frames[i].score(frames);
    }
    return total;
}

const std::string& Player::getName() const {
    return name;
}

const std::vector<Frame>& Player::getFrames() const {
    return frames;
}
