//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isValid(string s)
    {
        map<char,char>m=
        {
            {')','('},
            {']','['},
            {'}','{'}
        };

        stack<int>st;
        //if find closedin str check open in st, pop if true
        for(int i = 0; i<s.size();i++)
        {
            if(m.find(s[i])!=m.end())
            {
                if(!st.empty() && m[s[i]]==st.top())
                {
                     st.pop();
                }
                else
                {
                    return false;
                }
            }
            else{
                st.push(s[i]);
            }
            
        }
        return st.empty();
    }
    int maxLength(string s){
        
        stack<int> stk;
        int maxLength = 0;
        stk.push(-1); // Initialize the stack with a base index

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (!stk.empty()) {
                    // Calculate the length of the current valid substring
                    maxLength = max(maxLength, i - stk.top());
                } else {
                    // If the stack is empty, push the current index as a new base
                    stk.push(i);
                }
            }
        }

        return maxLength;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends