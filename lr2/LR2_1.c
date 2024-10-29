#include <stdio.h>

int main() 
{
    double E, sum = 0.0, term;
    int n = 1;
    unsigned long long factor = 1;
    printf("Введите точность E: ");
    if (scanf("%lf", &E) != 1 || E <= 0) {
    printf("Ошибка\n");
    return 1;
    }

    do {
            factor *= n;
            term = 1.0 / factor;
            sum += term;
            n++;
    } while (term > E);

    printf("%.10f", sum);
    return 0;
}