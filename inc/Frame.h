#pragma once
#include <vector>

class Frame {
public:
    Frame(int index = 0);

    void addRoll(int pins);
    int score(const std::vector<Frame>& allFrames) const;
    bool isStrike() const;
    bool isSpare() const;
    bool isComplete() const;
    int getTotalPins() const;
    const std::vector<int>& getRolls() const;

private:
    std::vector<int> rolls;
    int frameIndex;

    int getNextRoll(const std::vector<Frame>& frames) const;
    int getNextTwoRolls(const std::vector<Frame>& frames) const;
};
