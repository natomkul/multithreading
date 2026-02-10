#include "object.h"
#include "alarm.h"

void Alarm::operation(int data)
{
    while (true)
    {
        std::unique_lock lk(mtx);
        cv.wait(lk, [this]{ return ready; });

        if (data > 100)
        {
            printf("CRITICAL STATE temperature: %d", data);
        } 
        else if (data > 85) 
        {
            printf("TOO HOT temperature: %d", data);
        } 
        else if (data > 50) 
        {
            printf("little warm but normal: %d", data);
        } 
        else 
        {
            printf("normal: %d", data);
        }

        data = 0;
        processed = true;
        cv.notify_one();
    }
}
