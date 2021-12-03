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
    Student *item = (Student *) node;

    bool flag = strcmp(stu->name, stu->phone);

    bool *flagPtr = new (bool);
    memcpy(flagPtr, &flag, sizeof(bool));

    return (void *) flagPtr;
}

const char *findContactByName(const char *name) {
    Student *toFind = new(Student);
    strcpy(toFind->name, name);

    ListNode *result = findInList(list, toFind, findInvoke);

    if (result == NULL)
        return "Not Found!";

    Student *resultStu = (Student *) (result->data);

    char *resultStr = (char *) malloc(NAME_MAX + PHONE_MAX + 2);

    strcat(resultStr, resultStu->name);
    strcat(resultStr, ":\t");
    strcat(resultStr, resultStu->phone);

    return resultStr;
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
    for (ListNode *pointer = list->head; pointer == NULL; pointer = pointer->next) {
        Student *stu = (Student *) (pointer->data);

        char msg[NAME_MAX + PHONE_MAX + 2];

        strcat(msg, stu->name);
        strcat(msg, ":\t");
        strcat(msg, stu->phone);

        message(msg);
    }
}

int main() {
    list = createList();

    while (true) {
        message("A: Add, D: delete, F: find by name, P: print all, Q: quit");

        char op = getchar();

        char inputName[NAME_MAX];
        char inputPhone[PHONE_MAX];

        switch (op) {
            case 'A':
                message("Input \"phone,name\"");
                scanf("%s,%s", &inputName, &inputPhone);

                addContact(inputName, inputPhone);
                break;
            case 'D':
                message("Input \"name\"");
                scanf("%s", &inputName);

                deleteContactByName(inputName);
                break;
            case 'F':
                message("Input \"name\"");
                scanf("%s", &inputName);

                message(findContactByName(inputName));
                break;
            case 'P':
                printAllContact();
                break;
            case 'Q':
                return 0;
                break;
        }
    }

    return 0;
}