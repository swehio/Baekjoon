#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
    string ab = a+b;
    string ba = b+a;
    return ab > ba;
}

string solution(vector<int> numbers) {
    vector<string> sNumbers;
    string result ="";
    
    for(int i = 0; i<numbers.size(); ++i)
    {
        string transS = to_string(numbers[i]);
        sNumbers.push_back(transS);
    }
    sort(sNumbers.begin(), sNumbers.end(), compare);
    
    for(string sNumber : sNumbers)
    {
        result += sNumber;
    }
    
    if(result[0] == '0')
    {
        result = "0";
    }
          
    return result;
}