#include "chopstick.h"
#include "philosopher.h"
#include <iostream>                                                     
#include <thread>
#include <mutex>
#include <chrono>

philosopher::philosopher(int id, chopstick* l, chopstick* r) 
    : id_p(id), left(l), right(r) {}

void philosopher::hungry()
{
 std::cout << "glodnyy\n"; 
}

void philosopher::eating()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void philosopher::thinks()
{
    left->relase();
    right->relase();

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void philosopher::proc()
{
    if (left->try_get())
    {
        if (right->try_get())
        {
            eating();
        } else
        {
            hungry();
        }
        
    }
}

int philosopher::get_id() { return id_p; }

