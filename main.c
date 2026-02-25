#include <stdio.h>
#include <stdbool.h>

int main()
{
    char str[35] = "add,door,dad,data,added.";

    char word[100];
    int wordLen = 0;
    int dCount = 0;

    for (int i = 0; str[i] != '\0'; i++) {
      char letter = str[i];
      bool is_letter = (letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z');
      bool is_limiter = (letter == ',' || letter == '.');

      if (!is_letter && !is_limiter) {
          return 0;
      }

      if (letter != ',' && letter != '.') {
        word[wordLen++] = letter;
        if (letter == 'd') {
          dCount++;
        }
      }
      else {
        word[wordLen] = '\0';

        if (dCount == 2) {
          printf("%s\n", word);
        }

        wordLen = 0;
        dCount = 0;
      }
    }
}
