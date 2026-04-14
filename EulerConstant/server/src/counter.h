#pragma once

#include <iostream>
#include <cmath>
#include <thread>

class Counter
{
 private:
    const int n;
    const int start;

    bool ready = false;
    double sum = 0;

    std::thread th;
 public:
    Counter(const int start, const int n);
    ~Counter();
    void count();
    double result();
};
