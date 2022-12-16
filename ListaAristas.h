#ifndef __LISTAARISTAS_H__
#define __LISTAARISTAS_H__
#include "Arista.h"
#include <iostream>
using namespace std;
class ListaAristas
{
private:
    Arista* head;
public:
    ListaAristas();
    void add(int);
    void deleteA(int);
    bool search(int);
    void print();
    string values();
    ~ListaAristas();
};

ListaAristas::ListaAristas()
{
    this->head=nullptr;
}

void ListaAristas::add(int NuevaArista){
    if(this->head==nullptr){
        Arista* nuevo = new Arista(NuevaArista);
        this->head=nuevo;
        return;
    }
    Arista* auxiliar = head;
    while (true)
    {
        if(auxiliar->getNext() == nullptr){
            Arista* nuevo = new Arista(NuevaArista);
            auxiliar->setNext(nuevo);
            return;
        }
        if(auxiliar->getNext()!=nullptr){
            if(auxiliar->getNext()->getDato()==NuevaArista){return;}
            if(auxiliar->getNext()->getDato()>NuevaArista){
                Arista* nuevo = new Arista(NuevaArista);
                nuevo->setNext(auxiliar->getNext());
                auxiliar->setNext(nuevo);
                return;
            }
        }
        auxiliar = auxiliar->getNext();
    }
    return;
}

bool ListaAristas::search(int BuscarArista){
    Arista* auxiliar = head;
    while (auxiliar!=nullptr)
    {
        //std::cout<<auxiliar->getDato();
        if(auxiliar->getDato()==BuscarArista){
      //      std::cout<<"Existe";
            return true;}
        auxiliar = auxiliar->getNext();
    }
    //std::cout<<"No existe";
    return false;
}

void ListaAristas::deleteA(int AristaEliminar){
    if(head==nullptr){ return;}
    if(head->getDato()==AristaEliminar){
        Arista* auxiliarelim = head;
        head=head->getNext();
        auxiliarelim->eliminar();
        delete[] auxiliarelim;
        return;
    }   
    Arista* auxiliar = head;
    if (search(AristaEliminar)==true)
{
    while (auxiliar!=nullptr )
    {
        if(auxiliar->getNext()->getDato()==AristaEliminar){
            break;
        }
        if(auxiliar->getNext()==nullptr){return;}
        auxiliar = auxiliar->getNext();
    }

    if(auxiliar->getNext()->getNext()==nullptr){
        Arista* auxiliarelim = auxiliar->getNext();
        auxiliar->eliminar();
        auxiliarelim->eliminar();
        delete[] auxiliarelim;
        return;
    }
    Arista* auxiliarelim = auxiliar->getNext();
    auxiliar->setNext(auxiliar->getNext()->getNext());
    auxiliarelim->eliminar();
    delete[] auxiliarelim;
    return;
}
return;
}

void ListaAristas::print(){
   // std::cout<<"Aqui en imprimir";
    if (head==nullptr){std::cout<<"No existen Aristas"; return; }
    Arista* auxiliar = head;    
    while (auxiliar!=nullptr)
    {
        std::cout<<auxiliar->getDato()<<" -> ";
        auxiliar=auxiliar->getNext();
    }
    
}
string ListaAristas::values(){
    string salida = "";
    if (head==nullptr){std::cout<<"No existen Aristas"; return salida; }
    Arista* auxiliar = head;    
    while (auxiliar!=nullptr)
    {
        string num_cstr(std::to_string(auxiliar->getDato()));
        salida +=num_cstr+"-";
        auxiliar=auxiliar->getNext();
    }
    salida +="$";
     return salida;
}

ListaAristas::~ListaAristas()
{
}



#endif