//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    int sumSubtree(Node* root) {
        // If the current node is null, the sum is 0
        if (!root) {
            return 0;
        }

        // Calculate the sum of the left and right subtrees
        int leftSum = sumSubtree(root->left);
        int rightSum = sumSubtree(root->right);

        // Return the sum of the current subtree (including the current node)
        return leftSum + rightSum + root->data;
    }

    // Function to calculate the sum of the left and right subtrees separately
    void trav(Node* root, int& leftSum, int& rightSum) {
        // If the root is null, both sums are 0
        if (!root) {
            leftSum = 0;
            rightSum = 0;
            return;
        }

        // Calculate the sum of the left and right subtrees using the helper function
        leftSum = sumSubtree(root->left);
        rightSum = sumSubtree(root->right);
    }
    bool isSumTree(Node* root)
    { 
        if (!root || (!root->left && !root->right)) {
            // An empty tree or a leaf node is considered a Sum Tree
            return true;
        }

        // Calculate the sum of the left and right subtrees
        int leftSum = sumSubtree(root->left);
        int rightSum = sumSubtree(root->right);

        // Check if the current node's value is equal to the sum of its subtrees
        if (root->data == leftSum + rightSum) {
            // Recursively check the condition for left and right subtrees
            return isSumTree(root->left) && isSumTree(root->right);
        }

        return false;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        cout <<ob.isSumTree(root) << endl;
    }
    return 1;
}
// } Driver Code Ends