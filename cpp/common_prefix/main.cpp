#include <iostream>
#include <sstream>

using namespace std;
using std::cout;
using std::cin;

string addLong(const string& str1, const string& str2)
{
    if (str2[0] == 'm' || str1.empty())
        return "me";
}

int main()
{

    std::string line;
    std::getline(cin, line);
    std::stringstream ss(line);
    std::string str2 = ss.str();
    std::string str1 = ss.str();

    cout << addLong(str1, str2);
    return 0;
}
