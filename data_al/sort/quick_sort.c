/*
快速排序
gcc quick_sort.c -o quick_sort

优化思路：
1.到底层时采用插入排序算法
2.partition时随机选取标定的元素
3.考虑等于标定的情况，分成小于，等于，大于三部分
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

// 返回索引p，使得arr[l...p-1] < arr[p], arr[p + 1...r] > arr[p]
int __partition(int *arr, int l, int r)
{
    int v = arr[l];

    int i = l;
    for(int j = l + 1; j <= r; j++) {
        if (arr[j] < v) {
            int tmp = arr[j];
            arr[j] = arr[i + 1];
            arr[i + 1] = tmp;
            i++;
        }
    }

    int tmp = arr[l];
    arr[l] = arr[i];
    arr[i] = tmp;

    return i;
}

// arr[l, r]进行快速排序
void __quickSort(int *arr, int l, int r)
{
    if (l >= r)
        return;
    int p = __partition(arr, l, r);
    __quickSort(arr, l, p - 1);
    __quickSort(arr, p + 1, r);
}

void quickSort(int *arr, int n)
{
    __quickSort(arr, 0, n-1);
}

int main()
{
    int *arr = generateRandomArr(100, 2, 900);
    printArr(arr, 100);
    quickSort(arr, 100);
    if (0 == isSorted(arr, 100)) {
        printf("排序正确\n");
        printArr(arr, 100);
    } else {
        printf("排序错误\n");
    }
    return 0;
}