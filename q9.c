// Mirror the Code Name
// Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.
#include <stdio.h>
#include <string.h>

void reverse(char str[], int start, int end) {
    if(start >= end) return;   

    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reverse(str, start + 1, end - 1);
}

int main() {
    char str[100];
    scanf("%s", str);   

    int length = strlen(str);
    reverse(str, 0, length - 1);

    printf("%s\n", str);   

    return 0;
}
