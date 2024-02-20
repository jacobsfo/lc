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

using namespace std;
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        //intialize rank to 1s, and parents array with nodes
        vector<int>ranks;
        vector<int>parents;
        for(int i = 0; i<n;i++)
        {
            parents.push_back(i);
            ranks.push_back(1);
        }
        int res=n;
        //loop thru edges and decrement the res when you see a connected component(union)
        for(auto edge:edges)
        {
            res-= doUnion(parents,ranks,edge[0],edge[1]);
        }
        return res;

       
    }
private:
    int doFind(vector<int>& parents, int n) {
       //find root of parents
        int p  = parents[n];
       //loop till reach itself
       while(p!=parents[p])
       {
           //set parent to its grandpa
           parents[p] = parents[parents[p]];
           //update node to it's parent
           p=parents[p];
       }
       return p;
       

    }
    
    int doUnion(vector<int>& parents, vector<int>& ranks, int n1, int n2) {
        //find root parent of n1,n2
        int p1 = doFind(parents,n1);
        int p2 = doFind(parents,n2);

        //if parents same->ret 0
        if(p1==p2)
        {
            return 0;
        }
        else
        {
            if(ranks[p1]>ranks[p2])
            {
                //p1 is parent of p2
                parents[p2]=p1;
                ranks[p1]+=ranks[p2];
            }
            else
            {
                //p2 is parent of p1
                parents[p1]=p2;
                ranks[p2]+=ranks[p1];
            }
            return 1;
        }
        
        

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
