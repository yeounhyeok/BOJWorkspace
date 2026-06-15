#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void b_sort(char a[][30]){
    for(int i=0;i<6-1;i++){
        for(int j=i;j<6-1-i;j++){
            if(strcmp(a[j], a[j+1])>0){
                char tmp[30];
                strcpy(tmp, a[j]);
                strcpy(a[j], a[j+1]);
                strcpy(a[j+1], tmp);
            }
        }
    }
}

int main(){
    char a[6][30]={
        "apple",
        "banana",
        "avocado",
        "tomato",
        "pineapple",
        "pear"
    };

    b_sort(a);

    for(int i=0;i<6;i++){
        printf("%s\n", a[i]);
    }


    return 0;
}