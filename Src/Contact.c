#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "DataStructureUtil.h"
#include "LinkedList.h"
#include "Contact.h"

bool findInvoke(void *find, void *node) {
    Student *student = (Student *) find;
    Student *current = (Student *) node;

    return (bool) strcmp(student->name, current->name);
}

void findContactByName(LinkedList *list, const char *name) {
    Student *toFind = new(Student);
    strcpy(toFind->name, name);

    ListNode *result = findInList(list, toFind, findInvoke);

    if (result == NULL) {
        printf("%s\n", "Not Found!");
    } else {
        Student *resultStu = (Student *) (result->data);

        printf("%s:\t%s\n", resultStu->name, resultStu->phone);
    }
}

void addContact(LinkedList *list, const char *name, const char *phone) {
    Student *stu = new(Student);
    strcpy(stu->name, name);
    strcpy(stu->phone, phone);

    addLastToList(list, (void *) stu, sizeof(Student));
}

void deleteContactByName(LinkedList *list, const char *name) {
    Student *toFind = new(Student);
    strcpy(toFind->name, name);

    ListNode *result = findInList(list, toFind, findInvoke);

    if (result != NULL) {
        removeInList(list, result);
    }
}

void printAllContact(LinkedList *list) {
    traverseList(list, $(bool, (int index, ListNode *node){
            printf("[%d]%s:\t%s\n", index, ((Student *) (node->data))->name, ((Student *) (node->data))->phone);
            return true;
    }));

    /*
    for (ListNode *pointer = list->head; pointer != NULL; pointer = pointer->next) {
        Student *stu = (Student *) (pointer->data);
    }
    */
}

int main() {
    LinkedList *list = _createList();

    while (true) {
        printf("%s\n", "A: Add, D: delete, F: find by name, P: print all, Q: quit");

        char op = EOF;
        while (op == '\n' || op == 0 || op == ' ' || op == EOF) {
            op = (char) getchar();
        }

        char inputName[NAME_MAX];
        char inputPhone[PHONE_MAX];

        switch (op) {
            case 'A':
                printf("%s\n", "Input \"name phone\"");
                scanf("%s %s", inputName, inputPhone);

                addContact(list, inputName, inputPhone);
                break;
            case 'D':
                printf("%s\n", "Input \"name\"");
                scanf("%s", inputName);

                deleteContactByName(list, inputName);
                break;
            case 'F':
                printf("%s\n", "Input \"name\"");
                scanf("%s", inputName);

                findContactByName(list, inputName);
                break;
            case 'P':
                printAllContact(list);
                break;
            case 'Q':
                return 0;
                break;
            default:
                printf("%s\n", "UnKnow command");
        }
    }

    return 0;
}