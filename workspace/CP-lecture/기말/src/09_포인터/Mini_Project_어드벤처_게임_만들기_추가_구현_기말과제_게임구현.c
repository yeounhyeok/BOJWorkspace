#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define    DIFFICULTY    0.8    // 0~1 로 높을수록 어려움

#define    get_prob()    rand()/(double) RAND_MAX

int main(void)
{
    char board[10][10];
    int xpos = 1, ypos = 1;
    int xpos_m1 = 5, ypos_m1 = 5;
    int xpos_m2 = 7, ypos_m2 = 6;
    int xpos_g=9, ypos_g=9;
    int score=0;
    int num = 0;

    // 보드를 초기화한다.
    for (int y = 0; y < 10; y++)
        for (int x = 0; x < 10; x++) board[y][x] = '.';
    board[ypos][xpos] = '#';
    board[ypos_g][xpos_g] = 'G';
    board[ypos_m1][xpos_m1] = 'M';
    board[ypos_m2][xpos_m2] = 'M';

    srand(time(NULL));

    printf("왼쪽이동:a, 오른쪽 이동:d 위쪽 이동:w, 아래쪽 이동:s\n");
    // 사용자로부터 위치를 받아서 보드에 표시한다.
    while (1) {
        system("cls");
        printf("왼쪽이동:a, 오른쪽 이동:d 위쪽 이동:w, 아래쪽 이동:s (%d)\n",num++);
        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) printf("%c", board[y][x]);
            printf("\n");
        }
        if ((ypos == ypos_m1 && xpos == xpos_m1) || (ypos == ypos_m2 && xpos == xpos_m2)) {
            printf("캐릭터 죽음 (점수:%d)",score);
            break;
        }
        if (ypos == ypos_g && xpos == xpos_g) {
            printf("게임종료 (점수:%d)",score);
            break;
        }
        board[ypos][xpos] = '.';
        board[ypos_m1][xpos_m1] = '.';
        board[ypos_m2][xpos_m2] = '.';

        int ch = _getch();
        if (ch == 0) ch = _getch();  // 한번 입력해도 두번째 0이 또 입력되는 문제 해결
        if (ch == 'a') { if (xpos >= 1) xpos--; }
        else if (ch == 's') { if (ypos <= 8) ypos++; }
        else if (ch == 'w') { if (ypos >= 1) ypos--; }
        else if (ch == 'd') { if (xpos <= 8) xpos++; }

        if (get_prob() < DIFFICULTY) {    // monster 1 무작위 이동
            if (get_prob() < 0.5) {
                if (get_prob() < 0.5) {
                    if (xpos_m1 <= 8) xpos_m1++;
                }
                else {
                    if (xpos_m1 >= 1) xpos_m1--;
                }
            }else {
                if (get_prob() < 0.5) {
                    if (ypos_m1 <= 8) ypos_m1++;
                }
                else {
                    if (ypos_m1 >= 1) ypos_m1--;
                }
            }
        }
        if (get_prob() < DIFFICULTY) {    // monster 2 무작위 이동
            if (get_prob() < 0.5) {
                if (get_prob() < 0.5) {
                    if (xpos_m2 <= 8) xpos_m2++;
                }
                else {
                    if (xpos_m2 >= 1) xpos_m2--;
                }
            } else {
                if (get_prob() < 0.5) {
                    if (ypos_m2 <= 8) ypos_m2++;
                }
                else {
                    if (ypos_m2 >= 1) ypos_m2--;
                }
            }
        }

        board[ypos][xpos] = '#';
        board[ypos_m1][xpos_m1] = 'M';
        board[ypos_m2][xpos_m2] = 'M';
        score++;
    }
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define    DIFFICULTY    0.4    // 0~1 로 높을수록 어려움

#define    get_prob()    rand()/(double) RAND_MAX

void CursorView()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
    cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void move_monster(int xpos, int ypos, int* xpos_m, int* ypos_m)
{
    if (get_prob() < DIFFICULTY) {      // monster
        if (get_prob() < get_prob()) {  // 무작위 이동
            if (get_prob() < 0.5) {
                if (get_prob() < 0.5) {
                    if (*xpos_m <= 8) (*xpos_m)++;
                }
                else {
                    if (*xpos_m >= 1) (*xpos_m)--;
                }
            }
            else {
                if (get_prob() < 0.5) {
                    if (*ypos_m <= 8) (*ypos_m)++;
                }
                else {
                    if (*ypos_m >= 1) (*ypos_m)--;
                }
            }
        }
        else {   // 캐릭터 따라감
            *xpos_m = *xpos_m > xpos ? --(*xpos_m) : *xpos_m < xpos ? ++(*xpos_m) : *xpos_m;
            *ypos_m = *ypos_m > ypos ? --(*ypos_m) : *ypos_m < ypos ? ++(*ypos_m) : *ypos_m;
        }
    }
}

