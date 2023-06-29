#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
typedef std::map<int, size_t> IntSizetMap;


int charToInt(char c){
    return c - '0';
}

void printMapKeys(const IntSizetMap& myMap, std::ostream& ostr)
{
    string str_t;
    for(IntSizetMap::const_iterator it = myMap.begin(); it != myMap.end(); ++it)
    {
        str_t += std::to_string(it->first);
        str_t += ", ";
    }
    str_t.pop_back();
    str_t.pop_back();
    cout << str_t;
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

    IntSizetMap our_map;

    for (size_t i = 0; i < v.size(); ++i)
    {
        if (i%2 != 1)
            our_map.insert({v[i], v[i+1]});
    }

    printMapKeys(our_map, cout);
    cout << endl;
}
