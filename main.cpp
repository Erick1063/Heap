#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include "Heap.hpp"

int main()
{
	Heap H(9); // Creando un heap de tamano 9
	cout << "Tamano maximo: " << H.getMaxtamano() << endl;
	int A[9] = {50, 30, 20, 10, 15, 5, 6, 8, 7};
	Heap H2(9, A);
	cout << "Mostrando el heap en forma de arreglo" << endl;
	H2.MostrarHeap();
	cout << endl;
	cout << "Mostrando H I" << endl;
	cout << "NODO: " << H2.getAH()[1] << endl;
	cout << H2.HijoI(1);
	cout << endl;
	cout << "Mostrando H D" << endl;
	cout << H2.HijoD(1);
	cout << "Agregando nodo al final" << endl;
	H2.Insertar(35);
	cout << "Mostrando despues de insertar" << endl;
	H2.MostrarHeap();
	cout << endl;
	int A3[7] = {50, 35, 20, 10, 30, 5, 6};
	Heap H3(7, A3);
	cout << "Prueba de Recorrido en un heap" << endl;
	cout << "Arbol heap de prueba" << endl;
	H3.MostrarHeap();
	cout << endl;
	cout << "In order" << endl;
	H3.InOrder(0);
	cout << endl;
	cout << "PreOrder" << endl;
	H3.PreOrder(0);
	cout << endl;
	cout << "PostOrder" << endl;
	H3.PostOrder(0);
	cout << endl;
	cout << "BFS" << endl;
	H3.BFS();
	cout<<"Sale del bfs"<<endl;

	return 0;
}