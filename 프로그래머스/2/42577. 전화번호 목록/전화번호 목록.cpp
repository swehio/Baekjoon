#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> sPhone_book;
    
    for(string phoneNum : phone_book)
    {  
        sPhone_book.insert(phoneNum);
    }
    
    for(string phoneNum : phone_book)
    {
        for(int i = 0; i<phoneNum.size(); i++)
        {
            auto it = sPhone_book.find(phoneNum.substr(0, i));
            if(it != sPhone_book.end())
            {
                return false;
            }
        }
    }
    
    return true;
}