#include <bits/stdc++.h>
using namespace std;

// --
#define x first
#define y second
#define len(x) ((int)x.size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
    return (int)(((x%m) + m)%m);
}
// --

string mat[10][6];
string arr[10][6] = {   {"***", "* *", "* *", "* *", "***"},
                        {"  *", "  *", "  *", "  *", "  *"},
                        {"***", "  *", "***", "*  ", "***"},
                        {"***", "  *", "***", "  *", "***"},
                        {"* *", "* *", "***", "  *", "  *"},
                        {"***", "*  ", "***", "  *", "***"},
                        {"***", "*  ", "***", "* *", "***"}, 
                        {"***", "  *", "  *", "  *", "  *"},
                        {"***", "* *", "***", "* *", "***"},
                        {"***", "* *", "***", "  *", "***"},            };

void no() {
    cout << "BOOM!!\n";
    exit(0);
}

int main() {
    // for(int i = 0; i < 10; i++)
    //     for(int j = 0; j < 5; j++)
    //         cout << arr[i][j] << '\n';
    int qnt = 0;
    string line;
    int qntElem = 0;
    while (getline(cin, line)) {
        assert(line != "");
        // cout << line << '\n';
        int q = 0, elem = 0;
        for(int i = 0; i < len(line); i++) {
            mat[elem][qnt].push_back(line[i]);
            ++q;
            if(q == 3) {
                q = 0;
                ++i;
                if(i < len(line) and line[i] != ' ') no();
                ++elem;
            } else if(i == len(line)-1) {
                for(int j = 0; j < 3-q; j++)
                    mat[elem][qnt].push_back(' ');
                ++elem;
            }
        }
        qntElem = max(elem, qntElem);
        ++qnt;
        // cout << line << '\n';
    }

    if(qnt != 5) {
        no();
    } else {
        string s = "";
        for(int i = 0; i < qntElem; i++) {
            bool ok = false;
            for(int num = 0; num < 10; num++) {
                bool now = true;
                for(int j = 0; j < 5; j++) {
                    if(mat[i][j] != arr[num][j]) {
                        now = false;
                        break;
                    }
                }
                if(now) {
                    ok = true;
                    s.push_back(num+'0');
                    break;
                }
            }
            if(!ok) {
                no();
            }
        }
        // cout << s << '\n';
        int x = stoi(s);
        if(x%6 > 0) {
            no();
        }
    }
    cout << "BEER!!\n";

    return 0;
}