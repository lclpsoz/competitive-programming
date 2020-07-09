#include <iostream>

int main(){
  int n, arr[5100], c;
  for (int i = 1; i < 5100; i++) arr[i] = 1;  
	
  scanf("%d", &n); 
  while (n != 0) {
    c = 0;
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < n; i++){
      if (arr[i] == 0){
	if (arr[i+1] == 0){
	  arr[i+1] = 1;
	  c++;
	}
      }
    }
    printf("%d\n", c);
    scanf("%d", &n);
  }
  return 0;
}
