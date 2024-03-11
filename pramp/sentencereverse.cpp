#include <iostream>
#include <vector>

using namespace std;
//bs with out search
void mirrorReverse(vector<char>& arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

vector<char> reverseWords(const vector<char>& arr) {
    vector<char> result(arr); // Make a copy to keep the original array unchanged
    int n = result.size();
    
    // Reverse all characters
    mirrorReverse(result, 0, n - 1);

    // Reverse each word
    int wordStart = -1;
    for (int i = 0; i < n; i++) {
        if (result[i] == ' ') {
            if (wordStart != -1) {
                mirrorReverse(result, wordStart, i - 1);
                wordStart = -1;
            }
        } else if (i == n - 1) {
            if (wordStart != -1) {
                mirrorReverse(result, wordStart, i);
            }
        } else {
            if (wordStart == -1) {
                wordStart = i;
            }
        }
    }
    return result;
}

int main() {
      vector<char> arr = {'p', 'e', 'r', 'f', 'e', 'c', 't', ' ',
                        'm', 'a', 'k', 'e', 's', ' ',
                        'p', 'r', 'a', 'c', 't', 'i', 'c', 'e'};
    
    vector<char>a = reverseWords(arr);
    for (char c : a) {
        cout << c;
    }
    cout << endl;

    return 0;
}