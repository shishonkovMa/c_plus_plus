#include <iostream>

using namespace std;
using std::cout;
using std::cin;

bool isPalindrome(const string& input_word)
{
    size_t fac = input_word.size();

    for(size_t i = 0; i < fac/2; ++i)
        if (input_word[i] == input_word[fac-1-i])
            continue;
        else
            return false;
    return true;
}

int main()
{
    std::string input_word;
    std::getline(cin, input_word);
    cout << (isPalindrome(input_word) ? "true" : "false") << endl;
}
