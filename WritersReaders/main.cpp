#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <cstdlib>
#include "book.h"
#include "wrapper.h"
#include "reader.h"
#include "writer.h"

int main()
{
    srand(time(NULL));
    Book *bn = new Book("test.txt");
    Wrapper *wp = new Wrapper(bn);
    Reader r(wp);
    Writer w(wp);
}
