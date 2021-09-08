#include<string.h>
#include<stdlib.h>
#include<math.h>
#include <windows.h>

#define Employee struct emp

void add(FILE * fp);
void modify(FILE * fp);
void display(FILE * fp);

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

void modify(FILE * fp)
{
    title();

    Employee s;
    int i,flag=0,tempid,siz=sizeof(s);
    float cgpa;

    printf("\n\n\tEnter Id of Employee to MODIFY the Record : ");
    scanf("%d",&tempid);

    rewind(fp);

    while((fread(&s,siz,1,fp))==1)
    {
        if(s.employee_Id==tempid)
        {
            flag=1;
            break;
        }
    }

    if(flag==1)
    {
        fseek(fp,-siz,SEEK_CUR);
        printf("\n\n\t\t\t\tRecord Found\n\t\t\t");
        printChar('=',38);
        printf("\n\n\t\t\tEmployee Name: %s",s.name);
        printf("\n\n\t\t\tEmployee Id: %d\n\t\t\t",s.employee_Id);
        printChar('=',38);
        printf("\n\n\t\t\tEnter New Data for the Employee");

        printf("\n\n\t\t\tEnter Full Name of Employee: ");
        fflush(stdin);
        fgets(s.name,100,stdin);
        s.name[strlen(s.name)-1]='\0';

        printf("\n\n\t\t\tEnter Department: ");
        fflush(stdin);
        fgets(s.dept,50,stdin);
        s.dept[strlen(s.dept)-1]='\0';

        printf("\n\n\t\t\tEnter Employee Id: ");
        scanf("%d",&s.employee_Id);


        fwrite(&s,sizeof(s),1,fp);
    }

    else printf("\n\n\t!!!! ERROR !!!! RECORD NOT FOUND");

    printf("\n\n\t");
    system("pause");

}

void display(FILE * fp)
{
    title();
    Employee s;
    int i,siz=sizeof(s);

    rewind(fp);

    while((fread(&s,siz,1,fp))==1)
    {
        printf("\n\t\tNAME : %s",s.name);
        printf("\n\n\t\tDepertment : %s",s.dept);
        printf("\n\n\t\tId : %d",s.employee_Id);
        
    }
    printf("\n\n\n\t");
    printChar('*',65);
    printf("\n\n\t");
    system("pause");
}

