#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas/lista.h"
#include "radixSort.h"


void radixSort(Lista *l, tipoElemento numGrupos, tipoElemento numCifras){
	
	int i, j, digito, temp = 1;
	
	tipoPosicion aux;
	Lista *grupos;
	tipoPosicion *pos;
	
	//Reserva de memoria dinámica
	grupos =(Lista*)calloc(sizeof(Lista), numGrupos);										//Vector de elementos de tipo Lista
	pos = (tipoPosicion*)calloc(sizeof(tipoPosicion), numGrupos);							//Vector de elementos de tipo tipoPosicion
	
	//Inicialización de los vectores
	for(j = 0 ; j < numGrupos ; j++){
			creaVacia(&grupos[j]);
			pos[j] = primero(&grupos[j]);		
	}


	for(i = 0 ; i < numCifras ; i++){											
												
			contadorExterno++;

			//Inicio
			for(j = 0 ; j < numGrupos ; j++){
					pos[j] = primero(&grupos[j]);		
			}

			//Distribución de los nodos en diferentes grupos
			aux = primero(l);								
			while(aux->sig != NULL){														//Instrucción barómetro
				
				contadorInterno++;

				digito = (aux->sig->elemento)%(temp*10)/temp;

				traspasarNodo(aux, l,pos[digito],&grupos[digito]);
				pos[digito] = siguiente(pos[digito],&grupos[digito]);
				siguiente(aux,l);
			}
		
			anula(l);

			//Concatenación de los grupos
			for(j = numGrupos-1 ; j>0 ; j--){					
				concatenarListas(&grupos[j-1], &grupos[j]);									
			}
    			concatenarListas(l,&grupos[0]);
    	
    		
			temp=temp*10;						

	}
}
		
	

	

