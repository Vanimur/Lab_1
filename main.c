#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void Fill_associative_table(int *Tab, char *str, size_t size){
    for (size_t i = 0; i < size; i++){
        unsigned char letter = str[i];
        Tab[letter]++;
    }
}

bool Check_anagram(char *w1, char *w2){
    size_t Len_w1 = strlen(w1);
    size_t Len_w2 = strlen(w2);

    if (Len_w1 != Len_w2) {
        printf("The words W1 and W2 have different lengths. They can't be anagrams.\n");
        return false;
    }

    if (Len_w1 == 0 || Len_w2 == 0){
        printf("No words.\n");
        return false;
    }

    int Tab_w1[256] = {0};
    Fill_associative_table(Tab_w1, w1, Len_w1);

    int Tab_w2[256] = {0};
    Fill_associative_table(Tab_w2, w2, Len_w2);

    bool flag = true;
    for (int j = 0; (j < 256) && (flag == true); j++){
        if (Tab_w1[j] != Tab_w2[j]){
            flag = false;
        }
    }
    return flag;
}


int main()
{
//    char w1[7] = "komar"; // Yes.
//    char w2[7] = "korma";

//    char w1[7] = "kaban"; // Yes.
//    char w2[7] = "banka";

//    char w1[7] = "kommar"; // The words W1 and W2 have different lengths. They can't be anagrams.
//    char w2[7] = "korma";

//    char w1[7] = ""; // No words.
//    char w2[7] = "";

    char w1[7] = "komar"; // Yes.
    char w2[7] = "komar";

    if (Check_anagram(w1, w2) == true) printf("Yes.\n");
    else printf("No.\n");
    return 0;
}
