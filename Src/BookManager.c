#include "Sort.h"
#include "BookManager.h"
#include "DataStructureUtil.h"


int cmp(const void *v1, const void *v2) {
    int value1 = *(int *) v1;
    int value2 = *(int *) v2;
    if (value1 > value2) return 1;
    else if (value1 == value2) return 0;
    else return -1;
}


int main() {
    int array[5] = {9, 1, 5, 4, 8};

    quickSort(int, array, cmp);

    for (int i = 0; i < 5; ++i) {
        printf("%d,", array[i]);
    }
}
