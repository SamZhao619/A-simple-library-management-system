#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "../include/book_management.h"
#include "book.c"
void Register()//Registration system
{
    char name[100];
    printf("Please enter name:");
    scanf("%s",name);
    int fl=0;
    int i,j;
    for(i=0;i<nums_usr;i++)
    {
        for(j=0;j<strlen(name)&&strlen(usr[i].name);j++)
        {
            if(usr[i].name[j]!=name[j])
            {
                fl=1;
                break;
            }
        }
        if(fl==0)
        {
            printf("This user has been registered, registration failed!\n");
            return;
        }
    }
    strcpy(usr[nums_usr].name,name);
    printf("Please enter a numeric user name:");
    scanf("%d",&usr[nums_usr].id);
    printf("Please enter your password:");
    scanf("%s",usr[nums_usr].pwd);
    id2index[usr[nums_usr].id]=nums_usr;
    nums_usr++;
}
int  check(int id,char pwd[100])//Verify whether the user exists; 1 exists 0; does not exist
{
    int i=0,j;
    for(i=0;i<nums_usr;i++)
    {
        for(j=0;j<strlen(pwd);j++)
        {
            if(usr[i].pwd[j]!=pwd[j])
                break;
        }
        if(usr[i].id==id&&j==strlen(pwd))
        {
            return 1;
        }
    }
    return 0;
}
void login()//Login system
{
    char pwd[100];
    int id;
    printf("Please enter a numeric user name:");
    scanf("%d",&id);
    printf("Please enter your password:");
    scanf("%s",pwd);
    int fl=check(id,pwd);
    if(fl==1)
    {
        printf("Login system successful!\n");
        return;
    }
    else
    {
        printf("Failed to enter your account or password. Please re-enter it!");
        login();
    }
    return;
}
void admin_login()//Administrator login system
{
    int admin,pwd;
    printf("Please enter your administration account number:");
    scanf("%d",&admin);
    printf("Please enter your password:");
    scanf("%d",&pwd);
    if(admin==12345&&pwd==12345)
    {
        book_manage();
    }
    return;
}
int main()
{
    while(1)
    {
        printf("1. User registration\n");
        printf("2. Login system\n");
        printf("3. Search for books\n");
        printf("4. Borrow the books\n");
        printf("5. Return the books\n");
        printf("6. Administrator login\n");
        printf("7. Display all the books\n");
        int x;
        scanf("%d",&x);
        if(x==1)
            Register();
        else if(x==2)
        {
            login();
        }
        else if(x==3)
        {
            findbook();
        }
        else if(x==4)
        {
            rendbook();
        }
        else if(x==5)
        {
            takebook();
        }
        else if(x==6)
        {
            admin_login();
        }
        else if(x==7)
        {
            fileres();
            showfiles();
        }
        else
        {
            break;
        }
    }
    return 0;
}