#pragma once
void bookStorage();

enum BookFieldsOps {
    BOOK_NAME = 0,
    AUTHOR_NAME,
    COUNT_OF_PAGES,
    COUNT_OF_VOLUMES
};

typedef struct {
    char* authorName;
    int volumeCount;
} MetaInfo;

typedef struct {
    int pagesCount;
    char* name;
    MetaInfo info;
} Book;

typedef struct {
    int len;
    int cap;
    Book* books;
} Books;