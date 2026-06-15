#include <stdio.h>

int main(void) {
    char line[100] = "";
    char line2[100] = "";

    printf("문자열을 입력하시오: ");
    gets_s(line, sizeof(line));

    int k = 0;
    for (int i = 0; line[i] != '\0'; ++i) {
        while (line[i] >= 'A' && line[i] <= 'z') {
            line2[k++] = line[i++];
        }
    }
    line2[k] = '\0';
    printf("출력 문자열: %s\n", line2);
    return 0;
}
