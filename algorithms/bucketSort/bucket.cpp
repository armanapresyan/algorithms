#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

void insertionSort(std::list<double>& lst) {
    for (auto it = std::next(lst.begin()); it != lst.end(); ++it) {
        double key = *it;
        auto j = it;
        while (j != lst.begin() && *std::prev(j) > key) {
            --j;
        }
        lst.erase(it);
        lst.insert(j, key);
    }
}

void bucket(std::vector<double> A) {
    std::vector<double> B;
    double maxElement = *std::max_element(A.begin(), A.end());
    double minElement = *std::min_element(A.begin(), A.end());
    
    for (int i = 0; i < A.size(); ++i) {
        B.push_back((A[i] - minElement) / (maxElement - minElement));
    }
    
    int n = B.size();
    std::vector<std::list<double>> ds(n);
    
    for (int i = 0; i < n; ++i) {
        ds[int(n * B[i])].push_front(B[i]);
    }
    
    int i = 0;
    for (auto& x : ds) {
        insertionSort(x);
        for (auto& y : x) {
            if (i < A.size()) {
                A[i] = y * (maxElement - minElement) + minElement;  
                ++i;
            }
        }
    }

    for (int i = 0; i < A.size(); ++i) {
        std::cout << A[i] << " ";
    }
}

