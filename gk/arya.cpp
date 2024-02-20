//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int fun(string s, int k, int n, char c) {
    // code here
        int len=s.length();
    int idx=n%len;
    int m=n/len;
    int cnt=0,ans=0;
    for(int i=0;i<len;i++){
        if(s[i]==c){
            cnt++;
            if(i<idx)ans++;
        }
    }
    ans+=m*cnt;
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t, i, n, k;
    char c;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cin >> k >> n >> c;
        Solution ob;
        cout << ob.fun(s, k, n, c) << endl;
    }
    return 0;
}

// } Driver Code Ends