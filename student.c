#include "student.h"




int total_students_number;



void string_print(char* str){

    for (int i=0; str[i]; i++){
        printf("%c", str[i]);
    }
    printf("\n");
}


int string_len(char* str){

    int i;
    for( i=0; str[i]; i++);
    return i;

}


void string_copy(char* str1, char* str2){

    int i;
    for (i=0; str1[i]; i++){
        str2[i] = str1[i];
    }
    str2[i] = '\0';
}


void string_scan(char* str){

    int i=0;
    scanf(" %c", &str[i]);
    for ( ;str[i]!='\n';){

        i++;
        scanf("%c", &str[i]);

    }
    str[i] = 0;

}


void string_lowercase(char* str){

    for (int i=0; str[i]; i++){

        if(str[i]>='A' && str[i]<='Z'){
            str[i] = (str[i] - 'A')+'a';
        }
    }
}



int string_compare_notCase (char* str1, char* str2){

    int i;
    for (i=0; str1[i] || str2[i]  ;i++){

        if(str1[i]!=str2[i] && ((str1[i]-'a'+'A') != str2[i] && (str1[i]-'A'+'a') != str2[i])){
            return 0;
        }

    }
    return 1;
}

int string_compare (char* str1, char* str2){

    int i;
    for (i=0; str1[i]||str2[i]; i++){
        if(str1[i]!=str2[i]){
            return 0;
        }
    }
    return 1;
}

int find_string_in_array(char* str, char* word){

    int i, j = 0;
    char flag = 0;

    int size = string_len(word);

    for ( i=0; str[i]; i++){

        if (i==0 || str[i-1]==' ' || flag){

            if(j<size && j<size && (str[i] == word[j] || (str[i]-'A'+'a') == word[j])) {

                j++;
                flag = 1;
                if (j==size && (str[i+1]==' ' || str[i+1] == '\0')) return (i-size+1);


            } else {
                j = 0;
                flag = 0;
            }
        }
    }

    return -1;
}





void swap_pointers(char** p1, char** p2){

    char* temp = *p1;
    *p1 = *p2;
    *p2 = temp;


}


void arrayOfStrings_print(char** arr, int size){

    int i, j;

    for (i=0; i<size; i++){

        string_print(arr[i]);

    }
}



int string_whoseBigger (char* str1, char* str2){

    int i;
    for (i=0; str1[i]||str2[i]; i++){
        if(str1[i] > str2[i]){
            return 1;
        } else if (str1[i] < str2[i]){
            return -1;
        }
    }
    return 0;
}






int string_whoseBigger_notCase2 (char* str1, char* str2){

    int i;
    char x, y;


    for (i=0; str1[i]||str2[i]; i++){

         if (str1[i] >= 'A' && str1[i] <= 'Z'){
            x = str1[i]-'A'+'a';
        } else {
            x = str1[i];
        }

        if (str2[i] >= 'A' && str2[i] <= 'Z') {
            y = str2[i]-'A'+'a';
        } else {
            y = str2[i];
        }

        if(x > y){
            return 1;
        } else if (x < y){
            return -1;
        }
    }
    return 0;
}

void swap_student(std_t *s1, std_t *s2){

    std_t temp;
    temp = *s1;
    *s1 = *s2;
    *s2 = temp;

}

 void arrayOfStrings_bubbleSort(std_t *students){

    int i, j, c=0, sorted_flag;

    for (j=0; j<total_students_number; j++){

        sorted_flag = 1;
        for (i=0; i<total_students_number-1-j; i++){

            if(string_whoseBigger_notCase2(students[i].name, students[i+1].name) == 1){

                swap_student(&students[i], &students[i+1]);
                sorted_flag = 0;

            }
            c++;

        }
        if (sorted_flag == 1){
            break;
        }

    }


}


void student_print(std_t *s, int index){

    printf("\n%d- %s\n", index+1, s->name);
    printf("   Age: %d\n", s->age);
    printf("   Grade: %d\n", s->grade);
    printf("   Gender: %s\n", s->gender);
    printf("   Telephone number: %d\n\n", s->telephoneNumber);
}


char display_all(std_t *students){

    system("cls");

    if (total_students_number == 0){
        printf("There are no students yet\n");
    }

    for (int i=0; i<total_students_number; i++){

        student_print(students+i, i);

    }

    char choice;

    printf("================================\n");
    printf(">> Enter m to go back to menu\n");
    printf(">> Enter q to Quit program\n");
    printf("================================\n");

    scanf (" %c", &choice);

    return choice;


}



