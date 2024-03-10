/*
插入排序
就像打扑克牌一样，每次将未排序的牌插入到前面已排序的合适位置中
插入排序相对于选择排序来说，可以提前终止循环
特别是对于本身已经很有序或重复元素很多的数组来说，插入排序的效率会很高。
gcc insertion_sort.c -o insertion_sort
*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>

// 生成有n个元素的随机数组，每个元素的随机范围为[rangeL, rangeR]
int *generateRandomArr(int n, int rangeL, int rangeR)
{
    int i = 0;
    int *arr = (int *)malloc(n * sizeof(int));

    assert(rangeL <= rangeR);

    srand(time(NULL));
    for (i = 0; i < n; i++)
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
    return arr;
}

//打印数组中所有元素
void printArr(int *arr, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

//检查数组是否已被排序
int isSorted(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i+1])
            return -1;
    }
    return 0;
}

//插入排序
void insertionSort(int *arr, int n)
{
    int i = 0;
    int j = 0;

    for (i = 1; i < n; i++) {
        for (j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                int tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            } else {
                break;
            }
        }
    }
}

//第二种写法
void insertionSort_2(int *arr, int n)
{
    int i = 0;
    int j = 0;

    for (i = 1; i < n; i++) {
        for (j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            int tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
        }
    }
}

//插入排序改进
//在插入时，不是一个一个和前一张牌进行交换
//而是和我们打牌一样，找到最应该插入它的位置进行插入
//在它该插入位置后面的元素都需要向后挪一个位置
void insertionSort_3(int *arr, int n)
{
    int i = 0;
    int j = 0;

    for (i = 1; i < n; i++) {
        int e = arr[i];
        for (j = i; j > 0 && arr[j-1] > e; j--) {
            arr[j] = arr[j - 1]; //此时向后挪
        }
        arr[j] = e; //此时j的位置就是e该插入的位置
    }
}


int main()
{
    int *arr = generateRandomArr(1000, -200, 900);
    printArr(arr, 1000);
    insertionSort(arr, 1000);
    if (0 == isSorted(arr, 1000)) {
        printf("排序正确\n");
        printArr(arr, 1000);
    } else {
        printf("排序错误\n");
    }
    insertionSort_2(arr, 1000);
    if (0 == isSorted(arr, 1000)) {
        printf("排序正确\n");
        printArr(arr, 1000);
    } else {
        printf("排序错误\n");
    }
    insertionSort_3(arr, 1000);
    if (0 == isSorted(arr, 1000)) {
        printf("排序正确\n");
        printArr(arr, 1000);
    } else {
        printf("排序错误\n");
    }

    free(arr);
    return 0;
}