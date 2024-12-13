#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
using namespace std;

const int N = 1e5 + 10;
int a[N];

int partition(int low, int high)
{
    int pivot = a[low];
    int i = low, j = high;

    while (i < j)
    {
        // Find the leftmost element greater than or equal to the pivot
        while (a[i] <= pivot && i < high)
        {
            i++;
        }
        // Find the rightmost element smaller than the pivot
        while (a[j] > pivot && j > low)
        {
            j--;
        }

        if (i < j)
        {
            swap(a[i], a[j]);
        }
    }

    swap(a[low], a[j]); // Place pivot at its correct position
    return j;           // Return the position of the pivot
}

void quickSort(int low, int high)
{
    if (low < high)
    {
        int par = partition(low, high);
        quickSort(low, par - 1);
        quickSort(par + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    quickSort(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}