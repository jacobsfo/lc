#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'noPrefix' function below.
 *
 * The function accepts STRING_ARRAY words as parameter.
 */




class TrieNode{
public:

TrieNode* children[26];
bool eow=false;

//intialize
TrieNode(){
    for(int i = 0; i<26;i++)
    {
        children[i]=NULL;
    }
}

};
class Trie {
public:
TrieNode * root;
    Trie() {
        
        root = new TrieNode();
    }
    
   bool insert(string word) {
        TrieNode * cur = root;
        bool exist = true;
        for(int i = 0; i<word.size();i++)
        {   if(cur->eow)
            {
                return true;
            }
            //insert if dne each char into trie(create node, at cur)
            if(cur->children[word[i]-'a']==NULL)
            {
                cur->children[word[i]-'a']= new TrieNode();
                exist=false;
            }
            //if exists update cur to char
            cur = cur->children[word[i]-'a'];


        }
        cur->eow=true;
        return exist;

    }
    
    bool search(string word) {
                TrieNode * cur = root;
        for(int i = 0; i<word.size();i++)
        {
            if(cur->children[word[i]-'a']==NULL)
            {
                return false;
            }
            cur = cur->children[word[i]-'a'];
            
            
        }
        return cur->eow;

    }
    
    bool startsWith(string prefix) {
         TrieNode * cur = root;
        for(int i = 0; i<prefix.size();i++)
        {
            if(cur->children[prefix[i]-'a']==NULL)
            {
                return false;
            }
            cur = cur->children[prefix[i]-'a'];
            
            
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
void noPrefix(vector<string> words) {

Trie t = Trie();
    for (string word : words) {
        if (t.insert(word)) {
            cout << "BAD SET" << endl;
            cout << word << endl;
            return;
        }
    }
    cout << "GOOD SET" << endl;




}


int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        string words_item;
        getline(cin, words_item);

        words[i] = words_item;
    }

    noPrefix(words);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
