#include <iostream>
using namespace std;

void numberCrown(int n)
{
    int gap = 2 * n + 3;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i + 1; j++)
        {
            cout << j << " ";
        }

        for (int j = 0; j < gap; j++)
        {
            cout << " ";
        }

        for (int j = i + 1; j > 0; j--)
        {
            cout << j << " ";
        }

        gap -= 4;

        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    numberCrown(n);
}