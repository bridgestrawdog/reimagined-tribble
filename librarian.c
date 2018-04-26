int lib_main(void){
    char choice;
    system("cls"); window();
    gotoxy(32,4);printf("Librarian Workspace");
    gotoxy(15,10);printf("1. Book Info");
    gotoxy(35,10);printf("2. Student Info");
    gotoxy(15,12);printf("3. Student Password");
    gotoxy(55,10);printf("8. Back");
    gotoxy(55,12);printf("9. Exit");
    gotoxy(15,23);printf("Enter your choice: ");
    choice  = getche();

    switch(choice)
    {
    case '1':
    lib_main_book();
    break;

    case '2':
    lib_main_student();
    break;

    case '3':
    change_lib_pass();
    break;

    case '8':
    main();
    break;

    case '9':
    finish();
    break;

    default :
    lib_main();
    };
}

int lib_main_book(void){
    int x = 15;
    char choice;
    while(1){
        system("cls");
        window();
        gotoxy(35,4);printf("Librarian Area");
        gotoxy(x,6);printf("1. Add Book");
        gotoxy(x,8);printf("2. Search Book");
        gotoxy(x,10);printf("3. Modify Book Record");
        gotoxy(x,12);printf("4. Delete Book Record");
        gotoxy(x,14);printf("5. View book list");
        gotoxy(x,20);printf("8. Back");
        gotoxy(25,20);printf("9. Exit");
        gotoxy(x,23);printf("Enter your choice: ");
        choice  = getche();

        switch(choice){
            case '1':
                add_books();
                break;
            case '2':
                search_books();
                break;
            case '3':
                edit_books();
                break;
            case '4':
                delete_books();
                break;
            case '5':
                view_books();
                break;
            case '8':
                system("cls"); lib_main();
                break;
            case '9':
                finish();
                break;
            default:
                break;
        };
    };

}

int lib_main_student(void){
    int x = 15;
    char choice;
    while(1){
	system("cls"); window();
        gotoxy(35,4);printf("Librarian Area");
        gotoxy(x,6);printf("1. Add Student");
        gotoxy(x,8);printf("2. Search Student");
        gotoxy(x,10);printf("3. Modify Student Record");
        gotoxy(x,12);printf("4. Delete Student Record");
        gotoxy(x,14);printf("5. View All Students");
        gotoxy(x,20);printf("8. Back");
        gotoxy(25,20);printf("9. Exit");
        gotoxy(x,23);printf("Enter your choice: ");
        choice  = getche();
        switch(choice){
            case '1':
                add_student();
                break;
            case '2':
                search_student();
                break;
            case '3':
                edit_student();
                break;
            case '4':
                delete_student();
                break;
            case '5':
                view_student();
                break;
            case '8':
                lib_main();
                break;
            case '9':
                finish();
                break;
            default:
                break;
        };
    };
}

int change_lib_pass(){    // function for librarian Password change
    char password[10];
    system("cls"); window();
    FILE *login;
    char old_pass[10], new_pass[10];
    gotoxy(15,10);printf("Enter Old password: ");
    get_password(old_pass);
    gotoxy(15,12);printf("Enter New password: ");
    get_password(new_pass);
    login = fopen("password.dat","rb+");
    while(fread(&password,sizeof(password),1,login)==1){
        if(strcmp(old_pass,password)==0){
            strcpy(password,new_pass);
            fseek(login,-sizeof(password),SEEK_CUR);
            fwrite(&password,sizeof(password),1,login);
            fclose(login);
            gotoxy(15,15);printf("Password sucessfully changed! ");
        }else{
            gotoxy(15,15);printf("Password changing process failed!");
        }
    }
    gotoxy(15,23);printf("press any key to go back..");
    getch(); system("cls"); window(); lib_main();
}

int lib_signup(){     // function for save librarian Pass
    FILE *login;
    int x = 15;
    char password[10];
    char temp[10];
    login = fopen("password.dat","wb");
    gotoxy(10,10);printf("Enter password: ");
    get_password(password);
    gotoxy(10,11);printf("Re Enter Password: ");
    get_password(temp);
    while(strcmp(password,temp)!=0){
        gotoxy(10,10);printf("Password did not matched! Enter again");
        gotoxy(10,11);printf("Enter password: ");
        get_password(password);
        gotoxy(10,12);printf("Re Enter Password: ");
        get_password(temp);
        system("cls");
    }
    fwrite(&password,sizeof(password),1,login);
    fclose(login);
    system("cls"); window();
}


int lib_signin(){     // function for librarian Login part
    FILE *login;
    int x = 15;
    char password[10];
    char temp[10];
    login = fopen("password.dat","rb");
    gotoxy(15,10);printf("Enter password: ");
    get_password(temp);
    while(fread(&password, sizeof(password),1,login)==1){
        while(strcmp(temp,password)!=0){
            system("cls"); window();
            gotoxy(15,10); printf("Password did not match!---Enter Again: ");
            get_password(temp);
        }
        gotoxy(15,12);printf("Password Match");
        break;
    }
    fclose(login);
    Sleep(1000);
    system("cls");window();
}

int pass(){            // function for librarian Password
    FILE *login;
    login = fopen("password.dat","rb");
    if(login == NULL){
        gotoxy(10,9);printf("Unable to find librarian info in database. Sign up to become a librarian now.");
        lib_signup();
    }else{
        lib_signin();
    }
}
