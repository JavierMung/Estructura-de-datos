#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Lista{
	
	int *dato;
	int actual;
	int cuantos;
	
	
};

struct Lista* crearnodo(int);
void insertar(struct Lista** , int);
void eliminar(struct Lista**, int);
void mostrar (struct Lista*);

int main(void) {
	int dato;
	struct Lista* lista;
	lista=NULL;

	insertar(&lista, 3);
	insertar(&lista, 25);
		insertar(&lista, 35);
			insertar(&lista, 85);




	eliminar(&lista, 35);
	mostrar(lista);
	
	return 0;
}

struct Lista* crearnodo(int dato){
	struct Lista* nuevo;
	nuevo=NULL;
	nuevo=(struct Lista*)malloc(sizeof(struct Lista));
		if (nuevo==NULL){
		return NULL;
	}
	nuevo->dato=(int *)malloc(8*(sizeof(int)));
		if (nuevo->dato==NULL){
		return NULL;
	}
	nuevo->actual=0;
	nuevo->cuantos=8;
	*(nuevo-> dato) = dato;
	return nuevo;
}
void insertar(struct Lista** lista, int dato){
	int i;
	int *aux;
	i=0;
	aux=NULL;
	
	if (*lista==NULL){
		*lista = crearnodo(dato);
		if((*lista)==NULL){
			return;
		}
		return;
	}
	
	if((*lista)->cuantos==(*lista)->actual+1){
		aux = (int *) malloc (sizeof(int) * ((*lista)->cuantos * 2) );
		
		if(aux==NULL){
			return;
		}
		
		for(i=0; i<(*lista)->cuantos; i++){
			
			*(aux +i)=*((*lista)->dato+i);			
			
		}	
		
		free((*lista)->dato);
		(*lista)->dato=aux;
		(*lista)->cuantos=((*lista)->cuantos)*2;
		
	}
	
	
	
	(*lista)->actual ++ ; //=(*lista)->actual+1;
	
	*((*lista)->dato + (*lista)->actual)=dato;
 
}

void mostrar(struct Lista* lista){
	int i;
	if (lista==NULL){
		printf("No hay datos. ");
		return;
	}
	else{
		for(i=0; i<=lista->actual; i++){
			printf(" %d ->", *(lista->dato+i));
		}
	}
}

void eliminar(struct Lista** lista, int dato){
	int i=0;
	int *aux=NULL;
	
	if(*lista==NULL){
		return;
	} 
	if((*lista)->dato==NULL){
		return;
	}
	
	for (i=0; i<(*lista)->actual; i++){
		if (*((*lista)->dato+i)==dato){
			(*lista)->actual--;
			break;
		}
	}
	for(i; i<= (*lista)->actual; i++){
		*((*lista)-> dato+i) = *((*lista)->dato+(i+1));
	}
	if((*lista)->actual<(*lista)->cuantos/2){
		aux=(int*) malloc (sizeof (int) * ( (*lista)->cuantos/2) );
		if(aux==NULL){
			return;
		}else{
			for (i=0; i<=(*lista)->actual;i++){
				*(aux+i)=*((*lista)->dato+i);
			}
			free((*lista)->dato);
			(*lista)->dato=aux;
			(*lista)->cuantos=(*lista)->cuantos/2;
		}
	}

	
}
