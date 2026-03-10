#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int Find_first_word(char *str, int *word_len){
    if (str == NULL || word_len == NULL) return -2;
    size_t len = strlen(str);

    bool end_str = 0;
    bool in_word = 0;
    int word_start = -1;
    *word_len = 0;

    for (size_t i = 0; i <= len && !end_str; i++){
      char letter = str[i];
      bool is_letter = (letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z');
      bool is_limiter = (letter == ',' || letter == '.' || letter == ' ');
      bool is_end = (letter == '\0');

      if (!is_letter && !is_limiter && !is_end) {
        return -3;
      }
      if (is_letter) {
        if (!in_word) {
            in_word = 1;
            word_start = i;
        }
        *word_len = *word_len + 1;
      }
      else {
        if (in_word){
          end_str = 1;
        }
        in_word = 0;
        if (letter == '.'){
          end_str = 1;
        }
      }
    }
    return word_start;
}

bool Check_two_d(char *str, int start_word, int word_len){
    if (str == NULL || start_word < 0 || word_len <= 0) return false;
    int count_d = 0;
    for (int i = start_word; i < start_word + word_len; i++){
      char letter = str[i];
      if (letter == 'd' || letter == 'D'){
        count_d++;
      }
      if (count_d > 2) return false;
    }
    return (count_d == 2);
}

void Print_words(char *str, int *out_index, int len_out_index) {
    if (str == NULL || out_index == NULL) return;
    if (len_out_index == 0) {
        printf("No words.\n");
        return;
    }

    for (int i = 0; i < len_out_index; i += 2) {
        int start = out_index[i];
        int length = out_index[i + 1];

        printf("%.*s\n", length, str + start);
    }
}

int main()
{
    //char str[35] = "";
    //char str[35] = ",,....,,";
    //char str[35] = "apple,banana,orange";
    //char str[35] = "dog,cat,doll";
    //char str[35] = "daddy,mom";
    //char str[35] = "DaD,dog"; // DaD
    //char str[35] = "add,,dad"; //add dad
    //char str[35] = ".add."; // No words.
    //char str[35] = "add,123,dad"; // Invalid input.
    //char str[35] = "dada"; // dada
    //char str[35] = "dddd,add"; // add
    //char str[35] = "add, dad"; // add dad
    //char str[35] = "add,dad,ded"; // add dad ded
    //char str[35] = "Dd,dd,Dd"; // Dd dd Dd
    //char str[35] = "Dd,dd,Dd."; // Dd dd Dd

    char str[35] = "add,door,dad,data,added."; // add dad
    //char str[35] = "     dad ,  ded.    "; // dad ded
    //char str[35] = "dad  proba, add. f "; // dad ded
    //char str[35] = "dad  proba, add. ddd "; // dad ded
    //char str[35] = " dad, проба ddd"; // Invalid input.
    //char str[7] = ",,addh"; // addh

    int word_len;
    int offset = 0;
    //int word_start = Find_first_word(NULL, &word_len);
    //int word_start = Find_first_word(str, NULL);

    //char *ptr;
    //int word_start = Find_first_word(ptr, &word_len);
    int word_start = Find_first_word(str, &word_len);
    int out_index[100] = {0};
    int len_out_index = 0;
    while (word_start >= 0){
      if (Check_two_d(str, offset + word_start, word_len)){
        out_index[len_out_index++] = offset + word_start;
        out_index[len_out_index++] = word_len;
      };
      offset += (word_start + word_len);
      word_start = Find_first_word(str + offset, &word_len);
    }
    if (word_start < -1){
      printf("Invalid input. Error code: %d", word_start);
    }
    else Print_words(str, out_index, len_out_index);

    return 0;
}
