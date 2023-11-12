#include <iostream>
using namespace std;

void alphaHill(int n)
{
    int gap = 2 * n - 2;
    for (int i = 0; i < n; i++)
    {
        char ch = 'A';
        for (int j = 0; j < gap; j++)
        {
            cout << " ";
        }

        for (int j = 0; j <= i; j++)
        {
            cout << ch++ << " ";
        }

        ch -= 2;
        for (int j = i; j > 0; j--)
        {
            cout << ch-- << " ";
        }

        gap -= 2;

        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    alphaHill(n);
}