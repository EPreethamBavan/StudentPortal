
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>

#include <iomanip>
//for setw() and setprecision()

using namespace std;

//global variables declaration

int i,j,li,lp,rec,valid;

//COORD is a structure initialized with an initialization list
COORD coord = {0, 0};

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//A handle can be anything from an integer index to a pointer to a resource in kernel space.
//The idea is that they provide an abstraction of a resource, so you don't need to know much about the resource itself to use it.
void help();
void schoice();

char ch,choice;

// THIS CLASS DRAWS LINES, BOXES, ETC.

class DRAW
{

public :

    void LINE_HOR(int, int, int, char) ;
    void LINE_VER(int, int, int, char) ;
    void BOX(int,int,int,int,char) ;

} ;

// FUNCTION TO DRAW HORIZONTAL LINE

void DRAW :: LINE_HOR(int column1, int column2, int row, char c)
{
    for ( column1; column1<=column2; column1++ )
    {
        gotoxy(column1,row) ;
        cout <<c ;
    }

}

// FUNCTION TO DRAW VERTICAL LINE

void DRAW :: LINE_VER(int row1, int row2, int column, char c)
{

    for ( row1; row1<=row2; row1++ )
    {
        gotoxy(column,row1) ;
        cout <<c ;
    }

}

// FUNCTION TO DRAW BOX LINE

void DRAW :: BOX(int column1, int row1, int column2, int row2, char c)
{

    char ch=218 ;
    char c1, c2, c3, c4 ;
    char l1=196, l2=179 ;
    if (c == ch)
    {
        c1=218 ;
        c2=191 ;
        c3=192 ;
        c4=217 ;
        l1 = 196 ;
        l2 = 179 ;
    }

    else
    {
        c1=c ;
        c2=c ;
        c3=c ;
        c4=c ;
        l1 = c ;
        l2 = c ;
    }

    gotoxy(column1,row1) ;
        cout <<c1 ;
    gotoxy(column2,row1) ;
        cout <<c2 ;
    gotoxy(column1,row2) ;
        cout <<c3 ;
    gotoxy(column2,row2) ;
        cout <<c4 ;

    column1++ ;
    column2-- ;
    LINE_HOR(column1,column2,row1,l1) ;
    LINE_HOR(column1,column2,row2,l1) ;
    column1-- ;
    column2++ ;
    row1++ ;
    row2-- ;
    LINE_VER(row1,row2,column1,l2) ;
    LINE_VER(row1,row2,column2,l2) ;

}

class FEE

{
    char course;
    float tuition, examination, computer, library ;
    static float total;

public :

    void FEE_SLIP(void) ;
    void LIST(void) ;
    void HELP(void);
    void admin();
    void user();

}fee ;

float FEE::total=0;

//MAIN MENU FUNCTION

void mainmenu()
{
    system("cls");
    for(li=30;li<=50;li++)
    {
        gotoxy(li,14);
        Sleep(30);
        printf("*");
    }

    for(li=50;li>=30;li--)
    {
        gotoxy(li,30);
        Sleep(30);
        printf("*");
    }

    for(lp=15;lp<30;lp++)
    {
        gotoxy(30,lp);
        Sleep(100);
        printf("|");
    }

    for(lp=29;lp>=15;lp--)
    {
        gotoxy(50,lp);
        Sleep(100);
        printf("|");
    }

    gotoxy(15,10);
    printf("Press the corresponding Keys for the desired action");
    gotoxy(35,16);

    printf("F: FEE SLIP");
    gotoxy(35,19);
    printf("L: LIST");
    gotoxy(35,22);
    printf("H: HELP");
    gotoxy(35,25);
    printf("Q: QUIT");

    choice=getch();
    ch=toupper(choice);
    switch(ch)
    {
        case'F':fee.FEE_SLIP();
                break;
        case'L':fee.LIST();
                break;
        case'H':fee.HELP();
                break;
        case'Q':schoice();
        default:gotoxy(33,40);
        cout<<"Illegal Choice"<<endl;
        //cout<<"\tPress any key to return to Main Menu";
        getch();
        mainmenu();

    }

}

void menu()
{
    system("cls");
    cout<<setw(50)<<"ADMIN:  MODIFY FEE-STRUCTURE FOR..."<<endl<<endl;
    cout<<"1.Integrated M.Sc"<<endl;
    cout<<"2.B.E(Sandwich)"<<endl;
    cout<<"3.B.E"<<endl;
    cout<<"4.B.Tech"<<endl;
    cout<<"5.B.Sc"<<endl;
    cout<<"6.M.E"<<endl;
    cout<<"7.M.Tech"<<endl;
    cout<<"8.M.Sc(2 year)"<<endl;

}

