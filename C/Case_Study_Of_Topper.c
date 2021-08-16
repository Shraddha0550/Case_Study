#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define Max 5

struct
{
    char Stud_Name[10];
    int Roll_No;
    int Maths_mark;
    int Chem_mark;
    int Phy_mark;
    float Total;
    float Percentage;
}Student[Max];

///declare function
void Accept_Details();
void Display_All_Students();
void Display_Topper();
void Display_Second_Topper();
void search_Student_By_Id();
void Dispay_Rank();

///globaly declared
int i = 0, ID = 0 , Roll__No = 0 , STRoll__No = 0;
float Topper = 0.0 , STopper=0.0;
char Name[10] = " ", STName[10] = "";


void Accept_Details()
{
    while( i < Max)
    {
        printf("\n\t****%d. Student Details****\n",i+1);

        printf("\n\t\t Enter Student Name:");
        scanf("%s",Student[i].Stud_Name);
        fflush(stdin);

        printf("\n\t\t Enter Student Roll Number   :");
        scanf("%d",&Student[i].Roll_No);

        printf("\n\t\t Enter Student maths mark    :");
        scanf("%d",&Student[i].Maths_mark);

        printf("\n\t\t Enter Student chemistry mark:");
        scanf("%d",&Student[i].Chem_mark);

        printf("\n\t\t Enter Student physics mark  :");
        scanf("%d",&Student[i].Phy_mark);

        printf("\n\t\t Further Calculation Total And Percentage Is ...press Any key to Continue...\n");
        _getch();

        Student[i].Total = Student[i].Maths_mark + Student[i].Chem_mark + Student[i].Phy_mark;

        printf("\n\t\t Total is  \t: %.2f\n",Student[i].Total);

        Student[i].Percentage =  ( Student[i].Total / 300 ) * 100 ;

        printf("\n\t\t Percentage is : %.2f\n",Student[i].Percentage);

        if(Student[i].Percentage > Topper)
        {
            Topper = Student[i].Percentage;

            strcpy(Name ,Student[i].Stud_Name);
            Roll__No = Student[i].Roll_No;
        }

        i++;
    }
}
void Display_All_Students()
{
    for(i = 0 ; i < Max ; i++)
    {
        printf("\n\t ========*****%d .Student Information *****========\n\n",i+1);

        printf("\n\t\t Student Roll No = %d",Student[i].Roll_No);
        printf("\n\t\t Student Name Is = %s",Student[i].Stud_Name);
        printf("\n\t\t Maths Marks     = %d",Student[i].Maths_mark);
        printf("\n\t\t chemistry Marks = %d",Student[i].Chem_mark);
        printf("\n\t\t Physics Marks   = %d",Student[i].Phy_mark);
        printf("\n\n\t\t Total Marks     = %.2f",Student[i].Total);
        printf("\n\t\t percentage      = %.2f\n",Student[i].Percentage);
    }
}
void Display_Topper()
{
            printf("\n\t====**** Information About 1st Topper ****====\n");

            printf("\n\t\tRoll Number  :%d\n",Roll__No);
            printf("\n\t\tStudent Name :%s\n",Name);
            printf("\n\t\tpercentage   :%.2f\n",Topper);

}
void Display_Second_Topper()
{
     for(i = 0 ; i < Max ; i++)
    {
        if(Student[i].Percentage ==Topper)
        {
            continue;
        }
        if(Student[i].Percentage > STopper)
        {
            STopper = Student[i].Percentage;

            strcpy(STName ,Student[i].Stud_Name);
            STRoll__No = Student[i].Roll_No;
        }
    }
    printf("\n\t====**** Information About 2st Topper ****====\n");

    printf("\n\t\tRoll Number  :%d\n",STRoll__No);
    printf("\n\t\tStudent Name :%s\n",STName);
    printf("\n\t\tpercentage   :%.2f\n",STopper);

}
void search_Student_By_Id()
{
    printf("\n\t\t Enter Student Id = ");
    scanf("%d",&ID);

    int k = 1;

        while(k <= Max)
        {
             if(k == ID)
             {
                    printf("\n\t\t ======**************======    \n");

                    printf("\n\t\t Student Roll No = %d",Student[k-1].Roll_No);
                    printf("\n\t\t Student Name Is = %s",Student[k-1].Stud_Name);
                    printf("\n\t\t Maths Marks     = %d",Student[k-1].Maths_mark);
                    printf("\n\t\t chemistry Marks = %d",Student[k-1].Chem_mark);
                    printf("\n\t\t Physics Marks   = %d",Student[k-1].Phy_mark);
                    printf("\n\n\t\t Total Marks     = %.2f",Student[k-1].Total);
                    printf("\n\t\t percentage      = %.2f\n",Student[k-1].Percentage);


                    printf("\n\t\t ======**************======    \n");
             }
             k++;
        }
}
void Dispay_Rank()
{
    int Temp = 0,i = 0, j = 0,R = 0;
    float per[Max] ;

    printf("\n\t\t ==== Percentage In Rank Is =====\n");
    for(R = 0 ; R < Max ; R++)
    {
        per[R] = Student[R].Percentage;
    }
    for(i = 0; i < Max ; i++)
    {
        for(j = i+1 ; j < Max ; j++)
        {
            if(per[i] < per[j])
            {
                 Temp    = per[j];
                 per[j] =per[i] ;
                 per[i] = Temp;
            }
        }
    }
    for(i = 0; i <Max ; i++)
    {
        printf("\n\t\t\t %.2f\n",per[i]);

    }
}


int main()
{
    int Choice = 0;
    char ch = '\0';

    printf("\n   ================**** WELCOME TO FORK INFOSYSTEMS ****================ \n");

    Accept_Details();
    _getch();
    system("cls");

    for(;;)
    {
         printf("\n\t\t Enter Your Choice ==>\n");
         printf("\n\t\t 1.Display All Student Details \n\t\t 2.Display Topper In The Class \n\t\t 3.Display Second Topper In THe Class \n\t\t 4.Serch Student By ID \n\t\t 5.Dispaly Ranks \n\t\t 6.Exit \n");
         printf("\n\t\t   ");
         scanf("%d",&Choice);

         switch(Choice)
         {
                case 1:
                        Display_All_Students();

                        _getch();
                        system("cls");
                        break;
                case 2:
                        Display_Topper();

                        _getch();
                        system("cls");
                        break;
                case 3:
                        Display_Second_Topper();

                        _getch();
                        system("cls");
                        break;
                case 4:
                        search_Student_By_Id();
                        _getch();
                        system("cls");
                        break;
                case 5:
                        Dispay_Rank();
                        _getch();
                        system("cls");
                        break;
                case 6:
                        fflush(stdin);
                        printf("\n\t\t Are You Sure (yes / No)\n\t\t");
                        ch = getchar();
                        fflush(stdin);

                        if(ch == 'Y' || ch == 'y')
                        {
                            goto DWN;
                        }

                        system("cls");
                        break;
                default:
                        printf("\n\t\t Invalid Choice... Select Correct Choice \n");

                        _getch();
                        system("cls");
                        break;
         }
    }

    DWN:
        printf("\n\t\t Thanks FOR Visiting ....!!\n\n");
        _getch();
        return 0;

}
