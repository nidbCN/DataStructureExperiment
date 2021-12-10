#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "DataStructureUtil.h"
#include "LinkedList.h"
#include "Contact.h"

LinkedList *list;

void *findInvoke(void *find, void *node) {
    Student *stu = (Student *) find;

    bool flag = strcmp(stu->name, stu->phone);

    bool *flagPtr = new (bool);
    memcpy(flagPtr, &flag, sizeof(bool));

    return (void *) flagPtr;
}

void findContactByName(const char *name) {
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

void addContact(const char *name, const char *phone) {
    Student *stu = new(Student);
    strcpy(stu->name, name);
    strcpy(stu->phone, phone);

    addLastToList(list, (void *) stu, sizeof(Student));
}

void deleteContactByName(const char *name) {
    Student *toFind = new(Student);
    strcpy(toFind->name, name);

    ListNode *result = findInList(list, toFind, findInvoke);

    if (result != NULL) {
        removeInList(list, result);
    }
}

void printAllContact() {
    for (ListNode *pointer = list->head; pointer != NULL; pointer = pointer->next) {
        Student *stu = (Student *) (pointer->data);

        printf("%s:\t%s\n", stu->name, stu->phone);
    }
}

int main() {
    list = createList();

    while (true) {
        printf("%s\n", "A: Add, D: delete, F: find by name, P: print all, Q: quit");

        char op = EOF;
        while (op == '\n' || op == 0 || op == ' ' || op == EOF) {
            op =(char ) getchar();
        }

        char inputName[NAME_MAX];
        char inputPhone[PHONE_MAX];

        switch (op) {
            case 'A':
                printf("%s\n", "Input \"phone name\"");
                scanf("%s %s", &inputName, &inputPhone);

                addContact(inputName, inputPhone);
                break;
            case 'D':
                printf("%s\n", "Input \"name\"");
                scanf("%s", &inputName);

                deleteContactByName(inputName);
                break;
            case 'F':
                printf("%s\n", "Input \"name\"");
                scanf("%s", &inputName);

                findContactByName(inputName);
                break;
            case 'P':
                printAllContact();
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