#include <iostream>
using namespace std;

void nBinaryTriangle(int n)
{
    int zero = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if ((i + j) % 2 == 0)
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    nBinaryTriangle(n);
}