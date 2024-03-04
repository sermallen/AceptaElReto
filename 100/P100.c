#include <stdio.h>
#include <stdlib.h> // para qsort()

int compare(const void *_a, const void *_b) // ver ./utils/quick_sort.txt
{
    int *a, *b;
    a = (int *)_a;
    b = (int *)_b;
    return (*a - *b);
}

int main(int argc, char const *argv[])
{
    int casos, numero;
    scanf("%d", &casos);

    while (casos) // casos>0
    {
        scanf("%d", &numero);

        int iteraciones = 0;
        while (numero != 6174)
        {
            // separar numero en unidades, decenas, centenas y millares
            int digitos[4];
            digitos[3] = numero % 10;
            digitos[2] = (numero % 100 - digitos[3]) / 10;
            digitos[1] = (numero % 1000 - digitos[2]*10 - digitos[3]) / 100;
            digitos[0] = (numero % 10000 - digitos[1]*100 - digitos[2]*10 - digitos[3]) / 1000;

            // comprobar si todos los digitos son iguales
            if (digitos[3] == digitos[2] && digitos[3] == digitos[1]
             && digitos[3] == digitos[0]) 
            {
                iteraciones = 8;
                break;
            }

            //ordenar digitos de menor a mayor
            qsort(digitos, 4, sizeof(int), &compare); // ver ./utils/quick_sort.txt

            // juntar numeros haciendo el mayor posible y el menor posible
            int mayor = digitos[3]*1000 + digitos[2]*100 + digitos[1]*10 + digitos[0];
            int menor = digitos[0]*1000 + digitos[1]*100 + digitos[2]*10 + digitos[3];

            // generar numero para la siguiente iteracion
            numero = mayor - menor;
            iteraciones++;
        }

        printf("%d\n", iteraciones);
        casos--;
    }
    return 0;
}
