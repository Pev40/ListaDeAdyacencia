#ifndef __GRAFO_H__
#define __GRAFO_H__
#include "Vertice.h"
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

template<class U>
class Grafo
{
private:
    Vertice<U> *head;
    void insertArista(U V1,U V2);
    void insertVertice(U V1);    
public:
    Grafo();
    void print();
    void insert(U V1,U V2);
    bool search(U);
    Vertice<U> *searchVertice(U);
    string view();
    void grafhic();
    ~Grafo();
};

template<class U>
Grafo<U>::Grafo()
{
    head = nullptr;
}

template<class U>
bool Grafo<U>::search(U Valor){
    Vertice<U>* auxiliar = this->head;
    while (auxiliar!=nullptr)
    {
        //std::cout<<auxiliar->getDato();
        if(auxiliar->getValor()==Valor){
      //      std::cout<<"Existe";
            return true;}
        auxiliar = auxiliar->getNext();
    }
    //std::cout<<"No existe";
    return false;
}

template<class U>
Vertice<U>* Grafo<U>::searchVertice(U Valor){
    Vertice<U>* auxiliar = this->head;
    while (auxiliar!=nullptr)
    {
        //std::cout<<auxiliar->getDato();
        if(auxiliar->getValor()==Valor){
      //      std::cout<<"Existe";
            return auxiliar;}
        auxiliar = auxiliar->getNext();
    }
    //std::cout<<"No existe";
    return nullptr;
}

template<class U>
void Grafo<U>::insertVertice(U NuevaVertice){
    if(this->head==nullptr){
        Vertice<U>* nuevo = new Vertice<U>(NuevaVertice);
        this->head=nuevo;
        return;
    }
    Vertice<U>* auxiliar = head;
    while (true)
    {
        if(auxiliar->getNext() == nullptr){
            Vertice<U>* nuevo = new Vertice<U>(NuevaVertice);
            auxiliar->setNext(nuevo);
            return;
        }
        if(auxiliar->getNext()!=nullptr){
            if(auxiliar->getNext()->getValor()>NuevaVertice){
                Vertice<U>* nuevo = new Vertice<U>(NuevaVertice);
                nuevo->setNext(auxiliar->getNext());
                auxiliar->setNext(nuevo);
                return;
            }
        }
        auxiliar = auxiliar->getNext();
    }
    return;
}

template<class U>
void Grafo<U>::insertArista(U V1,U V2){
    if(head==nullptr){
        std::cout<<"Primer Insertado"<<std::endl;
        Vertice<U>* Nuevo1 = new Vertice<U>(V1);
        Vertice<U>* Nuevo2 = new Vertice<U>(V2);
        head=Nuevo1;
        head->setNext(Nuevo2);
        Nuevo1->add(V2);
        Nuevo2->add(V1);
        return;
    }
    Vertice<U>* auxiliar = head;
    if (search(V1)==true)
    {
        auxiliar = this->searchVertice(V1);
        auxiliar->add(V2);
    }
    else
    {
        this->insertVertice(V1);
        auxiliar = this->searchVertice(V1);
        auxiliar->add(V2);
    }
    if (search(V2)==true )
    {
        auxiliar = this->searchVertice(V2);
        auxiliar->add(V1);
    }

    else
    {
        this->insertVertice(V2);
        auxiliar = this->searchVertice(V2);
        auxiliar->add(V1);
    }   
}

template<class U>
void Grafo<U>::insert(U V1,U V2){
    if(V1>V2){
        int aux=V1;
        V2=V1;
        V1=aux;
    }
    insertArista(V1,V2);
}

template<class U>
void Grafo<U>::print(){
    Vertice<U>* p = head;
    while (p!=nullptr)
    {
        p->print();
        std::cout<<std::endl;
        p=p->getNext();
    }
    
}

template<class U>
string Grafo<U>::view(){
    string salida = "";
    if (head==nullptr)
    {
        return salida;
    }
    Vertice<U>* verticeN = head;
    salida += "graph CS {";
    while (verticeN!=nullptr)
    {
        salida+=verticeN->stringEnd();
        verticeN=verticeN->getNext();
    }
    salida +=" }";
    return salida;
}

template<class U>
void Grafo<U>::grafhic(){
  ofstream file;
  file.open("./salida1.dot");
  string data = this->view();
  file << data;
  file.close();

  system("dot -Tpng salida1.dot -o grafoSalida.png");
  system("grafoSalida.png");
  return;
}

template<class U>
Grafo<U>::~Grafo()
{
}


#endif