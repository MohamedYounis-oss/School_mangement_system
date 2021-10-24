#include <stdio.h>
#include <stdlib.h>
#include "student.h"


extern int total_students_number;


int get_choise(void){

    system("cls");

    int choice;

    printf("==========================\n");
    printf("\tMain Menu\t\n");
    printf("==========================\n");
    printf(" 1- Print all students\n");
    printf(" 2- Add a new student\n");
    printf(" 3- Search for a student\n");
    printf(" 4- Sort all students\n");
    printf(" 5- Insert a student\n");
    printf(" 6- Edit a student\n");
    printf(" 7- Call a student\n");
    printf(" 8- Delete a student\n");
    printf(" 9- Quit program\n");
    printf("==========================\n");

    printf(">> Enter your choice: ");
    scanf("%d", &choice);

    return choice;


}



int main()
{

    std_t students[] = {{"Mohamed Younis Mohamed", 21, 100, "Male", 107401303},
                        {"Fatma Ahmed Abdulkader", 30, 75, "Female", 105874965},
                        {"Ibrahim Osama Ismaeel", 40, 43, "Male", 106987423},
                        {"Layla Marawan khaled ", 20, 50, "Female", 104785478},
                        {"Mohamed Abdullah Marzouq", 18, 80, "Male", 1025825814},
                        {"Layla Mamdouh shaheen", 45, 99, "Female", 102323568},
                        {"Osama Mounir Ghanem", 20, 75, "Male", 101459862},
                        {"Zainab Ahmed Abdulfatah", 48, 30, "Female", 101113625}};
    total_students_number = sizeof(students)/sizeof(students[0]);


    int choice;
    char state;


    while (1){

        choice = get_choise();


        switch(choice){

        case 1:

            state = display_all(students);
            if (state == 'q'){
                return 0;
            } else {
                break;
            }

        case 2:

            add:
            state = add_student(students);
            if (state == 'q'){
                return 0;

            } else if (state == 'a'){
                goto add;
            } else {
                break;
            }

        case 3:

            search:
            state = search(students);
            if (state == 'q'){
                return 0;
            } else if (state == 'r'){
                goto search;
            }
            else {
                break;
            }

        case 4:

            sort:
            state = sort_students(students);
            if (state == 'q'){
                return 0;
            } else if (state == 'r'){
                goto sort;
            }
            else {
                break;
            }

        case 5:

            insert:
            state = insert_student(students);
            if (state == 'q'){
                return 0;

            } else if (state == 'i'){
                goto insert;
            } else {
                break;
            }

        case 6:

            edit:
            state = edit_student(students);
            if (state == 'q'){
                return 0;

            } else if (state == 'n'){
                goto edit;
            } else {
                break;
            }

        case 7:

            call:
            state = call_student(students);
            if (state == 'q'){
                return 0;

            } else if (state == 'c'){
                goto call;
            } else {
                break;
            }

        case 8:

            deleting:
            state = delete_student(students);
            if (state == 'q'){
                return 0;

            } else if (state == 'd'){
                goto deleting;
            } else {
                break;
            }

        case 9:

            return 0;

        default:
            break;

        }
    }

    return 0;
}
