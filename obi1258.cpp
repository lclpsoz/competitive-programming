#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, n) for(int i = (a); i < (n); i++)
#define fe(i, a, n) for(int i = (a); i <= (n); i++)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<tuple<string, string, char> > strings;

bool cmp(tuple<string, string, char> a, tuple<string, string, char> b){
    if(get<0>(a) != get<0>(b))
        return get<0>(a) < get<0>(b);
    if(get<2>(a) != get<2>(b))
        return get<2>(a) > get<2>(b);
    return get<1>(a) < get<1>(b);
}

int main(){
    io;

    int n;
    string str;
    char cor[10], tam;
    while(scanf("%d", &n), n){
        fr(i, 0, n){
            getline(cin, str);
            scanf("%s %c", cor, &tam);
            strings.push_back(make_tuple(cor, str, tam));
        }
        sort(strings.begin(), strings.end(), cmp);
        fr(i, 0, n){
            cout << get<0>(strings[i]) << " " << get<2>(strings[i]) << " " << get<1>(strings[i]) << "\n";
        }
        cout << "\n";
        strings.clear();
    }
}
