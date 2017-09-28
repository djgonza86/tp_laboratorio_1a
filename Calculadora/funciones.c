#include <stdio.h>
#include <stdlib.h>

/** \brief Recibe dos numeros y calcula la suma de ambos.
 * \param a Se recibe el primer valor del usuario
 * \param b Se recibe el segundo valor del usuario.
 * \return El resultado de la suma.
 */
float calcularSuma(float a, float b)
{
        float suma;
        suma = a+b;
        return suma;
}


/** \brief Recibe dos numeros y calcula la resta entre ambos.
 * \param a Se recibe el primer valor del usuario
 * \param b Se recibe el segundo valor del usuario
 * \return El resultado de la resta.
 */
float calcularResta(float a, float b)
{
        float resta;
        resta = a-b;
        return resta;
}


/** \brief Recibe dos numeros, valida el divisor, si es 0 imprime el mensaje: "ERROR" y sino calcula la division.
 * \param a Se recibe el primer valor del usuario
 * \param b Se recibe el primer valor del usuario
 * \return Retorna ERROR en caso del divisor 0 y sino da el resultado de la division.
 */
float calcularDivision(float a, float b)
{
    float division;
    if(b != 0)
    {
       division = a/b;
       printf("\nLa division es: %.2f",division);
    }
    else
    {
       printf("\n\nERROR: La division no puede llevarse a cabo\n\n");
    }
    return division;

}

/** \brief Recibe dos numeros y calcula el producto entre ambos.
 * \param a Se recibe el primer valor del usuario.
 * \param b Se recibe el segundo valor del usuario.
 * \return El resultado de la multiplicacion entre ambos.
 */
float calcularMultiplicacion(float a, float b)
{
        float multiplicacion;
        multiplicacion = a*b;
        return multiplicacion;
}

/** \brief Pide al usuario que ingrese un numero y lo retorna
 * \return El numero solicitado
 */
float ingresarNumero()
{
    float numero;
    printf("\nIngrese un numero: \n");
    scanf("%f",&numero);
    return numero;
}

/** \brief Recibe un valor y calcula el factorial
 * \param numero Se recibe el valor del usuario
 * \return El resultado del factorial
 * Si el valor recibido es 1 o 0 la funcion lo valida y retorna el numero 1
 */
int calcularFactorial(int numero)
{
    int resultado;
    if((numero ==0) || (numero==1))
    return 1;

    resultado=numero* calcularFactorial(numero-1);
    return (resultado);
}

