#include "counter.h"

Counter::Counter(const int start, const int n) : start(start), n(n) 
{
    th = std::thread(&Counter::count, this);
}

Counter::~Counter()
{
    th.join();
}

void Counter::count()
{

    for (int i = start; i <= n; i++)
    {
        sum += 1.0 / i;
    }

    ready = true;

    return;
}

double Counter::result()
{
    while (true)
    {
        if (ready)
        {
            return sum;
        }
    }
}
