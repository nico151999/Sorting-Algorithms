#include <stdio.h>
#include <time.h>

/*
My personal implementations of some sorting algorithms in C
The main goal was to write sorting functions which do not require any helper functions
*/

void setArray(int array[], int arrayReference[], int arrayLength);
void bubbleSort(int array[], int length);
void insertSort(int array[], int length);
void selectSort(int array[], int length);
void quickSort(int array[], int left, int right);
void mergeSort(int array[], int left, int right);

int main() {
    clock_t time;
    double time_taken;
    // array with some sample values
    int arrayReference[] = {1234, 32523, 4234, 324, 3, 324, 234, 234, 234, 23, 54234, 5, 325, 8979, 900, 0, 324, 567,
                            56757, 768, 67867, 457, 3167, 13567, 6575, 346, 9890, 36564, 1345, 657568, 653, 346247,
                            6538, 563865, 68587, 4785876, 463, 74847, 8970, 4, 768, 7648678, 768567, 6787, 67356, 67,
                            4, 67, 6, 8, 9, 0, 1456, 457, 6757, 6758, 678, 7865, 88, 67, 5634, 674, 77, 6, 467, 657};
    int arrayLength = sizeof(arrayReference) / sizeof(int);
    int array[arrayLength];

    setArray(array, arrayReference, arrayLength);
    time = clock();
    bubbleSort(array, arrayLength);
    time = clock() - time;
    time_taken = ((double) time) / CLOCKS_PER_SEC;
    printf("\nBubbleSort hat %f Sekunden gebraucht\n", time_taken);
    printf("Per BubbleSort sortiert:\n");
    for (int i = 0; i < arrayLength; i++) {
        printf("%d\n", array[i]);
    }

    setArray(array, arrayReference, arrayLength);
    time = clock();
    insertSort(array, arrayLength);
    time = clock() - time;
    time_taken = ((double) time) / CLOCKS_PER_SEC;
    printf("\nInsertSort hat %f Sekunden gebraucht\n", time_taken);
    printf("Per InsertSort sortiert:\n");
    for (int i = 0; i < arrayLength; i++) {
        printf("%d\n", array[i]);
    }

    setArray(array, arrayReference, arrayLength);
    time = clock();
    selectSort(array, arrayLength);
    time = clock() - time;
    time_taken = ((double) time) / CLOCKS_PER_SEC;
    printf("\nSelectSort hat %f Sekunden gebraucht\n", time_taken);
    printf("Per SelectSort sortiert:\n");
    for (int i = 0; i < arrayLength; i++) {
        printf("%d\n", array[i]);
    }

    setArray(array, arrayReference, arrayLength);
    time = clock();
    quickSort(array, 0, (arrayLength - 1));
    time = clock() - time;
    time_taken = ((double) time) / CLOCKS_PER_SEC;
    printf("\nQuickSort hat %f Sekunden gebraucht\n", time_taken);
    printf("Per QuickSort sortiert:\n");
    for (int i = 0; i < arrayLength; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}

void setArray(int array[], int arrayReference[], int arrayLength) {
    for (int i = 0; i < arrayLength; i++) {
        array[i] = arrayReference[i];
    }
}

void bubbleSort(int array[], int length) {
    int i, j, cache;
    for (i = 0; i < (length - 1); i++) {
        for (j = 0; j < (length - 1); j++) {
            if (array[j] > array[j + 1]) {
                cache = array[j];
                array[j] = array[j + 1];
                array[j + 1] = cache;
            }
        }
    }
}

void insertSort(int array[], int length) {
    int i, j, cache;
    for (i = length; i > 0; i--) {
        for (j = 1; j < i; j++) {
            if (array[j] < array[j - 1]) {
                cache = array[j];
                array[j] = array[j - 1];
                array[j - 1] = cache;
            }
        }
    }
}

void selectSort(int array[], int length) {
    int i, j, curMinIndex, cache;
    for (i = 0; i < (length - 1); i++) {
        curMinIndex = i;
        for (j = i + 1; j < length; j++) {
            if (array[j] < array[curMinIndex]) {
                curMinIndex = j;
            }
        }
        if (curMinIndex != i) {
            cache = array[curMinIndex];
            array[curMinIndex] = array[i];
            array[i] = cache;
        }
    }
}

void quickSort(int array[], int left, int right) {
    int i;
    int lengthLow = 0;
    int lengthHigh = 0;
    int cacheLow[right - left];
    int cacheHigh[right - left];
    for (i = left; i < right; i++) {
        if (array[i] > array[right]) {
            cacheHigh[lengthHigh] = array[i];
            lengthHigh++;
        } else {
            cacheLow[lengthLow] = array[i];
            lengthLow++;
        }
    }

    if (lengthLow != 0) {
        for (i = 0; i < lengthLow; i++) {
            array[i + left] = cacheLow[i];
        }
    }
    array[lengthLow + left] = array[right];
    if (lengthHigh != 0) {
        for (i = 0; i < lengthHigh; i++) {
            array[i + lengthLow + 1 + left] = cacheHigh[i];
        }
    }
    if (lengthLow > 1) {
        quickSort(array, left, (left + lengthLow - 1));
    }

    if (lengthHigh > 1) {
        quickSort(array, (left + lengthLow + 1), right);
    }
}

void mergeSort(int array[], int left, int right) {
    int middle = (right + left) / 2;
    if ((right + left) % 2 == 0) {

    }
    int arrA[] =
}