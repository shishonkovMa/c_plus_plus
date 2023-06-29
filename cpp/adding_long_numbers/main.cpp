#include <iostream>

using namespace std;
using std::cout;
using std::cin;


string addLong(const string& str1, const string& str2)
{
    if (str1.size() < str2.size()) {
        return addLong(str2, str1);
    }

    string result = "0" + str1;
    auto it1 = result.rbegin();
    auto it2 = str2.rbegin();
    int sum = 0;
    while (it2 != str2.rend()) {
        sum += (*it1 - '0') + (*it2 - '0');
        *it1 = (sum % 10) + '0';
        sum /= 10;
        it1++;
        it2++;
    }

    while (sum != 0) {
        sum += *it1 - '0';
        *it1 = (sum % 10) + '0';
        sum /= 10;
        it1++;
    }

    return result[0] == '0' ? result.substr(1) : result;
}

int main()
{
    string str1;
    string str2;
    cin >> str1 >> str2;

    cout << addLong(str1, str2) << endl;
    return 0;
}