void FEE::admin()
{
    menu();
    cout<<"select the course for which you have to set fees:"<<endl;
    int choice;
    cin>>choice;
    system("cls");
    switch(choice)
    {
    case 1:
    case 2:cout<<"Enter fee details for integrated M.Sc or B.E(Sandwich)";
            break;
    case 3:
    case 4:cout<<"Enter fee details for B.E or B.Tech";
            break;
    case 5:cout<<"Enter fee details for B.Sc";
            break;
    case 6:
    case 7:
    case 8:cout<<"Enter fee details for M.E or M.Tech or M.Sc";
            break;
    default:cout<<"wrong entry...enter again..."<<endl;
            admin();
    }
    fstream file1,file2,file3,file4;

    switch(choice)
    {
        case 1:
        case 2: file1.open("5yr.txt",ios::in|ios::out|ios::trunc);
                file1<<"Course::"<<"Integrated M.Sc/B.E(Sandwich)"<<endl;
                file1<<"Duration of course::5 years"<<endl;break;

        case 3:
        case 4:file2.open("4yr.txt",ios::in|ios::out|ios::trunc);
                file2<<"Course::"<<"B.E/B.Tech"<<endl;
                file2<<"Duration of course::4 years"<<endl;break;

        case 5:file3.open("3yr.txt",ios::in|ios::out|ios::trunc);
                file3<<"Course::"<<"B.Sc"<<endl;
                file3<<"Duration of course::3 years"<<endl;break;
        case 6:
        case 7:
        case 8:file4.open("2yr.txt",ios::in|ios::out|ios::trunc);
                file4<<"Course::"<<"M.E/M.Tech/M.Sc(2 year)"<<endl;
                file4<<"Duration of course::2 years"<<endl;break;
    }

    cout<<"Enter fee details for the course::"<<endl;
    cout<<"tution fee::";
    cin>>tuition;
    cout<<"exam fee::";
    cin>>examination;
    cout<<"library fee::";
    cin>>library;
    cout<<"computer science::";
    cin>>computer;
    total=tuition+examination+library+computer;

    switch(choice)
    {
        case 1:
        case 2:
            file1<<"Tution Fee::"<<tuition<<endl;
            file1<<"Examination Fee::"<<examination<<endl;
            file1<<"Library Fee::"<<library<<endl;
            file1<<"Computer Fee::"<<computer<<endl;
            file1<<"Total::"<<total<<endl;

            break;
        case 3:
        case 4:
            file2<<"Tution Fee::"<<tuition<<endl;
            file2<<"Examination Fee::"<<examination<<endl;
            file2<<"Library Fee::"<<library<<endl;
            file2<<"Computer Fee::"<<computer<<endl;
            file2<<"Total::"<<total<<endl;

            break;
        case 5:
            file3<<"Tution Fee::"<<tuition<<endl;
            file3<<"Examination Fee::"<<examination<<endl;
            file3<<"Library Fee::"<<library<<endl;
            file3<<"Computer Fee::"<<computer<<endl;
            file3<<"Total::"<<total<<endl;

            break;
        case 6:
        case 7:
        case 8:
            file4<<"Tution Fee::"<<tuition<<endl;
            file4<<"Examination Fee::"<<examination<<endl;
            file4<<"Library Fee::"<<library<<endl;
            file4<<"Computer Fee::"<<computer<<endl;
            file4<<"Total::"<<total<<endl;
            break;
    }
    file1.close();
    file2.close();
    file3.close();
    file4.close();

    char c;
    cout<<"do u want to enter again?<y/n>";
    cin>>c;
    if(c=='y'||c=='Y')
        admin();
    else
    {
        system("cls");
        FEE::FEE_SLIP();
    }

}

//void user();
void disp()
{
    int ch;
    cout<<"enter the course for which u want to view the fee structure::";
    menu();
    cin>>ch;
    system("cls");

    string line;
    fstream file1("5yr.txt",ios::in);
    fstream file2("4yr.txt",ios::in);
    fstream file3("3yr.txt",ios::in);
    fstream file4("2yr.txt",ios::in);
    switch(ch)
    {
        case 1:
        case 2:
                while(!file1.eof())
                {
                    getline(file1,line);
                    cout<<line<<endl;
                }
                break;

        case 3:
        case 4:
                 while(!file2.eof())
                {
                    getline(file2,line);
                    cout<<line<<endl;
                }
                break;


        case 5:
                while(!file3.eof())
                {
                    getline(file3,line);
                    cout<<line<<endl;
                }
                break;


        case 6:
        case 7:
        case 8:
                 while(!file4.eof())
                {
                    getline(file4,line);
                    cout<<line<<endl;
                }
                break;


        default:cout<<"wrong entry...enter again..."<<endl;
                cout<<"press any key to continue..."<<endl;
                getch();
                system("cls");
                disp();
    }
    //FEE::user();
}

void FEE :: LIST()

{
    system("cls") ;
    cout <<"PSG TECH FEE LIST:"<<endl ;
    float total ;

    fstream file1,file2,file3,file4 ;
    string line;

    file1.open("5yr.txt", ios::in) ;
    while (!file1.eof())
    {
        getline(file1,line) ;
        cout<<line;
        cout<<"\n";
    }

    file1.close() ;

    file2.open("4yr.txt", ios::in) ;
    while (!file2.eof())
    {
        getline(file2,line) ;
        cout<<line;
        cout<<"\n";

    }

    file2.close() ;

    file3.open("3yr.txt", ios::in);
    while (!file3.eof())
    {
        getline(file3,line) ;
        cout<<line;
        cout<<"\n";

    }

    file3.close() ;

    file4.open("2yr.txt", ios::in) ;
    while (!file4.eof())
    {
        getline(file4,line) ;
        cout<<line;
        cout<<"\n";

   }

    file4.close() ;

    cout <<"Press any key to continue............." ;
    getch() ;
    mainmenu();

}

void FEE::user()
{
    int ch;
    system("cls");
    cout<<"1.specific display"<<endl;
    cout<<"2.list"<<endl<<endl;
    cout<<"enter ur choice::";
    cin>>ch;
    if(ch==1)
    {
        disp();
        getch();
        mainmenu();
    }
    else if(ch==2)
        FEE::LIST();
    else
    {
        cout<<"wrongly entered...enter again...press any key to continue..."<<endl;
        getch();
        user();
    }

}

void FEE::FEE_SLIP()
{
    int ch;
    system("cls");
    cout<<"1.ADMIN"<<endl;
    cout<<"2.USER"<<endl;
    cout<<"3.MAIN MENU"<<endl<<endl;
    cout<<"enter ur choice::";
    cin>>ch;
    if(ch==1)
        FEE::admin();
    else if(ch==2)
        FEE::user();
    else if(ch==3)
    {
        system("cls");
        mainmenu();
    }
    else
    {
        cout<<"wrongly entered...enter again..."<<endl;
        FEE::FEE_SLIP();
    }
}


