int student_main(void){
    char choice;
    int x = 15;
    while(1){
        system("cls"); window();
        gotoxy(35,4);printf("You are logged in as a student");
        gotoxy(x,6);printf("1. View Book List");
        gotoxy(x,8);printf("2. Search Book");
        gotoxy(x,10);printf("3. View All Student info");
        gotoxy(x,20);printf("8. Back");
        gotoxy(25,20);printf("9. Exit");
        gotoxy(x,23);printf("Enter your choice: ");
        choice  = getche();

        switch(choice){
            case '1':
                view_books();
                break;
            case '2':
                search_books();
                break;
            case '3':
                view_student();
                break;
            case '8':
                system("cls");
                main();
                break;
            case '9':
                finish();
                break;
            default:
                main();
                break;
        };
    };
}

int student_pass(){          // function for student Password
    system("cls"); window();
    gotoxy(15,7);printf("To Enter the Library you need a pass");
    gotoxy(15,9);printf("Do you have a library pass?(Y/N): ");
    if(getch()=='n'){
    gotoxy(15,10);printf("Please contact the librarian to sign up if you don't have a pass");
    getch(); system("cls"); window(); main();
    }
    else
    {
    student_pass();
    }
}

//------------------------------Student Releted Function for Librarian-----------------------------------------------------
struct STUDENT             //Structure variable for student
{
    int id;
    char name[20];
    char pass[20];
    int mobile;
    float fee;
    int age;
    char *cat;
};
struct STUDENT student;

char catagories_u[][15]={"Student","Teacher","Others"};

int add_student(void){    //funtion for adding student
	FILE *fp;
	int i, choice, x = 15;
	system("cls");window();
	add_window_u();
	gotoxy(x,19);printf("Enter your choice:");scanf("%d", &choice);
	if(choice==7)
        lib_main_student() ;
	system("cls");window();
	fp = fopen("uRecord.dat","ab+");
	if(get_data_student(choice) == 1){
        student.cat=catagories_u[choice-1];
        fseek(fp,0,SEEK_END);
        fwrite(&student,sizeof(student),1,fp);
        fclose(fp);
        gotoxy(x,17);printf("The record is sucessfully saved");
        gotoxy(x,19);printf("Save any more?(Y / N):");
        if(getch()=='n'){
            system("cls"); window(); lib_main_student();
        }else{
            add_student();
        }
    }
    fclose(fp);
}

int get_data_student(int choice)
{
    int x = 15;
    int x1 = 30;
	int studentID;
	gotoxy(x,7);printf("Enter the Information Below");
	gotoxy(x,9);printf("Category:");  gotoxy(x1,9);printf("%s",catagories_u[choice-1]);
	gotoxy(x,10);printf("Student ID:");  gotoxy(x1,10);scanf("%d",&studentID);

            if(student.id==studentID){
                gotoxy(x,11);printf("Id is already Exits");
                getch(); add_student;
                }

	student.id=studentID;
	gotoxy(x,11);printf("Student Name:");  gotoxy(x1,11);scanf("%s",&student.name);
	gotoxy(x,12);printf("Password:");gotoxy(x1,12);scanf("%s",&student.pass);
	gotoxy(x,13);printf("Mobile:");     gotoxy(x1,13);scanf("%d",&student.mobile);
	gotoxy(x,14);printf("Fee:");        gotoxy(x1,14);scanf("%f",&student.fee);
	gotoxy(x,15);printf("Age:");        gotoxy(x1,15);scanf("%d",&student.age);
	return 1;
}

int checkid_student(int t)      //Function to check ID is exist or not
{
    FILE *temp;
	temp = fopen("uRecord.dat","rb+");
	while(fread(&student,sizeof(student),1,temp)==1)
        if(student.id == t){
            fclose(temp);
            return 0;
        }
        fclose(temp);
        return 1;

}

