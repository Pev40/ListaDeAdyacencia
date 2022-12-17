#ifndef __LISTAARISTAS_H__
#define __LISTAARISTAS_H__
#include "Arista.h"
#include <iostream>
using namespace std;
template<class R>
class ListaAristas
{
private:
    Arista<R>* head;
public:
    ListaAristas();
    void add(R);
    void deleteA(R);
    bool search(R);
    void print();
    string values();
    ~ListaAristas();
};

template<class R>
ListaAristas<R>::ListaAristas()
{
    this->head=nullptr;
}

template<class R>
void ListaAristas<R>::add(R NuevaArista){
    if(this->head==nullptr){
        Arista<R>* nuevo = new Arista<R>(NuevaArista);
        this->head=nuevo;
        return;
    }
    Arista<R>* auxiliar = head;
    while (true)
    {
        if(auxiliar->getNext() == nullptr){
            Arista<R>* nuevo = new Arista<R>(NuevaArista);
            auxiliar->setNext(nuevo);
            return;
        }
        if(auxiliar->getNext()!=nullptr){
            if(auxiliar->getNext()->getDato()==NuevaArista){return;}
            if(auxiliar->getNext()->getDato()>NuevaArista){
                Arista<R>* nuevo = new Arista<R>(NuevaArista);
                nuevo->setNext(auxiliar->getNext());
                auxiliar->setNext(nuevo);
                return;
            }
        }
        auxiliar = auxiliar->getNext();
    }
    return;
}

template<class R>
bool ListaAristas<R>::search(R BuscarArista){
    Arista<R>* auxiliar = head;
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

template<class R>
void ListaAristas<R>::deleteA(R AristaEliminar){
    if(head==nullptr){ return;}
    if(head->getDato()==AristaEliminar){
        Arista<R>* auxiliarelim = head;
        head=head->getNext();
        auxiliarelim->eliminar();
        delete[] auxiliarelim;
        return;
    }   
    Arista<R>* auxiliar = head;
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
        Arista<R>* auxiliarelim = auxiliar->getNext();
        auxiliar->eliminar();
        auxiliarelim->eliminar();
        delete[] auxiliarelim;
        return;
    }
    Arista<R>* auxiliarelim = auxiliar->getNext();
    auxiliar->setNext(auxiliar->getNext()->getNext());
    auxiliarelim->eliminar();
    delete[] auxiliarelim;
    return;
}
return;
}

template<class R>
void ListaAristas<R>::print(){
   // std::cout<<"Aqui en imprimir";
    if (head==nullptr){std::cout<<"No existen Aristas"; return; }
    Arista<R>* auxiliar = head;    
    while (auxiliar!=nullptr)
    {
        std::cout<<auxiliar->getDato()<<" -> ";
        auxiliar=auxiliar->getNext();
    }
    
}
template<class R>
string ListaAristas<R>::values(){
    string salida = "";
    if (head==nullptr){std::cout<<"No existen Aristas"; return salida; }
    Arista<R>* auxiliar = head;    
    while (auxiliar!=nullptr)
    {
        string num_cstr(std::to_string(auxiliar->getDato()));
        salida +=num_cstr+"-";
        auxiliar=auxiliar->getNext();
    }
    salida +="$";
     return salida;
}

template<class R>
ListaAristas<R>::~ListaAristas()
{
}



#endif