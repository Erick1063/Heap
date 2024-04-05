#ifndef HEAP_H
#define HEAP_H
class Heap{
	
	private:
		int *AH;        //Representa el arbol tipo heap
		int Maxtamano;  //Representa el tamano maximo del heap
		int C=0;        //Contador de espacios cubiertos
		
	public:
		Heap(int);         //Constructor de heap vacio
		Heap(int,int []);  //Constructor de un heap con un arreglo de parametro
		int getMaxtamano();//Retorna el tamano maximo que puede tener el heap
		int *getAH();      //Funcion que devuelve el arbol tipo heap
		int Padre(int);    //Retorna el nodo padre de un nodo especifico
		int HijoI(int);    //Retorna el hijo nodo izquierdo de un nodo especifico
		int HijoD(int);    //Retorna el hijo nodo derecho de un nodo especifico
		int Inpadre(int);  //Retorna el indice del padre
		int InHijoI(int);  //Retorna el indice del hijo izquierdo
		int InHijoD(int);  //Retorna el indice del hijo derecho
		void Insertar(int);//Inserta un nuevo nodo al arbol 
		void Intercambiar(int,int); //Intercambia de posiciones 2 nodos
		void Eliminar(int);//Elimina un nodo especifico de un arbol
		void Subir(int);   //Funcion auxiliar utilizada para subir un nodo
		void Bajar(int);   //Funcion auxiliar utilizada para baja un nodo 
		void MostrarHeap();//Muestra el arbol 
		//Formas de recorrer el heap
		int InOrder(int); //Pide como parametro un nodo
		int PreOrder(int);//Pide como parametro un nodo
		int PostOrder(int);//Pide como parametro un nodo
		int BFS(int);
			 
		
};
#endif