int edit_student()       //Function to Edit student info
{
    int x = 15;
    system("cls");window();
	FILE *fp;
	int c=0,d;
	gotoxy(27,6);printf("****Edit Student Section****");
	while(1)
	{
		gotoxy(x,8);printf("Enter Librarian Id to edit:");scanf("%d",&d);
		fp=fopen("uRecord.dat","rb+");
		while(fread(&student,sizeof(student),1,fp)==1)
		{
			if(checkid_student(d)==0)
			{
				gotoxy(x,9);printf("The Librarian is availble");
				gotoxy(x,10);printf("The Librarian ID:%d",student.id);
				gotoxy(x,11);printf("New Name:");scanf("%s",student.name);
				gotoxy(x,12);printf("Password:");scanf("%s",student.pass);
				gotoxy(x,13);printf("New Mobile:");scanf("%d",&student.mobile);
				gotoxy(x,14);printf("New Fee:");scanf("%f",&student.fee);
				gotoxy(x,15);printf("New Age:");scanf("%d",&student.age);
				gotoxy(x,16);printf("The record is modified");
				fseek(fp,ftell(fp)-sizeof(student),0);
				fwrite(&student,sizeof(student),1,fp);
				fclose(fp);
				c=1;
			}
			if(c==0)
			{
				gotoxy(x,11);printf("No record found");
			}
		}

    gotoxy(x,18);printf("Modify another Record?(Y/N)");
    if(getch()=='y'){
        edit_student();
    }
    else
        lib_main_student();
	}
}

int search_student(){    //Function to search student
    int x = 15;
    system("cls");window();
    gotoxy(27,7);printf("******Search Student******");
    gotoxy(x,10);printf("1. Search By ID");
    gotoxy(x,12);printf("2. Search By Name");
    gotoxy(x,14);printf("Enter Your Choice: ");
    switch(getch())
    {
        case '1':
            searchBy_student_ID();
            break;
        case '2':
            searchBy_student_Name();
            break;
        default :
            getch(); search_student();
    }
}

int searchBy_student_ID(){      //Function to search Student by given ID
    system("cls");window();
    int x = 15;
    int id; FILE *fp;
    gotoxy(27,7);printf("****Search Student By Id****");
    gotoxy(x,9);printf("Enter student id:");scanf("%d",&id);
    int find_student = 0;
    fp = fopen("studentRecord.dat","rb");
    while(fread(&student,sizeof(student),1,fp)==1){
        if(student.id==id){
            Sleep(2);
            gotoxy(x,11);printf("The student is available");
            gotoxy(x,13);printf("\xB2 ID:%d",student.id);
            gotoxy(x,14);printf("\xB2 Name:%s",student.name);
            gotoxy(x,15);printf("\xB2 Password:%s ",student.pass);
            gotoxy(x,16);printf("\xB2 Mobile:%d ",student.mobile);
            gotoxy(x,17);printf("\xB2 Fee:%.2f",student.fee);
            gotoxy(x,18);printf("\xB2 Age:%d ",student.age);

            find_student = 1;
        }
    }
    if(find_student == 0){  //checks whether conditiion enters inside loop or not
        gotoxy(x,12);printf("\aNo Record Found");
    }
    fclose(fp);
    gotoxy(x,20);printf("Try another search?(Y/N)");
    if(getch()=='y')
        searchBy_student_ID();
    else
        lib_main_student();
}

int searchBy_student_Name(){    //Function to search student by using Books name
    system("cls");window();
    int x = 15;
    char s[15];
    int d=0;
    FILE *fp;
    gotoxy(27,7);printf("****Search Student By Name****");
    gotoxy(x,9);printf("Enter Student Name:");scanf("%s",s);
    fp = fopen("uRecord.dat","rb");
    while(fread(&student,sizeof(student),1,fp)==1){
        if(strcmp(student.name,(s))==0){ //checks whether student.name is equal to s or not
            gotoxy(x,11);printf("The Student is available");
            gotoxy(x,13);printf("\xB2 ID:%d",student.id);
            gotoxy(x,14);printf("\xB2 Name:%s",student.name);
            gotoxy(x,15);printf("\xB2 Password:%s",student.pass);
            gotoxy(x,16);printf("\xB2 Mobile:%d",student.mobile);
            gotoxy(x,17);printf("\xB2 Fee:%.2f",student.fee);
            gotoxy(x,18);printf("\xB2 Age:%d ",student.age);

            d++;
        }
    }
    if(d==0){

        gotoxy(x,12);printf("\aNo Record Found");
    }
    fclose(fp);
    gotoxy(x,20);printf("Try another search?(Y/N)");
    if(getch()=='y')
        searchBy_student_Name();
    else
        lib_main_student();
}

