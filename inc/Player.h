#pragma once
#include "Frame.h"
#include <string>
#include <vector>

class Player {
public:
    Player(const std::string& name);
    void roll(int pins);
    int getScore() const;
    const std::string& getName() const;
    const std::vector<Frame>& getFrames() const;

private:
    std::string name;
    std::vector<Frame> frames;
};
