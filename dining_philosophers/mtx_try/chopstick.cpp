#include "chopstick.h"
#include <iostream>                                                     
#include <thread>
#include <mutex>
#include <chrono>

chopstick::chopstick(int id) : id_c(id) {}

bool chopstick::try_get()
{
    return chop.try_lock();
}

void chopstick::relase()
{
    chop.unlock();
}
