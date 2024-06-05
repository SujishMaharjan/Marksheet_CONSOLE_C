#include<stdio.h>
#include<conio.h>
#include<string.h>
struct marks
{
       int app;
       int bas;
       int com;
       int dra;
       int mat;
       int phy;
};
struct student
{
       char name[50];
       int roll;
       char sec[1];
       struct marks m;
       int total;
       float per;
       char rema[20];
}s;
void login();
void read();
void display();
void edit();
void display1();
void delete();
char d[]="Distinction",fi[]="FirstDivision",se[]="SecondDivision",fa[]="Fail";
int main()
{
    login();
    system("cls");
    char choice;
    while(1)
    {
     system("cls");
     printf("\n");
     printf("\n");
     printf("\n");
     printf("\n");
     printf("\n");
     printf("\n");
     printf("\n\t\t\t\tMAIN  MENU\t\t");
     printf("\n");
     printf("\n\t\tEnter a:For adding new records.");
     printf("\n\t\tEnter b:For displaying a list of all records:");
     printf("\n\t\tEnter c:For Displaying Marksheet of a particluar student:");
     printf("\n\t\tEnter d:For Deleting the details of a student:");
     printf("\n\t\tEnter e:For Editing the details of a student:");
     printf("\n\t\tEnter z:For exit \n");
     printf("                ");
     fflush(stdin);
     choice=getche();
     printf("\n");
     printf("\n");
     printf("\n");
     switch(choice)
     {
      case 'a':
           system("cls");
           read();
           printf("Press Enter to GO to Main Menu");
           break;
      case 'b':
           system("cls");
           display();
           break;
      case 'c':
           system("cls");
           display1();
           break;
      case 'e':
           system("cls");
           edit();
           break;
      case 'd':
           system("cls");
           delete();
           display();
           break;
      case 'z':
           exit(1);
      default:
           printf("\nEnter Valid Choice\n");
      }
     }
     return 0;
}
void login()
{
                     char username[]="username",password[]="password";
                     char user[15],pass[15],ch;
                     while(1)
                     {
                     system("cls");
                     printf("\n");
                     printf("\n");
                     printf("\n");
                     printf("\n");
                     printf("\n");
                     printf("\n");
                         int i=0;
                         printf("\t\t\t\tEnter username:\n");
                         printf("                                ");
                         scanf("%s",user);
                         printf("\t\t\t\tEnter password:\n");
                         printf("                                ");
                         while((ch=getch())!=13)
                         {
                                    pass[i]=ch;
                                    printf("*");
                                    i++;
                         }
                         pass[i]='\0';
                        if(strcmp(username,user)==0&&strcmp(password,pass)==0)
                         {
                                 printf("\n\t\t\tYou have logged in succesfully\n");
                                 printf("\n\t\t\tPRESS ENTER TO GO MAIN MENU");
                                 getch();
                                 break;
                         }
                         else
                         {
                                 printf("\n\t\t\tWRONG PASSWORD OR WRONG USERNAME\n");
                                 printf("\n\t\t\tPRESS ENTER TO TRY AGAIN");
                                 getch();
                                 continue;
                         }
                     }
} 
void read()
{
                          FILE *fp;
                          char test;
                          if((fp=fopen("E:\\project1.txt","ab+"))==NULL)
                          {
                                 if((fp=fopen("E:\\project1.txt","wb+"))==NULL)
                                        {
                                           printf("\t\tCannot open file");
                                           printf("\n");
                                           getch();
                                           exit(1);
                                         }
                          }
                          while(1)
                          {
                                   s.total=0;
                                   s.per=0;
                                   printf("\nEnter name:");
                                   gets(s.name);
                                   printf("\nEnter Rollno ,Section:");
                                   scanf("%d%s",&s.roll,s.sec);
                                   fflush(stdin);
                                   printf("\nEnter Marks of Subjects in order:");
                                   printf("\nApplied,Electrical,Computer,Drawing,Math,Physics:");
                                   scanf("%d%d%d%d%d%d",&s.m.app,&s.m.bas,&s.m.com,&s.m.dra,&s.m.mat,&s.m.phy);
                                   s.total+=s.m.app+s.m.bas+s.m.com+s.m.dra+s.m.mat+s.m.phy;
                                   s.per+=s.total/6;
                                   if(s.per>=80)
                                       {
                                           strcpy(s.rema,d);
                                       }
                                     else if(s.per<80&&s.per>=60)
                                       {
                                            strcpy(s.rema,fi);
                                       }
                                     else if(s.per<60&&s.per>=40)
                                       {
                                            strcpy(s.rema,se);
                                       }
                                     else
                                       {
                                            strcpy(s.rema,fa);
                                       }
                                   fwrite(&s,sizeof(s),1,fp);
                                   fflush(stdin);
                                   printf("\t\tEnter ESC TO GO MAIN MENU");
                                   printf("\n\t\tPress ENTER to Continue:");
                                   test=getche();
                                   if(test==27)
                                   {
                                           break;
                                   }
                        }
                        printf("\n");
                        fclose(fp);
}
void display()
{
                     FILE *fp;
                     if((fp=fopen("E:\\project1.txt","rb"))==NULL)
                     {
                      printf("Cannot open file");
                      exit(1);
                     }
                     printf("\n");
                     printf("\n\t\tDISPLAYING DETAILS OF ALL STUDENTS");
                     printf("\n");
                     printf("\n\t\tA=Applied Mechanics B=Basic Electrical P=Physics");
                     printf("\n\t\tC=C Programming     D=Drawing          M=Math");
                     printf("\n");
                     printf("\nSN       Name        Roll  Sec  A   B   C   D   M   P  Total Per  Remarks");
                     printf("\n");
                     int i=1;
                     while(fread(&s,sizeof(s),1,fp)==1)
                     {
                           printf("\n%-3d%-20s%-5d%-4s%-4d%-4d%-4d%-4d%-4d%-4d%-4d%-6.2f%-15s",i,s.name,s.roll,s.sec,s.m.app,s.m.bas,s.m.com,s.m.dra,s.m.mat,s.m.phy,s.total,s.per,s.rema);
                           i++;
                     }
                     printf("\n");
                     printf("\n");
                     fclose(fp);
                     printf("\n\t\tPRESS ENTER TO GO MAIN MENU");
                     getch();
}
void display1()
{
                     FILE *fp;
                     char name[50];
                     int flag=1;
                     if((fp=fopen("E:\\project1.txt","rb"))==NULL)
                       {
                           printf("\nCannot open file");
                           exit(1);
                       }
                     printf("\nEnter name of student to show Marksheet:");
                     gets(name);
                     while(fread(&s,sizeof(s),1,fp)==1)
                     {
                                  if(strcmp(s.name,name)==0)
                                    {
                                         printf("\n");
                                         printf("\n\t\tMARKSHEET");
                                         printf("\n");
                                         printf("\n");
                                         printf("\n  NAME:%-25s",name);
                                         printf("\n");
                                         printf("\n  ROLL NO:  %-10d",s.roll);
                                         printf("\n");
                                         printf("\n  SECTION: %-5s",s.sec);
                                         printf("\n");
                                         printf("\n   SUBJECTS            FULL MARKS   PASS MARKS     MARKS OBTAINED ");
                                         printf("\n");
                                         printf("\n APPLIED MECHAINICS     80           32             %-5d",s.m.app);     
                                         printf("\n BASIC ELECTRICAL       80           32             %-5d",s.m.bas);      
                                         printf("\n C PROGRAMMING          80           32             %-5d",s.m.com);
                                         printf("\n DRAWING I              80           32             %-5d",s.m.dra);
                                         printf("\n MATHEMATICS I          80           32             %-5d",s.m.mat);
                                         printf("\n PHYSICS                80           32             %-5d",s.m.phy); 
                                         printf("\n");
                                         printf("\n");    
                                         printf("\n");
                                         printf("\n");
                                         printf("\n\t\t\t\tGRAND TOTAL %-7d",s.total);
                                         printf("\n\t\t\t\tPERCENTAGE=%-5.2f\%",s.per);
                                         printf("\n\t\t\t\tREMARKS  %-15s",s.rema);
                                         printf("\n");
                                         flag=0;
                                         break;
                                    }
                     }
                     if(flag==1)
                     {
                          printf("\n");
                          printf("\n");    
                          printf("\n\t\tThere is no such student named %s",name);
                          printf("\n\t\tPRESS ENTER TO GO MAIN MENU");
                     }
                     fclose(fp);
                     getch();
}
void edit()
{
                           FILE *fp;
                           int flag=1;
                           char name[50];
                           if((fp=fopen("E:\\project1.txt","rb+"))==NULL)
                           {
                                  printf("Cannot open file");
                                  exit(1);
                           }
                           printf("\nEnter name of student you want to edit:");
                           gets(name);
                           while(fread(&s,sizeof(s),1,fp)==1)
                           {
                                   if(strcmp(s.name,name)==0)
                                       {
                                              s.total=0;
                                              s.per=0;
                                              printf("\nEnter name:");
                                              gets(s.name);
                                              printf("\nEnter Rollno ,Section:");
                                              scanf("%d%s",&s.roll,s.sec);
                                              fflush(stdin);
                                              printf("\nEnter Marks of Subjects in order:");
                                              printf("\nApplied,Electrical,Computer,Drawing,Math,Physics:");
                                              scanf("%d%d%d%d%d%d",&s.m.app,&s.m.bas,&s.m.com,&s.m.dra,&s.m.mat,&s.m.phy);
                                              s.total+=s.m.app+s.m.bas+s.m.com+s.m.dra+s.m.mat+s.m.phy;
                                              s.per+=s.total/6;
                                              if(s.per>=80)
                                                {
                                                            strcpy(s.rema,d);
                                                }
                                               else if(s.per<80&&s.per>=60)
                                                {
                                                            strcpy(s.rema,fi);
                                                 }
                                               else if(s.per<60&&s.per>=40)
                                                {
                                                            strcpy(s.rema,se);
                                                 }
                                                else
                                                 {
                                                             strcpy(s.rema,fa);
                                                  }
                                               fseek(fp,-sizeof(s),SEEK_CUR);
                                               fwrite(&s,sizeof(s),1,fp);
                                               flag=0;
                                               break;
                                       }
                           }
                           if(flag==1)
                           {
                                 printf("There is no such student named %-25s",name);
                                 printf("\n");
                                 printf("\n");
                           }
                           fclose(fp);
                           printf("\n\t\tPRESS ENTER TO GO MAIN MENU");
                           getch();
}
void delete()
{
     FILE *fp;
     FILE *temp;
     int flag=1;
     char name[50];
     if((fp=fopen("E:\\project1.txt","rb"))==NULL)
     {
      exit(1);
      }
      if((temp=fopen("E:\\project2.txt","wb"))==NULL)
      {
       exit(1);
      }
     printf("Enter the name of student you want to delete:");
     gets(name);
     while(fread(&s,sizeof(s),1,fp)==1)
     {
           if(strcmp(name,s.name)==0)
             {
              flag=0;
             continue;
             }
           else
           {
            fwrite(&s,sizeof(s),1,temp);
           }
     }
     if(flag==1)
     {
      printf("\nThere is no such student named %-25s",name);
     }
     else
     {
     printf("\nThe Details of student %-25s has been deleted",name);
     }
     fclose(fp);
     fclose(temp);
     remove("E:\\project1.txt");
     rename("E:\\project2.txt","E:\\project1.txt");
}
     
             
