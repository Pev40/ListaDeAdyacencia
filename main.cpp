#include <iostream>
#include "ListaAristas.h"
#include "Vertice.h"
#include "Grafo.h"
using namespace std;

int main(){
    Vertice<float> p = Vertice<float>(3);    
   // ListaAristas p = ListaAristas();
    p.add(1);
    p.add(10);
    p.add(2);
    p.add(12);
    p.add(6);
    p.add(13);
    p.add(135);
    p.add(100);
    p.add(18);
    p.add(18);
    p.add(18);
    p.print();
  //  cout<<p.values()<<endl;
    cout<<endl;
    p.deleteA(18);
    p.deleteA(135);
    p.deleteA(18);
    p.deleteA(1);
    cout<<endl;
    p.print();
    p.cout();    
  /*  Grafo p = Grafo();
    p.insert(1,2);
    cout<<"---------------"<<endl;
    p.insert(2,3);
    cout<<"---------------"<<endl;
    p.insert(2,5);
    cout<<"---------------"<<endl;
    p.insert(1,6);
    p.insert(6,9);
    p.insert(5,9);
    
    cout<<"---------------"<<endl;
    p.print();
    cout<< p.view();
    p.grafhic();
   */ return 0;
}