void FEE::HELP()
{

    system("cls");

    cout<<"This is a fee structure program of our college"<<endl;
    cout<<"It can be used to :  "<<endl;
    cout<<"\n";
    cout<<"1. View the fee slip of a student of a course"<<endl;
    cout<<"2. Modify the fee structure of the course"<<endl;
    cout<<"3. View the fee structure of the courses in the form of a list"<<endl;
    cout<<"\n";
    cout<<"The menu functions are described as follows:"<<endl;
    cout<<"\n";
    cout<<"1. FEE SLIP:  This function displays the fee slip for a given student"<<endl;
    cout<<"              from the course entered by the user. "<<endl;
    cout<<"2. MODIFY  :  This function modifies the fee structure for a give course."<<endl;
    cout<<"              The user can change the fees for various fields"<<endl;
    cout<<"3. LIST    :  This function displays the list of total fees for all the courses"<<endl;
    cout<<"\n";
    cout<<"Press any key to continue..........."<<endl;
    getch();
    mainmenu();
}

int lmain();
int cmain();

void help()
{
    system("cls");
    cout<<"\n";
    cout<<"This is the student portal of our college"<<endl;
    cout<<"It can be used to :  "<<endl;
    cout<<"\n";
    cout<<"1. LEAVE POSTING: Post leave and display the posted leave printout"<<endl;
    cout<<"2. CGPA CALCULATION: Calculate cgpa for integrated M.Sc course"<<endl;
    cout<<"3. FEE STRUCTURE: Fee structure of the courses"<<endl;
    cout<<"\n";
    cout<<"\n";
    cout<<"Press any key to continue..........."<<endl;
    getch();
    schoice();
}


class leave
{
        protected:
        string rno;
        string name;
        int prog;
        int sem;
        public:
                leave();
                void program();
                void semester();
};

leave::leave()
{
        system("cls");
        cout<<setw(50)<<"LEAVE POSTING"<<endl<<endl;

        cout<<"enter roll number::";
        cin>>rno;
        cout<<"enter name::";
        cin>>name;
        cout<<"enter programme::"<<endl;
        cout<<"\n";
        program();
        cin>>prog;
        while(prog<1||prog>8)
        {
                cout<<"error....enter program again...";
                cin>>prog;
        }
        cout<<"enter sem::";
        cin>>sem;
        semester();

        fstream file1;
        file1.open("post1.txt",ios::in|ios::out|ios::trunc);
        if(!file1.is_open())
                cout<<"error while opening the file...";
        else
        {
                file1<<"\t\tPOSTED LEAVE PRINTOUT:"<<endl;
                file1<<"ROLL NO::"<<rno<<endl;
                file1<<"NAME::"<<name<<endl;
                file1<<"PROGRAMME::";
                switch(prog)
                {
                        case 1:file1<<"Integrated M.Sc"<<endl;break;
                        case 2:file1<<"B.E"<<endl;break;
                        case 3:file1<<"B.Tech"<<endl;break;
                        case 4:file1<<"B.E(Sandwich)"<<endl;break;
                        case 5:file1<<"B.Sc"<<endl;break;
                        case 6:file1<<"M.E"<<endl;break;
                        case 7:file1<<"M.Tech"<<endl;break;
                        case 8:file1<<"M.Sc(2 year)"<<endl;break;
                }
                file1<<"SEMESTER::"<<sem<<endl;
                file1.close();
        }


}

void leave::program()
{
        cout<<"Programmes in our college::"<<endl;
        cout<<"1.integrated M.Sc"<<endl;
        cout<<"2.B.E"<<endl;
        cout<<"3.B.Tech"<<endl;
        cout<<"4.B.E(Sandwich)"<<endl;
        cout<<"5.B.Sc"<<endl;
        cout<<"6.M.E"<<endl;
        cout<<"7.M.Tech"<<endl;
        cout<<"8.M.Sc(2 year)"<<endl;
}

void leave::semester()
{
        switch(prog)
        {
                case 1:while(sem<1||sem>10)
                        {
                                cout<<"sem wrongly entered....enter again.....";
                                cin>>sem;
                        }
                        break;
                case 2:
                case 3:
                case 4:while(sem<1||sem>8)
                        {
                                cout<<"sem wrongly entered....enter again.....";
                                cin>>sem;
                        }
                        break;
                case 5:while(sem<1||sem>6)
                        {
                                cout<<"sem wrongly entered....enter again.....";
                                cin>>sem;
                        }
                        break;
                case 6:
                case 7:
                case 8:while(sem<1||sem>4)
                        {
                                cout<<"sem wrongly entered....enter again.....";
                                cin>>sem;
                        }
        }
}
class leave_type
{
        protected:
                int ltype,extype;
        public:
                //friend display(day_type,leave_type);
                leave_type()
                {
                        cout<<"select leave type::"<<endl<<endl;
                        cout<<"1.medical"<<endl;
                        cout<<"2.exemption"<<endl;
                        cout<<"3.leave"<<endl;
                        cout<<endl<<"enter ur choice::";
                        cin>>ltype;
                        if(ltype<1||ltype>3)
                        {
                                cout<<"you have entered wrongly....enter again..."<<endl;
                                leave_type();
                        }
                        if(ltype==2)
                        {
                                cout<<"select the type of exemption::"<<endl<<endl;
                                cout<<"1.sports"<<endl;
                                cout<<"2.club activities"<<endl;
                                cout<<endl<<"enter ur choice::";
                                cin>>extype;
                                while(!(extype==1||extype==2))
                                {
                                        cout<<"error....enter again...";
                                        cin>>extype;
                                }
                        }

                        fstream file1("post1.txt",ios::in|ios::out|ios::app);
                        file1<<"LEAVE TYPE::";
                        switch(ltype)
                        {
                                case 1:file1<<"medical leave"<<endl;break;
                                case 2:file1<<"exemption"<<endl;
                                        file1<<"TYPE OF EXEMPTION::";
                                        if(extype==1)
                                                file1<<"sports"<<endl;
                                        else
                                                file1<<"club activities"<<endl;
                                        break;
                                case 3:file1<<"casual leave"<<endl;break;
                        }
                        file1.close();

                }

};
class day_type
{
        int ch,dd,mm,dd1,mm1,dd2,mm2,session,no;
        int yy,yy1,yy2;
        public:
                int date_val(int);
                int date_val(int,int);
                int nod(int,int,int,int,int,int);
                //friend display(day_type,leave_type);

