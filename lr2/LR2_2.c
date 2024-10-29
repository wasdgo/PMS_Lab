#include <stdio.h>
#include <math.h>

double Integral(double a, double b, int n) {
    double width = (b - a) / n;
    double area = 0.0;

    for (int i = 0; i < n; i++) {
        double x_mid = a + (i + 0.5) * width;
        area += log(x_mid) * width;
    }

    return area;
}

int main() {
    int n = 1;
    double a, b, E;
    double result = 0.0;

    scanf("%lf %lf %lf", &a, &b, &E);

    if (a <= 0 || b <= 0 || a > b || E <= 0) {
        printf("Ошибка\n");
        return 1;
    }

    if (a == b) {
        printf("Приближенное значение интеграла от %.2f до %.2f: 0\n", a, b);
    }

    do 
    {
        result = Integral(a, b, n);
        n = n*2;
    } while ((Integral(a,b,n) - Integral(a,b,2*n)) > E);

    printf("Приближенное значение интеграла от %.2f до %.2f: %.10f\n", a, b, result);

    return 0;
}