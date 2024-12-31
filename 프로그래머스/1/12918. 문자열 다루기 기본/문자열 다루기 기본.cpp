#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    
    for(auto ch : s)
    {
        if(!isdigit(ch)) 
            return false;
    }
    return s.size() == 4 || s.size() == 6 ? true : false;

}