                day_type()
                {
                        cout<<"select day type::"<<endl<<endl;
                        cout<<"1.half day"<<endl;
                        cout<<"2.full day"<<endl;
                        cout<<"3.consecutive days"<<endl;
                        do{
                                cout<<endl<<"enter ur choice::";
                                cin>>ch;
                                int value;

                                switch(ch)
                                {
                                        case 1:cout<<"enter date - day, month, year::";
                                                cin>>dd>>mm>>yy;
                                                value=date_val(dd,mm);
                                                while(value==0)
                                                {
                                                        cout<<"invalid date entered...enter again..."<<endl;
                                                        cin>>dd;
                                                        value=date_val(dd,mm);
                                                }
                                                value=date_val(mm);
                                                while(value==0)
                                                {
                                                        cout<<"month should be between 1 and 12...enter again..."<<endl;
                                                        cin>>mm;
                                                        value=date_val(mm);
                                                }
                                                cout<<endl<<"enter session..."<<endl;
                                                cout<<endl<<"1.forenoon"<<endl;
                                                cout<<"2.afternoon"<<endl;
                                                cin>>session;
                                                if(session<1||session>2)
                                                {
                                                        cout<<"session wrongly entered...enter again";
                                                        cin>>session;
                                                }
                                                break;
                                        case 2:cout<<"enter date<dd/mm/yy>::";
                                                cin>>dd>>mm>>yy;
                                                value=date_val(dd,mm);
                                                while(value==0)
                                                {
                                                       cout<<"invalid date entered...enter again..."<<endl;
                                                        cin>>dd;
                                                        value=date_val(dd,mm);
                                                }
                                                value=date_val(mm);
                                                while(value==0)
                                                {
                                                        cout<<"month should be between 1 and 12...enter again..."<<endl;
                                                        cin>>mm;
                                                        value=date_val(mm);
                                                }
                                                break;
                                        case 3:cout<<"enter start date::";
                                                cin>>dd1>>mm1>>yy1;
                                                value=date_val(dd1,mm1);
                                                while(value==0)
                                                {
                                                        cout<<"invalid date entered...enter again..."<<endl;
                                                        cin>>dd1;
                                                        value=date_val(dd1,mm1);
                                                }
                                                value=date_val(mm1);
                                                while(value==0)
                                                {
                                                        cout<<"month should be between 1 and 12...enter again..."<<endl;
                                                        cin>>mm1;
                                                        value=date_val(mm1);
                                                }
                                                cout<<"enter end date::";
                                                cin>>dd2>>mm2>>yy2;
                                                value=date_val(mm2);
                                                value=date_val(dd2,mm2);
                                                while(value==0)
                                                {
                                                        cout<<"invalid date entered...enter again..."<<endl;
                                                        cin>>dd2;
                                                        value=date_val(dd2,mm2);
                                                }
                                                value=date_val(mm2);
                                                while(value==0)
                                                {
                                                        cout<<"month should be between 1 and 12...enter again..."<<endl;
                                                        cin>>mm2;
                                                        value=date_val(mm2);
                                                }
                                                while((yy1>yy2||(yy1==yy2&&(mm1>mm2||(mm1==mm2&&dd1>dd2)))))
                                                {
                                                        cout<<"enter valid dates....end date should be after start date...."<<endl;
                                                        cout<<"enter again....";
                                                        cout<<"enter start date::";
                                                        cin>>dd1>>mm1>>yy1;
                                                        value=date_val(dd1,mm1);
                                                        while(value==0)
                                                        {
                                                                cout<<"invalid date entered...enter again..."<<endl;
                                                                cin>>dd1;
                                                                value=date_val(dd1,mm1);
                                                        }
                                                        value=date_val(mm1);
                                                        while(value==0)
                                                        {
                                                                cout<<"month should be between 1 and 12...enter again..."<<endl;
                                                                cin>>mm1;
                                                                value=date_val(mm1);
                                                        }
                                                        cout<<"enter end date::";
                                                        cin>>dd2>>mm2>>yy2;
                                                        value=date_val(dd2,mm2);
                                                        while(value==0)
                                                        {
                                                                cout<<"invalid date entered...enter again..."<<endl;
                                                                cin>>dd2;
                                                                value=date_val(dd2,mm2);
                                                        }
                                                        value=date_val(mm2);
                                                        while(value==0)
                                                        {
                                                                cout<<"month should be between 1 and 12...enter again..."<<endl;
                                                                cin>>mm2;
                                                                value=date_val(mm2);
                                                        }/*
                                                        no=nod(dd1,mm1,yy1,dd2,mm2,yy2);
                                                        cout<<"diff="<<no<<endl;
                                                        if(no>10)
                                                        {
                                                                cout<<"leave for more than 10 days cannot be applied...."<<endl;
                                                                exit(0);
                                                        }*/
                                                }
                                                break;
                                        default:cout<<"day type wrongly entered...enter again..."<<endl;
                                }//end of switch

                        }while(ch<1||ch>3);
                        if(ch==3)
                        {
                                no=nod(dd1,mm1,yy1,dd2,mm2,yy2);
                                cout<<"diff="<<no<<endl;
                                if(no>10)
                                {
                                        cout<<"sorry...."<<endl<<"leave more than 10 days cannot be applied..."<<endl;
                                        cout<<"press any key to continue...";
                                        getch();
                                        schoice();
                                }
                        }

                        fstream file1;
                        file1.open("post1.txt",ios::in|ios::out|ios::app);
                        file1<<"DAY TYPE::";
                        switch(ch)
                        {
                                case 1:file1<<"half day"<<endl;
                                        file1<<"SESSION::";
                                        if(session==1)
                                                file1<<"forenoon"<<endl;
                                        else
                                                file1<<"afternoon"<<endl;
                                        file1<<"DATE::"<<dd<<"/"<<mm<<"/"<<yy<<endl;
                                        break;
                                case 2:file1<<"full day"<<endl;
                                        file1<<"DATE::"<<dd<<"/"<<mm<<"/"<<yy<<endl;
                                        break;
                                case 3:file1<<"consecutive days"<<endl;
                                        file1<<"FROM::"<<dd1<<"/"<<mm1<<"/"<<yy1<<"\tTO::"<<dd2<<"/"<<mm2<<"/"<<yy2<<endl;
                                        file1<<"NO. OF DAYS::"<<no<<endl;
                                        break;
                        }
                        file1.close();

               }//end of day_type()
               void disp();

};
int day_type::date_val(int mm)
{
        if(mm<1||mm>12)
                return 0;
        else
                return 1;
}

