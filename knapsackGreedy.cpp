#include <bits/stdc++.h>
using namespace std;

struct Objects
{
    int object;
    int profit;
    int weight;
};

bool comparison(Objects a, Objects b);
void Sacking(Objects arr[], int num, int knapSize);

int main()
{
    int knapSize;
    cin >> knapSize;
    int num;
    cin >> num;
    Objects arr[num];
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i].object;
        cin >> arr[i].profit;
        cin >> arr[i].weight;
    }

    Sacking(arr, num, knapSize);
}


bool comparison(Objects a, Objects b)
{
    return (float(a.profit/a.weight) > float(b.profit/b.weight));
}


void Sacking(Objects arr[], int num, int knapSize)
{
    sort(arr, arr + num, comparison);

    int i = 0, rem = 0, prof[num];
    float profit = 0, fraction = 0;
    int k = 0;
    while(knapSize >= 0)
    {
        if(knapSize - arr[i].weight >= 0)
        {
            profit += arr[i].profit;
            prof[k++] = i;
            knapSize -= arr[i].weight;
        }
        else
        {
            fraction = (float)knapSize / (float)arr[i].weight;
            profit += fraction * arr[i].profit;
            prof[k++] = i;
            break;
        }
        i++;
    }

    cout << fraction << "\n";
    cout << profit << "\n";
    for (int i=0; i<k; i++)
    {
        cout << arr[prof[i]].object << " ";
    }
}