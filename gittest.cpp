//写出cpp普遍需要的头文件
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iterator>
#include <fstream>
//写出快速排序的代码
void quickSort(int *arr, int left, int right)
{
    if (left >= right)
        return;
    int i = left, j = right;
    int key = arr[left];
    while (i < j)
    {
        while (i < j && arr[j] >= key)
            j--;
        arr[i] = arr[j];
        while (i < j && arr[i] <= key)
            i++;
        arr[j] = arr[i];
    }
    arr[i] = key;
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}
//写出归并排序的代码
void mergeSort(int *arr, int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) >> 1;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    int i = left, j = mid + 1, k = 0;
    int *temp = new int[right - left + 1];
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (int i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
    delete[] temp;
}
//写出堆排序的代码
void heapSort(int *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        int j = i;
        while (j * 2 + 1 < n)
        {
            int k = j * 2 + 1;
            if (k + 1 < n && arr[k] < arr[k + 1])
                k++;
            if (arr[j] < arr[k])
                swap(arr[j], arr[k]);
            j = k;
        }
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        int j = 0;
        while (j * 2 + 1 < i)
        {
            int k = j * 2 + 1;
            if (k + 1 < i && arr[k] < arr[k + 1])
                k++;
            if (arr[j] < arr[k])
                swap(arr[j], arr[k]);
            j = k;
        }
    }
}
