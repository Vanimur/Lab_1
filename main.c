#include <stdio.h>

int main()
{
//    char w1[7] = "komar"; // Yes.
//    char w2[7] = "korma";

//    char w1[7] = "kaban"; // Yes.
//    char w2[7] = "banka";

//    char w1[7] = "kommar"; // The words W1 and W2 have different lengths. They can't be anagrams.
//    char w2[7] = "korma";

    char w1[7] = ""; // The words W1 and W2 have different lengths. They can't be anagrams.
    char w2[7] = "";

    int Len_w1 = 0;
    int Len_w2 = 0;
    int i = 0;
    while (w1[i]){
        Len_w1++;
        i++;
    }

    i = 0;
    while (w2[i]){
        Len_w2++;
        i++;
    }

    if (Len_w1 != Len_w2) {
        printf("The words W1 and W2 have different lengths. They can't be anagrams.\n");
        return 0;
    }

    if (Len_w1 == 0 || Len_w2 == 0){
        printf("No words.\n");
        return 0;
    }

    int Tab_w1[256] = {0};
    for (int j = 0; j < Len_w1; j++){
        int letter = w1[j];
        Tab_w1[letter]++;
    }

    int Tab_w2[256] = {0};
    for (int j = 0; j < Len_w2; j++){
        int letter = w2[j];
        Tab_w2[letter]++;
    }

    int flag = 0;
    for (int j = 0; (j < 256) && (flag == 0); j++){
        if (Tab_w1[j] != Tab_w2[j]){
            flag = 1;
        }
    }
    if (flag == 0) printf("Yes.\n");
    else printf("No.\n");
    return 0;
}
