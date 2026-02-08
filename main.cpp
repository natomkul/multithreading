#include <iostream>
#include "chopstick.h"
#include "philosopher.h"
#include <iostream>
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <memory>

void feast(int n)
{
     std::vector<std::unique_ptr<chopstick>> chopsticks;
    
    for (int i = 0; i < n; i++)
    {
        chopsticks.push_back(std::make_unique<chopstick>(i));
    }

     std::vector<std::unique_ptr<philosopher>> philosophers;

    for (int i = 0; i < n; i++)
    {
        chopstick* left = chopsticks[i].get();
        chopstick* right = chopsticks[(i + 1) %n].get();
        philosophers.push_back(std::make_unique<philosopher>(i, left, right));
    }
}

int main() 
{
    feast(5);
    return 0;
}
