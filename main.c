#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int Find_words_with_two_d(char *str, int *out_index){
    int index_Count = 0;
    int d_Count = 0;
    int word_start = 0;
    bool in_word = 0;
    bool end_str = 0;
    if (str == NULL){
      return -2;
    }

    size_t len = strlen(str);

    for (size_t i = 0; i <= len && !end_str; i++) {
      char letter = str[i];
      bool is_letter = (letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z');
      bool is_limiter = (letter == ',' || letter == '.' || letter == ' ');
      bool is_end = (letter == '\0');

      if (!is_letter && !is_limiter && !is_end) {
        return -1;
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

        if (letter == '.'){
          end_str = 1;
        }
      }
    }
    return index_Count;
}

void Print_words_by_indices(char *str, int *out_index, int count){
    for (int i = 0; i < count; i++) {
      int start = out_index[i];
      bool end_str = 0;
      for (int j = start; str[j] != '\0' && !end_str; j++) {
        char letter = str[j];
        if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')) {
          printf("%c", letter);
        }
        else end_str = 1;
      }
      printf("\n");
    }
}

int main()
{
    //char str[35] = ""; //
    //char str[35] = ",,....,,";
    //char str[35] = "apple,banana,orange";
    //char str[35] = "dog,cat,doll";
    //char str[35] = "daddy,mom";
    //char str[35] = "DaD,dog"; // DaD
    //char str[35] = "add,,dad";
    //char str[35] = ".add."; // Invalid input.
    //char str[35] = "add,123,dad"; // Invalid input.
    //char str[35] = "dada"; // dada
    //char str[35] = "dddd,add"; // add
    //char str[35] = "add, dad"; // add dad
    //char str[35] = "add,dad,ded"; // add dad ded
    //char str[35] = "Dd,dd,Dd"; // Dd dd Dd
    //char str[35] = "Dd,dd,Dd."; // Dd dd Dd

    char str[35] = "add,door,dad,data,added."; // add dad
    //char str[35] = "dad ,  ded.    "; // dad ded
    //char str[35] = "dad  proba, add. f "; // dad ded
    //char str[35] = "dad  proba, add. ddd "; // dad ded
    //char str[35] = " dad, проба ddd"; // Invalid input.

    int out_index[100];
    for (int i = 0; i < 100; i++) {
      out_index[i] = -1;
    }

    int found_count = Find_words_with_two_d(str, out_index);
    //printf("%d\n", found_count);

    if (found_count >= 0) {
      Print_words_by_indices(str, out_index, found_count);
    }
    else {
      printf("Invalid input. Error code: (%d)\n", found_count);
    }
}
