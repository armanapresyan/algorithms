#include <iostream>
#include <vector>



int partition(std::vector<int>& arr, int low, int high) {
  int pivot = arr[low];
    int i = low;
    int j = high;
     while (i < j) {
        do {
            ++i;
        } while (pivot >= arr[i]);

        do {
            --j;
        } while (pivot < arr[j]);

        if (i < j) {
            std::swap(arr[i], arr[j]);
        }
    }
 
    std::swap(arr[low], arr[j]);
    
    return j;
      
}

void quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
