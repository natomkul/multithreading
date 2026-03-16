#pragma once

#include <iostream>
#include <vector>
#include <thread>
#include <cstdlib>
#include "wrapper.h"

class Reader
{
 private:
    std::thread rd;

    void run(Wrapper *bw);
 public:
    Reader(Wrapper *bw);
    ~Reader();
};
