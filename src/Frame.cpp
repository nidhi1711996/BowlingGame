#include "Frame.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Frame::Frame(int index) : frameIndex(index) { cout << "frame index: " << index << endl;}

void Frame::addRoll(int pins) {
    if (isComplete())
        throw std::runtime_error("Cannot add more rolls to this frame.");
    rolls.push_back(pins);
}

int Frame::score(const std::vector<Frame>& allFrames) const {
    if (frameIndex >= 10) return getTotalPins();

    if (isStrike()) {
        return 10 + getNextTwoRolls(allFrames);
    } else if (isSpare()) {
        return 10 + getNextRoll(allFrames);
    } else {
        return getTotalPins();
    }
}

bool Frame::isStrike() const {
    return !rolls.empty() && rolls[0] == 10;
}

bool Frame::isSpare() const {
    return rolls.size() >= 2 && rolls[0] + rolls[1] == 10 && rolls[0] != 10;
}

bool Frame::isComplete() const {
    if (frameIndex < 9) {
        return rolls.size() == 2 || isStrike();
    }
    if (rolls.size() == 3 || (rolls.size() == 2 && getTotalPins() < 10))
        return true;
    return false;
}

int Frame::getTotalPins() const {
    int sum = 0;
    for (int pins : rolls) sum += pins;
    return sum;
}

const std::vector<int>& Frame::getRolls() const {
    return rolls;
}

int Frame::getNextRoll(const std::vector<Frame>& frames) const {
    if (frameIndex + 1 < frames.size()) {
        auto next = frames[frameIndex + 1].getRolls();
        if (!next.empty()) return next[0];
    }
    return 0;
}

int Frame::getNextTwoRolls(const std::vector<Frame>& frames) const {
    int count = 0, sum = 0;
    for (size_t i = frameIndex + 1; i < frames.size() && count < 2; ++i) {
        for (int pins : frames[i].getRolls()) {
            sum += pins;
            if (++count == 2) break;
        }
    }
    return sum;
}
