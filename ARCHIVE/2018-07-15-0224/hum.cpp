#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int parent[N], weight[N];

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool join(int a, int b){
    a = find(a), b = find(b);
    if(a != b){
        if(weight[a] < weight[b]) swap(a, b);
        else if(weight[a] == weight[b]) weight[a]++;
        parent[b] = a;
        return true;
    }
    return false;
}

int main(){
    int n, m, k = 0;
    while(scanf("%d %d", &n, &m) && n != 0){
        for(int i = 1; i <= n; i++){
            parent[i] = i;
            weight[i] = 1;
        }
        vector<pair<int, pair<int, int> > > edges;
        for(int i = 0; i < m; i++){
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            edges.push_back(make_pair(z, make_pair(x, y)));
        }
        sort(edges.begin(), edges.end());

        printf("Teste %d\n", ++k);
        for(int i = 0; i < edges.size(); i++){
            int x = edges[i].second.first, y = edges[i].second.second;
            if(join(x, y)){
                printf("%d %d\n", min(x, y), max(x, y));
            }
        }
        printf("\n");
    }
    return 0;
}