char add_student(std_t *students){

    system("cls");

    Taking_student_data :

    printf(">> Enter student's name : ");
    string_scan(students[total_students_number].name);

    for (int i=0; i<total_students_number; i++){

        if (string_compare_notCase(students[total_students_number].name, students[i].name) == 1){
            printf(" --- This student already exists ---\n\n");
            goto Taking_student_data;

        }

    }

    printf(">> Enter student's age : ");
    scanf("%d", &students[total_students_number].age);

    printf(">> Enter student's grade : ");
    scanf("%d", &students[total_students_number].grade);

     printf(">> Enter student's gender : ");
    string_scan(students[total_students_number].gender);

    printf(">> Enter student's telephone number : ");
    scanf("%d", &students[total_students_number].telephoneNumber);

    printf("------Name added successfully-----\n");

    total_students_number++;

    char choice;

    end_menu:

        printf("\n================================\n");
        printf(">> Enter m to go back to menu\n");
        printf(">> Enter a to add another name\n");
        printf(">> Enter q to quit program\n");
        printf("================================\n");

        scanf (" %c", &choice);

        return choice;

}


char search_by_number(std_t *students){

    system("cls");

    int num;

    Take_student_data:

    printf(">> Enter the student's number: ");
    scanf("%d", &num);

    if (num > total_students_number){
        printf(" ----- There are only %d student -----\n", total_students_number);
        goto Take_student_data;
    }

    student_print(&students[num-1], num-1);

    char choice;

    end_menu:

    printf("================================\n");
    printf(" s- to search for another name\n");
    printf(" r- to go back to search menu\n");
    printf(" q- to quit program\n");
    printf("================================\n");

    scanf(" %c", &choice);


    return choice;

}


char search_by_name(std_t *students){

    system("cls");

    char name[40];

    printf(">> Enter the student's name: ");
    string_scan(name);

    string_lowercase(name);

    char found = 0;

    for (int i=0; i<total_students_number; i++){

        if (find_string_in_array(&students[i].name, name) != -1){
            student_print(&students[i], i);
            found = 1;
        }

    }

    if (found == 0)  printf(" --------- Not found ---------\n");

    char choice;

    end_menu:

    printf("================================\n");
    printf(" s- to search for another name\n");
    printf(" r- to go back to search menu\n");
    printf(" q- to quit program\n");
    printf("================================\n");

    scanf(" %c", &choice);


    return choice;

}

char search_by_age(std_t *students){

    system("cls");

    int age;

    printf(">> Enter the student's age: ");
    scanf("%d", &age);

    char found = 0;

    for (int i=0; i<total_students_number; i++){

        if (students[i].age == age){
            student_print(&students[i], i);
            found = 1;
        }

    }

    if (found == 0)  printf(" --------- Not found ---------\n");


    char choice;

    end_menu:

    printf("================================\n");
    printf(" s- to search for another age\n");
    printf(" r- to go back to search menu\n");
    printf(" q- to quit program\n");
    printf("================================\n");

    scanf(" %c", &choice);


    return choice;

}

char search_by_gender(std_t* students){

    system("cls");

    char gender[8];

    printf(">> Enter the student's gender: ");
    string_scan(gender);



    char found = 0;

    for (int i=0; i<total_students_number; i++){

        if (string_compare_notCase(&students[i].gender, gender) == 1){
            student_print(&students[i], i);
            found = 1;
        }

    }

    if (found == 0)  printf(" --------- Not found ---------\n");

    char choice;

    end_menu:

    printf("================================\n");
    printf(" s- to search for another name\n");
    printf(" r- to go back to search menu\n");
    printf(" q- to quit program\n");
    printf("================================\n");

    scanf(" %c", &choice);


    return choice;


}


char maxMin_age(std_t *students){

    system("cls");

    int max = students[0].age;
    int min = students[0].age;

    for (int i=1; i<total_students_number; i++){

        if (students[i].age > max) {
            max = students[i].age;
        }
        if (students[i].age < min){
            min = students[i].age;
        }

    }

    printf(">> Max age: \n");

    for (int i=0; i<total_students_number; i++){

        if (students[i].age == max){
            student_print(&students[i], i);
        }

    }


    printf(">> Min age: \n");

    for (int i=0; i<total_students_number; i++){

        if (students[i].age == min){
            student_print(&students[i], i);
        }

    }


    char choice;

    end_menu:

    printf("================================\n");
    printf(" r- to go back to search menu\n");
    printf(" q- to quit program\n");
    printf("================================\n");

    scanf(" %c", &choice);


    return choice;

}



