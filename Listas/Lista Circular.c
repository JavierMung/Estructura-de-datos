#include <stdio.h>
#include <stdlib.h>

struct Listac{
	
	int dato;
	struct Listac *siguiente;
	
};

struct Listac* crear(int dato);
void insertar_final(struct Listac **cabeza,  int dato);
void insertar(struct Listac **cabeza,  int dato);
void eliminar(struct Listac **, int);
void insertar_final(struct Listac **cabeza, int dato){
	
	struct Listac *nodo, *cola;
	nodo= crear(dato);
	
	cola =*cabeza;
	while(cola->siguiente!=*cabeza){
		cola= cola->siguiente;
	}
	
	if (*cabeza==NULL){
		*cabeza=nodo;
		nodo->siguiente=*cabeza;
	}
	else if((*cabeza)->siguiente==*cabeza){
		nodo->siguiente=*cabeza;
		(*cabeza)->siguiente=nodo;
	}
	else{
		nodo->siguiente=*cabeza;
		cola->siguiente=nodo;
		
	}
}

void eliminar(struct Listac**cabeza, int dato){
	struct Listac* eli, *aux;
	aux=NULL;
	eli=NULL;
	aux=*cabeza;
	eli =*cabeza;
	if((*cabeza)==NULL){
		return;
	}
	if((*cabeza)->siguiente==NULL){
		if((*cabeza)->dato==dato){
			eli=*cabeza;
			*cabeza=NULL;
			free(eli);
			return;
		}
	}
	
	else{
		while(aux->siguiente!=*cabeza){
			if(aux->siguiente->dato==dato){
			 eli=aux->siguiente;
			 aux->siguiente=aux->siguiente->siguiente;
			free(eli);
			}else{
				aux=aux->siguiente;
			}
		}
		return;
	}
		
}
struct Listac* crear(int dato){
	
	struct Listac*nuevo;
	nuevo=(struct Listac*)malloc(sizeof(struct Listac));
	nuevo->dato=dato;
	nuevo->siguiente=NULL;
	return nuevo;
}
void mostrar(struct Listac*cabeza){
	struct Listac *aux;
	aux=NULL;
	aux=cabeza;
	do{
		printf("%d ->", aux->dato);
		aux=aux->siguiente;
		
	}while(aux->siguiente!=cabeza->siguiente);
	
	
	
}
void insertar(struct Listac **cabeza,  int dato){

	struct Listac *nodo, *cola;
	cola=NULL; 
	nodo = crear(dato);
	
	
	cola=*cabeza;
	if(*cabeza==NULL){
		*cabeza=nodo;
		(*cabeza)->siguiente= *cabeza;
	}
	else if((*cabeza)->siguiente==*cabeza){
		(*cabeza)->siguiente=nodo;
		nodo->siguiente=*cabeza;		
	
		(*cabeza )=nodo;
	}
	else{
		while(cola->siguiente!= *cabeza){
		cola=cola->siguiente;
		}
		nodo->siguiente=*cabeza;
		cola->siguiente=nodo;
		*cabeza=nodo;
		
	}
	


	
}

int main(){
	
	struct Listac* cabeza;
	cabeza=NULL;
	
	insertar(&cabeza,  25);
	insertar(&cabeza,  24);
	insertar(&cabeza,  23);
	insertar(&cabeza,  22);
	insertar(&cabeza,  21);
	insertar_final(&cabeza, 26);
	insertar(&cabeza, 19);		
	eliminar(&cabeza, 24);
	mostrar(cabeza);
	
	return 0;
}
