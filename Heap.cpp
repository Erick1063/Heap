#include "Heap.hpp"
#include <math.h>
#include <iostream>
#include <queue> //Libreria cola,para el recorrido por anchura
using std::cout;
using std::endl;
using std::queue;
//Constructor de un heap de 0  ; la funcion ceil redondea un numero hacia arriba al siguiente entero
Heap::Heap(int tamano){
	this->Maxtamano=pow(2,ceil(log2(tamano)))-1;
	this->AH=new int[this->Maxtamano];
}
//Constructor de un heap en base a un arreglo
Heap::Heap(int tamano,int Arreglo[]){
	this->Maxtamano=pow(2,ceil(log2(tamano)))-1;
	this->AH=new int(this->Maxtamano);
	for(int i=0 ; i < tamano; i++)
	{
		this->AH[i]=Arreglo[i];
	}
	this->C=tamano;
}
//Funcion que retorna el tamano maximo del arbol 
int Heap::getMaxtamano(){
	return this->Maxtamano;
}
//Funcion que retorna el arbol heap
int *Heap::getAH(){
	return this->AH;
}
//Funcion que retorna  padre de un nodo, en caso de tener
int Heap::Padre(int i){
	if(i==0)
	{
		cout<<"Este nodo es la raiz, por lo tanto no tiene padre"<<endl;
		return -1;
	}
	else
	{
		return this->AH[(i-1)/2];
	}
}
//Funcion que retorna el hijo izquierdo de un nodo,en caso de tener
int Heap::HijoI(int i){
	if(2*i+1>=this->C){
		cout<<"no tiene hijo izquierdo"<<endl;
	}else{
		return this->AH[2*i+1];
	}
}
//Funcion que retorna el hijo derecho de un nodo, en caso de tener
int Heap::HijoD(int i){
	if(2*(i+1)>=this->C)
	{
		cout<<"No tiene hijo derecho"<<endl;
		return -1;
	}
	else
	{
		return this->AH[2*(i+1)];
	}
}
//Retorna el indice del padre
int Heap::Inpadre(int i){
	if(i==0)
	{
		cout<<"Este nodo es la raiz, por lo tanto no tiene padre"<<endl;
		return -1;
	}
	else
	{
		return (i-1)/2;
	}
}
//Retorna el indice del hijo izquierdo
int Heap::InHijoI(int i){
	if(2*i+1>=this->C){
		cout<<"no tiene hijo izquierdo"<<endl;
		return -1;
	}else{
		return 2*i+1;
	}
}
//Retorna el indice del hijo derecho
int Heap::InHijoD(int i){
	if(2*(i+1)>=this->C)
	{
		cout<<"No tiene hijo derecho"<<endl;
		return -1;
	}
	else
	{
		return 2*(i+1);
	}
}
//Funcion insertar
void Heap::Insertar(int data){
	if(this->C == this->Maxtamano)
	{
		cout<<"El arbol ya esta lleno"<<endl;
	}
	else
	{
		this->AH[this->C]=data;
		Subir(this->C);
		this->C++;
	}
}
//Intercambia de posiciones 2 nodos
void Heap::Intercambiar(int i ,int j ){
	int aux=this->AH[i];
	int aux2=this->AH[j];
	this->AH[j]=aux;
	this->AH[i]=aux2;
}
//Funcion que se utilizar para subir un nodo desde la raiz
void Heap::Subir(int i){
	if(i==0)//Seria en el caso en que se intente subir la raiz
	{
		cout<<" "<<endl;
	}
	else if(this->AH[Inpadre(i)]<this->AH[i])
	{
		Intercambiar(Inpadre(i),i);
		Subir(Inpadre(i));
	}
}
//Funcion que imprime el heap
void Heap::MostrarHeap(){
	cout<<"[ ";
	for(int i=0 ; i<this->C ; i++)
	{
		cout<<this->AH[i]<<" ";
	}
	cout<<"]";
}
//Eliminiar un nodo del heap , dada una posicion especifica
void Heap::Eliminar(int i){

	
}
//Funcion que se utiliza para bajar un nodo 
void Heap::Bajar(int i){
	int MaxIndex = i;
	if(InHijoI(i) < this->C && this->AH[InHijoI(i)]>this->AH[MaxIndex]){
		MaxIndex=InHijoI(i);
	}
	if(InHijoD(i) < this->C && this->AH[InHijoD(i)]>this->AH[MaxIndex]){
		MaxIndex=InHijoD(i);
	}
	if( i != MaxIndex){
		Intercambiar(this->AH[i],this->AH[MaxIndex] );
		Bajar(MaxIndex);
	}
}

//Formas de recorrer un heap
//In order
int Heap::InOrder(int i){
	if(i>=this->C){
		return i;
	}
	else
	{
		InOrder(InHijoI(i));
		cout<<" Nodo = "<<this->AH[i]<<"  ";
		InOrder(InHijoD(i));	
	}
	return i;
}
//PreOrder
int Heap::PreOrder(int i){
	if(i >= this->C)
	{
		return i;
	}
	else
	{
		cout<<" Nodo = "<<this->AH[i]<<"  ";
		PreOrder(InHijoI(i));
		PreOrder(InHijoD(i));
	}
	return i;
}
//Post Order
int Heap::PostOrder(int i)
{
	if(i>=this->C)
	{
		return i;
	}
	else
	{
		PostOrder(InHijoI(i));
		PostOrder(InHijoD(i));
		cout<<" Nodo = "<<this->AH[i]<<"  ";		
	}
	return i;
}
//BFS
int Heap::BFS(int i){
	queue<int> Q;
	Q.push(this->AH[0]);
	while(! Q.empty())
	{
		int Indice=Q.front();
		Q.pop();
		if(InHijoI(Indice)!=-1){
			Q.push(InHijoI(Indice));
		}
		if(InHijoD(Indice)!=-1){
			Q.push(InHijoD(Indice));
		}
		cout<<" Nodo = "<<this->AH[Indice]<<"  ";
	}
	return i;
}