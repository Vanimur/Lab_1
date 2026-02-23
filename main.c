#include <stdio.h>

int main()
{
    char s1[15] = "Helloh People!";
    char s2[7] = "ople";

    int Tab[256] = {0};
    char *ptr_s2 = NULL;
    ptr_s2 = s2;

    while (*ptr_s2) {
        Tab[(unsigned char)*ptr_s2++] = 1;
    }

    char *ptr_write = s1;
    for (char *ptr_read = s1; *ptr_read != '\0'; ptr_read++){
      if (Tab[(unsigned char) *ptr_read] == 0){
        *ptr_write = *ptr_read;
        ptr_write++;
      }
    }
    *ptr_write = '\0';
    printf("%s", s1);
    return 0;
}
