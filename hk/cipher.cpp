#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'caesarCipher' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */

std::string rotateAlphabet(const std::string& input, int positions) {
    std::string result = input;

    for (char& ch : result) {
        if (std::isalpha(ch)) {
            char base = (std::islower(ch)) ? 'a' : 'A';
            ch = base + (ch - base + positions) % 26;
        }
    }

    return result;
}

string caesarCipher(string s, int k) {
    
    string a="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string r="";
    string d="";
    int n = a.size();
    //rotate by moving first k chars at end
    r=rotateAlphabet(a, k);
    map<char,char>m;
    for(int i = 0; i<a.size();i++)
    {
    
        m[a[i]]=r[i];
    }
    
    for(int i = 0; i<s.size(); i++)
    {   
        if(!isalpha(s[i]))
        {
            d+=s[i];
            continue;
        }
        else
        {
            d+=m[s[i]];
        }
    
        
    }
    return d;
    
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = caesarCipher(s, k);

    fout << result << "\n";

    fout.close();

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
