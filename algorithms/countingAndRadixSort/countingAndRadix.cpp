#include <iostream>
#include <vector>


int getMax(const std::vector<int>& arr) {
    int max = arr[0];
    for (int i : arr) {
        if (i > max) {
            max = i;
        }
    }
    return max;
}

void countingSort(std::vector<int>& arr, int exp) {
    const int n = arr.size();
    std::vector<int> output(n, 0);
    std::vector<int> count(10, 0);

    for (int i = 0; i < n; ++i) {
        count[(arr[i] / exp) % 10]++;
    }

    
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    std::copy(output.begin(), output.end(), arr.begin());
}


void radixSort(std::vector<int>& arr) {
    int max = getMax(arr);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}