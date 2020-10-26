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
    show(arr);
    // bubble_sort(arr);
    // selection_sort(arr);
    insertion_sort(arr);
    show(arr);
}

void show(int arr[])
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}


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