int day_type::date_val(int dd,int mm)
{
        switch(mm)
        {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:if(dd<1||dd>31)
                                return 0;
                        else
                                return 1;
                case 2:if(dd<1||dd>29)
                                return 0;
                        else
                                return 1;
                default:if(dd<1||dd>30)
                                return 0;
                        else
                                return 1;
        }
}

struct Date
{
        int d,m,y;
};

const int monthDays[12] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};

//Counts no of leap years before the given date
int countLeapYears(Date d)
{
        int years = d.y;
        // Check if the current year needs to be considered
        if (d.m <= 2)
                years--;
        // A year is a leap year if it is a multiple of 4, multiple of 400 and not a multiple of 100.
        return years / 4 - years / 100 + years / 400;
}

int getDifference(Date dt1, Date dt2)
{
      long int n1 = dt1.y*365 + dt1.d;
      for (int i=0;i<dt1.m-1;i++)
                n1 += monthDays[i];

        // Since every leap year is of 366 days, Add a day for every leap year
        n1 += countLeapYears(dt1);
        long int n2 = dt2.y*365 + dt2.d;
        for (int i=0; i<dt2.m - 1; i++)
                n2 += monthDays[i];
        n2 += countLeapYears(dt2);

        return (n2 - n1);
}

int day_type::nod(int dd1,int mm1,int yy1,int dd2,int mm2,int yy2)
{
        Date dt1 = {dd1,mm1,yy1};
        Date dt2 = {dd2,mm2,yy2};

        return getDifference(dt1,dt2);
}

void day_type::disp()

{
        cout<<"\t\tleave posted succesfully..."<<endl;
        cout<<"\t\t***THANK YOU***"<<endl<<endl;
}

void print()
{
        fstream file1("post1.txt",ios::in|ios::out);
        string line;
        while(!file1.eof())
        {
                getline(file1,line);
                cout<<line<<endl;
        }
}

int lmain()
{
        char ch;
        leave l;
        leave_type s;
        day_type d;
        d.disp();

        cout<<"Do u want to print the posted leave?<y/n>";
        cin>>ch;
        system("cls");
        if(ch=='y'||ch=='Y')
        {
                print();
                getch();
                schoice();
        }
        else
//                exit(0);
            schoice();
}

//cgpa

class cgpa
{
        char name[20],rno[6];
        int gp[10][8];
        char sub[8][70];

        int tcu,tqp,qp[8];
        float gpa,cgp;

        public:
                cgpa(int);
                void in(int);
                void calc(int[][8],int);
                void disp();
};

