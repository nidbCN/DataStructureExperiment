#include "BookManager.h"
#include "Sort.h"
#include "DataStructureUtil.h"

#define NAME_MAX 12

enum major {
    AI, Security, IoT, BigData,
};

typedef struct borrowCard {
    int number;
    char name[NAME_MAX];
    enum major majorIn;
    int class;
} BorrowCard;

typedef struct indexItem {
    int length;
    BorrowCard *start;
} IndexItem;

char *majorTable[] = {"AI", "Security", "IoT", "BigData"};
#define showMajor(code) (majorTable[code])

#define LENGTH (6)
#define MAJOR_NUM (4)

void showTable(BorrowCard arr[]) {
    for (int i = 0; i < LENGTH * MAJOR_NUM; ++i) {
        BorrowCard card = arr[i];
        if (card.number > 0) {
            printf("%s %d: %d-%s", showMajor(card.majorIn), card.class, card.number, card.name);
        }
    }
}


int indexFromMajor(const char *str) {
    // calculate index from major string
    int code = (int) str[0];
    int index = ((int[]) {AI, IoT, 0, 0, Security, 0, BigData})[((code / 10) * (code % 10)) % 10];
    return index;
}

int main() {
    BorrowCard mainTable[LENGTH * MAJOR_NUM];
    for (int i = 0; i < LENGTH * MAJOR_NUM; ++i) {
        mainTable[i].majorIn = 0;
        mainTable[i].number = -1;
        mainTable[i].class = -1;
    }

    IndexItem indexTable[MAJOR_NUM];
    for (int i = 0; i < MAJOR_NUM; ++i) {
        indexTable[i].length = 0;
        indexTable[i].start = NULL;
    }

    for (int i = 0; i < LENGTH; ++i) {
        BorrowCard newCard;
        printf("%s\n", "Please input \"number name major class\":");
        char majorName[10];
        scanf("%d %s %s %d", &newCard.number, newCard.name, majorName, &newCard.class);

        int index = indexFromMajor(majorName);

        int majorNum = indexTable[index].length++;
        newCard.majorIn = index;
        mainTable[LENGTH * newCard.majorIn + majorNum] = newCard;

        if (majorNum == 0) {
            indexTable[index].start = &mainTable[6 * newCard.majorIn + majorNum];
        }


    }

    printf("%s\n", "Sort by number");
    // sort via num
    quickSort(int, mainTable, $(int, (const void *v1, const void*v2){
            BorrowCard value1 = *(BorrowCard *) v1;
            BorrowCard value2 = *(BorrowCard *) v2;
            if (value1.number > value2.number) return 1;
            else if (value1.number == value2.number) return 0;
            else return -1;
    }));
    showTable(mainTable);

    printf("%s\n", "Sort by class");
    // sort via class
    quickSort(int, mainTable, $(int, (const void *v1, const void*v2){
            BorrowCard value1 = *(BorrowCard *) v1;
            BorrowCard value2 = *(BorrowCard *) v2;
            if (value1.class > value2.class) return 1;
            else if (value1.class == value2.class) return 0;
            else return -1;
    }));
    showTable(mainTable);

    printf("%s\n", "Please input a major name:");
    char majorName[10];
    scanf("%s", majorName);
    int majorIndex = indexFromMajor(majorName);
    IndexItem item = indexTable[majorIndex];
    BorrowCard *start = item.start;
    for (int i = 0; i < item.length; ++i) {
        printf("%s %d: %d-%s", showMajor((*start).majorIn), (*start).class, (*start).number, (*start).name);
        start++;
    }

    return 0;
}
