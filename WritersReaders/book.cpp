#include "book.h"

Book::Book(const char *bookName) : bName(bookName) {}

const char* Book::get_title()
{
    return bName;
}
