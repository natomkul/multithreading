#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include "chopstick.h"

#pragma once

class atomic_chopstick : public chopstick
{
private:
    std::atomic<bool> chop{true};

public:
    using chopstick::chopstick;
    void block() override;
    void relase() override;
};
