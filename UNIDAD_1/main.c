#include <stdio.h>

#include "fracciones/fracciones.c"

int main()
{
    fraction* f = fraction_new(1,2);

    //Demostrar operaciones basicas
    fraction_print(f);
    printf("El numerador de la fraccion: %i\n", fraction_get_num(f));
    printf("El denominador de la fraccion: %i\n\n", fraction_get_den(f));
    fraction_destroy(f);

    //Demostrar operaciones matematicas
    fraction* f1 = fraction_new(4,8);
    fraction* f2 = fraction_new(4,8);
    fraction* ans;

    ans = fraction_add(f1,f2);
    printf("La suma de las fracciones es: ");
    fraction_print(ans);

    ans = fraction_sub(f1,f2);
    printf("La resta de las fracciones es: ");
    fraction_print(ans);

    ans = fraction_mult(f1,f2);
    printf("La multiplicacion de las fracciones es: ");
    fraction_print(ans);

    ans = fraction_div(f1,f2);
    printf("La divison de las fracciones es: ");
    fraction_print(ans);

    printf("Las fracciones son iguales? (1/0): %d", fraction_cmp(f1,f2));

    fraction_destroy(f1);
    fraction_destroy(f2);
    fraction_destroy(ans);
    return 0;
}
