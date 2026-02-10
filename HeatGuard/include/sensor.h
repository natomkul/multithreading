#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "object.h"

#pragma once

class Sensor : public Object
{
private:
    std::mutex mtx; 
    std::condition_variable cv;
    int temp_sim;
    bool ready = false;
    bool processed = false;

public:
    using Object::Object;
    void operation(int data) override; 
};
