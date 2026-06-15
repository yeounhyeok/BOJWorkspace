#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>

int main(void)
{
    HDC hdc = GetWindowDC(GetForegroundWindow());

    FILE * fp = fopen("d:\\lena(256x256).raw", "rb");
    if (fp == NULL) {
        printf("lena.raw 파일을 열 수 없습니다.");
        exit(1);
    }
    char image[256][256];
    fread(image, 1, 256 * 256, fp);
    fclose(fp);

    int r, c;
    for (r = 0; r < 256; r++) {
        for (c = 0; c < 256; c++) {
            int red = image[r][c];
            int green = image[r][c];
            int blue = image[r][c];
            SetPixel(hdc, c, r, RGB(red, green, blue));
        }
    }


}
