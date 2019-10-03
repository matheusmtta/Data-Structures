#include "list.h"
#include <iostream>

using namespace std;

List frascos;

int calc(int quant){
  List principal;
  principal.push_back(0, 0);
  List copy_list = frascos;
  while(!copy_list.empty()){
    int x = copy_list.front();
    int y = copy_list.weigth();
    if (x == quant) return 1;
    principal.push_back(x, y);
    copy_list.pop_front();
  }
  List combinations = principal;
  while(1){
    int tmp_first = combinations.front();
    int tmp_second = combinations.weigth();
    combinations.pop_front();
    int holder_first = principal.front();
    int holder_second = principal.weigth();
    principal.pop_front();
    principal.push_back(holder_first, holder_second);
    while(holder_first != principal.front()){
      int aux_first = principal.front();
      int aux_second = principal.weigth();
      principal.pop_front();
      principal.push_back(aux_first, aux_second);
      if (tmp_first+aux_first == quant) return tmp_second+aux_second;
      else combinations.push_back(tmp_first+aux_first, tmp_second+aux_second);
      if (tmp_first-aux_first > 0){
        if (tmp_first-aux_first == quant) return tmp_second+aux_second;
        else combinations.push_back(tmp_first-aux_first, tmp_second+aux_second);
      }
    }
  }
  return 0;
}

int main(){
  int n; char type;
  while(cin >> n >> type){
    if (type == 'i')
      frascos.push_back(n, 1);
    else if (type == 'r')
      frascos.remove(n);
    else if (type == 'p'){
      int ans = calc(n);
      cout << ans << endl;
    }
  }
  return 0;
}