int delete_student(){    //function that delete  record form Database
    system("cls");window();
    FILE *ft,*fp;
    char another;
    int x = 15;
    int d,find_student = 0;
    while(another = 'y'){  //infinite loop
        gotoxy(25,7);printf("********STUDENT DELETE********");
        gotoxy(x,9);printf("Enter the Student ID to  delete:");
        scanf("%d",&d);
        fp = fopen("uRecord.dat","rb+");
        while(fread(&student,sizeof(student),1,fp)==1){
            if(student.id==d){
                gotoxy(x,11);printf("The student record is available");
                gotoxy(x,13);printf("Student name is %s",student.name);
                gotoxy(x,14);printf("AGE. is %d",student.age);
                find_student = 1;
                gotoxy(x,16);printf("Do you want to delete it?(Y/N):");
                if(getch()=='y'){
                    ft=fopen("utest.dat","wb");  //temporary file for delete
                    rewind(fp);
                    while(fread(&student,sizeof(student),1,fp)==1){
                        if(student.id!=d){
                            fwrite(&student,sizeof(student),1,ft); //write all in tempory file except that
                        }                              //we want to delete
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("uRecord.dat");
                    rename("utest.dat","uRecord.dat"); //copy all item from temporary file to fp except that
                                        //we want to delete
                    gotoxy(x,17);printf("The record is sucessfully deleted");
                }
            }
        }
        if(find_student == 0){
            gotoxy(x,11);printf("No record is found");
        }

        gotoxy(x,18);printf("Delete another record?(Y/N)");
        if(getch()=='y'){
            delete_student();
        }
        else
            lib_main_student();
    }
}

int view_student()   //I use this function to view all student info
{
    int j;
    system("cls");window();
    FILE *fp;
    gotoxy(5,5);printf("*********************************Student List****************************");
    gotoxy(5,6);printf(" CATEGORY    ID   STUDENT NAME    Password     MOBILE       Age       Fee");
    j=8;
    fp=fopen("uRecord.dat","rb");
    while(fread(&student,sizeof(student),1,fp)==1){
        gotoxy(5,j);printf("%s",student.cat);
        gotoxy(17,j);printf("%d",student.id);
        gotoxy(24,j);printf("%s",student.name);
        gotoxy(38,j);printf("%s",student.pass);
        gotoxy(45,j);printf("%d",student.mobile);
        gotoxy(61,j);printf("%d",student.age);
        gotoxy(71,j);printf("%.2f",student.fee);
        printf("\n\n");
        j++;
    }
    fclose(fp);
    getch();system("cls");window();
}
//--------------------------------------------------------------------------------------------

//--------------------------------------Student Interface Functon---------------------------------------
int student_pass_remove(){    //function that delete  record form Database
    system("cls"); window();
    FILE *ft,*fp;
    int d,find_student = 0;
    int x = 15;
    while(1){  //infinite loop
        gotoxy(25,7);printf("****Student Login****");
        gotoxy(x,9);printf("Enter Student ID:");
        scanf("%d",&d);
        fp = fopen("uRecord.dat","rb+");
        while(fread(&student,sizeof(student),1,fp)==1){
            if(student.id==d){
                gotoxy(x,11);printf("The student record is available");
                gotoxy(x,13);printf("Student name is %s",student.name);
                gotoxy(x,14);printf("AGE. is %d",student.age);

                char p[20];
                gotoxy(x,16);printf("Enter Your Student Password:");scanf("%s",p);
                if(strcmp(student.pass,(p))==0){
                gotoxy(x,18); printf("Thank You");
                getch(); student_main();

                }
                else{
                gotoxy(x,18); printf("wrong Password");
                getch();
                main();
                }
            }
        }
        if(find_student == 0){
            gotoxy(x,11);printf("No student is found");
            getch(); system("cls"); window(); main();
        }
    }
}
