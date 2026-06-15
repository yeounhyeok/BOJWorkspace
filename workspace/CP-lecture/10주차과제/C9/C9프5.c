#include <stdio.h>
#include<math.h>
#define HEIGHT 10
#define WIDTH 10

void brighten_image(char* p, int w, int h){
    for(int i=0;i<w*h;i++) if(p[i]>0) p[i]--;
}

int main(){
    char image[HEIGHT * WIDTH] = {
        0, 0, 0, 0, 9, 0, 0, 0, 0, 0,
        0, 0, 0, 9, 9, 0, 0, 0, 0, 0,
        0, 0, 9, 0, 9, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 8, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 9, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 7, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 8, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 9, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 9, 0, 0, 0, 0, 0,
        0, 0, 6, 6, 9, 7, 7, 0, 0, 0
    };
    brighten_image(image, HEIGHT, WIDTH);
    return 0;
}