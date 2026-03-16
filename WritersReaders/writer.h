#include <iostream>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <chrono>
#include <atomic>
#include "wrapper.h"

class Writer
{
 private:
    std::thread wr;

    void run(Wrapper *bw);
 public:
    Writer(Wrapper *bw);
    ~Writer();
};
