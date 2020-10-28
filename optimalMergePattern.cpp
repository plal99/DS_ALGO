#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin >> num;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < num;i++)
    {
        int n;
        cin >> n;
        pq.push(n);
    }

    int count = 0;

    while(pq.size()>1)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        int temp = first + second;

        count += temp;

        pq.push(temp);
    }

    cout << count;
}