#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[50];
    char genero[20];
    int duracion;
    char descripcion[100];
    int puntaje;
    char linkImagen[100];
    int flagEstado;
    int id;
}EMovie;

#endif // FUNCIONES_H_INCLUDED

#define ESPACIO_LIBRE 0
#define ESPACIO_OCUPADO 1
#define INTENTOS 3

int movie_initPelicula(EMovie* arrayPelicula, int longitud);

int movie_generarNuevoId(EMovie* arrayPelicula, int longitud);
int movie_buscarPosicionLibre(EMovie* arrayPelicula, int longitud);
int movie_buscarIndicePorId(EMovie* arrayPelicula, int longitud, int id);

int movie_altaPelicula(EMovie* arrayPelicula, int longitud);
int movie_borrarPelicula(EMovie* arrayPelicula, int longitud);
int movie_modificarPelicula(EMovie* arrayPelicula, int longitud);
int movie_printPelicula(EMovie* arrayPelicula, int longitud);

int movie_fread(EMovie* arrayPelicula,int longitud);
int movie_fwrite(EMovie* arrayPelicula,int longitud);
