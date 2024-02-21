#include <vector>
#include <iostream>
#include <algorithm>

int countElementsGreaterThanTargetSorted(std::vector<int>& arr, int target) {
    int left = std::lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    int right = std::upper_bound(arr.begin(), arr.end(), target - 1) - arr.begin();
    return right - left;
}

int main() {
    std::vector<int> arr = {1, 2, 4, 5, 6, 8, 9};
    int target = 4;
    std::cout << countElementsGreaterThanTargetSorted(arr, target) << std::endl; // Output: 3
    return 0;
}
