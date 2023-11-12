#include <iostream>
using namespace std;

void nNumberTriangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= i; j--)
        {
            cout << n - j << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    nNumberTriangle(n);
}