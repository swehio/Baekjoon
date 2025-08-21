#include <bits/stdc++.h>

using namespace std;

string arr[55];

bool compare(const string& a, const string& b)
{
    if(a.size() == b.size())
    {
        int sumA = 0;
        int sumB = 0;
        for(int i = 0; i<a.size(); i++)
        {
            if(a[i] >= '0' && a[i] <= '9')
                sumA += a[i] - '0';
            if(b[i] >= '0' && b[i] <= '9')
                sumB += b[i] - '0';
        }
        if(sumA == sumB)
        {
            for(int i = 0; i<a.size(); i++)
            {
                if(a[i] == b[i]) continue;
                return a[i] < b[i];
            }
        }
        return sumA < sumB;
        
    }
    return a.size() < b.size();
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        string str;
        cin >> arr[i];
    }
    
    sort(arr, arr+N, compare);
    
    for(int i = 0; i < N; i++)
    {
        cout << arr[i] << '\n';
    }
}