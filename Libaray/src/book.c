#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "../include/book_management.h"
void fileres()
{
    FILE* fp=fopen("1.txt","w");
    int i,j;
    for(i=0;i<nums_usr;i++)
    {
        fprintf(fp," %d",usr[i].id);
        fprintf(fp," %d",usr[i].booknums);
        for(j=0;j<usr1[i].booknums;j++)
        {
            fprintf(fp," %d",usr[i].borrowbook[j]);
        }
      fprintf(fp," %s",usr[i].name);
      fprintf(fp," %s\n",usr[i].pwd);
    }
    for(i=0;i<nums_book;i++)
    {
        fprintf(fp," %d",book[i].bookid);
        fprintf(fp," %d",book[i].years);
        fprintf(fp," %s",book[i].bookname);
        fprintf(fp," %s\n",book[i].author);
    }
    fclose(fp);
    return;
}
void book_manage()
{
    int x;
    int nums_book;
    while(1)
    {
        printf("Please enter your actions: 1.Add Book 2.Delete Book 3.Log out\n");
        scanf("%d",&x);
        if(x==1)
        {
            printf("Please enter the title:");
            scanf("%s",book[nums_book].bookname);
            printf("Please enter author:");
            scanf("%s",book[nums_book].author);
            printf("Please enter the year of publication:");
            scanf("%d",&book[nums_book].years);
            nums_book++;
        }
        else if(x==2)
        {
            int indddd,j;
            printf("Please enter the deletion book number:");
            scanf("%d",&indddd);
            for(j=0;j<nums_book;j++)
            {
                if(book[j].bookid==indddd)
                {
                    break;
                }
            }
            int i;
            for(i=j;i<nums_book-1;i++)
            {
                book[i]=book[i+1];
            }
            nums_book--;
        }
        else if(x==3)
            break;
    }
    return;

}
void showfiles()
{
    int nums_usr;
    FILE* fp=fopen("1.txt","r");
    int i,j;
    for(i=0;i<nums_usr;i++)
    {
        fscanf(fp," %d",&usr1[i].id);
        fscanf(fp," %d",&usr1[i].booknums);
        for(j=0;j<usr1[i].booknums;j++)
        {
            fscanf(fp," %d",&usr1[i].borrowbook[j]);
        }
      fscanf(fp," %s",usr1[i].name);
      fscanf(fp," %s",usr1[i].pwd);

    }
    for(i=0;i<nums_book;i++)
    {
        fscanf(fp," %d",&book1[i].bookid);
        fscanf(fp," %d",&book1[i].years);
        fscanf(fp," %s",book1[i].bookname);
        fscanf(fp," %s",book1[i].author);

    }
    fclose(fp);
    for(i=0;i<nums_usr;i++)
    {
        printf("%d %d ",usr1[i].id,usr1[i].booknums);
        for(j=0;j<usr1[i].booknums;j++)
        {
            printf(" %d ",usr1[i].borrowbook[j]);
        }
        printf("%s %s\n",usr1[i].name,usr1[i].pwd);
    }
    for(i=0;i<nums_book;i++)
    {
        printf("%d %d ",book1[i].bookid,book1[i].years);

        printf("%s %s\n",book1[i].bookname,book1[i].author);
    }
    return;
}