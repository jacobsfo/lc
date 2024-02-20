//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
          // Your code here
        vector<int> ans(1, -1);
        int right = 1, left = 0;
        long long sum = 0;
        if(s == 0){
            for(int i = 0; i<n; ++i){
                if(arr[i] == 0){
                    ans.push_back(i+1);
                    ans[0] = i+1;
                }
            }
        }
        else{
            while(right <= n && left <= right - 1){
                sum += arr[right - 1];
                while(sum >= s){
                    if(sum == s){
                        ans.push_back(right);
                        ans[0] = left+1;
                        return ans;
                    }
                    sum -= arr[left];
                    left ++;
                }
                right++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends