bool hasDuplicateValues(const std::map<std::string, std::set<std::string>>& myMap) {
    // Use an unordered_set to keep track of encountered values
    std::unordered_set<std::string> encounteredValues;

    for (const auto& entry : myMap) {
        const std::set<std::string>& currentSet = entry.second;

        for (const std::string& value : currentSet) {
            // Check if the value is already in the set
            if (encounteredValues.find(value) != encounteredValues.end()) {
                // Found a duplicate value
                return true;
            }

            // Add the value to the set
            encounteredValues.insert(value);
        }
    }

    // No duplicate values found
    return false;
}
bool solution(vector<string> strings, vector<string> patterns) {
//if suffix is same, prefix should be same
//if val has n > 1
vector<string>v1;

map<string,set<string>>m;
for(int i = 0; i<patterns.size();i++)
{
    m[patterns[i]].insert(strings[i]);
}

for(auto x:m)
{
    if(x.second.size()>1)
    {
        return false;
    }

}
if(hasDuplicateValues(m))
{
    return false;
}
return true;
// map<string,int>m1,m2;
// for(int i = 0; i<strings.size();i++)
// {
//     m1[strings[i]]++;
// }
// for(int i = 0; i<patterns.size();i++)
// {
//     m2[patterns[i]]++;
// }
// for(auto x:m1)
// {   cout << x.first <<"->"<< x.second << endl;
//     v1.push_back(x.second);
// }
// cout << "----" << endl;
// for(auto x:m2)
// {   cout << x.first <<"->"<< x.second << endl;
//     v2.push_back(x.second);
// }
// sort(v1.begin(),v1.end());
// sort(v2.begin(),v2.end());

// return v1==v2;

}
