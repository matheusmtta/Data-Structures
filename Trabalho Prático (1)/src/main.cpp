#include "includes/list.h"
#include "includes/measures.h"
#include <iostream>

int main(){
  List* frascos = new List();
  int n; char type;
  while(std::cin >> n >> type){
    if (type == 'i')
      frascos->push_back(n, 1);
    else if (type == 'r')
      frascos->remove(n);
    else if (type == 'p'){
      int ans = measure(n, frascos);
      std::cout << ans << std::endl;
    }
  }
  return 0;
}
