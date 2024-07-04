#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "lista.h"



int
creaVacia(Lista *l)
{
    if (l == NULL)		
        return -2;
    else if (NULL == (l->raiz = l->ultimo = (tipoCelda *)malloc(sizeof(tipoCelda))))
        return -1;			
    else {
        l->raiz->sig = NULL;
        return 0;
    }
}


int
vacia(Lista *l)
{
    if (l == NULL || l->raiz == NULL) {
        return -1;		
    }
    else if (l->raiz->sig == NULL)
        return 1;
    else
        return 0;
}

int
anula(Lista *l)
{
	tipoPosicion q, aBorrar;
	
	if(l==NULL){
		return -2;			
	}
	q = (l->raiz)->sig;
	
	while(q!=NULL){
		
		aBorrar = q;
		q = q->sig;
		free(aBorrar);	
	
	}

	l->ultimo=l->raiz;
	l->ultimo->sig=NULL;
}



int
destruye(Lista *l)
{
    if (l == NULL || l->raiz == NULL) {
        return -1;				
    }
    else if (l->raiz->sig != NULL){
        return -2;				
    }
    else {
        free(l->raiz);
        l->raiz = l->ultimo = NULL;
        return 0;
    }
}


void
imprime(Lista *l)
{
    tipoCelda *aImprimir;
    int posicion;
    
    if (l == NULL || l->raiz == NULL) {
        return;
    }
    else {
        posicion = 1;
        aImprimir = l->raiz->sig;
        while (aImprimir != NULL) {
            printf(" %d ",aImprimir->elemento);
            aImprimir = aImprimir->sig;
        }
    }
}


tipoPosicion
siguiente(tipoPosicion p,Lista *l)
{
    
	if(l == NULL || l->raiz == NULL || p == NULL){
		return NULL;
	}
	else if(p == fin(l)){
		return l->ultimo;		
	}
	else{
		return p->sig;
	}
	
}



tipoPosicion
anterior(tipoPosicion p, Lista *l)
{
    tipoCelda *anterior;
    
    if (l == NULL || l->raiz == NULL || p == NULL) {
        return NULL;
    }
    else if (p == l->raiz){
        return l->raiz;
    }
    else {
        anterior = l->raiz;
        while (anterior->sig != p)
            anterior = anterior->sig;
        return anterior;
    }
}

tipoPosicion
primero(Lista *l)
{
 	if (l == NULL) {
        return NULL;
    }
    else if (l->raiz == NULL){
        return NULL;
    } else
        return l->raiz;
    
}



tipoPosicion
fin(Lista *l)
{
    if (l == NULL) {
        return NULL;
    }
    else if (l->ultimo == NULL){
        return NULL;
    }
    else
        return l->ultimo;
}




int
inserta(tipoElemento x, tipoPosicion p, Lista *l)
{
    tipoCelda *nuevo;
    
    if (l == NULL) {
        return -1;
    }
    else if (l->raiz == NULL) {
        return -2;
    }
    else if (p == NULL){
        return -3;
    }
    else if ((nuevo = (tipoCelda*)malloc(sizeof(tipoCelda))) == NULL) {
        return -4;
    }
    else {
        nuevo->elemento = x;
        nuevo->sig = p->sig;
        p->sig = nuevo;
        if (p == l->ultimo)
            l->ultimo = nuevo;
	    }
        return 0;
	
}


int
suprime (tipoPosicion p, Lista *l)
{
	tipoPosicion aBorrar;
	
    if(p == NULL){
    	return -1;
	}
    else if(l == NULL){
    	return -2;
	}
	
	aBorrar = p->sig;
    p->sig = aBorrar->sig;
    
    if(l->ultimo == aBorrar){
    	l->ultimo = p;
	}
    free(aBorrar);
    
}








tipoPosicion
localiza (tipoElemento x, Lista *l)
{
	
	tipoPosicion q;
	
	q = l->raiz;
	
	if(l == NULL){
			return NULL;	
	}
	else{

	while(q->sig != NULL){
		
		if(q->sig->elemento == x){
			
			return q;
		
		}	
		q = q->sig;
		
	}
	return fin(l);	

	}
}



tipoElemento
recupera(tipoPosicion p, Lista *l)
{
    
    if(p == NULL){
    	return -1;
	}
	else if(l == NULL){
		return -2;
	}
	 if(p == fin(l)){
		return p->elemento;
	}
    
    return p->sig->elemento;
    
}





int 
traspasarNodo(tipoPosicion p, Lista *lA, tipoPosicion q, Lista *lB)
{
	tipoPosicion temp;
	tipoElemento x;
	
	if(lA == NULL){
		return -1;
	}
	else if(lB == NULL){
		return -2;
	}
	else if(p == NULL){
		return -3;
	}
	else if(q == NULL){
		return -4;
	}
	else{
	//temp = anterior(p,lA);
		x=recupera(p, lA);
		suprime(p, lA);
		inserta(x,q, lB);
	}
	return 0;
	
}


int 
concatenarListas(Lista *lA, Lista *lB) {

    if (lA == NULL){
    	return -1;
	}
	else if(lA->raiz == NULL){
		return -2;
	}
	else if(lB->raiz == NULL){
		return -3;
	}
	else if(lB== NULL){
		return -4;
	} 
    else {
    	
        while (!vacia(lB)) {
        	
            inserta(siguiente(primero(lB),lB)->elemento, fin(lA), lA);
            
            suprime(primero(lB), lB);
            
        }
    }
    
    return 0;
}



