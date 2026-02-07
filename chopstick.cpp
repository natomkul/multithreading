#include "chopstick.h"
#include <iostream>                                                     
#include <thread>
#include <mutex>
#include <chrono>

chopstick::chopstick(int id_c) {}

bool chopstick::try_get()
{
    if (chop.try_lock()) {return true;}

    return false;
}

void chopstick::relase()
{
    chop.unlock();
}
