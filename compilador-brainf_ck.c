#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100000

void compile_brain_f_ck(char *source) {
  int count_source;
  FILE *output;

  output = fopen("saida.c", "w");

  if(output == NULL) {
    printf("Arquivo não foi criado!");
  }

  fprintf(output, "#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n#define SIZE 100000\n");
  fprintf(output, "int main() {\n char vector[SIZE] = {};\n int position = 0;\n\n");

  for(count_source=0; count_source < strlen(source); count_source++) {
      switch (source[count_source]) {
        case '+':
          fprintf(output, " vector[position]++;\n");
          break;
        case '-':
          fprintf(output, " vector[position]--;\n");
          break;
        case '>':
          fprintf(output, " position++;\n");
          break;
        case '<':
          fprintf(output, " position--;\n");
          break;
        case '.':
          fprintf(output, " putchar(vector[position]);\n");
          break;
        case ',':
          fprintf(output, " vector[position] = getchar();\n");
          break;
        case '[':
          fprintf(output, "while(vector[position]!=0) {\n");
          break;
        case ']':
          fprintf(output, "}\n");
          break;

        default:;
      }
  }

  fprintf(output, "\n return 0;\n}");

  fclose(output);
}

int main() {
  char source[SIZE] = {};

  scanf("%s", source);
  printf("%s\n", source);
  interpreta_brain_f_ck(source);
  puts("\nCodigo em Linguagem C gerado com sucesso!");

  return 0;
}
