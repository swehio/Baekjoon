#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    for(char ch : str)
    {
        if(isupper(ch))
            cout << (char)tolower(ch);
        else
            cout <<  (char)toupper(ch);
    }
    return 0;
}