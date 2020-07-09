#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

bool arr[11];

bool test (int a) {
    memset (arr, 0, sizeof arr);
    while (a) {
        if (arr[a%10]) return false;
        arr[a%10] = true;
        a /= 10;
    }
    return true;
}

int main()
{
    int a, b;
    while (scanf ("%d %d", &a, &b) != EOF) {
        int ret = 0;
        for (int i = a; i <= b; i++)
            ret += test (i);
        printf ("%d\n", ret);
    }

    return 0;
}
