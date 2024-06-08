#include <iostream>

#include "memLibrary/memDirecta.hpp"
#include "memLibrary/memVias.hpp"
#include "memLibrary/memFullAsoc.hpp"
  
using namespace std;

int main(int argc, const char* argv[])
{
    int tipo,tamano,palabras,vias;
    cin >> tipo;
    switch (tipo)
    {
        case 2:{
            cin >> tamano >> palabras >> vias;
            memVias memoria(tamano,palabras,vias);
            memoria.imprimir();
            break;
        }
        case 3:{
            cin >> tamano;
            memFullAsoc memoriaA(tamano);
            memoriaA.imprimir();
            break;
        }
        default:{
            cin >> tamano >> palabras;
            memDirecta memoria(tamano,palabras);
            memoria.imprimir();
            break;
        }
    }
    return 0;
}