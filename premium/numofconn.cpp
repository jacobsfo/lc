/*
    Graph of n nodes, given edges array, return # of connected components
    Ex. n = 5, edges = [[0,1],[1,2],[3,4]] -> 2

    Union find, for each edge combine, if already in same set keep traversing
    If not in same set, decrement count by 1, count will store # of components

    Time: O(n)
    Space: O(n)
*/
#include <vector>
#include <queue>
#include <iostream>
#include <limits>
#include <climits>
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        
    }
private:
    int doFind(vector<int>& parents, int n) {
        
    }
    
    int doUnion(vector<int>& parents, vector<int>& ranks, int n1, int n2) {
        
    }
};
int main(){
    Solution a;
    //Ex. n = 5, edges = [[0,1],[1,2],[3,4]] -> 2
    int n = 5;
    vector<vector<int>>edges={
        {0,1},
        {1,2},
        {3,4},
    };
    int ans = a.countComponents(n,edges);
    cout << ans << endl;
return 0;
}
