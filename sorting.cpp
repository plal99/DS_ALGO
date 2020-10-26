#include <bits/stdc++.h>
using namespace std;

const int n = 13;

void show(int arr[]);
void bubble_sort(int arr[]);
void selection_sort(int arr[]);
void insertion_sort(int arr[]);
void merge_sort(int *array, int l, int r);
void merge_(int *array, int l, int m, int r);

int main()
{
    int arr[] = {8, 9, 5, 6, 4, 6, 5, 2, 3, 2, 12, 56, 89};
    int size = sizeof(arr) / sizeof(arr[0]);
    show(arr);
    // bubble_sort(arr);
    // selection_sort(arr);
    // insertion_sort(arr);
    merge_sort(arr, 0, n - 1);
    show(arr);
}

// For printing all the elements
void show(int arr[])
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// Bubble sort
void bubble_sort(int arr[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

// Selection sort
void selection_sort(int arr[])
{
    int min_idx;
    for (int i = 0; i < n; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
    }
}

// Insertion sort
void insertion_sort(int arr[])
{
    int temp, j;
    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;

        while (j >= 0 and arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = temp;
    }
}

void merge_sort(int *array, int l, int r)
{
    int m;
    if (l < r)
    {
        int m = l + (r - l) / 2;
        // Sort first and second arrays
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge_(array, l, m, r);
    }
}

void merge_(int *array, int l, int m, int r)
{
    int i, j, k, nl, nr;
    //size of left and right sub-arrays
    nl = m - l + 1;
    nr = r - m;
    int larr[nl], rarr[nr];
    //fill left and right sub-arrays
    for (i = 0; i < nl; i++)
        larr[i] = array[l + i];
    for (j = 0; j < nr; j++)
        rarr[j] = array[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    //marge temp arrays to real array
    while (i < nl && j < nr)
    {
        if (larr[i] <= rarr[j])
        {
            array[k] = larr[i];
            i++;
        }
        else
        {
            array[k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < nl)
    { //extra element in left array
        array[k] = larr[i];
        i++;
        k++;
    }
    while (j < nr)
    { //extra element in right array
        array[k] = rarr[j];
        j++;
        k++;
    }
}