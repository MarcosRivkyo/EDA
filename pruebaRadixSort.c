#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listas/lista.h"
#include "radixSort.h"


long int contadorInterno, contadorExterno;



int main(int argc, char *argv[])
{   

    double tiempoInicial, tiempoFinal, tiempo;
    int i,j,repeticiones=0;

	Lista miLista;
    tipoPosicion p;
    int numElementos = 5000, codigoError;
    

	FILE *f;
	

	if (argc > 2) {
            printf("\n Uso: ./pruebaRadixSort <número de elementos de la lista>\n\n");
            return -1;
        }
        
    if (argc==2)
		numElementos=atoi(argv[1]);
	
	f = fopen("resRadixSort.txt", "w+");
	
	fprintf(f,"<<<< TIEMPOS DE EJECUCI�N OBTENIDOS >>>>\n\n");
	fprintf(f,"--------------------------------------------------------------------------");	
	fprintf(f,"\n numElementos\t tiempoMedio \t contadorExterno \t contadorInterno");
	fprintf(f,"\n--------------------------------------------------------------------------");
	


	for(j=numElementos;j<=50000;j=j+5000){
		
		repeticiones=contadorInterno=contadorExterno=0;
		
    		printf("Creando lista vacía: %d\n", creaVacia(&miLista));
    		printf("Se crea una lista de %d elementos\n", numElementos);
	    
    	anula(&miLista);	
    	p = primero(&miLista);

    		printf("Creando lista desordenada\n");	
    	
		for (i = 0; i < j; i++) { 
    			codigoError = inserta(rand()%100000,p,&miLista);
    			p = siguiente(p,&miLista);
    	}    

    		printf("\nLista Desordenada \n");
    	
		imprime(&miLista);
    

		tiempoInicial = (double)clock();			
		
    		radixSort(&miLista,10,5);																	
    		repeticiones++;
    
		tiempoFinal = (double)clock();
    

    	tiempo = (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;
    
    		printf("\n\nLista Ordenada \n");
    		
		imprime(&miLista);
		
			printf( "\n\nTiempo de ejecución en ordenar %d elementos: %f   Repeticiones externas:%ld    Repeticiones internas:%ld   \n\n", j,tiempo,contadorExterno/repeticiones, contadorInterno/repeticiones);
			fprintf(f,"\n %d \t\t %lf \t %ld \t\t\t %ld", j,tiempo,contadorExterno/repeticiones,contadorInterno/repeticiones);

	
		anula(&miLista);
    	
			printf("Destruyendo la lista\n");
		
		destruye(&miLista); 
}


	fclose(f);
	      
	
	printf("\n\t<<SE HA CREADO EL FICHERO 'resRadixSort' CON LOS TIEMPOS DE EJECUCION OBTENIDOS>>\n\n");
    
    
    return 0;
}




