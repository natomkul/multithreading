#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include "chopstick.h"

#pragma once

class philosopher
{
private:
     int id_p;
     chopstick* left;
     chopstick* right;

     std::thread phi;

public:
     philosopher(int id_p, chopstick* left, chopstick* right);
     void hungry();
     void eating();
     void thinks();
     void proc();
     int get_id();
};
