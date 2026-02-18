#include <stdio.h>
// Function to swap two elements
void swap(int* a, int* b) {
int temp = *a;
*a = *b;
*b = temp;
}
// Function to heapify a subtree rooted with node i
void heapify(int arr[], int n, int i) {
int largest = i; // Initialize largest as root
int left = 2 * i + 1; // left child index
int right = 2 * i + 2; // right child index
// If left child is larger than root
if (left < n && arr[left] > arr[largest])
largest = left;
// If right child is larger than largest so far
if (right < n && arr[right] > arr[largest])
largest = right;
// If largest is not root
if (largest != i) {
swap(&arr[i], &arr[largest]);
// Recursively heapify the affected sub-tree
heapify(arr, n, largest);
}
}
// Function to perform heap sort
void heapSort(int arr[], int n) {
// Build heap (rearrange array)
for (int i = n / 2 - 1; i >= 0; i--)
heapify(arr, n, i);
// One by one extract an element from heap
for (int i = n - 1; i >= 0; i--) {
// Move current root to end
swap(&arr[0], &arr[i]);
// Call heapify on the reduced heap
heapify(arr, i, 0);
}
}
// Function to print an array
void printArray(int arr[], int n) {
for (int i = 0; i < n; i++)
printf("%d ", arr[i]);
printf("\n");
}
int main() {
int arr[] = {12, 11, 13, 5, 6, 7};
int n = sizeof(arr) / sizeof(arr[0]);
printf("Original array: ");
printArray(arr, n);
heapSort(arr, n);
printf("Sorted array: ");
printArray(arr, n);
return 0;
}
// This program performs heap sort, an efficient algorithm for sorting data. It
includes functions for swapping elements, heapifying a subtree, sorting using heap
sort, and printing an array. The swap function exchanges values of two elements.
The heapify function ensures that a subtree rooted at a given index maintains the
heap property by adjusting elements recursively. The heapSort function builds a max
heap from the array and then repeatedly extracts the largest element, placing it at
the end, and heapifies the remaining heap. The printArray function displays the
array elements. The main function sorts a sample array, displaying both the
original and sorted arrays.
