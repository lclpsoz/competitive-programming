#include <iostream> 
#include <string.h> 
using namespace std; 

int main() {

  int arr[100]; 

  memset(arr, -2, sizeof(arr));
  cout << arr[2] << '\n'; 

  return 0; 

}
