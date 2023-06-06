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
    if (left <= right)
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
