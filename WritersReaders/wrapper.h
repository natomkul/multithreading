#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <cstdlib>

#include "book.h"

class Wrapper
{
 private:
    Book *bn;
    std::mutex mtx;
    int count = 0;
    std::condition_variable cv;
 public:
    Wrapper(Book *bn);
    void counter();

    bool read();
    bool write();
};