cgpa::cgpa(int sem)
{

        cout<<"enter name::";
        cin>>name;
        cout<<"enter roll number::";
        cin>>rno;
        fstream file;
        file.open("cgpa1.txt",ios::in|ios::out|ios::app);
       if(!file.is_open())
        {
            cout<<"error while opening file"<<endl;
        }
        else
        {
                cout<<"file opened successfully"<<endl<<endl;
                file<<"\t\tCGPA CALCULATION:"<<endl<<endl;
                file<<"NAME:"<<name<<endl;
                file<<"ROLL NUMBER:"<<rno<<endl;
                file<<"SEMESTER:"<<sem<<endl<<endl;
                file.close();
        }
}
void gpa_valid(char sub[][70],int gp[][8],int sem)
{
        for(int i=0;i<8;i++)
        {
            while(gp[sem][i]<5||gp[sem][i]>10)
            {
                cout<<"gpa should be between 5 and 10..."<<endl;
                cout<<"enter for::\t"<<sub[i];
                cin>>gp[sem][i];
            }
        }
}
void put(char sub[][70],int gp[][8],int sem)
{
        fstream file("cgpa1.txt",ios::in|ios::out|ios::app);
        file<<"\t\tMARK STATEMENT:"<<endl<<endl;
        for(int i=0;i<8;i++)
        {
                file<<sub[i]<<gp[sem][i]<<endl;
        }
        file.close();
}
void fn1(char sub[][70],int gp[][8])
{
        cout<<"Enter your grade points for the particular subjects::"<<endl;
        strcpy(sub[0],"Calculus And Its Applications::");
        cout<<sub[0];
        cin>>gp[0][0];
        strcpy(sub[1],"English For Professional Skills::");
        cout<<sub[1];
        cin>>gp[0][1];
        strcpy(sub[2],"Applied Physics::");
        cout<<sub[2];
        cin>>gp[0][2];
        strcpy(sub[3],"Digital System Design::");
        cout<<sub[3];
        cin>>gp[0][3];
        strcpy(sub[4],"Problem Solving And C Programming::");
        cout<<sub[4];
        cin>>gp[0][4];
        strcpy(sub[5],"Mathematical Foundations Lab::");
        cout<<sub[5];
        cin>>gp[0][5];
        strcpy(sub[6],"C Programming Lab::");
        cout<<sub[6];
        cin>>gp[0][6];
        strcpy(sub[7],"Applied Physics Lab::");
        cout<<sub[7];
        cin>>gp[0][7];
        gpa_valid(sub,gp,0);
        put(sub,gp,0);
}

void fn2(char sub[][70],int gp[][8])
{
        cout<<"Enter your grade points for the particular subjects::"<<endl;
        strcpy(sub[0],"Discrete Structures::");
        cout<<sub[0];
        cin>>gp[1][0];
        strcpy(sub[1],"Algebra And Number Theory::");
        cout<<sub[1];
        cin>>gp[1][1];
        strcpy(sub[2],"Data Structures::");
        cout<<sub[2];
        cin>>gp[1][2];
        strcpy(sub[3],"Object Oriented Programming::");
        cout<<sub[3];
        cin>>gp[1][3];
        strcpy(sub[4],"Computer Architecture::");
        cout<<sub[4];
        cin>>gp[1][4];
        strcpy(sub[5],"Data Structures Lab::");
        cout<<sub[5];
        cin>>gp[1][5];
        strcpy(sub[6],"Object Computing Lab::");
        cout<<sub[6];
        cin>>gp[1][6];
        strcpy(sub[7],"Python Programming Lab::");
        cout<<sub[7];
        cin>>gp[1][7];
        gpa_valid(sub,gp,1);
        put(sub,gp,1);
}


void fn3(char sub[][70],int gp[][8])
{
        cout<<"Enter your grade points for the particular subjects::"<<endl;
        strcpy(sub[0],"Probability And Statistics::");
        cout<<sub[0];
        cin>>gp[2][0];
        strcpy(sub[1],"Microcontrollers And Embedded Systems::");
        cout<<sub[1];
        cin>>gp[2][1];
        strcpy(sub[2],"Linear Algebra::");
        cout<<sub[2];
        cin>>gp[2][2];
        strcpy(sub[3],"Database Design::");
        cout<<sub[3];
        cin>>gp[2][3];
        strcpy(sub[4],"Design And Analysis Of Algorithms::");
        cout<<sub[4];
        cin>>gp[2][4];
        strcpy(sub[5],"Embedded Systems Lab::");
        cout<<sub[5];
        cin>>gp[2][5];
        strcpy(sub[6],"Design And Analysis Of Algorithms Lab::");
        cout<<sub[6];
        cin>>gp[2][6];
        strcpy(sub[7],"Database Design Lab::");
        cout<<sub[7];
        cin>>gp[2][7];
        gpa_valid(sub,gp,2);
        put(sub,gp,2);
}
void fn4(char sub[][70],int gp[][8])
{
        cout<<"Enter your grade points for the particular subjects::"<<endl;
        strcpy(sub[0],"Optimization Techniques::");
        cout<<sub[0];
        cin>>gp[3][0];
        strcpy(sub[1],"Computer Networks::");
        cout<<sub[1];
        cin>>gp[3][1];
        strcpy(sub[2],"Operating Systems::");
        cout<<sub[2];
        cin>>gp[3][2];
        strcpy(sub[3],"Cryptography::");
        cout<<sub[3];
        cin>>gp[3][3];
        strcpy(sub[4],"Hardware Security::");
        cout<<sub[4];
        cin>>gp[3][4];
        strcpy(sub[5],"Computer Networks Lab::");
        cout<<sub[5];
        cin>>gp[3][5];
        strcpy(sub[6],"Operating Systems Lab::");
        cout<<sub[6];
        cin>>gp[3][6];
        strcpy(sub[7],"Java Programming Lab::");
        cout<<sub[7];
        cin>>gp[3][7];
        gpa_valid(sub,gp,3);
        put(sub,gp,3);
}
void fn5(char sub[][70],int gp[][8])
{
        cout<<"Enter your grade points for the particular subjects::"<<endl;
        strcpy(sub[0],"Network Security::");
        cout<<sub[0];
        cin>>gp[4][0];
        strcpy(sub[1],"Web Engineering::");
        cout<<sub[1];
        cin>>gp[4][1];
        strcpy(sub[2],"Machine Learning::");
        cout<<sub[2];
        cin>>gp[4][2];
        strcpy(sub[3],"Compilers And Program Analysis ::");
        cout<<sub[3];
        cin>>gp[4][3];
        strcpy(sub[4],"Professional Elective I::");
        cout<<sub[4];
        cin>>gp[4][4];
        strcpy(sub[5],"Windows System Programming Lab::");
        cout<<sub[5];
        cin>>gp[4][5];
        strcpy(sub[6],"Web Engineering Lab::");
        cout<<sub[6];
        cin>>gp[4][6];
        strcpy(sub[7],"Ethical Hacking Lab::");
        cout<<sub[7];
        cin>>gp[4][7];
        gpa_valid(sub,gp,4);
        put(sub,gp,4);
}
void fn6(char sub[][70],int gp[][8])
{
        cout<<"Enter your grade points for the particular subjects::"<<endl;
        strcpy(sub[0],"Cloud Security::");
        cout<<sub[0];
        cin>>gp[5][0];
        strcpy(sub[1],"Ubiquitous Computing::");
        cout<<sub[1];
        cin>>gp[5][1];
        strcpy(sub[2],"Cyber Security Analytics::");
        cout<<sub[2];
        cin>>gp[5][2];
        strcpy(sub[3],"Secure Coding::");
        cout<<sub[3];
        cin>>gp[5][3];
        strcpy(sub[4],"Professional Elective II::");
        cout<<sub[4];
        cin>>gp[5][4];
        strcpy(sub[5],"Cloud Security Lab::");
        cout<<sub[5];
        cin>>gp[5][5];
        strcpy(sub[6],"Cyber Security Analytics And Visualization Lab::");
        cout<<sub[6];
        cin>>gp[5][6];
        strcpy(sub[7],"Distributed Computing Lab::");
        cout<<sub[7];
        cin>>gp[5][7];
        gpa_valid(sub,gp,5);
        put(sub,gp,5);
}