char maxMin_grade(std_t *students){

    system("cls");

    int max = students[0].grade;
    int min = students[0].grade;

    for (int i=1; i<total_students_number; i++){

        if (students[i].grade > max) {
            max = students[i].grade;
        }
        if (students[i].grade < min){
            min = students[i].grade;
        }

    }

    printf(">> Max grade: \n");

    for (int i=0; i<total_students_number; i++){

        if (students[i].grade == max){
            student_print(&students[i], i);
        }

    }


    printf(">> Min grade: \n");

    for (int i=0; i<total_students_number; i++){

        if (students[i].grade == min){
            student_print(&students[i], i);
        }

    }


    char choice;

    end_menu:

    printf("================================\n");
    printf(" r- to go back to search menu\n");
    printf(" q- to quit program\n");
    printf("================================\n");

    scanf(" %c", &choice);


    return choice;

}





char search(std_t *students){

    system("cls");

    char choice, state;

    printf("================================\n");
    printf("\tSearch Menu\t\n");
    printf("================================\n");
    printf(" 1- search by number\n");
    printf(" 2- search by name\n");
    printf(" 3- search by age\n");
    printf(" 4- Max and min age\n");
    printf(" 5- Max and min grade\n");
    printf(" 6- search by gender\n");
    printf(" m- to go back to main menu\n");
    printf(" q- to quit program\n");
    printf("================================\n");

    printf(">> Enter your choice: ");
    scanf(" %c", &choice);


        switch(choice){

        case '1':

            by_number:
            state = search_by_number(students);
            if (state == 'q' || state == 'r'){
                return state;
            }  else if (state == 's'){
                goto by_number;
            }
            else {
                break;
            }

        case '2':

            by_name:
            state = search_by_name(students);
            if (state == 'q' || state == 'r'){
                return state;
            }  else if (state == 's'){
                goto by_name;
            }
            else {
                break;
            }

        case '3':

            by_age:
            state = search_by_age(students);
            if (state == 'q' || state == 'r'){
                return state;
            }  else if (state == 's'){
                goto by_age;
            }
            else {
                break;
            }

        case '4':

            state = maxMin_age(students);
            if (state == 'q' || state == 'r'){
                return state;
            } else {
                break;
            }


        case '5':

            state = maxMin_grade(students);
            if (state == 'q' || state == 'r'){
                return state;
            } else {
                break;
            }

        case '6':

            by_gender:
            state = search_by_gender(students);
            if (state == 'q' || state == 'r'){
                return state;
            }  else if (state == 's'){
                goto by_gender;
            }
            else {
                break;
            }


        case 'm':
        case 'M':
            return 'm';
            break;

        case 'q':
        case 'Q':
            return 'q';
            break;

        default:
            printf("Please choose from the menu..\n");
            break;

        }


}


char sort_by_name(std_t* students){

    system("cls");

    arrayOfStrings_bubbleSort(students);


    for (int i=0; i<total_students_number; i++){

        student_print(students+i, i);

    }




    char choice;

    end_menu:

    printf("================================\n");
    printf(" r- to go back to sorting menu\n");
    printf(" q- to quit program\n");
    printf("================================\n");

    scanf(" %c", &choice);


    return choice;

}


char sort_by_age(std_t *students){

    system("cls");

    int i, j, c=0, sorted_flag;

    for (j=0; j<total_students_number; j++){

        sorted_flag = 1;
        for (i=0; i<total_students_number-1-j; i++){

            if (students[i].age < students[i+1].age){
                swap_student(&students[i], &students[i+1]);
                sorted_flag = 0;

            }
            c++;

        }
        if (sorted_flag == 1);

    }


    for (int i=0; i<total_students_number; i++){

        student_print(students+i, i);

    }


    char choice;

    end_menu:

    printf("================================\n");
    printf(" r- to go back to sorting menu\n");
    printf(" q- to quit program\n");
    printf("================================\n");

    scanf(" %c", &choice);


    return choice;

}


char sort_by_grade(std_t *students){

    system("cls");

    int i, j, c=0, sorted_flag;

    for (j=0; j<total_students_number; j++){

        sorted_flag = 1;
        for (i=0; i<total_students_number-1-j; i++){

            if (students[i].grade < students[i+1].grade){
                swap_student(&students[i], &students[i+1]);
                sorted_flag = 0;

            }
            c++;

        }
        if (sorted_flag == 1);

    }


    for (int i=0; i<total_students_number; i++){

        student_print(students+i, i);

    }



    char choice;

    end_menu:

    printf("================================\n");
    printf(" r- to go back to sorting menu\n");
    printf(" q- to quit program\n");
    printf("================================\n");

    scanf(" %c", &choice);


    return choice;

}


