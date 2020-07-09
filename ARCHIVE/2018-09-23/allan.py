#include <iostream>
#include <cstdio>
using namespace std; 

int f(unsigned int n){
  if (n == 1) return 1; 
  if (n%2 == 0) return f(n/2)+1; 
  return f((3*n)+1)+1; 
}

int main(){
  unsigned int x, y, big, aux; 

  while(cin >> x >> y){
    big = 0;
    for (int i = x; i <= y; i++){
      aux = f(i);
      if (aux > big) big = aux;     
    }
    printf("%u %u %u\n", x, y, big);
  }

  return 0;
}
