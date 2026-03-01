#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int Find_words_with_two_d(char *str, int *out_index){
    int index_Count = 0;
    int d_Count = 0;
    int word_start = 0;
    int in_word = 0;
    size_t len = strlen(str);

    for (size_t i = 0; i <= len; i++) {
      char letter = str[i];
      bool is_letter = (letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z');
      bool is_limiter = (letter == ',' || letter == '.');
      bool is_end = (letter == '\0');

      if (!is_letter && !is_limiter && !is_end) {
        return 0;
      }

      if (is_letter) {

        if (!in_word) {
            in_word = 1;
            word_start = i;
        }

        if (letter == 'd' || letter == 'D') {
          d_Count++;
        }
      }
      else {

        if (d_Count == 2) {
          out_index[index_Count] = word_start;
          index_Count++;
        }
        d_Count = 0;
        in_word = 0;
      }
    }
    return index_Count;
}

void Print_words_by_indices(char *str, int *out_index, int count){
    for (int i = 0; i < count; i++) {
      int start = out_index[i];
      for (int j = start; str[j] != '\0'; j++) {
        char letter = str[j];
        if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')) {
          printf("%c", letter);
        } else {
          break;
        }
      }
      printf("\n");
    }
}

int main()
{
    char str[35] = "add,door,dad,data,added.";

    int out_index[100];
    for (int i = 0; i < 100; i++) {
      out_index[i] = -1;
    }

    int found_count = Find_words_with_two_d(str, out_index);

    if (found_count) {
      Print_words_by_indices(str, out_index, found_count);
    }
    else {
      printf("Found invalid characters.\n");
    }
}
