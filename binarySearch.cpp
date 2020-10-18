#include <bits/stdc++.h>
using namespace std;

int binarysearch(vector<int> arr, int low, int high, int n);

int main()
{
    vector<int> arr;
    for (int i = 0; i < 25; i++)
    {
        arr.push_back(i);
    }

    sort(arr.begin(), arr.end());
    int n;
    cout << "Enter num : ";
    cin >> n;
    cout << "Position is: " << binarysearch(arr, 0, arr.size()-1, n);

    return 0;
}

int binarysearch(vector<int> arr, int low, int high, int n)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == n)
            return mid;

        (n < arr[mid]) ? high = mid - 1 : low = mid + 1;
    }

    return -1;
}