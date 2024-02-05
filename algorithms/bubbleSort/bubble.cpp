#include <iostream>

void bubbleSort(int* arr, int size) {
    bool flag = false;
    for (int i = 0; i < size; ++i) {
        flag = false; 
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = true; 
                std::cout << "aa" << "|";
            }
        }
        if (flag == false) {
          std::cout << "Yes";
            break;
        }
    }
}