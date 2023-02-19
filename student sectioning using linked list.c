#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct students{
    char * name;
    char * id;
    struct students * next;
}student;

student * add_student(char * name, char * id, student * root){
    printf(" you entered: %s\n id: %s", name, id );
    student * new_student;
    new_student = (student *)malloc(sizeof(student));
    new_student->name = (char *)malloc(sizeof(char) * (strlen(name)) + 1);
    new_student->id = (char *)malloc(sizeof(char) * (strlen(id)) + 1);
    strcpy(new_student->name,name);
    strcpy(new_student->id, id);
    new_student->next = NULL;

    if(root == NULL){
        return root = new_student;
    }else{
        student * pointing;
        pointing = root;
        while(pointing->next != NULL){
            pointing = pointing->next;
        }
        pointing->next = new_student;
        return root;
    }
}

void display(student * root){
    student * pointing = root;  //avoid damage to the list
    int i = 1;
    if(pointing == NULL){
        printf("This section is empty\n");
    }else{
        while(pointing != NULL){
        printf("%d. %s - id: %s \n", i, pointing->name, pointing->id);
        pointing = pointing->next;
        i++;
        }
    }
    printf("\n");
}

void search(student * root, int x){
    bool not_found = true;
    student * pointing = root; //avoid damage to the list
    char * section[] = {"Section A", "Section B", "Section C"};
    if(pointing == NULL){
        printf("%s is empty\n", section[x - 1]);
    }else{
        char * search_id;
        search_id = (char *)malloc(sizeof(char));
        printf("Enter an Id you want to search: ");
        scanf(" %[^\n]", search_id);
        while(pointing != NULL){
            if(strcmp(search_id,pointing->id) == 0){
                printf("Search Result in %s\n", section[x - 1]);
                printf("name: %s -id: %s\n", pointing->name, pointing->id);
                not_found = false;
            }
            pointing = pointing->next;
        }
        if(not_found){
        printf("Student not found in %s \n", section[x - 1]);
        }
    }

    printf("\n");
}

int main()
{
    student * section_A = NULL, * section_B = NULL, * section_C = NULL;
    bool flag = true;
    int select, selectSection;
    char * name, * id;
    //allocate memory
    name = (char *)malloc(sizeof(char));
    id = (char *)malloc(sizeof(char));

    while(flag){
        printf("\n\n--ADD NEW STUDENT--\n");
        printf("1 - add student \n");
        printf("2 - display student and thier id's \n");
        printf("3 - search a student's id\n");
        printf("4 - exit \n");
        scanf("%d", &select);
        switch(select){
            case 1:
                printf("Enter name: ");
                scanf(" %[^\n]", name);
                printf("Enter id number: ");
                scanf(" %[^\n]", id);
                printf("1 -add to Section A\n");
                printf("2 -add to section B\n");
                printf("3 -add to section C\n");
                printf("select: ");
                scanf("%d", &selectSection);
                if(selectSection == 1){         //for section A
                    section_A = add_student(name, id, section_A);
                }else if(selectSection == 2){   //for section B
                    section_B = add_student(name, id, section_B);
                }else{                          //for section C
                    section_C = add_student(name, id, section_C);
                }
                break;
            case 2:
                printf("Display --- \n");
                printf("1 - Section A\n");
                printf("2 - section B\n");
                printf("3 - section C\n");
                printf("select: ");
                scanf("%d", &selectSection);
                if(selectSection == 1){         //for section A
                    printf("---Students in Section A ---\n");
                    display(section_A);
                }else if(selectSection == 2){   //for section B
                    printf("---Students in Section B ---\n");
                    display(section_B);
                }else{                          //for section C
                    printf("---Students in Section C ---\n");
                    display(section_C);
                }
                break;
            case 3:
                printf("Search in --- \n");
                printf("1 - Section A\n");
                printf("2 - section B\n");
                printf("3 - section C\n");
                printf("select: ");
                scanf("%d", &selectSection);
                if(selectSection == 1){
                    search(section_A, selectSection);
                }else if(selectSection == 2){
                    search(section_B, selectSection);
                }else{
                    search(section_C, selectSection);
                }
                break;
            case 4:
                exit(1);
                break;
            default:
                printf("invalid input \n");
        }
    }


    return 0;
}

