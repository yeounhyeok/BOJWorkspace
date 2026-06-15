#include<stdio.h>

double f(double x, double y) { return 1.5*x + 3.0 * y; }

int main(){
    double a[3][2] = {
        {1, 2},
        {2, 0},
        {2, 1}
    };
    for(int i=0;i<3;i++) printf("x=%lf, y=%lf, f(x,y)=%lf\n", a[i][0], a[i][1], f(a[i][0], a[i][1]));
    
    return 0;
}