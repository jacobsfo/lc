#include <vector>
#include <iostream>

int countElementsGreaterThanTarget(std::vector<int>& arr, int target) {
    int count = 0;
    for (int num : arr) {
        if (num > target) {
            count++;
        }
    }
    return count;
}

int main() {
    std::vector<int> arr = {5, 2, 8, 6, 1, 9};
    int target = 4;
    std::cout << countElementsGreaterThanTarget(arr, target) << std::endl; // Output: 4
    return 0;
}
