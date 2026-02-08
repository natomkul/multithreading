#include "chopstick.h"
#include <iostream>                                                     
#include <thread>
#include <mutex>
#include <chrono>

chopstick::chopstick(int id) : id_c(id) {}

bool chopstick::try_get()
{
    if (chop.try_lock()) {return true;}

    return false;
}

void chopstick::relase()
{
    chop.unlock();
}
