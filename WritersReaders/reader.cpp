#include "reader.h"
#include <iostream>
#include <vector>
#include <thread>
#include <cstdlib>
#include "wrapper.h"

Reader::Reader(Wrapper *bw)
{
    rd = std::thread(&Reader::run, this, bw);
}

Reader::~Reader()
{
    if (rd.joinable())
    {
        rd.join();
    }
}

void Reader::run(Wrapper *bw)
{
    while(true)
    {
        if (!bw->read())
            return;
    }
}
