#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "funciones.h"
#include "validar.h"

/*********************************************************************************************
** \brief inicializa el array
 * \param *arrayPelicula recibido por referencia
 * \param longitud cantidad de elementos del array
 * \return 0 (ok)  o -1 (error)
 *
 */
int movie_initPelicula(EMovie* arrayPelicula, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayPelicula != NULL && longitud > 0)
    {
        for(i = 0; i < longitud ; i++)
        {
            arrayPelicula[i].flagEstado = ESPACIO_LIBRE;
        }

    }
    return retorno;
}


/*********************************************************************************************
** \brief Genera un ID que se incrementa a partir del ultimo encontrado
 * \param *arrayPelicula recibido por referencia
 * \param longitud cantidad de elementos del array
 * \return idMax el id generado
 */
int movie_generarNuevoId(EMovie* arrayPelicula, int longitud)
{
    int idMax = -1;
    int i;
    if(arrayPelicula != NULL && longitud > 0)
    {
        for(i = 0; i < longitud ; i++)
        {
            if(arrayPelicula[i].flagEstado == ESPACIO_OCUPADO && arrayPelicula[i].id > idMax)
            {
                idMax = arrayPelicula[i].id;
            }
        }
        idMax++;
    }
    return idMax;
}


/**********************************************************************************************
** \brief Busca un indice libre
 * \param *arrayPelicula recibido por referencia
 * \param longitud cantidad de elementos del array
 * \return 0(ok) o -1 (error)
 */
