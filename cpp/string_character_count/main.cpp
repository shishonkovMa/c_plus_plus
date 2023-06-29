#include <iostream>

using namespace std;
using std::cout;
using std::cin;

int charStatistics(const string& str,
                   unsigned int& x,
                   unsigned int& y,
                   unsigned int& z)
{
    int size_intr = str.size();

    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
            ++x;
        if ((int)str[i] >= 48  && (int)str[i] <= 57)
            ++y;
        z = size_intr - x - y;
    }
    return size_intr;
}

int main()
{
    unsigned int x = 0;
    unsigned int y = 0;
    unsigned int z = 0;
    string str;
    std::getline(cin, str);
    cout << charStatistics(str, x, y, z) << ' ' << x << ' ' << y << ' ' << z << endl;

}
