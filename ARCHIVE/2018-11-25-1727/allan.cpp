#include <bits/stdc++.h>
using namespace std; 

int main(){
  int n, k, test_cases;  
  long long int numbers[110010010];
  set<int> excluded; 
	
  scanf("%d", &test_cases); 
	
  while (test_cases--){
		
    scanf("%d %d", &n, &k); 
    if (n < k){
      printf("%d\n", n-1); 
    }
		
    else{
      // resetting array 
      for (long long int i = 2; i <= n; i++){
	numbers[i] = 1; 
      }
			
      for (int i = 2; i <= k; i++){
	if (numbers[i]){
	  numbers[i] = 1; 
	  for (long long int j = i*i; j <= n; j += i){
	    numbers[j] = 0; 
	  }
	}
      }
			
      for (int i = k+1; i <= n; i++){
	if (numbers[i]){
	  excluded.insert(i); 
	  for (long long int j = i+i; j <= n; j += i){
	    excluded.insert(j); 
	  }
	}
      }
			
      cout << n-excluded.size()-1 << endl; 
      excluded.clear(); 		
    }
  }
	
  return 0; 
}
