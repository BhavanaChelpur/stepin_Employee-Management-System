#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include <windows.h>
#include"Myheader.h"

#define Student struct Stud

void add(FILE * fp);
void modify(FILE * fp);
void display(FILE * fp);
void Indivisual(FILE *fp);
void password();
FILE * del(FILE * fp);
void printChar(char ch,int n);
void title();
FILE *tp;

void gotoxy(int x,int y)
{
	COORD CRD;
    CRD.X = x;
    CRD.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);
}

struct pass
{
	char pass[25];
}pa;

struct Stud
{
    char name[100];
    char dept[50];
    int employee_Id;
    
};


int main()
{
    int ch,id,k,i;
    char c,pas[50];
    SetConsoleTitle("Employee Management System | DIU");
    FILE * fp;
    Student s;
    int option;
    char another;

    if((fp=fopen("db.txt","rb+"))==NULL)
    {
        if((fp=fopen("db.txt","wb+"))==NULL)
        {
            printf("Can't create or open Database.");
            return 0;
        }
    }
    system("color 9f");
	gotoxy(42,8);
	printf("LOGIN(If 1st login press ENTER)");
	gotoxy(42,10);
	printf("____________________________________");
	gotoxy(42,11);
	printf("|\tEnter password :             |");
	gotoxy(42,12);
	printf("|__________________________________|");
	//printf("\n\t\t\t\t\t");
	gotoxy(65,11);
	while( k<10)
	{
	    pas[k]=getch();
	    char s=pas[k];
	    if(s==13)
		 break;
	    else printf("*");
	    k++;
	}
	pas[k]='\0';
	tp=fopen("F:/Password.txt","r+");
    fgets(pa.pass,25,tp);
    if(strcmp(pas,pa.pass)==0)
	{
		system("cls");
		gotoxy(10,3);
		printf("<<<< Loading Please Wait >>>>");
		for(i=0; i<5; i++)
        {
            printf("\t*");
            Sleep(500);
        }
        
    printChar('=',38);
    printf("\n\n\n\t\t\t       press any key to Enter");
    getch();

    while(1)
    {
        title();
        printf("\n\t");
        printChar('*',64);

        printf("\n\n\t\t\t\t1. Add");
        printf("\n\n\t\t\t\t2. Modify");
        printf("\n\n\t\t\t\t3. Show All Records");
        printf("\n\n\t\t\t\t4. Individual View");
        printf("\n\n\t\t\t\t5. Remove");
        printf("\n\n\t\t\t\t6. Change Password");
        printf("\n\n\t\t\t\t7. Logout\n\t");
        printChar('*',64);
        printf("\n\n\t\t\t\tEnter Your Option :--> ");
        scanf("%d",&option);

        switch(option)
        {
            case 1:
                add(fp);
                break;
            case 2:
                modify(fp);
                break;
            case 3:
                display(fp);
                break;
            case 4:
                Indivisual(fp);
                break;
            case 5:
                fp=del(fp);
                break;
            case 6:
                    system("cls");
				    system("color 5f");
			        password();
                break;
            case 7:
                return 1;
                break;
            default:
                printf("\n\t\tNo Action Detected");
                printf("\n\t\tPress Any Key\n\n\n");
                getch();
                system("pause");
        }
    }
    }
    else
    {
        printf("Wrong Password . Get Out");
        getch();
    }
    return 1;

}


void printChar(char ch,int n)
{
    while(n--)
    {
        putchar(ch);
    }
}

void title()
{
    system("cls");
    system("COLOR 03");
    printf("\n\n\t");
    printChar('=',19);
    printf(" Employee Management System ");
    printChar('=',19);
    printf("\n");
}


