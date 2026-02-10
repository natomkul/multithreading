#include "object.h"

Object::Object(int data) : data(data) 
{ 
    th = std::thread(&Object::operation, this, data);
}

Object::~Object()
{
    if (th.joinable())
    {
        th.join();
    }
}

void Object::operation(int data)
{
    printf("thread running\n");
}
