#include <vector>
int solution(vector<int> coins, vector<int> quantity) {
     int n = coins.size();
    std::unordered_set<int> distinctSums;

    for (int i = 0; i < n; ++i) {
        std::unordered_set<int> currentSums;

        // Iterate through each quantity of the current coin
        for (int j = 1; j <= quantity[i]; ++j) {
            // Calculate sums for the current quantity
            for (int sum : distinctSums) {
                currentSums.insert(sum + j * coins[i]);
            }
            currentSums.insert(j * coins[i]);
        }

        // Add sums from the current coin to the overall distinct sums set
        distinctSums.insert(currentSums.begin(), currentSums.end());
    }

    // The size of distinctSums is the number of distinct sums
    return distinctSums.size();
    
    
}
