#include <stdio.h>

#include "generated/spm_config.h"

int main() {
    int *myArray = (int *)DSPM_START_ADDRESS;
    myArray[5] = 10;
    myArray[3] = myArray[5];
    printf("[3]:%d, [5]:%d\n", myArray[3], myArray[5]);
    return 0;
}