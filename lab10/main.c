#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"

void firstTask() {
    int num = getValidatedIntInput("Insert any integer: ");
    if (num & 1) {
        printf("The number is odd\n");
    }
    else {
        printf("The number is even\n");
    }
}

void getStringInput(char* str, int size) {
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
    if (strlen(str) == size - 1) {
        char ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
    }
}

enum BookFieldsOps {
    BOOK_NAME = 0,
    AUTHOR_NAME,
    COUNT_OF_PAGES,
    COUNT_OF_VOLUMES
};


char* bookFields[4] = { "Book name", "Author name", "Count of pages", "Count of volumes" };
short bookFieldsCount = 4;

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

void freeBook(Book* book) {
    free(book->name);
    free(book->info.authorName);
    free(book);
}

void freeBooks(Books* books) {
    for (int i = 0; i < books->len; i++) {
        free(books->books[i].name);
        free(books->books[i].info.authorName);
    }
    free(books->books);
    free(books);
}

Books* newBooks(int cap) {
    Books* books = malloc(sizeof(Books));

    books->cap = cap;
    books->len = 0;
    books->books = malloc(sizeof(Book) * cap);
    return books;
}

void printBook(Book* book) {
    printf("Book: %s\n", book->name);
    printf("\tCount of pages: %d\n", book->pagesCount);
    printf("\tAuthor name: %s\n", book->info.authorName);
    printf("\tCount of volumes: %d\n", book->info.volumeCount);
}

void printBooks(Books* books) {
    // printf("Some debug info:\n");
    // printf("Books len: %d\n", books->len);
    // printf("Books cap: %d\n", books->cap);
    for (int i = 0; i < books->len; i++) {
        printBook(&(books->books[i]));
    }
}

void copyBook(Book* dst, Book* src) {
    dst->name = _strdup(src->name);
    dst->pagesCount = src->pagesCount;
    dst->info.authorName = _strdup(src->info.authorName);
    dst->info.volumeCount = src->info.volumeCount;
}

Books* evacuateBooks(Books* oldBooks) {
    Books* evacuatedBooks = newBooks((oldBooks->cap) * 2);
    evacuatedBooks->len = oldBooks->len;
    for (int i = 0; i < oldBooks->len; i++) {
        copyBook(&(evacuatedBooks->books[i]), &(oldBooks->books[i]));
    }
    freeBooks(oldBooks);
    return evacuatedBooks;
}

Book* getBookFromUser() {
    Book* newBook = malloc(sizeof(Book));
    for (enum BookFieldsOps bookField = 0; bookField < bookFieldsCount; bookField++) {
        printf("Insert %s: ", bookFields[bookField]);
        char* str = malloc(sizeof(char) * 256);
        getStringInput(str, 256);
        switch (bookField)
        {
        case AUTHOR_NAME:
            newBook->info.authorName = str;
            break;
        case BOOK_NAME:
            newBook->name = str;
            break;
        case COUNT_OF_PAGES:
            newBook->pagesCount = atoi(str);
            break;
        case COUNT_OF_VOLUMES:
            newBook->info.volumeCount = atoi(str);
            break;
        default:
            break;
        }
    }
    return newBook;
}


Books* addBook(Books* books, Book* newBook) {
    if (books->len == books->cap) {
        Books* newBooks = evacuateBooks(books);
        copyBook(&(newBooks->books[newBooks->len++]), newBook);
        return newBooks;
    }
    copyBook(&(books->books[books->len++]), newBook);
    return books;
}

Book* findBookByName(Books* books, char* name) {
    for (int i = 0; i < books->len; i++) {
        if (strcmp(books->books[i].name, name) == 0) {
            return &(books->books[i]);
        }
    }
    return NULL;
}

Books* findBooksByPagesCount(Books* books, int pagesCount) {
    Books* foundBooks = newBooks(5);
    for (int i = 0; i < books->len; i++) {
        if (books->books[i].pagesCount == pagesCount) {
            foundBooks = addBook(foundBooks, &(books->books[i]));
        }
    }
    return foundBooks;
}

Books* deleteBooks(Books* books, Books* booksToDel) {
    Books* stayedBooks = newBooks(5);
    for (int i = 0; i < books->len; i++) {
        int isFound = 0;
        for (int j = 0; j < booksToDel->len; j++) {
            if (strcmp(books->books[i].name, booksToDel->books[j].name) == 0) {
                isFound = 1;
                break;
            }
        }
        if (!isFound) {
            stayedBooks = addBook(stayedBooks, &(books->books[i]));
        }
    }
    freeBooks(books);
    freeBooks(booksToDel);
    return stayedBooks;
}

void secondTask() {
    Books* books = newBooks(1);
    int choice;

    do {
        printf("\nMenu\n");
        printf("1. Add a book\n");
        printf("2. Delete books by page count\n");
        printf("3. Show all books\n");
        printf("4. Find books by name\n");
        printf("5. Exit\n");
        choice = getValidatedIntInput("Select option: ");

        switch (choice) {
        case 1: {
            Book* newBook = getBookFromUser();
            books = addBook(books, newBook);
            freeBook(newBook);
            break;
        }
        case 2: {
            int pages = getValidatedIntInput("Enter page count to delete: ");
            Books* toDelete = findBooksByPagesCount(books, pages);
            books = deleteBooks(books, toDelete);
            printf("%d books deleted\n", toDelete->len);
            break;
        }
        case 3: {
            printf("\nAll books:\n");
            printBooks(books);
            break;
        }
        case 4: {
            char name[256];
            printf("Enter book name to search: ");
            getStringInput(name, sizeof(name));
            printf("\nResult:\n");
            for (int i = 0; i < books->len; i++) {
                if (strcmp(books->books[i].name, name) == 0) {
                    printBook(&books->books[i]);
                }
            }
            break;
        }
        case 5: {
            printf("eixted\n");
            break;
        }
        default: {
            printf("Invalid choice\n");
        }
        }
    } while (choice != 5);

    freeBooks(books);
}


int main() {
    char validChars[2] = { '1', '2' };
    char choice = getValidatedCharInput("Choose the task: 1-first taks, 2 - second task: ", validChars, 2);
    if (choice == '1') firstTask();
    else secondTask();
}