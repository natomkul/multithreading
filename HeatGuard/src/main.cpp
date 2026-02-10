#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "object.h"
#include "alarm.h"
#include "sensor.h"

void proc(){
    int data;

    Sensor* sensor = new Sensor(data);
    Alarm* alarm = new Alarm(data);
    
    sensor->~Sensor();
    alarm->~Alarm();
}

int main()
{
    proc();
    return 0;
}
