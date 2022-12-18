#ifndef __VERTICE_H__
#define __VERTICE_H__
#include "ListaAristas.h"
#include <sstream>

template<class S>
class Vertice
{
private:
    S valor;
    int dimension;
    ListaAristas<S> *head;
    Vertice<S>*next;
public:
    Vertice(S);
    ListaAristas<S>* getLista();
    Vertice<S>* getNext();
    int getValor();
    void setNext(Vertice<S>*);
    string stringEnd();
    ~Vertice();
    void cout();
    void print();
    void add(S);
    void deleteA(S);
};

template<class S>
Vertice<S>::Vertice(S NuevoV)
{
    this->dimension=0;
    this->valor=NuevoV;
    this->head=new ListaAristas<S>();
    this->next=nullptr;
}

template<class S>
void Vertice<S>::add(S ValorA){   
    if(this->head->search(ValorA)==true || ValorA==this->getValor()){return;}
    this->head->add(ValorA); this->dimension+=1;  
    return;}

template<class S>
void Vertice<S>::deleteA(S ValorA){
    if(this->head->search(ValorA)==true){
        this->head->deleteA(ValorA); this->dimension-=1; 
    }
    return;}

template<class S>
void Vertice<S>::cout(){std::cout<<"Dimension: "<<this->dimension;}

template<class S>
void Vertice<S>::print(){std::cout<<S(this->valor)<<": ";  this->head->print(); return;}

template<class S>
void Vertice<S>::setNext(Vertice<S>* nuevo){this->next=nuevo;return;}

template<class S>
int Vertice<S>::getValor(){return this->valor;}

template<class S>
string Vertice<S>::stringEnd(){
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

template<class S>
ListaAristas<S>* Vertice<S>::getLista(){return this->head;}

template<class S>
Vertice<S>* Vertice<S>::getNext(){return this->next;}

template<class S>
Vertice<S>::~Vertice()
{
}

#endif