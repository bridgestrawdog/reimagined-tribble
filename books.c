//--------------------------Book Releted Function-------------------------------------------------
struct BOOK             //Structure variable for BOOK
{
    int id;
    char name[20];
    char Author[20];
    int quantity;
    float Price;
    int rackno;
    char *cat;
};
struct BOOK book;

char catagories[][15]={"Computer","Electronics","Electrical","Civil","Mechnnical","Architecture"};

int add_books(void){    //funtion for adding books
    int x = 15;
	system("cls");window();
	FILE *fp;
	int i, choice;
	system("cls"); window(); add_window();
	gotoxy(x,19); printf("Enter your choice:");
	scanf("%d", &choice);
	if(choice==7)
        lib_main_book() ;
	system("cls"); window();
	fp = fopen("Record.dat","ab+");
	if(get_data(choice) == 1){
        book.cat=catagories[choice-1];
        fseek(fp,0,SEEK_END);
        fwrite(&book,sizeof(book),1,fp);
        fclose(fp);
        gotoxy(x,17);printf("The record is sucessfully saved");
        gotoxy(x,19);printf("Save any more?(Y / N):");
        if(getch()=='n'){
            system("cls"); lib_main_book();
        }else{
            add_books();
        }
    }
    fclose(fp);
}

int add_window(){      //Function for Books Catagory Interface
    int x = 15;
    system("cls"); window();
    gotoxy(25,6);printf("******SELECT CATEGOIES******");
	gotoxy(x,9);printf("1. Computer");
	gotoxy(x,10);printf("2. Electronics");
	gotoxy(x,11);printf("3. Electrical");
	gotoxy(x,12);printf("4. Civil");
	gotoxy(x,13);printf("5. Mechanical");
	gotoxy(x,14);printf("6. Architecture");
	gotoxy(x,16);printf("7. Back");
}

int get_data(int choice){
    int x = 15;
    int x1 = 30; int bookID;
	gotoxy(x,7);printf("Enter the Information Bellow");
	gotoxy(x,9);printf("Category:");  gotoxy(x1,9);printf("%s",catagories[choice-1]);
	gotoxy(x,10);printf("Book ID:");  gotoxy(x1,10);scanf("%d",&bookID);

	 if(book.id==bookID){
                gotoxy(x,11);printf("Id is already Exits");
                getch(); add_books();
                }

	book.id=bookID;
	gotoxy(x,11);printf("Book Name:"); gotoxy(x1,11);scanf("%s",book.name);
	gotoxy(x,12);printf("Author:");    gotoxy(x1,12);scanf("%s",book.Author);
	gotoxy(x,13);printf("Quantity:");  gotoxy(x1,13);scanf("%d",&book.quantity);
	gotoxy(x,14);printf("Price:");     gotoxy(x1,14);scanf("%f",&book.Price);
	gotoxy(x,15);printf("Rack No:");   gotoxy(x1,15);scanf("%d",&book.rackno);
	return 1;
}

int check_id(int t)      //Function to check ID is exist or not
{
    FILE *temp;
	temp = fopen("Record.dat","rb+");
	while(fread(&book,sizeof(book),1,temp)==1)
        if(book.id == t){
            fclose(temp);
            return 0;
        }
        fclose(temp);
        return 1;

}


