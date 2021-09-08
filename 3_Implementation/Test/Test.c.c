#include <stdio.h>
int main()
{
    FILE *fp, *ft; /// file pointers
    
    fp = fopen("Bhavana/emp.txt","rb+");
    if(fp == NULL)
    {
        fp = fopen("Bhavana/emp.txt","wb+");
        if(fp == NULL)
        {
            printf("Connot Open File");
            exit(1);
        }
    }
}