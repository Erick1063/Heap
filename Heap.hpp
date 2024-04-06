#ifndef HEAP_H
#define HEAP_H
class Heap
{

private:
	int *AH;	   // Representa el arbol tipo heap
	int Maxtamano; // Representa el tamano maximo del heap
	int C = 0;	   // Contador de espacios cubiertos

public:
	Heap(const int);						 // Constructor de heap vacio
	Heap(const int, const int[]);			 // Constructor de un heap con un arreglo de parametro
	int getMaxtamano() const;				 // Retorna el tamano maximo que puede tener el heap
	int *getAH() const;						 // Funcion que devuelve el arbol tipo heap
	int Padre(int) const;					 // Retorna el nodo padre de un nodo especifico
	int HijoI(int) const;					 // Retorna el hijo nodo izquierdo de un nodo especifico
	int HijoD(int) const;					 // Retorna el hijo nodo derecho de un nodo especifico
	int Inpadre(int) const;					 // Retorna el indice del padre
	int InHijoI(int) const;					 // Retorna el indice del hijo izquierdo
	int InHijoD(int) const;					 // Retorna el indice del hijo derecho
	void Insertar(const int);				 // Inserta un nuevo nodo al arbol
	void Intercambiar(const int, const int); // Intercambia de posiciones 2 nodos
	void Eliminar(const int);				 // Elimina un nodo especifico de un arbol
	void Subir(const int);					 // Funcion auxiliar utilizada para subir un nodo
	void Bajar(const int);					 // Funcion auxiliar utilizada para baja un nodo
	void MostrarHeap();						 // Muestra el arbol
	// Formas de recorrer el heap
	void InOrder(int);	 // Pide como parametro un nodo(indice)
	void PreOrder(int);	 // Pide como parametro un nodo(indice)
	void PostOrder(int); // Pide como parametro un nodo(indice)
	void BFS();
};
#endif