#ifndef __VERTICE_H__
#define __VERTICE_H__
#include "ListaAristas.h"
#include <sstream>


class Vertice
{
private:
    int valor;
    int dimension;
    ListaAristas *head;
    Vertice *next;
public:
    Vertice(int);
    ListaAristas* getLista();
    Vertice* getNext();
    int getValor();
    void setNext(Vertice*);
    string stringEnd();
    ~Vertice();
    void cout();
    void print();
    void add(int);
    void deleteA(int);
};

Vertice::Vertice(int NuevoV)
{
    this->dimension=0;
    this->valor=NuevoV;
    this->head=new ListaAristas();
    this->next=nullptr;
}

void Vertice::add(int ValorA){   
    if(this->head->search(ValorA)==true || ValorA==this->getValor()){return;}
    this->head->add(ValorA); this->dimension+=1;  
    return;}

void Vertice::deleteA(int ValorA){
    if(this->head->search(ValorA)==true){
        this->head->deleteA(ValorA); this->dimension-=1; 
    }
    return;}

void Vertice::cout(){std::cout<<"Dimension: "<<this->dimension;}

void Vertice::print(){std::cout<<this->valor<<": ";  this->head->print(); return;}

void Vertice::setNext(Vertice* nuevo){this->next=nuevo;return;}

int Vertice::getValor(){return this->valor;}

string Vertice::stringEnd(){
    if(head==nullptr){return "";}
    string cadenaValores = head->values();
    int i =0;
    string valorString (std::to_string(this->getValor()));
    string salida="";
    while (cadenaValores[i]!='$')
    {
        if(cadenaValores[i]!='-'){
            string valueString(1,cadenaValores[i]);
            stringstream intValue(valueString);
            int intValues = 0;
            intValue >> intValues;
            if ( intValues > this->getValor()) 
            {
                salida+= valorString+" -- "+cadenaValores[i]+";\n";
            } 
        }
        i++;
    }
    return salida;
}

ListaAristas* Vertice::getLista(){return this->head;}

Vertice* Vertice::getNext(){return this->next;}

Vertice::~Vertice()
{
}

#endif