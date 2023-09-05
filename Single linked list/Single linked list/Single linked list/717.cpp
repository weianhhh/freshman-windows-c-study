#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[20];
    struct Student* prev;
    struct Student* next;
};

struct Student* createStudent(int id,const char* name) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->id = id;
    strcpy(newStudent->name,name);
    newStudent->prev = NULL;
    newStudent->next = NULL;
    return newStudent;
}

void insertAtEnd(struct Student** head, int id,const char* name) {
    struct Student* newStudent = createStudent(id,name);
    if (*head == NULL) {
        *head = newStudent;
        (*head)->next = *head;
        (*head)->prev = *head;
    }
    else {
        struct Student* last = (*head)->prev;
        newStudent->next = *head;
        newStudent->prev = last;
        last->next = newStudent;
        (*head)->prev = newStudent;
    }
}

void printStudents(struct Student* head) {
    if (head == NULL) {
        printf("No students found.\n");
        return;
    }

    struct Student* current = head;
    do {
        printf("id:%d ,Name:%s\n", current->id,current->name);
        current = current->next;
    } while (current != head);
    printf("\n");
}
void deleteStudent(struct Student** head, int id) {
    if (*head == NULL) {
        printf("No students found.\n");
        return;
    }

    struct Student* current = *head;
    struct Student* prev = NULL;
    int found = 0;

    do {
        if (current->id == id) {
            found = 1;
            break;
        }
        prev = current;
        current = current->next;
    } while (current != *head);

    if (found) {
        if (current == *head && current->next == *head) {
            // Only one student in the list
            *head = NULL;
        }
        else {
            prev->next = current->next;
            current->next->prev = prev;
            if (current == *head) {
                *head = current->next;
            }
        }

        free(current);
        printf("Student with ID %d deleted.\n", id);
    }
    else {
        printf("Student with ID %d not found.\n", id);
    }
}

void freeStudents(struct Student** head) {
    if (*head == NULL) {
        return;
    }

    struct Student* current = *head;
    struct Student* next = NULL;

    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != *head);

    *head = NULL;
}
int main() {
    struct Student* head = NULL;

    insertAtEnd(&head, 1,"hrt");
    insertAtEnd(&head, 2,"hrg");
    insertAtEnd(&head, 3,"hrk");
    insertAtEnd(&head, 4,"hrh");

    printStudents(head);
    deleteStudent(&head, 2);

    printStudents(head);

    freeStudents(&head);
    return 0;
}
