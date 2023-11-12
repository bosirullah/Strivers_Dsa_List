#include <iostream>
using namespace std;

void nStarTriangle(int n)
{
    int gap = 0, stars = 2 * n - 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < gap; j++)
        {
            cout << " ";
        }

        for (int j = gap; j < gap + stars; j++)
        {
            cout << "*";
        }

        gap++;
        stars -= 2;

        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    nStarTriangle(n);
}