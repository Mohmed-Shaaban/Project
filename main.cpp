#include <iostream>
#include <vector>
using namespace std;


void heapify(vector<int>& arr, int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to perform Heap Sort
void heapSort(vector<int>& arr)
{
    int n = arr.size();

    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        // Move the current root to the end
        swap(arr[0], arr[i]);


        heapify(arr, i, 0);
    }
}


void printArray(const vector<int>& arr)
{
    for (int val : arr)
        cout << val << " ";
    cout << endl;
}

int main()
{

    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    printArray(arr);


    heapSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
