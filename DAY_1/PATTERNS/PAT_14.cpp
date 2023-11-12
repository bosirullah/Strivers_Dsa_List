#include <iostream>
using namespace std;

void nLetterTriangle(int n)
{
    char ch = 'A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << (char)(ch + j) << " ";
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