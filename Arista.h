#ifndef __ARISTA_H__
#define __ARISTA_H__

class Arista
{
private:
    int Dato;
    Arista* next=nullptr;
public:
    Arista(int);
    ~Arista();
    int getDato();
    void setDato(int);
    void eliminar();
    Arista* getNext();
    void setNext(Arista*);
};

Arista::Arista(int DatoNuevo)
{
    this->Dato=DatoNuevo;
}
void Arista::setDato(int DatoNuevo){this->Dato=DatoNuevo;  return;}

void Arista::setNext(Arista* NuevoArista){this->next=NuevoArista;  return;}

int Arista::getDato(){return this->Dato;}

void Arista::eliminar(){this->next=nullptr;return;}

Arista* Arista::getNext(){return this->next;}

Arista::~Arista()
{}

#endif