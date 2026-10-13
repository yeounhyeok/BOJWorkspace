# 자료구조 중간고사 구현 연습

시험 범위는 e-class 8주차 중간고사 안내 기준 **1~5장**입니다. 문제 설명은 Obsidian에서 보고, 직접 구현은 이 폴더의 C 파일에 하도록 구성했습니다.

## 파일 구성

| 구현할 문제 | 문제 설명 | 작성할 C 파일 |
|---|---|---|
| 01 재귀 연습 | `problems/01_recursion.md` | `01_recursion_A.c` ~ `_C.c` |
| 02 배열·포인터·선택 정렬 | `problems/02_array_pointer.md` | `02_array_pointer_A.c` ~ `_D.c` |
| 03 동적 메모리·학생 정보 | `problems/03_dynamic_memory.md` | `03_dynamic_memory.c` |
| 04 스택 명령 처리 | `problems/04_stack.md` | `04_stack.c` |
| 05 원형 큐 명령 처리 | `problems/05_circular_queue.md` | `05_circular_queue.c` |

**다섯 `.c` 파일은 의도적으로 완전히 비어 있습니다.** 함수 뼈대, `main`, TODO, 정답 코드를 넣지 않았습니다. 구현 조건·입력·출력·예제는 각 문제 MD에만 있습니다. 여러 소문제가 있는 문서는 하나씩 골라 같은 C 파일에서 구현하고 테스트하시면 됩니다.

## 구현 후 컴파일

각 파일에 운혁 님의 코드를 작성한 다음 저장소 루트에서 해당 파일을 컴파일하고 실행하세요. 예를 들어:

```sh
mkdir -p "$HOME/.cache/ds-midterm-build"
cc -std=c11 -Wall -Wextra -Wpedantic -Werror \
  workspace/DataStructure/midterm/01_recursion_A.c \
  -o "$HOME/.cache/ds-midterm-build/01_recursion_A"
"$HOME/.cache/ds-midterm-build/01_recursion_A"
```

빈 파일 상태에서는 실행할 `main`이 없으므로 링크가 되지 않는 것이 정상입니다. 구현이 끝난 뒤에 빌드하시면 됩니다.

## C 표기 메모

- `size_t`는 메모리 크기·배열 개수에 사용하는 표준 정수형입니다. 메모리 할당 크기를 계산할 때 종종 보이지만, 이 문제들의 자료구조 알고리즘 자체는 아닙니다.
- `void function(...)`은 반환값이 없는 함수라는 뜻이고, `(void)name;`은 사용하지 않는 값을 버린다고 표시하는 구문입니다. 이번 빈 연습 파일에는 그런 코드를 미리 넣지 않았습니다.

## 교수님 실습게시판 아카이브

`../practice_board/`에는 실습게시판의 **91개 게시글**과 연결 자료 **139개**를 보관했습니다. `catalog.md`에서 전체 색인을 볼 수 있고, 원문은 `posts/`, 첨부는 `attachments/`, 교재 예제 HTML은 `examples/`에 있습니다.

이번 문제 설명은 게시판 실습 1~6의 주제(선택 정렬, 순환, swap·배열, 동적 메모리, 포인터, 스택)를 반영했습니다. 큐는 5장 시험 범위이므로 원형 큐 ADT를 별도 문제로 구성했습니다. 게시판의 실습 7 미로·실습 8 시뮬레이션은 e-class 일정상 중간고사 이후라 여기서는 제외했습니다.

기존 상위 폴더의 `과제1.cpp`와 `과제2.cpp`는 수정하지 않았습니다. 커밋·푸시도 하지 않았습니다.
