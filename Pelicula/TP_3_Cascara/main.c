#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "validar.h"
#define CANTIDAD_PELICULAS 2

int main()
{
    char bufferOpcion[5];
    EMovie arrayPelicula[CANTIDAD_PELICULAS];
    movie_initPelicula(arrayPelicula, CANTIDAD_PELICULAS);
    movie_fread(arrayPelicula, CANTIDAD_PELICULAS);


    do
    {
        val_getUnsignedInt(bufferOpcion,"\n1) AGREGAR PELICULA\n2) BORRAR PELICULA\n3) MODIFICAR PELICULA\n4) GENERAR PAGINA WEB\n8) SALIR\n\n ELIJA UNA OPCION: ","\nERROR!....INGRESE UNA OPCION VALIDA\n",INTENTOS,5);

        switch(atoi(bufferOpcion))
            {
            case 1:
                if(movie_altaPelicula(arrayPelicula, CANTIDAD_PELICULAS) == 0)
                {
                   movie_fwrite(arrayPelicula, CANTIDAD_PELICULAS);
                }
                break;
            case 2:
                movie_printPelicula(arrayPelicula, CANTIDAD_PELICULAS);
                if(movie_borrarPelicula(arrayPelicula, CANTIDAD_PELICULAS) == 0)
                {
                    movie_fwrite(arrayPelicula, CANTIDAD_PELICULAS);
                }
                break;
            case 3:
                movie_printPelicula(arrayPelicula, CANTIDAD_PELICULAS);
                if(movie_modificarPelicula(arrayPelicula, CANTIDAD_PELICULAS) == 0)
                {
                    movie_fwrite(arrayPelicula, CANTIDAD_PELICULAS);
                }
                break;
            case 4:

                break;
            case 8:
                printf("\nGRACIAS!\n");
                break;
            default:
                printf("\nERROR!....INGRESE UNA OPCION VALIDA\n");
                break;
            }
    }while(atoi(bufferOpcion) != 8);

    return 0;
}
