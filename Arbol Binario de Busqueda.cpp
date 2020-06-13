/*
	Name: Arbol Binario de Busqueda
	Author: Pablo Alejandro Salazar Santizo 
	Instagram Personal: @pablosalazzar
	Instagram del canal: @programandoconpablo
	Canal Youtube: https://www.youtube.com/channel/UC4kQg80cyA7VHEV4VGKwtEA
	Date: 12/06/20 22:27
	Description: Insertar,busquea,recorridos y conteo
*/

#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

struct estructuraNodo{
	int valor;
	struct estructuraNodo *izquierda;
	struct estructuraNodo *derecha;
};

typedef struct estructuraNodo *nodo;

void insertar(int valor,nodo &raiz){
	if(raiz == NULL){
		nodo nuevo = new (struct estructuraNodo);
		nuevo->valor = valor;
		nuevo->izquierda = NULL;
		nuevo->derecha = NULL;
		raiz = nuevo;
	}else{
		if(valor > raiz->valor){
			insertar(valor,raiz->derecha);
		}else if(valor < raiz->valor){
			insertar(valor,raiz->izquierda);
		}else{
			// Numero repetido
		}
	}
}


// ------- RECORRIDOS ----------
//	Preorden 		(R) I D
//	Inorden  		I (R) D *
//	Postorden		I D (R)	

void preorden(nodo raiz){
	if(raiz != NULL){
		cout<<raiz->valor<<", ";
		preorden(raiz->izquierda);
		preorden(raiz->derecha);
	}
}

void inorden(nodo raiz){
	if(raiz != NULL){
		inorden(raiz->izquierda);
		cout<<raiz->valor<<", ";
		inorden(raiz->derecha);
	}
}

void postorden(nodo raiz){
	if(raiz != NULL){
		postorden(raiz->izquierda);
		postorden(raiz->derecha);
		cout<<raiz->valor<<", ";
	}
}

bool buscar(nodo raiz,int numero){
	if(raiz != NULL){
		if(raiz->valor == numero){
			return true;
		}else if(numero > raiz->valor){
			return buscar(raiz->derecha,numero);
		}else if(numero < raiz->valor){
			return buscar(raiz->izquierda,numero);
		}else{
			return false;
		}
	}
}

int main(){
	
	nodo arbol = NULL;
	
	int numeros[] = {35,15,80,10,20,18,17,50,100,70,40};
	int sizeArray = (sizeof(numeros)/sizeof(*numeros));
	
	for(int i=0 ; i < sizeArray; i++){
		insertar(numeros[i],arbol);
	}
	
	cout<<"			+-------------------------------+"<<endl;
	cout<<"			|   Arbol Binario de Busqueda   |"<<endl;
	cout<<"			+-------------------------------+"<<endl;

	cout<<endl<<"PREORDEN : "<<endl;
	preorden(arbol);
	cout<<endl<<"INORDEN : "<<endl;
	inorden(arbol);
	cout<<endl<<"POSTORDEN : "<<endl;
	postorden(arbol);
	
	int busquedaNumero = 0;
	
	cout<<endl<<endl<<"Ingrese numero a buscar:";
	cin>>busquedaNumero;
	cout<<endl;
	
	cout<< ( buscar(arbol,busquedaNumero) ? "Valor encontrado  ": "Valor no encontrado " )<<endl;
	
cout<<endl;	
cout<<endl;
cout<<"****  ****  ****** ******   **   *     *   **   *     * *****  ******      ****** ****** *     *"<<endl;
cout<<"*   * *   * *    * *       *  *  **   **  *  *  **    * *    * *    *      *      *    * **    *"<<endl;
cout<<"*   * *   * *    * *      *    * * * * * *    * * *   * *    * *    *      *      *    * * *   *"<<endl;
cout<<"****  ****  *    * *  *** ****** *  *  * ****** *  *  * *    * *    *      *      *    * *  *  *"<<endl;
cout<<"*     * *   *    * *    * *    * *     * *    * *   * * *    * *    *      *      *    * *   * *"<<endl;
cout<<"*     *  *  *    * *    * *    * *     * *    * *    ** *    * *    *      *      *    * *    **"<<endl;
cout<<"*     *   * ****** ****** *    * *     * *    * *     * *****  ******      ****** ****** *     *"<<endl;
cout<<endl;
cout<<"****    **   ****  *     ****** "<<endl;
cout<<"*   *  *  *  *   * *     *    * "<<endl; 
cout<<"*   * *    * *   * *     *    * "<<endl;
cout<<"****  ****** ****  *     *    * "<<endl;
cout<<"*     *    * *   * *     *    * "<<endl;
cout<<"*     *    * *   * *     *    * "<<endl;
cout<<"*     *    * ****  ***** ****** "<<endl;
	
	getch();
	return 0;
	
}
