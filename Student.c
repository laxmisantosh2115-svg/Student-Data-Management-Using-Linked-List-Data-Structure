#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
typedef struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
}SLL;

void addrecord(SLL **);
void deleterecord(SLL **);
void showlist(SLL *);
void modifyrecord(SLL *);
void saverecord(SLL *);
void exitrecord(SLL **);
void sortlist(SLL *);
void deleteAll(SLL **);
void reverserecord(SLL *);


int main()
{
    SLL *headptr=0;
    int op,c;
    while(1)
        {
            printf("********STUDENT RECORD MENU*********\n");
            printf("1.ADD NEW RECORD\n2.DELETE A RECORD\n3.Show THE LIST\n4.MODIFY A RECORD\n5.SAVE RECORDS\n6.EXIT\n7.SORT THE LIST\n8.DELETE ALL THE RECORDS\n9.REVERSE THE LIST\n" );
            printf("Enter your Choice:\n");
            scanf("%d",&op);
    switch(op)
        {
            case 1:addrecord(&headptr);
                    break;
            case 2:deleterecord(&headptr);
                    break;
            case 3:showlist(headptr);
                    break;
            case 4:modifyrecord(headptr);
                    break;
            case 5:saverecord(headptr);
                    break;
            case 6:exitrecord(&headptr);
                    break;
            case 7:sortlist(headptr);
                    break;
           case 8:deleteAll(&headptr);
                    break;
            case 9:reverserecord(headptr);
                    break;
            
        }
    }
}

    void addrecord(SLL **ptr)
{
    SLL *new;
    new=malloc(sizeof(SLL));
    printf("Enter the Rollno,Name and Marks:\n");
    scanf("%d %s %f",&new->rollno,new->name,&new->percentage);
    new->next=0;
    if(*ptr==0)
     *ptr=new;
    else
    {
        SLL *last=*ptr;
        while(last->next)
        last=last->next;
        
        last->next=new;
    }
}

   void showlist(SLL *ptr)
{
    if(ptr==0)
    {
        printf("No record Found");
        return;
    }
    while(ptr)
    {
        printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
        ptr=ptr->next;
    }
}

void modifyrecord(SLL *ptr)
{
    if(ptr==0)
    {
        printf("No record Found\n");
        return;
    }

    int num;
    printf("Enter Rollno to modify:\n");
    scanf("%d",&num);

    while(ptr)
    {
        if(num==ptr->rollno)
        {
            printf("Enter new Name and Percentage:\n");
            scanf("%s %f",ptr->name,&ptr->percentage);

            printf("Record modified successfully\n");
            return;
        }

        ptr=ptr->next;
    }

    printf("Rollno not found\n");
}

  void deleterecord(SLL **ptr)
{
    if(*ptr==0)
    {
        printf("no record found\n");
        return;
    }
    int num;
    printf("Enter num to delete:\n");
    scanf("%d",&num);
    SLL *del=*ptr,*prev;
    while(del)
        {
            if(num==del->rollno)
            {
                if(*ptr==del)
                    *ptr=del->next;
                else
                    prev->next=del->next;
                free(del);
                return;
            }
            prev=del;
            del=del->next;
        }
    printf("Rollno not found\n");
}

void saverecord(SLL *ptr)
{
    if(ptr==0)
    {
        printf("No record found\n");
        return;
    }
    FILE *fp=fopen("std.txt","w");
    while(ptr)
        {
            fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
            ptr=ptr->next;
        }
    printf("Data saved in file\n");
    fclose(fp);
}

void exitrecord(SLL **ptr)
{
    SLL *temp;
    while(*ptr)
        {
            temp=*ptr;
            *ptr=(*ptr)->next;
            free(temp);
        }
    printf("program existed succesfully");
    exit(0);
}

void sortlist(SLL *ptr)
{
    int countnode(SLL *ptr)
{
    int c=0;
    while(ptr)
    {
        c++;
        ptr=ptr->next;
    }
    return c;
}
    if(ptr==0)
    {
        printf("No record Found\n");
        return;
    }
    SLL *p1=ptr, *p2,t;
    int i,j,c=countnode(ptr);
    for(i=0;i<c-1;i++)
    {
        p2=p1->next;
        for(j=0;j<c-1-i;j++)
        {
            if(strcmp(p1->name,p2->name)>0)
            {
                t.rollno=p1->rollno;
                strcpy(t.name,p1->name);
                t.percentage=p1->percentage;
                
                p1->rollno=t.rollno;
                strcpy(p1->name,p2->name);
                p1->percentage=p2->percentage;
                
                p2->rollno=t.rollno;
                strcpy(p2->name,t.name);
                p2->percentage=t.percentage;
            }
            p2=p2->next;
        }
        p1=p1->next;
    }
}

void deleteAll(SLL **ptr)
{
    if(*ptr==0)
    {
        printf("No Record Found");
        return;
    }
    SLL *del=*ptr;
    int c=1;
    while(del)
    {
        *ptr=del->next;
        printf("Node position:%d deleted\n",c++);
        sleep(1);
        free(del);
        del=*ptr;
    }
    printf("All Record deleted\n");
}

void reverserecord(SLL *ptr)
{
    int countnode(SLL *ptr)
{
    int c=0;
    while(ptr)
    {
        c++;
        ptr=ptr->next;
    }
    return c;
}
    if(ptr==0)
    {
        printf("No Record found");
    }
    SLL *t;
    int i,j,c=countnode(ptr);
    for(i=0;i<c;i++)
    {
        t=ptr;
        for(j=0;j<c-1-i;j++)
         t=t->next;
         printf("%d %s %f\n",t->rollno,t->name,t->percentage);
    }
}
