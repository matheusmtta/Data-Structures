#include "list.h"
#include <iostream>

using namespace std;

List frascos;

int calc(int quant){
  List principal;
  principal.push_back(0, 0);
  Node *head = frascos.begin;
  while(frascos.begin != nullptr){
    if (frascos.front() == quant) return 1;
    principal.push_back(frascos.front(), frascos.weigth());
    frascos.begin = frascos.begin->next;
  }
  frascos.begin = head;
  List combinations;
  Node *head_2 = principal.begin;
  while(principal.begin != nullptr){
    combinations.push_back(principal.front(), principal.weigth());
    principal.begin = principal.begin->next;
  }
  principal.begin = head_2;
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
      if (tmp_first+aux_first == quant) 
        return tmp_second+aux_second;
      else combinations.push_back(tmp_first+aux_first, tmp_second+aux_second);
      if (tmp_first-aux_first > 0){
        if (tmp_first-aux_first == quant) 
          return tmp_second+aux_second;
        else 
          combinations.push_back(tmp_first-aux_first, tmp_second+aux_second);
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