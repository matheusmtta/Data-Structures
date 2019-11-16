#include <cstdio>
#include <cstdlib>
#include <ctime>

int _dist(int max) {
  // maneira bem ineficiente de gerar numeros aleatorios entre 0..max
  // sem que a distribuição seja uniforme
  int sum = 0;
  for (int i = 0; i < (max - 1); ++i)
    sum += rand()%2;
  return sum;
}

int main(int argc, char *argv[]) {
  int n = (argc < 2) ? 5 : atoi(argv[1]);
  printf("%d\n", n);
  srand(time(NULL));
  int p = n/5 + rand()%(2*n/5); // numero de palavras unicas eh aleatorio
                                // entre 20% e 40% de N
  char words[p][64];
  for (int i = 0; i < p; ++i) {
    int len = 1 + rand()%62;
    for (int j = 0; j < len; ++j)
      words[i][j] = 'a' + rand()%('z' - 'a');
    words[i][len] = '\0';
  }
  // o primeiro loop garante que cada palavra aparece ao menos uma vez
  printf("%s", words[0]);
  for (int i = 1; i < p; ++i)
    printf(" %s", words[i]);
  for (int i = p; i < n; ++i)
    printf(" %s", words[_dist(p)]);
  for (int i = 0; i < p; ++i)
    printf("\nq %s", words[i]);
  return 0;
}
