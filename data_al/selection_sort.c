/*
选择排序算法
随机生成数组并排序
gcc selection_sort.c -o selection_sort
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

//选择排序，每次循环找出最小元素，放到最前面
void selectionSort(int *arr, int n)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < n - 1; i++) {
        int min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (arr[min_index] < arr[i]) {
            int tmp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = tmp;
        }
    }
}

int main()
{
    int *arr = generateRandomArr(100, 1, 200);
    printArr(arr, 100);
    selectionSort(arr, 100);
    printArr(arr, 100);
    // 释放数组内存
    free(arr);
    return 0;
}