#include <iostream>
using namespace std;

void alphaTriangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + n - 1;
        for (int j = 0; j <= i; j++)
        {
            cout << ch-- << " ";
        }

        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    alphaTriangle(n);
}