int main(void)
{
    char board[10][10];
    int xpos = 1, ypos = 1;
    int xpos_m1 = 5, ypos_m1 = 5;
    int xpos_m2 = 7, ypos_m2 = 6;
    int xpos_g = 9, ypos_g = 9;
    int score = 0;
    int num = 0, ch=0;

    CursorView();
    // 보드를 초기화한다.
    for (int y = 0; y < 10; y++)
        for (int x = 0; x < 10; x++) board[y][x] = '.';
    board[ypos][xpos] = '#';
    board[ypos_g][xpos_g] = 'G';
    board[ypos_m1][xpos_m1] = 'M';
    board[ypos_m2][xpos_m2] = 'M';

    srand(time(NULL));

    printf("왼쪽이동:a, 오른쪽 이동:d 위쪽 이동:w, 아래쪽 이동:s\n");
    // 사용자로부터 위치를 받아서 보드에 표시한다.
    while (1) {
        system("cls");
        printf("왼쪽이동:a, 오른쪽 이동:d 위쪽 이동:w, 아래쪽 이동:s (%d)\n", num++);
        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) printf("%c", board[y][x]);
            printf("\n");
        }
        if ((ypos == ypos_m1 && xpos == xpos_m1) || (ypos == ypos_m2 && xpos == xpos_m2)) {
            printf("캐릭터 죽음 (점수:%d)", score);
            break;
        }
        if (ypos == ypos_g && xpos == xpos_g) {
            printf("게임종료 (점수:%d)", score);
            break;
        }
        board[ypos][xpos] = '.';
        board[ypos_m1][xpos_m1] = '.';
        board[ypos_m2][xpos_m2] = '.';

        if (_kbhit() == 1) {
            ch = _getch();
            //if (ch == 0) ch = _getch();  // 한번 입력해도 두번째 0이 또 입력되는 문제 해결

            if (ch == 'a') { if (xpos >= 1) xpos--; }
            else if (ch == 's') { if (ypos <= 8) ypos++; }
            else if (ch == 'w') { if (ypos >= 1) ypos--; }
            else if (ch == 'd') { if (xpos <= 8) xpos++; }
        }

        move_monster(xpos, ypos, &xpos_m1, &ypos_m1);
        move_monster(xpos, ypos, &xpos_m2, &ypos_m2);

        board[ypos][xpos] = '#';
        board[ypos_m1][xpos_m1] = 'M';
        board[ypos_m2][xpos_m2] = 'M';
        board[ypos_g][xpos_g] = 'G';
        score++;

        Sleep(200);
    }
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define     DIFFICULTY    0.4    // 0~1 로 높을수록 어려움
#define     NUM_MONSTER     5

#define    get_prob()    rand()/(double) RAND_MAX

void CursorView()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
    cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void move_monster(int xpos, int ypos, int* xpos_m, int* ypos_m)
{
    if (get_prob() < DIFFICULTY) {      // monster
        if (get_prob() < get_prob()) {  // 무작위 이동
            if (get_prob() < 0.5) {
                if (get_prob() < 0.5) {
                    if (*xpos_m <= 8) (*xpos_m)++;
                }
                else {
                    if (*xpos_m >= 1) (*xpos_m)--;
                }
            }
            else {
                if (get_prob() < 0.5) {
                    if (*ypos_m <= 8) (*ypos_m)++;
                }
                else {
                    if (*ypos_m >= 1) (*ypos_m)--;
                }
            }
        }
        else {   // 캐릭터 따라감
            *xpos_m = *xpos_m > xpos ? --(*xpos_m) : *xpos_m < xpos ? ++(*xpos_m) : *xpos_m;
            *ypos_m = *ypos_m > ypos ? --(*ypos_m) : *ypos_m < ypos ? ++(*ypos_m) : *ypos_m;
        }
    }
}

int main(void)
{
    char board[10][10];
    int xpos = 1, ypos = 1;
    int xpos_m[NUM_MONSTER], ypos_m[NUM_MONSTER];

    int xpos_g = 9, ypos_g = 9;
    int score = 0;
    int num = 0, ch=0, flag=0;

    CursorView();
    srand(time(NULL));

    // 보드를 초기화한다.
    for (int y = 0; y < 10; y++)
        for (int x = 0; x < 10; x++) board[y][x] = '.';
    for (int i = 0; i < NUM_MONSTER; i++) {
        xpos_m[i] = rand() % 10;
        ypos_m[i] = rand() % 10;
    }
    board[ypos][xpos] = '#';
    board[ypos_g][xpos_g] = 'G';
    for (int i = 0; i < NUM_MONSTER; i++) {
        board[ypos_m[i]][xpos_m[i]] = 'M';
    }

    printf("왼쪽이동:a, 오른쪽 이동:d 위쪽 이동:w, 아래쪽 이동:s\n");
    // 사용자로부터 위치를 받아서 보드에 표시한다.
    while (1) {
        system("cls");
        printf("왼쪽이동:a, 오른쪽 이동:d 위쪽 이동:w, 아래쪽 이동:s (%d)\n", num++);
        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) printf("%c", board[y][x]);
            printf("\n");
        }
        for (int i = 0 ; i < NUM_MONSTER; i++) {
            if (ypos == ypos_m[i] && xpos == xpos_m[i]) {
                printf("캐릭터 죽음 (점수:%d)", score);
                flag = 1;
                break;
            }
        }
        if (flag == 1) break;
        if (ypos == ypos_g && xpos == xpos_g) {
            printf("게임종료 (점수:%d)", score);
            break;
        }
        board[ypos][xpos] = '.';
        for (int i = 0; i < NUM_MONSTER; i++) {
            board[ypos_m[i]][xpos_m[i]] = '.';
        }


        if (_kbhit() == 1) {
            ch = _getch();
            //if (ch == 0) ch = _getch();  // 한번 입력해도 두번째 0이 또 입력되는 문제 해결

            if (ch == 'a') { if (xpos >= 1) xpos--; }
            else if (ch == 's') { if (ypos <= 8) ypos++; }
            else if (ch == 'w') { if (ypos >= 1) ypos--; }
            else if (ch == 'd') { if (xpos <= 8) xpos++; }
        }

        for (int i = 0; i < NUM_MONSTER; i++) {
                move_monster(xpos, ypos, &xpos_m[i], &ypos_m[i]);
        }

        board[ypos][xpos] = '#';
        for (int i = 0; i < NUM_MONSTER; i++) {
            board[ypos_m[i]][xpos_m[i]] = 'M';
        }
        board[ypos_g][xpos_g] = 'G';
        score++;

        Sleep(200);
    }
    return 0;
}
