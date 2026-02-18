#include <bits/stdc++.h>
using namespace std;

// Max-Heapify a subtree rooted at index i
void maxHeapify(int arr[], int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left child
    int right = 2 * i + 2; // right child

    // If left child is larger
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest); // Recursively heapify the affected subtree
    }
}

// Convert Min Heap to Max Heap
void convertMinToMaxHeap(int arr[], int n)
{
    // Start from last non-leaf node and heapify each node
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}

