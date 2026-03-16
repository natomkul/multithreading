#include <cstdlib>
#include <thread>
#include <mutex>
#include <chrono>
#include <atomic>
#include "writer.h"
#include "wrapper.h"

Writer::Writer(Wrapper *bw)
{
    wr = std::thread(&Writer::run, this, bw);
}

Writer::~Writer()
{
    if (wr.joinable())
    {
        wr.join();
    }
}

void Writer::run(Wrapper *bw)
{
    while(true)
    {
        if (!bw->write())
            return;

    }
}
