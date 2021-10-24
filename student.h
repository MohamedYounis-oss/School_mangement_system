
typedef struct student{

    char name[40];
    int age;
    int grade;
    char gender[8];
    long telephoneNumber;


}std_t;


void string_print(char* str);
int string_len(char* str);
void string_copy(char* str1, char* str2);
void string_scan(char* str);
void string_lowercase(char* str);
int string_compare_notCase (char* str1, char* str2);
int string_compare (char* str1, char* str2);
int find_string_in_array(char* str, char* word);
void swap_pointers(char** p1, char** p2);
void arrayOfStrings_print(char** arr, int size);
int string_whoseBigger (char* str1, char* str2);
int string_whoseBigger_notCase2 (char* str1, char* str2);
void swap_student(std_t *s1, std_t *s2);
void arrayOfStrings_bubbleSort(std_t *students);


void student_print(std_t *s, int index);
char display_all(std_t *students);
char add_student(std_t *students);
char search_by_number(std_t *students);
char search_by_name(std_t *students);
char search_by_age(std_t *students);
char search_by_gender(std_t* students);
char maxMin_age(std_t *students);
char maxMin_grade(std_t *students);
char search(std_t *students);
char sort_by_name(std_t* students);
char sort_by_age(std_t *students);
char sort_by_grade(std_t *students);
char sort_students(std_t* students);
char insert_student(std_t* students);
char delete_student(std_t* students);
char call_student(std_t *students);
char edit_name(std_t* students, int index);
char edit_age(std_t* students, int index);
char edit_grade(std_t* students, int index);
char edit_gender(std_t* students, int index);
char edit_tele(std_t* students, int index);
char edit_student(std_t* students);

