#include<string.h>
#include<stdlib.h>
#include<math.h>
#include <windows.h>

#define Employee struct emp

void add(FILE * fp);

struct pass
{
	char pass[25];
}pa;

struct emp
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
    Employee s;
    int option;
    char another;

    if((fp=fopen("db.txt","rb+"))==NULL)
    {
        if((fp=fopen("db.txt","wb+"))==NULL)
        {
            printf("Can't create or open Database.");
            return 0;
        }
void add(FILE * fp)
{
    title();

    char another='y';
    Employee s;
    int i;
    

    fseek(fp,0,SEEK_END);
    while(another=='y'||another=='Y')
    {

        printf("\n\n\t\tEnter Full Name of Employee: ");
        fflush(stdin);
        fgets(s.name,100,stdin);
        s.name[strlen(s.name)-1]='\0';

        printf("\n\n\t\tEnter Depertment Name: ");
        fflush(stdin);
        fgets(s.dept,50,stdin);
        s.dept[strlen(s.dept)-1]='\0';

        printf("\n\n\t\tEnter Employee Id: ");
        scanf("%d",&s.employee_Id);

       

        fwrite(&s,sizeof(s),1,fp);

        printf("\n\n\t\tAdd another Employee?(Y/N)?");
        fflush(stdin);
        another=getchar();
    }
}
