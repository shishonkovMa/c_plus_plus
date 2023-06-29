#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;
typedef std::set<int> IntSet;
typedef std::map<int, size_t> IntSizetMap;


int charToInt(char c){
    return c - '0';
}

void printMap(const IntSizetMap& our_map)
{
    string str_t = "{";
    for(IntSizetMap::const_iterator it = our_map.begin(); it != our_map.end(); ++it)
    {
        str_t += "{";
        str_t += std::to_string(it->first);
        str_t += ", ";
        str_t += std::to_string(it->second);
        str_t += "}, ";
    }
    str_t.pop_back();
    str_t.pop_back();
    str_t += "}";
    cout << str_t;
}

IntSizetMap createMapFromVec(const vector<int>& v)
{
    IntSizetMap our_map;

    for(vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        if (our_map.find(*it) == our_map.end())
            our_map.insert({*it, 1});
        else
            our_map[*it] += 1;
    }

    return our_map;
}

int main()
{
    vector<int> v;
    string s;
    getline(cin, s);

    for(size_t i = 0; i < s.length(); ++i)
    {
        char c = s[i];
        if (isdigit(c))
        {
            int z = charToInt(c);
            v.push_back(z);
        }
    }
    IntSizetMap our_map = createMapFromVec(v);
    printMap(our_map);
    cout << endl;
}
