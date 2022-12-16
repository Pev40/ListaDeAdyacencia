#include <iostream>
using namespace std;

void imprimirGrafo(){
    system("dot -Tpng salida.dot -o grafoSalida.png");
    system("grafoSalida.png");
    return;
}

int main(){

    imprimirGrafo();

    return 0;
}