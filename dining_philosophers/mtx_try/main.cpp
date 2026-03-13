#include "chopstick.h"
#include "philosopher.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <deque>
#include <memory>

void feast(int n)
{
    std::deque<chopstick> chopsticks;
    
    for (int i = 0; i < n; i++)
    {
        chopsticks.emplace_back(i);
    }

    std::deque<philosopher> philosophers;

    for (int i = 0; i < n; i++)
    {
        chopstick* left = &chopsticks[i];
        chopstick* right = &chopsticks[(i + 1) %n];
        philosophers.emplace_back(i, left, right);
    }
}

int main() 
{
    feast(5);
    return 0;
}
