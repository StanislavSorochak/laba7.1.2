#include <iostream>
#include <time.h>
#include <Windows.h>
#include <iomanip>

using namespace std;
void Create(int** a, const int row, const int col, const int low, const int high, int i, int j);
void Print(int** a, const int row, const int col, int i, int j);
void Sort(int** a, const int row, const int col, int i, int j);
void Zamina(int** a, const int row, const int col, int i, int j);
int Sum(int** a, const int row, const int col, int i, int j, int S);
void Change(int** a, const int row0, const int row1, const int col);

int main()
{

    srand((unsigned)time(NULL));

    using std::cout;
    using std::endl;

    int low = -41;
    int high = 23;

    int row = 7;
    int col = 9;
    int** a = new int* [row];
    for (int i = 0; i < row; i++)
        a[i] = new int[col];

    Create(a, row, col, low, high, 0, 0); cout << endl;
    Print(a, row, col, 0, 0); cout << endl;

    Print(a, row, col, 0, 0); cout << endl;
    Zamina(a, row, col, 0, 0); cout << endl; cout << endl;


    for (int i = 0; i < row; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
void Create(int** a, const int row, const int col, const int low, const int high, int i, int j)
{
    if (j < col)
    {
        a[i][j] = low + rand() % (high - low + 1);
        return Create(a, row, col, low, high, i, j + 1);
    }
    if (i < row - 1)
        return Create(a, row, col, low, high, i + 1, 0);
}
void Print(int** a, const int row, const int col, int i, int j)
{
    if (j < col)
    {
        cout << setw(4) << a[i][j];
        return Print(a, row, col, i, j + 1);
    }
    cout << endl;
    if (i < row - 1)
        return Print(a, row, col, i + 1, 0);
}
void Zamina(int** a, const int row, const int col, int i, int j)
{
    if (j < col)
    {
        if ((!(i % 2) || !(j & 2)) && (!(a[i][j] > 0)))
            cout << setw(4) << 0;
        else
            cout << setw(4) << a[i][j];
        return Zamina(a, row, col, i, j + 1);
    }
    if (i < row - 1)
    {
        cout << endl;
        return Zamina(a, row, col, i + 1, 0);
    }
}
int Sum(int** a, const int row, const int col, int i, int j, int S)
{
    if ((!(i % 2) || !(j & 2)) && (!(a[i][j] > 0))) if (((a[i][j] < 0) && !(a[i][j] % 4 == 0)))
    {
        S += a[i][j];
        return Sum(a, row, col, i, j + 1, S);
    }
    else
        return Sum(a, row, col, i, j + 1, S);
    if (i < row - 1)
        return Sum(a, row, col, i + 1, 0, S);
    return S;
}
void Sort(int** a, const int row, const int col, int i, int j)
{
    if (j < col)
    {
        if ((a[j][0] < a[j + 1][0])
            ||
            (a[j][0] == a[j + 1][0] &&
                a[j][1] < a[j + 1][1])
            ||
            (a[j][0] == a[j + 1][0] &&
                a[j][1] == a[j + 1][1] &&
                a[j][2] > a[j + 1][2]))
            Change(a, j, j + 1, col);
        return Sort(a, row, col, i, j + 1);
    }
    if (i < row - 1)
        return Sort(a, row, col, i + 1, 0);
}
void Change(int** a, const int row0, const int row1, const int col)
{
    int temp;
    for (int k = 0; k < col; k++)
    {
        temp = a[row0][k];
        a[row0][k] = a[row1][k];
        a[row1][k] = temp;
    }
}