void fn7(char sub[][70],int gp[][8])
{
        cout<<"Enter your grade points obtained in::"<<endl;
        strcpy(sub[0],"PROJECT WORK 1-INDUSTRY/RESEARCH PROJECT::");
        cout<<sub[0];
        cin>>gp[6][0];

        while(gp[6][0]<5||gp[6][0]>10)
        {
        cout<<"gpa should be between 5 and 10..."<<endl;
        cout<<"enter for::\t"<<sub[0];
        cin>>gp[6][0];
        }

        fstream file("cgpa1.txt",ios::in|ios::out|ios::app);
        file<<"\t\tMARK STATEMENT:"<<endl<<endl;
        file<<sub[0]<<gp[6][0]<<endl;
        file.close();


}

void fn8(char sub[][70],int gp[][8])
{
        cout<<"Enter your grade points for the particular subjects::"<<endl;
        strcpy(sub[0],"Software Security And Exploitation::");
        cout<<sub[0];
        cin>>gp[7][0];
        strcpy(sub[1],"Mobile Security::");
        cout<<sub[1];
        cin>>gp[7][1];
        strcpy(sub[2],"Data Privacy::");
        cout<<sub[2];
        cin>>gp[7][2];
        strcpy(sub[3],"Professional Elective III::");
        cout<<sub[3];
        cin>>gp[7][3];
        strcpy(sub[4],"Open Elective I::");
        cout<<sub[4];
        cin>>gp[7][4];
        strcpy(sub[5],"Software Security And Exploitation Lab::");
        cout<<sub[5];
        cin>>gp[7][5];
        strcpy(sub[6],"Mobile Security Lab::");
        cout<<sub[6];
        cin>>gp[7][6];
        strcpy(sub[7],"Malware Analysis Lab::");
        cout<<sub[7];
        cin>>gp[7][7];
        gpa_valid(sub,gp,7);
        put(sub,gp,7);

}
void fn9(char sub[][70],int gp[][8])
{
        cout<<"Enter your grade points for the particular subjects::"<<endl;
        strcpy(sub[0],"Threat Hunting::");
        cout<<sub[0];
        cin>>gp[8][0];
        strcpy(sub[1],"Cryptoeconomics::");
        cout<<sub[1];
        cin>>gp[8][1];
        strcpy(sub[2],"Computer Forensics::");
        cout<<sub[2];
        cin>>gp[8][2];
        strcpy(sub[3],"Professional Elective IV::");
        cout<<sub[3];
        cin>>gp[8][3];
        strcpy(sub[4],"Open Elective II::");
        cout<<sub[4];
        cin>>gp[8][4];
        strcpy(sub[5],"Threat Hunting Lab::");
        cout<<sub[5];
        cin>>gp[8][5];
        strcpy(sub[6],"Computer Forensics Lab::");
        cout<<sub[6];
        cin>>gp[8][6];
        strcpy(sub[7],"Security Capstone Lab::");
        cout<<sub[7];
        cin>>gp[8][7];
        gpa_valid(sub,gp,8);
        put(sub,gp,8);

}

void fn10(char sub[][70],int gp[][8])
{
        cout<<"Enter your grade points obtained in::"<<endl;
        strcpy(sub[0],"PROJECT WORK 2-INDUSTRY/RESEARCH PROJECT::");
        cout<<sub[0];
        cin>>gp[9][0];

        while(gp[9][0]<5||gp[9][0]>10)
        {
        cout<<"gpa should be between 5 and 10..."<<endl;
        cout<<"enter for::\t"<<sub[0];
        cin>>gp[9][0];
        }

        fstream file("cgpa1.txt",ios::in|ios::out|ios::app);
        file<<"\t\tMARK STATEMENT:"<<endl<<endl;
        file<<sub[0]<<gp[9][0]<<endl;
        file.close();


}

void cgpa::in(int sem)
{
        switch(sem)
        {
                case 1:fn1(sub,gp);
                        break;
                case 2:fn2(sub,gp);
                        break;
                case 3:fn3(sub,gp);
                        break;
                case 4:fn4(sub,gp);
                        break;
                case 5:fn5(sub,gp);
                        break;
                case 6:fn6(sub,gp);
                        break;
                case 7:fn7(sub,gp);
                        break;
                case 8:fn8(sub,gp);
                        break;
                case 9:fn9(sub,gp);
                        break;
                case 10:fn10(sub,gp);
                        break;
        }
}

