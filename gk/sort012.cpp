//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
    void sort012(int a[], int n)
    {
        // code here 
       //0 array
       //1 array
       //2 array
       vector<int>vec1,vec2,vec3;
       for(int i = 0; i<n;i++)
       {
           if(a[i]==0)
           {
               vec1.push_back(0);
           }
            if(a[i]==1)
           {
               vec2.push_back(1);
           }
           if(a[i]==2)
           {
               vec3.push_back(2);
           }
       }
        std::vector<int> combinedVec;

    // Reserve space in the combined vector to avoid reallocations
    combinedVec.reserve(vec1.size() + vec2.size() + vec3.size());

    // Append elements from vec1
    combinedVec.insert(combinedVec.end(), vec1.begin(), vec1.end());

    // Append elements from vec2
    combinedVec.insert(combinedVec.end(), vec2.begin(), vec2.end());

    // Append elements from vec3
    combinedVec.insert(combinedVec.end(), vec3.begin(), vec3.end());
    
       //combine arrays
       for(int i = 0; i<n;i++)
       {
           a[i]=combinedVec[i];
       }
       
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends