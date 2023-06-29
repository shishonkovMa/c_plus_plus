#include <iostream>
#include <sstream>

using namespace std;

double calcMean(const string& line)
{
    std::stringstream ss(line);

    double sum = 0.0;
    double num;
    int count = 0;

    while (ss >> num)
    {
        sum += num;
        ++count;
    }

    double res;
    res = sum/count;

    return res;
}

int main()
{
    std::string line;
    while ( std::getline(cin, line))
    {
        if (line.empty())
            break;
        else
            cout << calcMean(line);
    }

    return 0;
}
