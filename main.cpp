#include <iostream>
#include <cmath>
#include <vector> 
#include "cache.hpp"
#include <bitset>
#include <string>
  
using namespace std;

string convertBinary(unsigned int num);
void printCDirecta();
void correspondenciaDirecta(int cantPalabras,int tamanoBloque);

int main(int argc, const char* argv[])
{
    int a;
    correspondenciaDirecta(4,2);
    cout << "sonic";
    return 0;
}

void correspondenciaDirecta(int cantPalabras,int tamanoBloque){
    vector<BloqueCache> listaCache(cantPalabras * tamanoBloque, BloqueCache());
    int entrada;
    int offsetPalabra = log2(cantPalabras);
    int offsetBit = log2(tamanoBloque);

    cout << "Correspondencia Directa: \n";
    string BinAdrss,Etiqueta,Indice,HM,Word;
    BinAdrss = "Binary Adress: ";
    Etiqueta = "Etiquetas: ";
    Indice = "Indice: ";
    HM = "Hit/Miss: ";
    Word = "Palabra: ";

    while(cin >> entrada){
        //Calculos
        int etiqueta = entrada >> offsetBit;
        int indice =  (entrada >> offsetPalabra) % tamanoBloque;
        int palabra = entrada % cantPalabras;

        BinAdrss += convertBinary(entrada) + ", ";
        Etiqueta += convertBinary(etiqueta) + ", ";
        Indice += convertBinary(indice) + ", ";
        Word += convertBinary(palabra) + ", ";

        if(listaCache[indice].getEtiqueta() != etiqueta)
        {
            listaCache[indice].setEtiqueta(etiqueta);
            listaCache[indice].setPalabra(palabra);
            listaCache[indice].setAcierto(false);
            HM += "M, ";
        }
        else{
            listaCache[indice].setAcierto(true);
            listaCache[indice].setPalabra(palabra);
            HM += "H, ";
        }
    };
    cout << BinAdrss << '\n' << Etiqueta << '\n' << Indice << '\n' << Word << '\n' << HM << endl;
}

string convertBinary(unsigned int num) {
    string binary;
    while (num > 0) {
        int bit = num & 1; // Extrae el bit más a la derecha
        binary = (bit == 0 ? '0' : '1') + binary; // Agrega '0' o '1' según el bit
        num >>= 1; // Desplaza el valor decimal un bit hacia la derecha
    }
    binary = binary.size() <= 0 ? "0" : binary;
    return binary;
}