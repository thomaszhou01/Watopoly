#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "and the C++ extension!", "Watopoly"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}
