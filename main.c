#include <stdio.h>

void Compact_String(char *s1, char *s2){
    if (s1 == NULL || s2 == NULL) return;

    int Tab[256] = {0};
    char *ptr_s2 = NULL;
    ptr_s2 = s2;

    while (*ptr_s2) {
        Tab[(unsigned char) *ptr_s2++] = 1;
    }

    char *ptr_write = s1;
    for (char *ptr_read = s1; *ptr_read != '\0'; ptr_read++){
      if (Tab[(unsigned char) *ptr_read] == 0){
        *ptr_write = *ptr_read;
        ptr_write++;
      }
      else printf("%d %c\n",(unsigned char)*ptr_read, (unsigned char)*ptr_read);
    }
    *ptr_write = '\0';
}

int main()
{
    char s1[20] = "Helloh People!";
    char s2[10] = "ople";

    //char s1[20] = "abcdef"; // abcdef
    //char s2[10] = "";

    //char s1[20] = "";
    //char s2[10] = "abc";

    //char s1[20] = "aaaa";
    //char s2[10] = "a";

    //char s1[20] = "abc"; // abc
    //char s2[10] = "xyz";

    //char s1[20] = "AaBb"; //ABb
    //char s2[10] = "a";

    //char s1[20] = "a b c"; // abc
    //char s2[10] = " ";

    //char s1[20] = "abcdef"; // def
    //char s2[10] = "aabbcc";

    //char s1[20] = "Hello!"; // Hello
    //char s2[10] = "!";

    // Compact_String(NULL, "abc");
    // Compact_String("abc", NULL);

    //char s1[20] = "привет";
    //char s2[10] = "п";

    //char s1[20] = "привет";
    //char s2[10] = "privet";

    //char s1[20] = "привет";
    //char s2[10] = "";

    //char s1[20] = "privet"; // privet
    //char s2[20] = "привет";

    //char s1[20] = "как dela";
    //char s2[10] = "de";

    Compact_String(s1, s2);
    printf("%s", s1);

    return 0;
}
