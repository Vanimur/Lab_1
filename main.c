#include <stdio.h>
#include <stdbool.h>

int main()
{
    char str[35] = "add,door,dad,data,added.";

    int out_index[100] = {-1};
    int index_Count = 0;
    int d_Count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
      char letter = str[i];
      bool is_letter = (letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z');
      bool is_limiter = (letter == ',' || letter == '.');

      if (!is_letter && !is_limiter) {
          return 0;
      }

      if (letter != ',' && letter != '.') {
        if (letter == 'd') {
          d_Count++;
        }
      }
      else {

        if (d_Count == 2) {
          out_index[index_Count] = i;
          index_Count++;
        }
        d_Count = 0;
      }
    }

    for (int i = 0; i < 100; i++){
      printf("%d\n", out_index[i]);
    }
}
