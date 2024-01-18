#include <iostream>
using namespace std;
// Function of partition parts:
int partition(int arr[], int start, int end)
{
    // pivot element :
    int pivot = arr[start];
    // counting the place where pivot index should be placed:
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    // Place pivot at right position:
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    // In this, it will see left and right and placed the values accordingly:
    int i = start;
    int j = end;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
// Function of quick sort is:
void quickSort(int *arr, int start, int end)
{
    // Base case:
    if (start >= end)
    {
        return;
    }
    // Partition parts:
    int p = partition(arr, start, end);
    // left part of an array:
    quickSort(arr, start, p - 1);
    // Right part of an array:
    quickSort(arr, p + 1, end);
}
int main()
{
    // Quick sort:
    int arr[8] = {6,6,-6, -2, -4, -6, 2, -6};
    int size = 8;
    int start = 0;
    int end = size - 1;
    quickSort(arr, start, end);
    cout << "The Quick sorted array is: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}