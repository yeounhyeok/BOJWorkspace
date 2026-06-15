#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    int id;
    char name[30];
    char author[30];
};
struct book library[1000];

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void remove_newline(char* str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

int main() {
    char name[30], author[30];
    int select = 0;
    int nbooks = 0;

    while (select != 6) {
        printf("===========================================\n");
        printf("1. 도서 번호로 책 찾기\n");
        printf("2. 저자 이름으로 책 찾기\n");
        printf("3. 제목으로 책 찾기\n");
        printf("4. 새로운 책 추가\n");
        printf("5. 도서관이 소장한 도서의 수 표시\n");
        printf("6. 종료\n");
        printf("===========================================\n");
        printf("메뉴 중에서 하나를 선택하세요: ");
        scanf("%d", &select);
        clear_input_buffer();

        switch (select) {
        case 1:  // 도서 번호로 책 찾기
            printf("도서 번호를 입력하세요: ");
            int id;
            scanf("%d", &id);
            clear_input_buffer();
            if (id >= 0 && id < nbooks) {
                printf("도서 번호: %d\n", library[id].id);
                printf("책 이름: %s\n", library[id].name);
                printf("저자 이름: %s\n", library[id].author);
            }
            else {
                printf("해당 도서 번호의 책이 없습니다.\n");
            }
            break;

        case 2:  // 저자 이름으로 찾기
            printf("저자 이름을 입력하시오: ");
            fgets(author, sizeof(author), stdin);
            remove_newline(author);
            for (int i = 0; i < nbooks; i++) {
                if (strcmp(author, library[i].author) == 0)
                    printf("도서번호: %d, 제목: %s, 저자: %s\n", library[i].id, library[i].name, library[i].author);
            }
            break;

        case 3:  // 제목으로 찾기
            printf("책 제목을 입력하시오: ");
            fgets(name, sizeof(name), stdin);
            remove_newline(name);
            for (int i = 0; i < nbooks; i++) {
                if (strcmp(name, library[i].name) == 0)
                    printf("도서번호: %d, 제목: %s, 저자: %s\n", library[i].id, library[i].name, library[i].author);
            }
            break;

        case 4:  // 새로운 책 추가
            printf("책 이름 = ");
            fgets(library[nbooks].name, sizeof(library[nbooks].name), stdin);
            remove_newline(library[nbooks].name);
            printf("저자 이름 = ");
            fgets(library[nbooks].author, sizeof(library[nbooks].author), stdin);
            remove_newline(library[nbooks].author);
            library[nbooks].id = nbooks;
            nbooks++;
            printf("책이 추가되었습니다.\n");
            break;

        case 5:  // 모든 도서 출력
            printf("총 소장 도서 수: %d\n", nbooks);
            for (int i = 0; i < nbooks; i++) {
                printf("도서번호: %d, 제목: %s, 저자: %s\n", library[i].id, library[i].name, library[i].author);
            }
            break;

        case 6:  // 종료
            printf("프로그램을 종료합니다.\n");
            exit(0);

        default:
            printf("잘못된 선택입니다. 1~6 사이의 숫자를 입력하세요.\n");
        }
    }

    return 0;
}
