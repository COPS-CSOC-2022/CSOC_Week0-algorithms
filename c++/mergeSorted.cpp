#include <iostream>
#include <vector>

void merge(std::vector<int>& arr1, std::vector<int>& arr2, std::vector<int>& arr3) {
    int i{}, j{}, k{};
    int n1 = arr1.size();
    int n2 = arr2.size();

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        }    
        else {
            arr3[k++] = arr2[j++];
        }
    }
 
    while (i < n1) {
        arr3[k++] = arr1[i++];
    }

    while (j < n2) {
        arr3[k++] = arr2[j++];
    }
}

int main() {
    std::vector<int> arr1 = { 1, 3, 5, 9 };
    std::vector<int> arr2 = { -1, 0, 3, 6, 11 };

    std::cout << "The original arrays are: \n";
    std::cout << "arr1: ";
    for (const auto v : arr1) {
        std::cout << v << " ";
    }
    std::cout << "\n";

    std::cout << "arr2: ";
    for (const auto v : arr2) {
        std::cout << v << " ";
    }
    std::cout << "\n";

    std::vector<int> mergedArr;
    auto totalSize = arr1.size() + arr2.size();

    for (int i = 0; i < totalSize; ++i) {
        mergedArr.push_back(0);
    }

    merge(arr1, arr2, mergedArr);

    std::cout << "The merged array is: \n";
    for (const auto v : mergedArr) {
        std::cout << v << " ";
    }
    std::cout << "\n";

    int result{};

    if (totalSize % 2 == 0) {
        result = (mergedArr[(totalSize / 2) - 1] + mergedArr[(totalSize / 2)]) / 2;
    } 
    else {
        result = mergedArr[((totalSize + 1)/ 2) - 1];
    }
    std::cout << "The median of the two sorted arrays is: " << result << "\n";
}