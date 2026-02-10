#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "object.h"

#pragma once

class Alarm : public Object
{
private:
    std::mutex mtx;
    std::condition_variable cv;
    bool ready = false;
    bool processed = false;
public:
    using Object::Object;
    void operation(int data) override; 
};
