#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    vector<int> arr;
    int arrSize;
    int n;
    cin >> arrSize >> n;
    for(int i = 0; i<arrSize; ++i)
    {
        int num;
        cin >> num;
        if(num < n)
        {
            if(i == arrSize-1)
            {
                cout << num;
            }
            else
            {
                cout << num << " ";
            }
        }
    }
    
    return 0;
}