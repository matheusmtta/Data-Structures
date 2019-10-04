#include "../includes/list.h"
#include <iostream>

using namespace std;

List frascos;

int calc(int quant){
  List principal;
  principal.push_back(0, 0);
  Node *head = frascos.begin;
  while(head != nullptr){
    if (head->element == quant) return 1;
    principal.push_back(head->element, head->operations);
    head = head->next;
  }
  List combinations;
  Node *head_2 = principal.begin;
  while(head_2 != nullptr){
    combinations.push_back(head_2->element, head_2->operations);
    head_2 = head_2->next;
  }
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
