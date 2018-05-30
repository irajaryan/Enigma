#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<conio.h>
struct data{
    char q[100];
    int f;
    struct data *next;
};
struct users{
    char id[20];
    char pass[20];
    struct data *ptr;
    struct users *next1;
};
int sq();
void swap();
int key();
char encryp1(char a[]);
char decryp1(char e[]);
char encryp2(char a[]);
char decryp2(char e[]);
char encryp3(char a[]);
char decryp3(char e[]);
typedef struct data Data;
typedef struct users User;
Data *p,*temp;
User *head1=NULL,*p1,*temp1;
main()
{
    int i,n,z,y,w,t,u,j,b,opt,flag=0;
    char e[100],a[100],usr[20],pas[20],us[20],ps[20],ch;
    char msg[]={"\t\t\t\t\tWelcome to ENIGMA\n"};
    char mstrid[]={"raj.aryan"};
    char mstrpas[]={"vanila"};
    printf("\n");
    for(i=0;i<strlen(msg);i++)
    {
        printf("%c",msg[i]);
        for(j=0;j<60000000;j++)
        {

        }
    }
    printf("\t\t\t\t       -------------------\n");
    while(1)
    {
    label1:
    printf("1. New User\n2. Existing User\n3. Exit\n\n");
    printf("Enter the option: ");
    scanf("%d",&opt);
    switch(opt)
    {
    case 1:
    {
        printf("Enter Username:\t");
        scanf("%s",usr);
        printf("Enter Password (6 characters):\t");
        for(i=0;i<6;i++)
        {
        ch = getch();
        pas[i] = ch;
        ch = '*' ;
        printf("%c",ch);
        }
        temp1 = (User *) malloc(sizeof (User));
        strcpy(temp1->id,usr);
        strcpy(temp1->pass,pas);
        temp1->next1=NULL;
        temp1->ptr=NULL;
        if(head1==NULL)
            {
                head1=temp1;
            }
        else
            {
                p1=head1;
                while(p1->next1!=NULL)
                {
                    p1=p1->next1;
                }
                p1->next1=temp1;
            }
            system("cls");
            printf("Successfully created login\n");
    break;
    }
    case 2:
    {
        system("cls");
        printf("Enter Username:\t");
        scanf("%s",us);
        printf("Enter Password:\t");
        scanf("%s",ps);
        printf("\n");
        temp1=head1;
        while(temp1!=NULL)
        {
            if((strcmp(us,temp1->id)==0)&&(strcmp(ps,temp1->pass)==0))
            {
                flag=1;
                break;
            }
            else if((strcmp(us,mstrid)==0)&&(strcmp(ps,mstrpas)==0))
            {
                flag=2;
                break;
            }
            else
            {
                temp1=temp1->next1;
                flag=0;
            }
        }
    label:
    if(flag==1)
    {printf("1. New message\n2. Old messages\n3. Display\n4. Sign out\n");
    scanf("%d",&u);
    if(u==1)
    {
        system("cls");
        printf("Enter the message\n");
        scanf("%s",a);
            printf("Encryption Algorithm\n1.Type 1\n2.Type 2\n3.Type 3\n");
            scanf("%d",&n);
            if(n==1)
            {
                encryp1(a);
                printf("\n");
            }
            if(n==2)
            {
                encryp2(a);
                printf("%s\n",a);
            }
            if(n==3)
            {
                encryp3(a);
                printf("%s\n",a);
            }
            printf("Encryption successful\n");
            w=key(a,n);
            t=w%10;
            temp = (Data *) malloc(sizeof (Data));
            strcpy(temp->q,a);
            temp->f=w;
            temp->next=NULL;
            p=temp1->ptr;
            if(temp1->ptr==NULL)
            {
                temp1->ptr=temp;
            }
            else
            {
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=temp;
            }
        goto label;
        }
    else if (u==2)
    {
        system("cls");
        printf("Enter the key: ");
        scanf("%d",&z);
        y=z%10;
        temp=temp1->ptr;
        while(temp!=NULL)
        {
            if(temp->f==z)
            {
                strcpy(e,temp->q);
                break;
            }
            else
            {
                temp=temp->next;
            }
        }
        if(y==1)
        {
            decryp1(e);
        }
        else if(y==2)
        {
            decryp2(e);
        }
        else if(y==3)
        {
            decryp3(e);
        }
        printf("\n");
        goto label;
    }
    else if (u==3)
    {
        temp=temp1->ptr;
        while(temp!=NULL)
        {
            printf("%d\t",temp->f);
            printf("%s\n",temp->q);
            temp=temp->next;
        }
        goto label;
    }
    else if (u==4)
    {
        system("cls");
        goto label1;
    }
    break;
    }
    else if(flag==0)
    {
        printf("\nInvalid Credentials\n");
        goto label1;
    }
    else if(flag==2)
    {
        temp1=head1;
        while(temp1!=NULL)
        {
            printf("\n%s\n\n",temp1->id);
            temp=temp1->ptr;
        while(temp!=NULL)
        {
            strcpy(e,temp->q);
            if(temp->f%10==1)
            {
            decryp1(e);
            printf("\n");
            }
            else if(temp->f%10==2)
            {
            decryp2(e);
            printf("\n");
            }
            else if(temp->f%10==3)
            {
            decryp3(e);
            printf("\n");
            }
            temp=temp->next;
        }
            temp1=temp1->next1;
        }
        printf("\n");
        goto label1;
    }
    }
    case 3:
        {
            exit(0);
            break;
        }
    default:
        {
        printf("Enter the valid option!\n\n");
        break;
        }
    }
}
}
char encryp1(char a[])
{
    int i,x,j,k,l=0;
    char c[100];
    i=strlen(a);
    x=sq(i);
    char b[x][x];
    for (j=0;j<x;j++)
    {
        for(k=0;k<x;k++)
        {
            b[j][k]=a[l];
            l++;
        }
    }
    l=0;
    for (j=0;j<x;j++)
    {
        for(k=0;k<x;k++)
        {
            printf("%c",b[k][j]);
        }
    }
    return a;
}
char decryp1(char e[])
{
    int i,x,j,k,l=0;
    char c[100];
    i=strlen(e);
    x=sq(i);
    char b[x][x];
    for (j=0;j<x;j++)
    {
        for(k=0;k<x;k++)
        {
            b[j][k]=e[l];
            l++;
        }
    }
    l=0;
    for (j=0;j<x;j++)
    {
        for(k=0;k<x;k++)
        {
            c[l]=b[j][k];
            l++;
        }
    }
    for(j=0;j<i;j++)
    {
        printf("%c",c[j]);
    }
}
int sq(int a)
{
    double b;
    b=sqrt(a);
    a=(int)b+1;
    return(a);
}
char encryp2(char a[])
{
    int i,x;
    int j=strlen(a);
    for(i=j-1;i>=0;i-=2)
    {
        x=i/2;
        swap(&a[i],&a[x]);
    }
    return a;
}
char decryp2(char e[])
{
    int i,x;
    int j=strlen(e);
    if(j%2==1)
    {
        for(i=1;i<j;i++)
        {
            if(2*i>=j)
            {
                break;
            }
            x=2*i;
            swap(&e[i],&e[x]);
        }
        printf("%s",e);
    }
    else if(j%2==0)
    {
        for(i=0;i<j;i++)
        {
            if(2*i+1>=j)
            {
                break;
            }
            x=2*i+1;
            swap(&e[i],&e[x]);
        }
        printf("%s",e);
    }
}
void swap(char *a,char *b)
{
    char* t;
    t=*a;
    *a=*b;
    *b=t;
}
char encryp3(char a[])
{
    int i,x;
    int j=strlen(a);
    for(i=0;i<j;i++)
    {
        a[i]=a[i]+i+1;
    }
    return a;
}
char decryp3(char e[])
{
    int i,x;
    int j=strlen(e);
    for(i=0;i<j;i++)
    {
        e[i]=e[i]-i-1;
    }
    printf("%s",e);

}
int key(char a[],int n)
{
    int w,i,s=0;
    for (i=0;i<(strlen(a));i++)
    {
        s=s+(a[i]*i);
    }
    w=abs(((s%1000)*10))+n;
    printf("Key: %d\n",w);
    return w;
}
