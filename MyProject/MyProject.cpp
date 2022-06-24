#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    string input, temp;
    //take input from user 
    cout << "Type letters and space-bar individually(A B b a C D E) : ";
    getline(cin, input);

    //create a vector that will hold the individual words
    vector<string> vectorOfString;

    istringstream ss(input);

    //go word by word 
    while (ss >> temp)
    {
        vectorOfString.emplace_back(temp);
    }   
    

    sort(vectorOfString.begin(), vectorOfString.end(), [](const auto& lhs, const auto& rhs) {
        const auto result = mismatch(lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend(), [](const auto& lhs, const auto& rhs) {return tolower(lhs) == tolower(rhs); });

        return result.second != rhs.cend() && (result.first == lhs.cend() || tolower(*result.first) < tolower(*result.second));
        });

    for (auto& i : vectorOfString) {
        cout << i;
    }
    return 0;
}