#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define present(container, element) (container.find(element) != container.end())
#define ss  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define cpresent(container, element) (find(all(container),element) != container.end())
#define all(c) c.begin(), c.end()
#define mod 998244353 
#define PI 3.141592654
typedef long long ll;
using namespace std;
int BIT[10000005];
int maxi;
int read(int idx){
    int sum = 0;
    while(idx > 0){
        sum += BIT[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
void update(int idx, int val){
    while(idx <= maxi){
        BIT[idx] += val;
        idx += (idx & -idx);
    }
}
int main(){
	int a,b,c,x,y;
	ll n;
	while (cin >> n) {
		memset (BIT, 0, sizeof BIT);
		string s;
		cin>>s;
		int l=0,r=n-1,index,ans=0;
		for(int i=1;i<n;i++){
			if(s[i]==s[i-1]){
				ans++;
			}
			else{
				ans++;
				index=i;
				break;
			}
		}
		int bc=0;
		if(s[0]==s[n-1]) bc=1;
		for(int i=n-2;i>=0;i--){
			if(s[i]==s[i+1]){
				ans++;
			}
			else{
				ans++;
				if(s[0]==s[n-1]) {
					ans=ans+(((n-1-i)%mod)*(index)%mod)%mod;
				};
				break;
			}
		}
			
			cout<<ans+1<<endl;
	}
}