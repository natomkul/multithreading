#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

#pragma once

class chopstick
{
private:
     std::mutex chop;
     int id_c;

public:
     chopstick(int id_c);
     bool try_get();
     void relase();
};

