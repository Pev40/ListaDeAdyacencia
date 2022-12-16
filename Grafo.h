#ifndef __GRAFO_H__
#define __GRAFO_H__
#include "Vertice.h"
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Grafo
{
private:
    Vertice *head;
    void insertArista(int V1,int V2);
    void insertVertice(int V1);    
public:
    Grafo();
    void print();
    void insert(int V1,int V2);
    bool search(int);
    Vertice *searchVertice(int);
    string view();
    void grafhic();
    ~Grafo();
};

Grafo::Grafo()
{
    head = nullptr;
}

bool Grafo::search(int Valor){
    Vertice* auxiliar = this->head;
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


Vertice* Grafo::searchVertice(int Valor){
    Vertice* auxiliar = this->head;
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


void Grafo::insertVertice(int NuevaVertice){
    if(this->head==nullptr){
        Vertice* nuevo = new Vertice(NuevaVertice);
        this->head=nuevo;
        return;
    }
    Vertice* auxiliar = head;
    while (true)
    {
        if(auxiliar->getNext() == nullptr){
            Vertice* nuevo = new Vertice(NuevaVertice);
            auxiliar->setNext(nuevo);
            return;
        }
        if(auxiliar->getNext()!=nullptr){
            if(auxiliar->getNext()->getValor()>NuevaVertice){
                Vertice* nuevo = new Vertice(NuevaVertice);
                nuevo->setNext(auxiliar->getNext());
                auxiliar->setNext(nuevo);
                return;
            }
        }
        auxiliar = auxiliar->getNext();
    }
    return;
}


void Grafo::insertArista(int V1,int V2){
    if(head==nullptr){
        std::cout<<"Primer Insertado"<<std::endl;
        Vertice* Nuevo1 = new Vertice(V1);
        Vertice* Nuevo2 = new Vertice(V2);
        head=Nuevo1;
        head->setNext(Nuevo2);
        Nuevo1->add(V2);
        Nuevo2->add(V1);
        return;
    }
    Vertice* auxiliar = head;
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

void Grafo::insert(int V1,int V2){
    if(V1>V2){
        int aux=V1;
        V2=V1;
        V1=aux;
    }
    insertArista(V1,V2);
}

void Grafo::print(){
    Vertice* p = head;
    while (p!=nullptr)
    {
        p->print();
        std::cout<<std::endl;
        p=p->getNext();
    }
    
}

string Grafo::view(){
    string salida = "";
    if (head==nullptr)
    {
        return salida;
    }
    Vertice* verticeN = head;
    salida += "graph CS {";
    while (verticeN!=nullptr)
    {
        salida+=verticeN->stringEnd();
        verticeN=verticeN->getNext();
    }
    salida +=" }";
    return salida;
}

void Grafo::grafhic(){
  ofstream file;
  file.open("./salida1.dot");
  string data = this->view();
  file << data;
  file.close();

  system("dot -Tpng salida1.dot -o grafoSalida.png");
  system("grafoSalida.png");
  return;
}

Grafo::~Grafo()
{
}


#endif