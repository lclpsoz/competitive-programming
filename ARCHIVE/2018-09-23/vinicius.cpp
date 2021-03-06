#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 1e5+10;
vector<int> relation[MAXN];
vector<bool> visited;
 
int main () {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    relation[a].push_back(b);
    relation[b].push_back(a);
  }
   
  int countF = 0;
 
  for(int i = 0; i <= n+1; i++) visited.push_back(false);
 
  for(int i = 1; i <= n; i++){
    if(!visited[i]){
      countF++;
      stack<int> s;
      s.push(i);
      while(!s.empty()){
	int u = s.top();
	s.pop();
	visited[u] = true;
	for(int v : relation[u]){
	  if(!visited[v]){
	    s.push(v);
	  }
	}
      }
    }
  }
 
  cout << countF << endl;
 
  return 0;
}
