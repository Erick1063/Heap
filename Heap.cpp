#include "Heap.hpp"
#include <math.h>
#include <iostream>
#include <queue> //Libreria cola,para el recorrido por anchura
using namespace std;
// Constructor de un heap de 0  ; la funcion ceil redondea un numero hacia arriba al siguiente entero
Heap::Heap(const int tamano)
{
	this->Maxtamano = pow(2, ceil(log2(tamano))) - 1;
	this->AH = new int(this->Maxtamano);
}
// Constructor de un heap en base a un arreglo
Heap::Heap(const int tamano,const int Arreglo[])
{
	this->Maxtamano = pow(2, ceil(log2(tamano))) - 1;
	this->AH = new int(this->Maxtamano);
	for (int i = 0; i < tamano; i++)
	{
		this->AH[i] = Arreglo[i];
	}
	this->C = tamano;
}
// Funcion que retorna el tamano maximo del arbol
int Heap::getMaxtamano()const
{
	return this->Maxtamano;
}
// Funcion que retorna el arbol heap
int *Heap::getAH()const
{
	return this->AH;
}
// Funcion que retorna  padre de un nodo, en caso de tener
int Heap::Padre(int i)const
{
	if (i == 0)
	{
		cout << "Este nodo es la raiz, por lo tanto no tiene padre" << endl;
		return -1;
	}
	else
	{
		return this->AH[(i - 1) / 2];
	}
}
// Funcion que retorna el hijo izquierdo de un nodo,en caso de tener
int Heap::HijoI(int i)const
{
	if (2 * i + 1 >= this->C)
	{
		cout << "no tiene hijo izquierdo" << endl;
		return -1;
	}
	else
	{
		return this->AH[2 * i + 1];
	}
}
// Funcion que retorna el hijo derecho de un nodo, en caso de tener
int Heap::HijoD(int i)const
{
	if (2 * (i + 1) >= this->C)
	{
		cout << "No tiene hijo derecho" << endl;
		return -1;
	}
	else
	{
		return this->AH[2 * (i + 1)];
	}
}
// Retorna el indice del padre
int Heap::Inpadre(int i)const
{
	if (i == 0)
	{
		cout << "Este nodo es la raiz, por lo tanto no tiene padre" << endl;
		return -1;
	}
	else
	{
		return (i - 1) / 2;
	}
}
// Retorna el indice del hijo izquierdo
int Heap::InHijoI(int i)const
{
	if (2 * i + 1 >= this->C)
	{
		cout << "no tiene hijo izquierdo" << endl;
		return -1;
	}
	else
	{
		return 2 * i + 1;
	}
}
// Retorna el indice del hijo derecho
int Heap::InHijoD(int i)const
{
	if (2 * (i + 1) >= this->C)
	{
		cout << "No tiene hijo derecho" << endl;
		return -1;
	}
	else
	{
		return 2 * (i + 1);
	}
}
// Funcion insertar
void Heap::Insertar(const int data)
{
	if (this->C == this->Maxtamano)
	{
		cout << "El arbol ya esta lleno" << endl;
	}
	else
	{
		this->AH[this->C] = data;
		Subir(this->C);
		this->C++;
	}
}
// Intercambia de posiciones 2 nodos
void Heap::Intercambiar(const int i,const int j)
{
	int aux = this->AH[i];
	int aux2 = this->AH[j];
	this->AH[j] = aux;
	this->AH[i] = aux2;
}
// Funcion que se utilizar para subir un nodo desde la raiz
void Heap::Subir(const int i)
{
	if (i == 0) // Seria en el caso en que se intente subir la raiz
	{
		cout << " " << endl;
	}
	else if (this->AH[Inpadre(i)] < this->AH[i])
	{
		Intercambiar(Inpadre(i), i);
		Subir(Inpadre(i));
	}
}
// Funcion que imprime el heap
void Heap::MostrarHeap()
{
	cout << "[ ";
	for (int i = 0; i < this->C; i++)
	{
		cout << this->AH[i] << " ";
	}
	cout << "]";
}
// Eliminiar un nodo del heap , dada una posicion especifica
void Heap::Eliminar(const int i)
{
}
// Funcion que se utiliza para bajar un nodo
void Heap::Bajar(const int i)
{
	int MaxIndex = i;
	if (InHijoI(i) < this->C && this->AH[InHijoI(i)] > this->AH[MaxIndex])
	{
		MaxIndex = InHijoI(i);
	}
	if (InHijoD(i) < this->C && this->AH[InHijoD(i)] > this->AH[MaxIndex])
	{
		MaxIndex = InHijoD(i);
	}
	if (i != MaxIndex)
	{
		Intercambiar(this->AH[i], this->AH[MaxIndex]);
		Bajar(MaxIndex);
	}
}

// Formas de recorrer un heap
// In order
void Heap::InOrder(const int i)
{
	if (i >= this->C)
	{
		cout << "No es posible" << endl;
	}
	else if (i != -1)
	{
		InOrder(InHijoI(i));
		cout << " Nodo = " << this->AH[i] << "  ";
		InOrder(InHijoD(i));
	}
}
// PreOrder
void Heap::PreOrder(const int i)
{
	if (i >= this->C)
	{
		cout << "No es posible" << endl;
	}
	else if (i != -1)
	{
		cout << " Nodo = " << this->AH[i] << "  ";
		PreOrder(InHijoI(i));
		PreOrder(InHijoD(i));
	}
}
// Post Order
void Heap::PostOrder(const int i)
{
	if (i >= this->C)
	{
		cout << "No es posible" << endl;
	}
	else if (i != -1)
	{
		PostOrder(InHijoI(i));
		PostOrder(InHijoD(i));
		cout << " Nodo = " << this->AH[i] << "  ";
	}
}
// BFS
void Heap::BFS()
{
	
}