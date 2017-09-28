#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "conio.h"

int main()
{
    int opcion = 0, factorial;
    float  numero_1, numero_2, suma, resta, multiplicacion;

   do{
        system("cls");
        printf("\n\n................INGRESAR NUMEROS.................\n\n");
        printf("\n1. Ingresar 1er Numero (A=%.2f)\n",numero_1);
        printf("\n2. Ingresar 2do Numero (B=%.2f)\n",numero_2);
        printf("\n\n.................OPERACIONES.....................\n\n");
        printf("\n3. Calcular la Suma (A+B)\n");
        printf("\n4. Calcular la Resta (A-B)\n");
        printf("\n5. Calcular la Division (A/B)\n");
        printf("\n6. Calcular la Multiplicacion (A*B)\n");
        printf("\n7. Calcular el Factorial (A!)\n");
        printf("\n8. Calcular todas las operaciones\n");
        printf("\n\n.................SALIDA..........................\n\n");
        printf("\n9. Salir\n");
        printf("\n\n.................ELIGE LA OPCION.................\n\n");
        printf("\n\nHaz ingresado: \n\n");

        scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                system("cls");
                numero_1= ingresarNumero();
                break;
            case 2:
                system("cls");
                numero_2= ingresarNumero();
                break;
            case 3:
                system("cls");
                suma= calcularSuma(numero_1,numero_2);
                printf("\nLa suma es: %.2f",suma);
                getch();
                break;
            case 4:
                system("cls");
                resta= calcularResta(numero_1,numero_2);
                printf("\nLa resta es: %.2f",resta);
                getch();
                break;
            case 5:
                system("cls");
                calcularDivision(numero_1,numero_2);
                getch();
                break;
            case 6:
                system("cls");
                multiplicacion= calcularMultiplicacion(numero_1,numero_2);
                printf("\nLa multiplicacion es: %.2f",multiplicacion);
                getch();
                break;
            case 7:
                system("cls");
                factorial=calcularFactorial(numero_1);
                printf("\nEl factorial del numero %f es: %d",numero_1,factorial);
                getch();
                break;
            case 8:
                system("cls");
                suma= calcularSuma(numero_1,numero_2);
                printf("La suma es: %.2f\n\n",suma);
                resta= calcularResta(numero_1,numero_2);
                printf("La resta es: %.2f\n\n",resta);
                multiplicacion= calcularMultiplicacion(numero_1,numero_2);
                printf("La multiplicacion es: %.2f\n",multiplicacion);
                calcularDivision(numero_1,numero_2);
                factorial=calcularFactorial(numero_1);
                printf("\n\nEl factorial del numero %.2f es: %d\n\n",numero_1,factorial);
                getch();
                break;
            case 9:
                system("cls");
                printf("\n\n\n\t.................GRACIAS!.................\n\n\n");
                break;
        }

    }while(opcion != 9);

return 0;

}
