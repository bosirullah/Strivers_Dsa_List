#include <iostream>
using namespace std;

void nLetterTriangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A';
        for (int j = n - 1; j >= i; j--)
        {
            cout << ch++ << " ";
        }

        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    nLetterTriangle(n);
}