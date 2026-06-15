#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

int main(void)
{
    char board[10][10];
    int xpos = 1, ypos = 1;
    int k, i;

    // 보드를 초기화한다.
    for (int y = 0; y < 10; y++)
        for (int x = 0; x < 10; x++) board[y][x] = '.';
    board[ypos][xpos] = '#';
    board[9][9] = 'G';
    board[5][5] = 'M';
    board[6][7] = 'M';

    printf("왼쪽이동:a, 오른쪽 이동:d 위쪽 이동:w, 아래쪽 이동:s\n");
    // 사용자로부터 위치를 받아서 보드에 표시한다.
    while (1) {
        system("cls");
        printf("왼쪽이동:a, 오른쪽 이동:d 위쪽 이동:w, 아래쪽 이동:s\n");
        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) printf("%c", board[y][x]);
            printf("\n");
        }
        board[ypos][xpos] = '.';
        int ch = _getch();
        if (ch == 'a') xpos--;
        else if (ch == 's') ypos++;
        else if (ch == 'w') ypos--;
        else if (ch == 'd') xpos++;
        board[ypos][xpos] = '#';
    }
    return 0;
}
