#ifndef VALIDAR_H_INCLUDED
#define VALIDAR_H_INCLUDED

#endif // VALIDAR_H_INCLUDED

#define MAX_INPUT_BUFFER 4096
#define LF 32

void val_myFgets(char* buffer, int limite, FILE* archivo);

int val_getUnsignedInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarUnsignedInt(char* buffer);

int val_getString(char* destino, char* mensaje, char* mensajeError,int intentos,int limite);
int val_validarString(char* buffer);

int val_getLinkImagen(char* destino, char* mensaje,char* mensajeError, int intentos, int limite);
int val_validarLinkImagen(char* buffer);

int val_getAlfanumerico(char* destino, char* mensaje, char* mensajeError, int intentos,int len);
int val_validarAlfanumerico(char* buffer);
