#include "atomic_chop.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

void atomic_chopstick::block()
{
    while (!chop.load()) {}
    
    chop.store(false);
}

void atomic_chopstick::relase()
{
    chop.store(true);
}