int edit_books()       //Function to Edit Books info
{
    int x = 15;
    system("cls");window();
	FILE *fp;
	int c=0,d;
	gotoxy(27,6);printf("****Edit Book Section****");
	while(1)
	{
		gotoxy(x,8);printf("Enter Book Id to edit:");scanf("%d",&d);
		fp=fopen("uRecord.dat","rb+");
		while(fread(&book,sizeof(book),1,fp)==1)
		{
			if(check_id(d)==0)
			{
				gotoxy(x,9);printf("The book is availble");
				gotoxy(x,10);printf("The Book ID:%d",book.id);
				gotoxy(x,11);printf("New name:");scanf("%s",book.name);
				gotoxy(x,12);printf("New Author:");scanf("%s",book.Author);
				gotoxy(x,13);printf("New quantity:");scanf("%d",&book.quantity);
				gotoxy(x,14);printf("New price:");scanf("%f",&book.Price);
				gotoxy(x,15);printf("New rackno:");scanf("%d",&book.rackno);
				gotoxy(x,16);printf("The record is modified");
				fseek(fp,ftell(fp)-sizeof(book),0);
				fwrite(&book,sizeof(book),1,fp);
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
        edit_books();
    }
    else
        lib_main_student();
	}
}



int search_books(){    //Function to search books
    int x = 15;
    system("cls"); window();
    gotoxy(25,7);printf("********Search Books********");
    gotoxy(x,10);printf("1. Search By ID");
    gotoxy(x,12);printf("2. Search By Name");
    gotoxy(x,16);printf("Enter Your Choice: ");
    switch(getch())
    {
        case '1':
            searchByID();
            break;
        case '2':
            searchByName();
            break;
        default :
            getch();search_books();
    }
}

int searchByID(){      //Function to search books by given ID
    system("cls"); window();
    int id, x = 15;; FILE *fp;
    gotoxy(25,7);printf("*****Search Books By Id*****");
    gotoxy(x,9);printf("Enter the book id:");scanf("%d",&id);
    int findBook = 0;
    fp = fopen("Record.dat","rb");
    while(fread(&book,sizeof(book),1,fp)==1){
        if(book.id==id){
            Sleep(2);
            gotoxy(x,11);printf("The Book is available");
            gotoxy(x,13);printf("\xB2 ID:%d",book.id);
            gotoxy(x,14);printf("\xB2 Name:%s",book.name);
            gotoxy(x,15);printf("\xB2 Author:%s ",book.Author);
            gotoxy(x,16);printf("\xB2 Qantity:%d ",book.quantity);
            gotoxy(x,17);printf("\xB2 Price:%.2f",book.Price);
            gotoxy(x,18);printf("\xB2 Rack No:%d ",book.rackno);
            findBook = 1;
        }
    }
    if(findBook == 0){  //checks whether conditiion enters inside loop or not
        gotoxy(x,12);printf("\aNo Record Found");
    }
    fclose(fp);
    gotoxy(x,20);printf("Try another search?(Y/N)");
    if(getch()=='y')
        searchByID();
    else
    system("cls");window();
}

int searchByName(){    //Function to search books by using Books name
    system("cls");window();
    char s[15];
    int d=0, x = 15;
    FILE *fp;
    gotoxy(25,7);printf("****Search Books By Name****");
    gotoxy(x,9);printf("Enter Book Name:");scanf("%s",s);
    fp = fopen("Record.dat","rb");
    while(fread(&book,sizeof(book),1,fp)==1){
        if(strcmp(book.name,(s))==0){ //checks whether book.name is equal to s or not
            gotoxy(x,11);printf("The Book is available");
            gotoxy(x,13);printf("\xB2 ID:%d",book.id);
            gotoxy(x,14);printf("\xB2 Name:%s",book.name);
            gotoxy(x,15);printf("\xB2 Author:%s",book.Author);
            gotoxy(x,16);printf("\xB2 Qantity:%d",book.quantity);
            gotoxy(x,17);printf("\xB2 Price:Rs.%.2f",book.Price);
            gotoxy(x,18);printf("\xB2 Rack No:%d ",book.rackno);
            d++;
        }
    }
    if(d==0){
        gotoxy(x,12);printf("\aNo Record Found");
    }
    fclose(fp);
    gotoxy(x,20);printf("Try another search?(Y/N)");
    if(getch()=='y')
    searchByName();
    else
    system("cls");window();
}

int delete_books(){    //function that delete  record form Database
    system("cls"); window();
    FILE *ft,*fp;
    char another;
    int x = 15;
    int d,findBook = 0;
    while(another = 'y'){  //infinite loop
        gotoxy(25,7);printf("********BOOK DELETE********");
        gotoxy(x,9);printf("Enter the Book ID to  delete:"); scanf("%d",&d);
        fp = fopen("Record.dat","rb+");
        while(fread(&book,sizeof(book),1,fp)==1){
            if(book.id==d){
                gotoxy(x,11);printf("The book record is available");
                gotoxy(x,13);printf("Book name is %s",book.name);
                gotoxy(x,14);printf("Rack No. is %d",book.rackno);
                findBook = 1;
                gotoxy(x,16);printf("Do you want to delete it?(Y/N):");
                if(getch()=='y'){
                    ft=fopen("test.dat","wb");  //temporary file for delete
                    rewind(fp);
                    while(fread(&book,sizeof(book),1,fp)==1){
                        if(book.id!=d){
                            fwrite(&book,sizeof(book),1,ft); //write all in tempory file except that
                        }                              //we want to delete
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("Record.dat");
                    rename("test.dat","Record.dat"); //copy all item from temporary file to fp except that
                                        //we want to delete
                    gotoxy(x,17);printf("The record is sucessfully deleted");
                }
            }
        }
        if(findBook == 0){
            gotoxy(x,11);printf("No record is found");
        }

        gotoxy(x,18);printf("Delete another record?(Y/N)");
        if(getch()=='y'){
            delete_books();
        }
        else
            lib_main_book();
    }
}

int view_books()   //I use this function to view all books info
{
    int j;
    system("cls");window();
    FILE *fp;
    gotoxy(5,5);printf("*********************************Book List****************************");
    gotoxy(5,6);printf(" CATEGORY      ID      BOOK NAME       AUTHOR     QTY   PRICE   RackNo");
    j=8;
    fp=fopen("Record.dat","rb");
    while(fread(&book,sizeof(book),1,fp)==1){
        gotoxy(5,j);printf("%s",book.cat);
        gotoxy(19,j);printf("%d",book.id);
        gotoxy(27,j);printf("%s",book.name);
        gotoxy(44,j);printf("%s",book.Author);
        gotoxy(56,j);printf("%d",book.quantity);
        gotoxy(61,j);printf("%.2f",book.Price);
        gotoxy(71,j);printf("%d",book.rackno);
        printf("\n\n");
        j++;
    }
    fclose(fp);
    getch(); system("cls"); window();
}
//--------------------------------------------------------------------------------------------



int add_window_u(){      //Function for Student Catagory Interface
    int x = 15;
    system("cls"); window();
    gotoxy(25,6);printf("******SELECT CATEGOIES******");
	gotoxy(x,9);printf("1. Student");
	gotoxy(x,11);printf("2. Teacher");
	gotoxy(x,13);printf("3. Others");
	gotoxy(x,15);printf("7. Back");
}
