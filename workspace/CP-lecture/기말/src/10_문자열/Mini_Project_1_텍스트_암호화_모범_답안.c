#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void XORCipher(char* data, const char* key, int dataLen, int keyLen, char* output) {
    for (int i = 0; i < dataLen; ++i) {
        output[i] = data[i] ^ key[i % keyLen];
    }
    output[dataLen] = '\0';
}

int main(void)
{
    char text[] = "This is a house.";
    char key[] = "123456";
    int dataLen = strlen(text);
    int keyLen = strlen(key);

    // 암호화 결과와 복호화 결과를 담을 버퍼
    char cipherText[100];  // 충분히 큰 크기로 선언
    char plainText[100];

    XORCipher(text, key, dataLen, keyLen, cipherText);
    XORCipher(cipherText, key, dataLen, keyLen, plainText);

    printf("암호화 전의 문자열=%s\n", text);
    printf("암호화 키=%s\n", key);
    printf("암호화 후의 문자열=%s\n", cipherText);
    printf("복호화 후의 문자열=%s\n", plainText);

    return 0;
}
