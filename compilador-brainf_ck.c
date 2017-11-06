#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100000

void interpreta_brain_f_ck(char * codigo) {
  char vetor[TAM];
  int count_source, count_brackets, posicao = 0, count = 0, open_brackets[TAM];

  for(count_source=0; count_source < strlen(codigo); count_source++) {
      switch (codigo[count_source]) {
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
        case ',':
          vetor[posicao] = getchar();
          break;
        case '[':
          if(vetor[posicao] == 0) {
            count = 1;
            while(count != 0) {
              count_source++;
              if(codigo[count_source] == '[')
                count++;
              else if(codigo[count_source] == ']')
                count--;
            }
          }
          else {
            open_brackets[count_brackets] = count_source;
            count_brackets++;
          }
          break;
        case ']':
          count_brackets--;
          count_source = open_brackets[count_brackets] - 1;
          open_brackets[count_brackets] = 0;
          break;

        default:;
      }
  }
  puts("");
}

int main() {
  char *codigo, *lixo;

  puts("Entrada:");
  scanf("%s", codigo);
  lixo = codigo;
  puts("\nSaida:");
  interpreta_brain_f_ck(codigo);

  return 0;
}
