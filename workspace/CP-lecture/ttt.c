#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    char board[3][3];
    int x, y, k, i;
    srand(time(NULL));
 
    // 보드를 초기화한다. 
    for (x = 0; x < 3; x++)
        for (y = 0; y < 3; y++) board[x][y] = ' ';
 
    // 사용자로부터 위치를 받아서 보드에 표시한다. 
    for (k = 0; k < 9; k++) {
        printf("현재 플레이어: %c\n(x, y) 좌표: ", (!(k%2))?'X':'O');

        if(!(k%2)){ //COMPUTER
            do{
                x = rand() % 3;
                y = rand() % 3;
            }while(board[x][y]!=' ');
            printf("%d %d\n", x, y);
        }
        else{ // USER
            do{
                scanf("%d %d", &x, &y);
            }while(board[x][y]!=' ');
        }
        
        board[x][y] = (k % 2 == 0) ? 'X' : 'O';    // 현재의 순번에 따라 'X', 'O'중 선택
        
        // 보드를 화면에 그린다. 
        for (i = 0; i < 3; i++) {
            printf("---|---|---\n");
            printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        }
        printf("---|---|---\n");

        for(int i=0;i<3;i++){
            if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!=' '){
                printf("%c 승\n", board[i][0]);
                goto there;
            }
        }
        for(int i=0;i<3;i++){
            if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=' '){
                printf("%c 승\n", board[0][i]);
                goto there;
            }
        }
        if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[1][1]!=' '){
            printf("%c 승\n", board[1][1]);
            goto there;
        }
        if(board[2][0]==board[1][1] && board[1][1]==board[0][2] && board[1][1]!=' '){
            printf("%c 승\n", board[1][1]);
            goto there;
        }
    }
    there:;
    return 0;
}