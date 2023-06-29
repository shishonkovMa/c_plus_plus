#include <iostream>
#include <vector>
#include <string>

using namespace std;


int charToInt(char c){
    return c - '0';
}

void printVec(const std::vector<int>& v, std::ostream& ostr)
{
    for(size_t i = 0; i < v.size(); ++i)
    {
        if (i)
            cout << ", ";
        cout << v[i];
    }
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

    vector<int> tot;
    for(vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
    {
        tot.push_back(*it);
    }

    printVec(tot, cout);
    cout << endl;
}
