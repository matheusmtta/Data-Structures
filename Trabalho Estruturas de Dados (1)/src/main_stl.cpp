#include <bits/stdc++.h>

using namespace std;

list <int> frascos;

int calc(int quant){
  queue <pair<int,int>> principal;
  principal.push({0,0});
  list<int> copy_list = frascos;
  while(!copy_list.empty()){
    int x = copy_list.front();
    if (x == quant) return 1;
    principal.push({x, 1});
    copy_list.pop_front();
  }
  queue <pair<int,int>> combinacoes = principal;
  while(1){
    pair <int, int> tmp = combinacoes.front();
    combinacoes.pop();
    pair <int, int> holder = principal.front();
    principal.pop();
    principal.push(holder);
    while(principal.front() != holder){
      pair <int, int> aux = principal.front();
      principal.pop();
      principal.push(aux);
      if (tmp.first+aux.first == quant) return tmp.second+aux.second;
      else combinacoes.push({tmp.first+aux.first, tmp.second+aux.second});
      if (tmp.first-aux.first > 0){
        if (tmp.first-aux.first == quant) return tmp.second+aux.second;
        else combinacoes.push({tmp.first-aux.first, tmp.second+aux.second});
      }
    }
  }
}

int main(){
  int n;
  char m;
  while(cin >> n >> m){
    if (m == 'i') frascos.push_back(n);
    else if (m == 'r' ) frascos.remove(n);
    else if (m == 'p') {
      int ans = calc(n);
      cout << ans << endl;
    }
  }
  return 0;
}
