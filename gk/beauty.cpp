//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    std::pair<int, int> findFrequentAndLeastFrequent(const std::string& str) {
   
    vector<int> frequency(26, 0);

        // Count character frequencies
        for (char c : str) {
            frequency[c - 'a']++;
        }

        int mostFrequent = *max_element(frequency.begin(), frequency.end());
        int leastFrequent = *min_element(frequency.begin(), frequency.end());
        return {mostFrequent, leastFrequent};
        

    }
std::vector<std::string> findAllSubstrings(const std::string& s) {
    std::vector<std::string> substrings;

    for (size_t i = 0; i < s.length(); ++i) {
        for (size_t j = i; j < s.length(); ++j) {
            cout << s.substr(i, j - i + 1) << endl;
            substrings.push_back(s.substr(i, j - i + 1));
        }
    }

    return substrings;
}
    int beautySum(string s) {
               int ans = 0;
        
        //iterating over each character of the string.
        for (auto i = 0; i < s.size(); ++i) {
            int cnt[26] = {}, max_f = 0, min_f = 0;
            
            //iterating over subarrays starting from i.
            for (auto j = i; j < s.size(); ++j) {
                int idx = s[j] - 'a';
                //updating maximum frequency.
                max_f = max(max_f, ++cnt[idx]);
                
                //updating minimum frequency.
                if (min_f >= cnt[idx] - 1) {
                    min_f = cnt[idx];
                    for (int k = 0; k < 26; ++k)
                        //finding minimum frequency of all characters.
                        min_f = min(min_f, cnt[k] == 0 ? INT_MAX : cnt[k]);
                }
                
                //adding the difference between maximum and minimum frequency.
                ans += max_f - min_f;
            }
        }
        
        //returning the beauty sum.
        return ans;
           
           
           
           
           
           
           
           
           
           
           
           
           
           
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends