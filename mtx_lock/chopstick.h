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
     chopstick(int id);
     void block();
     void relase();
     int get_id();
};