float cg(float gpa,int sem)
{
        float old,part,cgp;
        cout<<endl<<"gpa::"<<setprecision(3)<<gpa<<endl;
        cout<<"enter your old cgpa(till last sem)::";
        cin>>old;
        if(gpa==old)
                cgp=gpa;
        else if(gpa>old)
        {
                part=(gpa-old)/sem;
                cgp=old+part;
        }
        else
        {
                part=(old-gpa)/sem;
                cgp=old-part;
        }
        return cgp;
}


void cgpa::calc(int cu[][8],int sem)
{
        int i;
        tcu=0;
        tqp=0;
//      float cgp;
        for(i=0;i<8;i++)
        {
                tcu=tcu+cu[sem-1][i];
                qp[i]=cu[sem-1][i]*gp[sem-1][i];
                tqp=tqp+qp[i];
        }
        gpa=1.0*tqp/tcu;
        if(sem>1&&sem<=10)
                cgp=cg(gpa,sem);
        else if(sem==1)
                cgp=gpa;
        fstream file("cgpa1.txt",ios::in|ios::out|ios::app);
        file<<endl<<"GPA:"<<setprecision(3)<<gpa<<endl;
        file<<"CGPA:"<<setprecision(3)<<cgp<<endl<<endl;

}

void cgpa::disp()
{
        cout<<endl<<endl<<"name::"<<name<<endl;
        cout<<"roll number::"<<rno<<endl<<endl;
        cout<<"grade point average::"<<setprecision(3)<<gpa<<endl;
        cout<<"Cumulative grade point average::"<<setprecision(3)<<cgp<<endl<<endl;
}

int cmain()
{
        int cu[10][8]={{4,4,4,3,3,2,2,2},{3,4,4,3,3,2,2,2},{4,4,3,4,3,2,2,2},{4,3,3,3,3,2,2,2},{4,4,3,3,4,2,2,2},{4,3,3,3,4,2,2,2},{12,0,0,0,0,0,0,0},{3,3,3,4,4,2,2,2},{3,3,3,4,4,2,2,2},{12,0,0,0,0,0,0,0}};

        system("cls");
        int sem;
        cout<<setw(50)<<"CGPA CALCULATOR"<<endl<<endl;
        cout<<"enter semester::";
        cin>>sem;//do validation
        //while(sem<1||sem>10)
        while(sem<1||sem>10)
        {
                cout<<"Invalid....Enter valid sem::";
                cin>>sem;
        }
        cgpa c(sem);
                c.in(sem);
                c.calc(cu,sem);
                c.disp();
                getch();
                schoice();

}

void quit()
{
    system("cls");
    gotoxy(28,15);
    cout<<"CPP PACKAGE"<<endl;
    gotoxy(28,17);
    cout<<"E.Preetham Bavan    21pc22"<<endl;;
    gotoxy(28,19);
    cout<<"A.Dharshaan      21pc08"<<endl;
    gotoxy(28,21);
    cout<<"Package Topic::  STUDENTS PORTAL"<<endl;
    gotoxy(28,23);
    cout<<"Thank you...:)"<<endl;
    getch();
    exit(0);
}

void schoice()
{
    system("cls");
    for(li=30;li<=50;li++)
    {
        gotoxy(li,14);
        Sleep(30);
        printf("*");

    }

    for(li=50;li>=30;li--)
    {
        gotoxy(li,30);
        Sleep(30);
        printf("*");
    }

    for(lp=15;lp<30;lp++)
    {
        gotoxy(30,lp);
        Sleep(100);
        printf("|");
    }

    for(lp=29;lp>=15;lp--)
    {
        gotoxy(50,lp);
        Sleep(100);
        printf("|");
    }

    gotoxy(15,10);
    printf("what do you want to do?\n");
    gotoxy(35,16);

    printf("L:LEAVE");
    gotoxy(35,19);
    printf("C:CGPA");
    gotoxy(35,22);
    printf("F:FEE ");
    gotoxy(35,25);
    printf("H: HELP");
    gotoxy(35,28);
    printf("Q: QUIT");

    choice=getch();
    ch=toupper(choice);
    switch(ch)
    {
        case'L':lmain();
                break;
        case'C':cmain();
                break;
        case'F':mainmenu();
                break;
        case'H':help();
                break;
        case'Q':quit();
                break;
        default:gotoxy(33,40);
        cout<<"Illegal Choice"<<endl;
        cout<<"\tPress any key to return to Main Menu";
        getch();
        schoice();

}
}

// MAIN FUNCTION TO DISPLAY MENU AND CALL OTHER FUNCTIONS

int main()
{
    FEE fee;
//    fee.ADDITION();

    system("cls");
    for(i=10;i<71;i++)
    {
        gotoxy(i,15);
        Sleep(30);
        cout<<"/";
    }
    for(i=70;i>=10;i--)
    {
        gotoxy(i,22);
        Sleep(30);
        cout<<" / ";
    }
    for(j=16;j<=21;j++)
    {
        gotoxy(10,j);
        Sleep(100);
        cout<<"-";
    }
    for(j=21;j>=16;j--)
    {
        gotoxy(70,j);
        Sleep(100);
        cout<<"-";
    }
        gotoxy(16,17);
        cout<<"\tPSG TECH :: STUDENTS' PORTAL";
        gotoxy(12,20);
        cout<<"Press Any Key To Continue........";
        getch();
        //screen waits until input is got
        schoice();
//        mainmenu();
        return 0;
}
