#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
typedef  std::set< int > IntSet;


int charToInt(char c){
    return c - '0';
}

IntSet createSetFromVec(const vector<int>& v)
{
    IntSet our_set;

    for(vector<int>::const_iterator i = v.begin(); i != v.end(); ++i)
    {
        our_set.insert(*i);
    }
    return our_set;
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

    IntSet our_set = createSetFromVec(v);

    string str_t = "{";
    for(IntSet::const_iterator it = our_set.begin(); it != our_set.end(); ++it)
    {
        str_t += to_string(*it);
        str_t += ", ";
    }
    str_t.pop_back();
    str_t.pop_back();
    str_t += "}";
    cout << str_t;
    cout << endl;
}
