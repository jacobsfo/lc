//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    
struct Node* createLinkedList(const string& str) {
        if (str.empty()) {
            return nullptr;
        }

        // Create the head node
        struct Node* head = new Node(str[0] - '0');
        struct Node* current = head;

        // Iterate over the string to create the linked list
        for (size_t i = 1; i < str.size(); ++i) {
            current->next = new Node(str[i] - '0');
            current = current->next;
        }

        return head;
    }

    struct Node* addTwoLists(struct Node* first, struct Node* second) {
        string op1;
        string op2;

        // Traverse and cast for the first number
        while (first != nullptr) {
            op1 += to_string(first->data);
            first = first->next;
        }

        // Traverse and cast for the second number
        while (second != nullptr) {
            op2 += to_string(second->data);
            second = second->next;
        }

        // Pad the shorter number with leading zeros
        int lengthDiff = op1.length() - op2.length();
        if (lengthDiff > 0) {
            op2 = string(lengthDiff, '0') + op2;
        } else if (lengthDiff < 0) {
            op1 = string(-lengthDiff, '0') + op1;
        }

        int carry = 0;
        string res;

        // Perform addition digit by digit
        for (int i = op1.length() - 1; i >= 0; --i) {
            int digitSum = (op1[i] - '0') + (op2[i] - '0') + carry;
            res = to_string(digitSum % 10) + res;
            carry = digitSum / 10;
        }

        // Add any remaining carry
        if (carry > 0) {
            res = to_string(carry) + res;
        }

        // Create a linked list from the result string
        struct Node* ans = createLinkedList(res);
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
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends