#include <stdio.h>
#include <string.h>
#define TAM 100000

void interpreta_brainf_ck(char * codigo) {
  char vetor[TAM] = {};
  int i, posicao=0, g=0;

  for(i=0; codigo[i]!='\0'; i++) {
      switch (codigo[i]) {
        case '+':
          vetor[posicao]++;
          break;
        case '-':
          vetor[posicao]--;
          break;
        case '>':
          posicao++;
          break;
        case '<':
          posicao--;
          break;
        case '.':
          putchar(vetor[posicao]);
          break;

        default:;
      }
  }
  printf("\n");
  printf("%s\n", codigo);

}

int main() {
  char *codigo, *lixo;

  scanf("%s", codigo);
  lixo = codigo;
  interpreta_brainf_ck(codigo);

  return 0;
}
