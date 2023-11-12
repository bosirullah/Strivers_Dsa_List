#include <iostream>
using namespace std;

void triangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    triangle(n);
}