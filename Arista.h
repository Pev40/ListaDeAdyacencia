#ifndef __ARISTA_H__
#define __ARISTA_H__

template<class T>
class Arista
{
private:
    T Dato;
    Arista<T>* next=nullptr;
public:
    Arista(T);
    ~Arista();
    int getDato();
    void setDato(T);
    void eliminar();
    Arista<T>* getNext();
    void setNext(Arista<T>*);
};

template<class T>
Arista<T>::Arista(T DatoNuevo)
{
    this->Dato=DatoNuevo;
}
template<class T>
void Arista<T>::setDato(T DatoNuevo){this->Dato=DatoNuevo;  return;}

template<class T>
void Arista<T>::setNext(Arista<T>* NuevoArista){this->next=NuevoArista;  return;}

template<class T>
int Arista<T>::getDato(){return this->Dato;}

template<class T>
void Arista<T>::eliminar(){this->next=nullptr;return;}

template<class T>
Arista<T>* Arista<T>::getNext(){return this->next;}

template<class T>
Arista<T>::~Arista()
{}

#endif