char sort_students(std_t* students){

    system("cls");

    char choice, state;

    printf("================================\n");
    printf("\tSorting Menu\t\n");
    printf("================================\n");
    printf(" 1- sort by name\n");
    printf(" 2- sort by age\n");
    printf(" 3- sort by grade\n");
    printf(" m- to go back to main menu\n");
    printf(" q- to quit program\n");
    printf("================================\n");

    printf(">> Enter your choice: ");
    scanf(" %c", &choice);



        switch(choice){

        case '1':

            state = sort_by_name(students);
            if (state == 'q' || state == 'r'){
                return state;
            }
            else {
                break;
            }

        case '2':

            state = sort_by_age(students);
            if (state == 'q' || state == 'r'){
                return state;
            }
            else {
                break;
            }

        case '3':

            state = sort_by_grade(students);
            if (state == 'q' || state == 'r'){
                return state;
            }
            else {
                break;
            }


        case 'm':
        case 'M':
            return 'm';
            break;

        case 'q':
        case 'Q':
            return 'q';
            break;

        default:
            printf("Please choose from the menu..\n");
            break;

        }

}


char insert_student(std_t* students){

    system("cls");

    int position;

    Take_position :

    printf(">> where do you want to put this student (number): ");
    scanf("%d", &position);

    if (position > total_students_number){
        printf(" ----- There are only %d student -----\n", total_students_number);
        goto Take_position;
    }

    total_students_number++;


    for (int i=total_students_number-1; i>position-1; i--){

        students[i] = students[i-1];

    }

    Take_student_data :

    printf(">> Enter student's name : ");
    string_scan(students[position-1].name);



    for (int i=0; i<total_students_number; i++){

        if (string_compare_notCase(students[position-1].name, students[i].name) == 1 && i != position-1) {
            printf(" --- This student already exists ---\n\n");
            goto Take_student_data;

        }

    }

    printf(">> Enter student's age : ");
    scanf("%d", &students[position-1].age);

    printf(">> Enter student's grade : ");
    scanf("%d", &students[position-1].grade);

     printf(">> Enter student's gender : ");
    string_scan(students[position-1].gender);

    printf(">> Enter student's telephone number : ");
    scanf("%d", &students[position-1].telephoneNumber);

    printf("------Student insertd successfully-----\n");


    char choice;

    end_menu:

        printf("\n================================\n");
        printf(">> Enter m to go back to menu\n");
        printf(">> Enter i to insert another name\n");
        printf(">> Enter q to quit program\n");
        printf("================================\n");

        scanf (" %c", &choice);

        return choice;

}


char delete_student(std_t* students){

    system("cls");

    char name[40];

    Take_student_data:

    printf(">> Enter student's name you want to delete: \n>> ");
    string_scan(name);


    int index;
    char found = 0;

    for (int i=0; i<total_students_number; i++){

        if(string_compare_notCase(students[i].name, name) == 1){
            student_print(&students[i], i);
            index = i;
            found = 1;
        }
    }

    if (found == 0){
        printf(" --------- Not found ---------\n");
        goto Take_student_data;
    }

    for (int i=index; i<=total_students_number-1; i++){
        students[i] = students[i+1];
    }

    total_students_number--;

    printf("------Student deleted successfully-----\n");


    char choice;

    end_menu:

        printf("\n================================\n");
        printf(">> Enter m to go back to menu\n");
        printf(">> Enter d to delete another name\n");
        printf(">> Enter q to quit program\n");
        printf("================================\n");

        scanf (" %c", &choice);

        return choice;

}


char call_student(std_t *students){

    system("cls");

    char name[40];

    Take_student_data:

    printf(">> Enter student's name you want to Call: \n>> ");
    string_scan(name);

    int index;
    char found = 0;

    for (int i=0; i<total_students_number; i++){

        if(string_compare_notCase(students[i].name, name) == 1){
            student_print(&students[i], i);
            index = i;
            found = 1;
        }
    }

    if (found == 0){
        printf(" --------- Not found ---------\n");
        goto Take_student_data;
    }

    printf("\tCalling %d ", students[index].telephoneNumber);
    for (int i=0; i<7; i++){
        printf(". ");
        sleep(1);
    }
    printf("\n\tCan not call %d, please try another time\n", students[index].telephoneNumber);


    char choice;

    end_menu:

        printf("\n================================\n");
        printf(">> Enter m to go back to menu\n");
        printf(">> Enter c to Call another name\n");
        printf(">> Enter q to quit program\n");
        printf("================================\n");

        scanf (" %c", &choice);

        return choice;

}