int movie_buscarPosicionLibre(EMovie* arrayPelicula, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayPelicula != NULL && longitud > 0)
    {
        for(i = 0; i < longitud ; i++)
        {
            if(arrayPelicula[i].flagEstado == ESPACIO_LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


/**********************************************************************************************
** \brief Busca el indice del ID.
 * \param *arrayPelicula recibido por referencia
 * \param longitud  cantidad de elementos del array
 * \param id se pasa el id para buscar el indice
 * \return retorno -> indice, -1(no se encontro)
 */
int movie_buscarIndicePorId(EMovie* arrayPelicula, int longitud, int id)
{
    int i;
    int retorno = -1;
    if(arrayPelicula != NULL && longitud > 0 && id >= 0)
    {
        for(i = 0; i < longitud; i++)
        {
            if(arrayPelicula[i].flagEstado == ESPACIO_OCUPADO)
            {
                if(id == arrayPelicula[i].id)
                {
                    retorno = i;
                    break;
                }
            }
        }
    }
    return retorno;
}


/***********************************************************************************************
**  \brief Carga los campos de la estructura
 *  \param *arrayPelicula recibido por referencia
 *  \param longitud cantidad de elementos del array
 *  \return retorno -1(Error) o 0(OK)si pudo agregar la pelicula o no
 */
int movie_altaPelicula(EMovie* arrayPelicula, int longitud)
{
    int retorno = -1;

    if(arrayPelicula != NULL && longitud >= 0)
    {
        int indice = movie_buscarPosicionLibre(arrayPelicula,longitud);

        if(indice >= 0)
        {
            char bufferTitulo[50];
            char bufferGenero[20];
            char bufferDuracion[5];
            char bufferDescripcion[100];
            char bufferPuntaje[5];
            char bufferLinkImagen[100];

            if(val_getAlfanumerico(bufferTitulo,"\nIngrese el TITULO: \n","\nError! Solamente Numeros y Letras\n",INTENTOS,50)==0)
            {
                if(val_getString(bufferGenero, "\nIngrese el GENERO: \n","\nError! Solamente Letras\n",INTENTOS,20)==0)
                {
                    if(val_getUnsignedInt(bufferDuracion,"\nIngrese la DURACION: \n","\nError! Solamente Numeros\n",INTENTOS,5)==0)
                    {
                        if(val_getAlfanumerico(bufferDescripcion,"\nIngrese la DESCRIPCION: \n","\nError! Solamente Numeros y Letras\n",INTENTOS,100)==0)
                        {
                            if(val_getUnsignedInt(bufferPuntaje,"\nIngrese el PUNTAJE: \n","\nError! Solamente Numeros\n",INTENTOS,5)==0)
                            {
                                if(val_getLinkImagen(bufferLinkImagen,"\nIngrese el LINK de la IMAGEN: \n","\nError! Caracter no comprendido para el Link\n",INTENTOS,100)==0)
                                {
                                    int IdNuevo = movie_generarNuevoId(arrayPelicula,longitud);
                                    arrayPelicula[indice].id = IdNuevo;
                                    arrayPelicula[indice].flagEstado = ESPACIO_OCUPADO;

                                    strncpy(arrayPelicula[indice].titulo, bufferTitulo,50);
                                    strncpy(arrayPelicula[indice].genero, bufferGenero,20);
                                    arrayPelicula[indice].duracion = atoi(bufferDuracion);
                                    strncpy(arrayPelicula[indice].descripcion, bufferDescripcion,100);
                                    arrayPelicula[indice].puntaje = atoi(bufferPuntaje);
                                    strncpy(arrayPelicula[indice].linkImagen, bufferLinkImagen,100);
                                    retorno = 0;
                                }
                            }
                        }
                    }
                }
            }
        }

    }
    return retorno;
}


/************************************************************************************************
**  \brief Borra los campos de la estructura, colocando el flag en 0
 *  \param *arrayPelicula recibido por referencia
 *  \param longitud cantidad de elementos del array
 *  \return retorna -1(Error) o 0(OK) de acuerdo a si pudo eliminar la pelicula o no
 */
int movie_borrarPelicula(EMovie* arrayPelicula, int longitud)
{
    int retorno = -1;
    char bufferId[10];

    if(arrayPelicula != NULL && longitud > 0)
    {
        val_getUnsignedInt(bufferId,"\nINGRESE EL ID: \n","\nINGRESE UN ID VALIDO: \n",INTENTOS,10);
        int indice = movie_buscarIndicePorId(arrayPelicula, longitud, atoi(bufferId));

        if(indice >= 0)
        {
            arrayPelicula[indice].flagEstado = ESPACIO_LIBRE;
            printf("\nBORRADO \n");
            retorno = 0;
        }
        else
        {
            printf("\n NO SE ENCONTRO EL ID \n");
        }
    }
    return retorno;
}


/***********************************************************************************************
**  \brief Modifica los campos de la estructura mediante un ID que ingresa el Usuario
 *  \param *arrayPelicula recibido por referencia
 *  \param longitud cantidad de elementos del array
 *  \return retorno -1(Error) o 0(OK)si pudo agregar la pelicula o no
 */
int movie_modificarPelicula(EMovie* arrayPelicula, int longitud)
{
    int retorno = -1;
    char bufferId[10];

    if(arrayPelicula != NULL && longitud >= 0)
    {
        if(val_getUnsignedInt(bufferId,"\nINGRESE EL ID: \n","\nINGRESE UN ID VALIDO \n",INTENTOS,10) != -1)
        {
            int indice = movie_buscarIndicePorId(arrayPelicula, longitud, atoi(bufferId));
            if(indice >= 0)
            {
                char bufferTitulo[50];
                char bufferGenero[20];
                char bufferDuracion[5];
                char bufferDescripcion[100];
                char bufferPuntaje[5];
                char bufferLinkImagen[50];

                if(val_getAlfanumerico(bufferTitulo,"\nIngrese el TITULO: \n","\nError! Solamente Numeros y Letras\n",INTENTOS,50)==0)
                {
                    if(val_getString(bufferGenero, "\nIngrese el GENERO: \n","\nError! Solamente Letras\n",INTENTOS,20)==0)
                    {
                        if(val_getUnsignedInt(bufferDuracion,"\nIngrese la DURACION: \n","\nError! Solamente Numeros\n",INTENTOS,5)==0)
                        {
                            if(val_getAlfanumerico(bufferDescripcion,"\nIngrese la DESCRIPCION: \n","\nError! Solamente Numeros y Letras\n",INTENTOS,100)==0)
                            {
                                if(val_getUnsignedInt(bufferPuntaje,"\nIngrese el PUNTAJE: \n","\nError! Solamente Numeros\n",INTENTOS,5)==0)
                                {
                                    if(val_getLinkImagen(bufferLinkImagen,"\nIngrese el LINK de la IMAGEN: \n","\nError! Caracter no comprendido para el Link\n",INTENTOS,100)==0)
                                    {
                                        strncpy(arrayPelicula[indice].titulo, bufferTitulo,50);
                                        strncpy(arrayPelicula[indice].genero, bufferGenero,20);
                                        arrayPelicula[indice].duracion = atoi(bufferDuracion);
                                        strncpy(arrayPelicula[indice].descripcion, bufferDescripcion,100);
                                        arrayPelicula[indice].puntaje = atoi(bufferPuntaje);
                                        strncpy(arrayPelicula[indice].linkImagen, bufferLinkImagen,50);
                                        retorno = 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                printf("\n NO SE ENCONTRO EL ID \n");
            }
        }

    }
    return retorno;
}


/***********************************************************************************************
**  \brief Imprime la Estructura y sus campos
 *  \param *arrayPelicula recibido por referencia
 *  \param longitud cantidad de elementos del array
 *  \return retorno -1(Error) o 0(OK)
 */
int movie_printPelicula(EMovie* arrayPelicula, int longitud)
{
    int retorno = -1;
    int i;
    int acumulador  = 0;

    printf("%s\t%s\t%s\t%s\t%s\t%s\n","ID","TITULO","GENERO","DURACION","DESCRIPCION","PUNTAJE");

    if(arrayPelicula != NULL && longitud > 0 )
    {
        for (i = 0; i < longitud; i++)
        {
            if(arrayPelicula[i].flagEstado == ESPACIO_OCUPADO)
            {
                printf("%d\t%s\t%s\t%d\t%s\t%d\n", arrayPelicula[i].id, arrayPelicula[i].titulo, arrayPelicula[i].genero, arrayPelicula[i].duracion, arrayPelicula[i].descripcion, arrayPelicula[i].puntaje);
                acumulador++;
                retorno = 0;
            }
        }
        if(acumulador == 0)
        {
            printf("\n NO SE CARGARON DATOS \n");
        }
    }
    return retorno;
}


/***********************************************************************************************
** \brief Lee un archivo binario
 * \param *arrayPelicula recibido por referencia
 * \param longitud  cantidad de elementos del array
 * \return retorno -1(Error) o 0(OK)
 */
int movie_fread(EMovie* arrayPelicula,int longitud)
{
    int cantidadLeida;
    FILE *pArchivo;
    int retorno = 0;

    pArchivo = fopen("Peliculas.bin", "rb");
    if(pArchivo == NULL)
    {
        printf("ERROR! \n");
        retorno = -1;
    }
    else
    {
        cantidadLeida = fread(arrayPelicula,sizeof(EMovie),longitud,pArchivo);
        if(cantidadLeida != longitud)
        {
            printf("ERROR! \n");
            retorno = -1;
        }
    }
    fclose(pArchivo);

    return retorno;
}


/*********************************************************************************************
** \brief Escribe un archivo binario
 * \param *arrayPelicula recibido por referencia
 * \param longitud  cantidad de elementos del array
 * \return retorno -1(Error) o 0(OK)
 *
 */
int movie_fwrite(EMovie* arrayPelicula,int longitud)
{
    int cantidadEscrita;
    FILE *pArchivo;
    int retorno = 0;

    pArchivo = fopen("Peliculas.bin", "wb");

    if(pArchivo == NULL)
    {
        printf("ERROR! \n");
        retorno = -1;
    }
    else
    {
        cantidadEscrita = fwrite(arrayPelicula,sizeof(EMovie),longitud,pArchivo);
        if(cantidadEscrita < longitud)
        {
            printf("ERROR! \n");
            retorno = -1;
        }
    }
    fclose(pArchivo);

    return retorno;
}


/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */





