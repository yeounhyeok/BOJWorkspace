#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>

int main(void) {
    char solution[100] = "meet at midnight";    // 정답이 들어 있는 문자 배열
    char answer[100] = "____ __ ________";  // 현재까지 사용자가 맞춘 문자열
    char ch;
    int i;

    while (1) {
        printf("\n문자열을 입력하시오: %s \n", answer);
        printf("글자를 추측하시오: ");
        ch = _getch();

        // 사용자가 입력한 문자를 answer[]에 넣어서  정답을 비교한다.
        for (i = 0; solution[i] != '\0'; i++) {

            // 사용자가 맞추었으면 글자를 보이게 한다.
            if (solution[i] == ch)
                answer[i] = ch;
        }
        if (strcmp(solution, answer) == 0) break; // 정답과 일치하는지를 검사
    }
    return 0;
}
