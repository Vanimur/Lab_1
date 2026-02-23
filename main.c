#include <stdio.h>

int main()
{
    char str[35] = "add,door,dad,data,added.";

    char word[100];
    int wordLen = 0;
    int dCount = 0;

    for (int i = 0; str[i] != '\0'; i++) {
      char letter = str[i];

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
