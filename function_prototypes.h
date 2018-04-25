//-----------Function prototypes-----------\\

//Librarian Prototypes
int lib_main(void);
int checkid_lib(int d);
int change_lib_pass();
int lib_signup();
int lib_signin();
int lib_main_book(void);
int lib_main_student(void);


//Student Prototypes
int student_pass();
int add_student(void);
int search_student();
int edit_student();
int delete_student();
int view_student();
int student_pass_remove();
int student_main(void);
int getdata_student(int choice);

//Books prototypes
int add_books(void);
int search_books();
int edit_books();
int delete_books();
int view_books();

int finish();
int pass();
int get_password(char* pass);
int add_window();
int get_data(int choice);
int checkid(int t);
int gotoxy(int x, int y);
int developer_info();
int window();
