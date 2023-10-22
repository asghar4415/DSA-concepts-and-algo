#include <iostream>

using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
    if (x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool ratinMaze(int **arr, int x, int y, int n, int **solArray)
{
    if (x == n - 1 && y == n - 1)
    {
        solArray[x][y] = 1;
        return true;
    }
    if (isSafe(arr, x, y, n))
    {
        solArray[x][y] = 1;
        if (ratinMaze(arr, x + 1, y, n, solArray))
        {

            return true;
        }
        if (ratinMaze(arr, x, y + 1, n, solArray))
        {
            return true;
        }
        solArray[x][y] = 0; //backtracking
        return false;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    int **solArray = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solArray[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            solArray[i][j] = 0;
        }
    }
    cout << "Enter the maze" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    

    if (ratinMaze(arr, 0, 0, n, solArray))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solArray[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}