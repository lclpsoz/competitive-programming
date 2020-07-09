#include <bits/stdc++.h>

using namespace std;

typedef multimap<int,int> mmpii;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long int ll;

vi v;
mmpii r;
string str;

int main() {
  cin >> str;
  
  for(auto i: str) {
    int x = (int) i - 48;
    r.emplace(x % 8,x);
  }

  mmpii::iterator it = r.begin();
  int z = it->first;
  v.push_back(it->second);
  r.erase(it);
  
  while(!r.empty() && z > 0) {
    z = (z*10) % 8;

    it = r.lower_bound(8-z);
    if(it->second == 0) it = r.begin();
    else if(it->first != 8-z && it != r.begin()) it--;

    //cout << "> " << it->first << " " << it->second << endl;
    
    int y = it->first;
    v.push_back(it->second);
    r.erase(r.find(y));
    z = (z+y) % 8;
  }


  if(z == 0) {
    cout << "YES" << endl;
    for(auto i: v)
      cout << i;
    cout << endl;
  }
  else
    cout << "NO" << endl;
  

  /*
  r.emplace(1,1);
  r.emplace(2,2);
  r.emplace(3,3);
  cout << r.end()->first << endl; */
    
  return 0;
}
