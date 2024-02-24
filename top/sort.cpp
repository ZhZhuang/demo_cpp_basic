//
// Created by Administrator on 2023/11/15.
//

// 经典排序算法

//选择，冒泡，快排，归并

#include <stdio.h>
#include <stdlib.h>

void  swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void select_sort(int arry[], int len){
    int i, j;
    for(i=0;i<len-1;i++){
        int minindex = i;
        for(j=i+1;j<len;j++){
            if(arry[j] < arry[ minindex]){
                minindex = j;
            }
        }
        int temp = arry[minindex];
        arry[minindex] = arry[i];
        arry[i] = temp;

        // 交换变量
        //arry[minindex] ^= arry[i] ^= arry[minindex] ^= arry[i];
    }
}

void bubble_sort(int arry[], int len) {
    int i, j, temp;
    for (i = 0; i < len ; i++) {
        for (j = 0 ; j < len-i-1; j++) {
            if (arry[j] > arry[j + 1]) {
                temp = arry[j];
                arry[j] = arry[j + 1];
                arry[j + 1] = temp;
            }
        }
    }
}

// 用于归并排序的归并阶段
void merge(int *arr, int start, int mid, int end) {
    int *temp = (int *)malloc((end - start + 1) * sizeof(int));
    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= end) {
        temp[k++] = arr[j++];
    }

    // 将 temp数组中的数组复制给 arr
    for (i = 0; i < k; i++) {
        arr[start + i] = temp[i];
    }
    free(temp);
}

// 比较有难度
//void merge_sort(int arry[], int len){{
void merge_sort(int arry[], int start, int end) {
    //int mid = (end - start) / 2;  // 错误
    int mid = start + (end - start) / 2;
    if (start >= end)
        return;

    merge_sort(arry, start, mid);
    merge_sort(arry, mid + 1, end);
    merge(arry, start, mid, end);
}

//void quick_sort(int arry[], int len){
void quick_sort(int arry[], int low, int high) {
    int temp = arry[low];
    int i = low, j = high;
    if (low >= high)  //如果low >= high说明排序结束了
    {
        return;
    }
    while (i < j) {
        while (arry[j] >= temp && i < j) j--;
        if (arry[j] < temp) {
            swap(&arry[i], &arry[j]);
            ++i;
        }
        while (arry[i] <= temp && i < j) i++;
        if (arry[i] > temp) {
            swap(&arry[i], &arry[j]);
            --j;
        }
    }
    quick_sort(arry, low, i - 1);
    quick_sort(arry, i + 1, high);
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 10, 100, 99};
    int n = sizeof(arr) / sizeof(arr[0]);

    //select_sort(arr, n);
    //bubble_sort(arr,n);
    //quick_sort(arr,0,n-1);
    merge_sort(arr,0,n-1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }

    return 0;
}