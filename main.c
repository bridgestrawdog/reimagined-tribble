//Header files
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "function_prototypes.h"
#include "librarian.h"
#include "student.h"
#include "books.h"
//-----------------------------Main Interface functions-----------------------------------------------------
int main(){
FILE *login;
char findBook;
char choice;
char password[10];
int x = 15;
    SetConsoleTitle("Library Information System");
    system("cls");
    window();
    gotoxy(34,4);printf("Login Area");
    gotoxy(20,10);printf("1. Librarian");
    gotoxy(45,10);printf("2. Student");
    gotoxy(20,12);printf("3. Developer Info");
    gotoxy(45,12);printf("9. Exit");
    gotoxy(15,23);printf("Enter your choice: ");
    choice  = getche(); // input from keyboard
    system("cls");      //used to clear windows
    window();           // for title message
    switch(choice)
    {
    case '1':
    pass(); lib_main();
    break;

    case '2':
    student_pass();
    break;

    case '3':
    developer_info();
    break;

    case '9':
    finish();
    break;

    default :
    gotoxy(20,17);printf("Could not verify input. Please try again");
    main();
    };
    return 0;
}

//-----------------------------General Function-----------------------------------------------------
COORD coord = {0,0}; ///set the cordinate to 0, 0 (top-left corner of window);
int gotoxy(int x, int y){
    coord.X = x; coord.Y = y; /// X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int developer_info(){       // function to show dev info
    system("cls"); window();
    gotoxy(20,6);printf("Design and Developed by....");
    gotoxy(25,8);printf("George Strawbridge");
    gotoxy(25,9);printf("School of Computing");
    gotoxy(25,10);printf("University of Leeds");
    getch(); main();
}

int window(){          // function for show software info altime
    gotoxy(15,1); printf("*****Library Information System*****");
    gotoxy(5,2);printf("________________________________________________________");
 }


int finish(){          // function to Exit Message
    char choice;
    int x = 15;
    system("cls"); window();
    gotoxy(16,11);printf("Are you sure wanna Exit (Y/N): ");
    choice  = getche();
    if(choice == 'n' || choice == 'N'){
    system("cls");window(); main();
    }
    else{
    system("cls"); window();
    gotoxy(15,9);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(15,14);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(33,11);printf("Thank You");
    gotoxy(21,12);printf("Department of Software Enginnering");
    gotoxy(x,21);printf("Exiting in 3 second...........>");
    Sleep(3000);
    exit(0);
    }
}









int get_password(char* pass){  // function for Password
    char temp_passP[25];
    int i=0;
     while(1)
    {
            temp_passP[i]=getch();
            if(temp_passP[i]==13){break;}
            else if(temp_passP[i]==8)
            {
                if(i!=0) {
                printf("\b \b");
                i--;
                } else {printf("\a");}
            }
            else
            {
                printf("*");
                *(pass+i) = temp_passP[i];
                i++;
            }
             *(pass+i)='\0';
     }
}
//--------------------------------------------------------------------------------------------








































