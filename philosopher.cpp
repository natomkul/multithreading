#include "chopstick.h"
#include "philosopher.h"
#include <iostream>                                                     
#include <thread>
#include <mutex>
#include <chrono>

philosopher::philosopher(int id, chopstick* l, chopstick* r) 
    : id_p(id), left(l), right(r) {phi = std::thread(&philosopher::proc, this);}

philosopher::~philosopher() 
{
    if (phi.joinable()) 
    {
        phi.join();
    }
}

void philosopher::hungry()
{
    printf("%d: Philosopher is HUNGRY\n", get_id());

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

        if ((get_id() % 2) == 0)
        {
            if (left->try_get())
            {
                if (right->try_get())
                {
                    return;
                } else
                {
                    left->relase();
                    hungry();
                }
        
            } else
            {
                hungry();
            }
        }

        if ((get_id() % 2) == 1)
        {
            if (right->try_get())
            {
                if (left->try_get())
                {
                    return;
                } else
                {
                    right->relase();
                    hungry();
                }
        
            } else
            {
                hungry();
            }
        }


}

void philosopher::eating()
{
    printf("%d: Philosopher is EATING\n", get_id());

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void philosopher::thinks()
{
    printf("%d: Philosopher is THINKING\n", get_id());

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void philosopher::proc()
{
    while (true)
    {
        thinks();
        hungry();
        eating();
        left->relase();
        right->relase();
    }
}

int philosopher::get_id() { return id_p; }

