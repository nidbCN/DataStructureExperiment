#include <stdbool.h>

bool isOdd(int num) {
    return (bool) (num & 0x01);
}

bool isEven(int num) {
    return !isOdd(num);
}