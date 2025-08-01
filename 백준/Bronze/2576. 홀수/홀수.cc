#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num;
    int sum = 0;
    vector<int> nums;
    for(int i = 0; i<7; ++i)
    {
        cin >> num;
        if(num % 2 != 0)
        {
            sum += num;
            nums.push_back(num);
        }
    }

    if(sum == 0)
    {
        cout << -1 << '\n';
    }
    else
    {
        int min = *min_element(nums.begin(), nums.end());
        cout << sum << '\n';
        cout << min;
    }
}