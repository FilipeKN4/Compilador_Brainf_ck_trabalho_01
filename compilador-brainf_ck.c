#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100000

void read_file(char *source) {
  FILE *file;
  int count = 0;
  char ch;
  file = fopen("brain_f_ck.txt", "rt");
  if (file == NULL) {
    puts("ERRO AO ABRIR ARQUIVO !");
		getchar();
  }
  else {
    while((ch = fgetc(file)) != EOF) {
      if(ch == '+' ||
         ch == '-' ||
         ch == '>' ||
         ch == '<' ||
         ch == '[' ||
         ch == ']' ||
         ch == '.' ||
         ch == ',') {
        source[count] = ch;
        count++;
      }
    }
    source[count] = '\0';
  }
  fclose(file);
}

void interpreta_brain_f_ck(char *codigo) {
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
  char source[TAM];

  read_file(source);
  printf("%s\n", source);
  puts("\nSaida:");
  interpreta_brain_f_ck(source);

  return 0;
}
