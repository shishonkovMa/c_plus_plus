#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
typedef set<int> IntSet;


int charToInt(char c){
    return c - '0';
}

string findKeyInSet(IntSet our_set, int to_find)
{
    if (our_set.find(to_find) != our_set.end())
        return "true";
    return "false";
}

int main()
{
    IntSet our_set;
    int to_find;
    string s;
    getline(cin, s);

    for(size_t i = 0; i < s.length(); ++i)
    {
        char c = s[i];
        if (isdigit(c))
        {
            int z = charToInt(c);

            if (i != s.length() - 1)
                our_set.insert(z);
            else
                to_find = z;
        }
    }

    string answer = findKeyInSet(our_set, to_find);
    cout << answer << endl;
}
