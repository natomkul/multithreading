#include "wrapper.h"

Wrapper::Wrapper(Book *bn) : bn(bn) {}

void Wrapper::counter()                                
{
    count++;

    if (count == 4)
    {
        count = 0;
    }
}


bool Wrapper::read()
{
    std::unique_lock<std::mutex> lck(mtx);
    cv.wait(lck, [&] { return count != 0; });

    FILE *f = fopen(bn->get_title(), "r");

    if (!f)
    {
        perror("Couldnt open file");
        return false;
    }

    char buff[10];

    while (fgets(buff, sizeof(buff), f) != NULL) {
        printf("%s", buff);
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    fclose(f);
    counter();
    cv.notify_all();

    return true;
}

bool Wrapper::write()
{
    std::unique_lock<std::mutex> lck(mtx);
    cv.wait(lck, [&] { return count == 0; });

    FILE *f = fopen(bn->get_title(), "w");

    if (!f)
    {
        perror("Couldnt open file");
        return false;
    }

    int buff = rand() % 1000;

    fprintf(f, "%d \n", buff);

    printf("Writer: %d \n", buff);

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    fclose(f);
    counter();
    cv.notify_all();

    return true;
}

