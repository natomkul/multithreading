#include <iostream>
#include <thread>

#pragma once

class Object
{
private:
    std::thread th;
    int data;

public:
    Object(int data);
    ~Object();
    virtual void operation(int data);
};