char edit_name(std_t* students, int index){


    char name[40];

    printf(">> Enter the student's new name: ");
    string_scan(&students[index].name);



    char choice;

    end_menu:

    printf("================================\n");
    printf(" m- to go back to Main menu\n");
    printf(" e- to edit another section\n");
    printf(" n- to edit another student\n");
    printf(" q- to quit program\n");
    printf("================================\n");

    scanf(" %c", &choice);


    return choice;


}


char edit_age(std_t* students, int index){


    char name[40];

    printf(">> Enter the student's new age: ");
    scanf("%d", &students[index].age);



    char choice;

    end_menu:

    printf("================================\n");
    printf(" m- to go back to Main menu\n");
    printf(" e- to edit another section\n");
    printf(" n- to edit another student\n");
    printf(" q- to quit program\n");
    printf("================================\n");

    scanf(" %c", &choice);


    return choice;


}


char edit_grade(std_t* students, int index){


    char name[40];

    printf(">> Enter the student's new grade: ");
    scanf("%d", &students[index].grade);



    char choice;

    end_menu:

    printf("================================\n");
    printf(" m- to go back to Main menu\n");
    printf(" e- to edit another section\n");
    printf(" n- to edit another student\n");
    printf(" q- to quit program\n");
    printf("================================\n");

    scanf(" %c", &choice);


    return choice;


}


char edit_gender(std_t* students, int index){


    char name[40];

    printf(">> Enter the student's new gender: ");
    string_scan(&students[index].gender);



    char choice;

    end_menu:

    printf("================================\n");
    printf(" m- to go back to Main menu\n");
    printf(" e- to edit another section\n");
    printf(" n- to edit another student\n");
    printf(" q- to quit program\n");
    printf("================================\n");

    scanf(" %c", &choice);


    return choice;


}


char edit_tele(std_t* students, int index){


    char name[40];

    printf(">> Enter the student's new Telephone number: ");
    scanf("%d", &students[index].telephoneNumber);



    char choice;

    end_menu:

    printf("================================\n");
    printf(" m- to go back to Main menu\n");
    printf(" e- to edit another section\n");
    printf(" n- to edit another student\n");
    printf(" q- to quit program\n");
    printf("================================\n");

    scanf(" %c", &choice);


    return choice;


}


char edit_student(std_t* students){

    system("cls");

    char name[40];

    Take_student_data:

    printf(">> Enter student's name you want to Edit: \n>> ");
    string_scan(name);

    int index;
    char found = 0;

    for (int i=0; i<total_students_number; i++){

        if(string_compare_notCase(students[i].name, name) == 1){
            student_print(&students[i], i);
            index = i;
            found = 1;
        }
    }

    if (found == 0){
        printf(" --------- Not found ---------\n");
        goto Take_student_data;
    }

    char choice, state;

    edit_menu:

    printf("================================\n");
    printf("\tEdit Menu\t\n");
    printf("================================\n");
    printf(" 1- Edit name\n");
    printf(" 2- Edit age\n");
    printf(" 3- Edit grade\n");
    printf(" 4- Edit gender\n");
    printf(" 5- Edit Telephone number\n");
    printf(" m- to go back to main menu\n");
    printf(" q- to quit program\n");
    printf("================================\n");

    printf(">> Enter your choice: ");
    scanf(" %c", &choice);



        switch(choice){

        case '1':

            state = edit_name(students, index);
            if (state == 'q' || state == 'n'){
                return state;

            } else if(state == 'e'){

                system("cls");
                student_print(&students[index], index);
                goto edit_menu;
            }
            else {
                break;
            }

        case '2':

            state = edit_age(students, index);
            if (state == 'q' || state == 'n'){
                return state;

            } else if(state == 'e'){

                system("cls");
                student_print(&students[index], index);
                goto edit_menu;
            }
            else {
                break;
            }

        case '3':

            state = edit_grade(students, index);
            if (state == 'q' || state == 'n'){
                return state;

            } else if(state == 'e'){

                system("cls");
                student_print(&students[index], index);
                goto edit_menu;
            }
            else {
                break;
            }

        case '4':

            state = edit_gender(students, index);
            if (state == 'q' || state == 'n'){
                return state;

            } else if(state == 'e'){

                system("cls");
                student_print(&students[index], index);
                goto edit_menu;
            }
            else {
                break;
            }

        case '5':

            state = edit_tele(students, index);
            if (state == 'q' || state == 'n'){
                return state;

            } else if(state == 'e'){

                system("cls");
                student_print(&students[index], index);
                goto edit_menu;
            }
            else {
                break;
            }


        case 'm':
        case 'M':
            return 'm';
            break;

        case 'q':
        case 'Q':
            return 'q';
            break;

        default:
            printf("Please choose from the menu..\n");
            break;

        }
}




