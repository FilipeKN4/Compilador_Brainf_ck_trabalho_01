#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100000

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
         ch == '.' ||
         ch == ',' ||
         ch == '[' ||
         ch == ']') {
        source[count] = ch;
        count++;
      }
    }
    source[count] = '\0';
  }
  fclose(file);
}

void interpreta_brain_f_ck(char *source) {
  char vector[SIZE];
  int count_source, count_brackets, position = 0, count = 0, open_brackets[SIZE];

  for(count_source=0; count_source < strlen(source); count_source++) {
      switch (source[count_source]) {
        case '+':
          vector[position]++;
          break;
        case '-':
          vector[position]--;
          break;
        case '>':
          position++;
          break;
        case '<':
          position--;
          break;
        case '.':
          putchar(vector[position]);
          break;
        case ',':
          vector[position] = getchar();
          break;
        case '[':
          if(vector[position] == 0) {
            count = 1;
            while(count != 0) {
              count_source++;
              if(source[count_source] == '[')
                count++;
              else if(source[count_source] == ']')
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
  char source[SIZE];

  read_file(source);
  printf("%s\n", source);
  puts("\nSaida:");
  interpreta_brain_f_ck(source);

  return 0;
}
