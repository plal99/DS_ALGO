#include <bits/stdc++.h>
using namespace std;

struct Job
{
    char id;
    int deadline;
    int profit;
};

bool comparison(Job a, Job b);
void jobSequencing(Job arr[], int num);

int main()
{
    int num;
    cin >> num;
    Job arr[num];
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i].id;
        cin >> arr[i].profit;
        cin >> arr[i].deadline;
    }

    jobSequencing(arr, num);
}


bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}


void jobSequencing(Job arr[], int num)
{
    sort(arr, arr + num, comparison);

    int result[num];
    
    bool slot[num];
    memset(slot, 0, sizeof(slot));

    for (int i = 0; i < num; i++)
    {
        for (int j = min(num, arr[i].deadline)-1; j >= 0; j--)
        {
            if(slot[j] == false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    for (int i=0; i<num; i++)
    {
       if (slot[i] == true)
        cout << arr[result[i]].id << " ";
    }
}