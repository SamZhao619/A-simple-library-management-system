#ifndef BOOK_MANAGEMENT_H_INCLUDED
#define BOOK_MANAGEMENT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct usr
{
    char name[100];//user's name
    int id;
    char pwd[100];//password
    int borrowbook[100];//the list of borrow books lists
    int booknums;//the number of borrowed books
}usr[1000], usr1[1000];
int id2index[10000];
int nums_usr = 0;
struct book
{
    char bookname[100];
    char author[100];
    int years;
    int bookid;
}book[1000], book1[1000];
int nums_book = 0;
void findbook()
{
    int x, i, j;
    printf("Please enter by which format to search for books:1.Title 2.Author 3.Year of publication\n");
    scanf("%d", &x);
    if (x == 1)
    {
        char s[100];
        printf("Please enter the title of book: ");
        scanf("%s", s);
        for (i = 0; i < nums_book; i++)
        {
            for (j = 0; j < strlen(book[i].bookname); j++)
            {
                if (book[i].bookname[j] != s[j])
                    break;
            }
            if (j == strlen(book[i].bookname))
                printf("Title: %s, Author: %s, Year of publication: %d\n", book[i].bookname, book[i].author, book[i].years);
        }
    }
    else if (x == 2)
    {
        char s[100];
        printf("Please enter the Author's name: ");
        scanf("%s", s);
        for (i = 0; i < nums_book; i++)
        {
            for (j = 0; j < strlen(book[i].author); j++)
            {
                if (book[i].author[j] != s[j])
                    break;
            }
            if (j == strlen(book[i].author))
                printf("Title:%s Author:%s Year of publication: %d\n", book[i].bookname, book[i].author, book[i].years);
        }
    }
    else if (x == 3)
    {
        int s;
        printf("Please enter the year of publication: ");
        scanf("%d", &s);
        for (i = 0; i < nums_book; i++)
        {
            if (s == book[i].years)
                printf("Title:%s Author:%s Year of publication:%d\n", book[i].bookname, book[i].author, book[i].years);
        }
    }
}
int id2index2[100][1000];
void rendbook()
{
    int id, id1;
    printf("Please enter a user name:");
    scanf("%d", &id1);
    int i;
    int f = 0;
    for (i = 0; i < nums_usr; i++)
        if (usr[i].id == id1)
        {
            f = 1;
            break;
        }
    if (f == 0)
    {
        printf("You are not registered, please register first!\n");
        return;
    }
    int ind = id2index[id1];
    printf("Please enter the number of the book you want to borrow:");
    scanf("%d", &id);
    f = 0;
    for (i = 0; i < nums_book; i++)
        if (book[i].bookid == id)
        {
            f = 1;
            break;
        }
    if (f == 0)
    {
        printf("Library does not have this book, failed to borrow book!\n");
        return;
    }
    usr[ind].borrowbook[usr[ind].booknums] = id;
    usr[ind].booknums++;
    printf("Books borrowed successfully!\n");
    return;
}
void takebook()
{
    int id, id1;
    printf("Please enter a user name:");
    scanf("%d", &id);
    int f = 0;
    int i, j;
    for (i = 0; i < nums_usr; i++)
        if (usr[i].id == id)
        {
            f = 1;
            break;
        }
    if (f == 0)
    {
        printf("You are not registered, please register first!\n");
        return;
    }
    int ind = id2index[id];
    printf("Please enter the number of the book you want to return:");
    scanf("%d", &id1);
    f = 0;
    for (i = 0; i < nums_book; i++)
        if (book[i].bookid == id1)
        {
            f = 1;
            break;
        }
    if (f == 0)
    {
        printf("Library does not have this book, failed to return book:\n");
        return;
    }
    i = 0;
    for (i = 0; i < usr[ind].booknums; i++)
    {
        if (usr[ind].borrowbook[i] == id1)
            break;
    }
    j = 0;
    for (j = i; j < usr[ind].booknums - 1; i++)
    {
        usr[ind].borrowbook[j] = usr[ind].borrowbook[j + 1];
    }
    usr[ind].booknums--;
    printf("Return the book successfully!\n");
    return;
}
#endif // BOOK_MANAGEMENT_H_INCLUDED
