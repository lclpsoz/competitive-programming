#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

const int N = 2010;
int n;
pair<int, pii> oil[N];

bool inter(pii a, pii b)
{
    if(b.first <= a.second || b.second >= a.first) return true;
    return false;
}

int solve(int i)
{

    for(int j = i + 1; j < n; j++
    
}

int main()
{
    while(cin >> n)
    {
        
        for(int i = 0; i < n; i++)
        {
            int x0, x1, y;
            cin >> x0 >> x1 >> y;
            
            oil[i] = {y, {x0, x1}};
        }
        
        sort(oil.begin(), oil.end());
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(oil[i].first == oil[j].first) continue;
                if(inter(oil[i].second, oil[j].second))
                    
            }
        }
    }
    return 0;
}
