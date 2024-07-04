#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pila.h"


//Inicia o crea la pila p como una pila vacía, sin ningún elemento

int pilaCreaVacia(Pila *p)
{
	*p = NULL;
	return 0;
    
}

//Devuelve verdadero si la pila p está vacía, y falso en caso contrario

int pilaVacia(Pila *p)
{
   if(*p == NULL){
   		return 1;
   }
   
   return 0;
    
}

//Añade el elemento x a la pila p convirtiéndolo en el nuevo tope o cima de la pila

int pilaInserta(Pila *p,tipoElemento elemento)
{
	Pila nueva = malloc(sizeof(tipoCelda));
	
	if(nueva == NULL){
		return -1;
	}
	
	nueva->sig=NULL;
	nueva->elemento=elemento;
	
	if(pilaVacia(p)){
		*p=nueva;
	}else{
		nueva->sig=*p;
		*p = nueva;
	}
	
	return 0;
        
}

//Devuelve y suprime el elemento del tope o cima de la pila

tipoElemento pilaSuprime(Pila *p)
{
	
	tipoElemento elemento;
	Pila aBorrar = *p;
	
	if(aBorrar == NULL)
			exit(-1);
		
	elemento = aBorrar->elemento;
	*p = aBorrar->sig;
	free(aBorrar);
		
	return elemen;
   
}
