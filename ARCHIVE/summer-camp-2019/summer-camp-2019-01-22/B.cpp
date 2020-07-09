#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

int main()
{
    int n;
    while (scanf ("%d", &n) != EOF) {
        if (n%6 == 0)
            printf ("Y\n");
        else
            printf ("N\n");
    }
    
    return 0;
}
