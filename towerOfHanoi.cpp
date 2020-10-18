#include <iostream>
using namespace std;

void hanoi(int n, char source, char destination, char auxilary);

int main()
{
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}

void hanoi(int n, char source, char destination, char auxilary)
{
    if (n == 1)
    {
        cout << "Move 1 from " << source << " to " << destination << "\n";
        return;
    }
    hanoi(n - 1, source, auxilary, destination);
    cout << "Move " << n << " from " << source << " to " << destination << "\n";
    hanoi(n - 1, auxilary, destination, source);
}