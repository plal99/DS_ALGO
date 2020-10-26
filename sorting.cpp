#include<bits/stdc++.h>
using namespace std;

const int n = 13;

void show(int arr[]);
void bubble_sort(int arr[]);
void selection_sort(int arr[]);
void insertion_sort(int arr[]);

int main()
{
    int arr[] = {8, 9, 5, 6, 4, 6, 5, 2, 3, 2, 12, 56, 89};
    int size = sizeof(arr) / sizeof(arr[0]);
    show(arr);
    // bubble_sort(arr);
    // selection_sort(arr);
    // insertion_sort(arr);
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
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

// Selection sort
void selection_sort(int arr[])
{
    int min_idx;
    for (int i = 0; i < n;i++)
    {
        min_idx = i;
        for (int j = i + 1; j < n;j++)
        {
            if(arr[j]<arr[min_idx])
                min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
    }
}

// Insertion sort
void insertion_sort(int arr[])
{
    int temp,j;
    for (int i = 1; i < n;i++)
    {
        temp = arr[i];
        j = i - 1;

        while(j >= 0 and arr[j]>temp)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = temp;
    }
}

void merge_sort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = l + (l - r) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge_arr(arr, l, m, r);
    }
}
