#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "object.h"
#include "sensor.h"

void Sensor::operation(int data)
{
    while (true)
    {
        temp_sim = rand() % 110;
        std::unique_lock lk(mtx);
        cv.wait(lk, [this]{ return ready; });
    
        data = temp_sim;
        printf("temperature sensor: %d", data);

        processed = true;
        cv.notify_one();
    }
}

