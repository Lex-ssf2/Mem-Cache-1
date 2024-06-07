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
void asociativaConjuntos(int cantPalabras,int tamanoBloque,int vias);
void asociativaFull(int tamano);

int main(int argc, const char* argv[])
{
    int a;
    asociativaFull(1);
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
        int etiqueta = entrada >> offsetBit + offsetPalabra;
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

void asociativaConjuntos(int cantPalabras,int tamanoBloque,int vias){
    vector<vector<BloqueCache>> listaCacheVias(cantPalabras * tamanoBloque, vector<BloqueCache>(vias + 1));
    int entrada;
    int offsetPalabra = log2(cantPalabras);
    int offsetBit = log2(tamanoBloque);

    cout << "Asociativa por Conjuntos: \n";
    string BinAdrss,Etiqueta,Indice,HM,Word;
    BinAdrss = "Binary Adress: ";
    Etiqueta = "Etiquetas: ";
    Indice = "Indice: ";
    HM = "Hit/Miss: ";
    Word = "Palabra: ";

    while(cin >> entrada){
        //Calculos
        int etiqueta = entrada >> offsetBit + offsetPalabra;
        int indice =  (entrada >> offsetPalabra) % tamanoBloque;
        int palabra = entrada % cantPalabras;

        BinAdrss += convertBinary(entrada) + ", ";
        Etiqueta += convertBinary(etiqueta) + ", ";
        Indice += convertBinary(indice) + ", ";
        Word += convertBinary(palabra) + ", ";

        bool encontrado = false;
        int contador = listaCacheVias[indice][vias].getCont() + 1;
        listaCacheVias[indice][vias].setCont(contador);
        for (size_t i = 0; i < vias && !encontrado; i++)
        {
            if(listaCacheVias[indice][i].getEtiqueta() == etiqueta){
                encontrado = true;
                listaCacheVias[indice][i].setCont(contador);
                HM += "H, ";
            }
        }

        if(!encontrado){

            int tmpCont = listaCacheVias[indice][0].getCont();
            int tmpIndex = 0;
            for (size_t i = 0; i < vias; i++)
            {
                if(listaCacheVias[indice][i].getCont() < tmpCont){
                    tmpIndex = i;
                    tmpCont = listaCacheVias[indice][i].getCont();
                }
            }
            listaCacheVias[indice][tmpIndex].setEtiqueta(etiqueta);
            listaCacheVias[indice][tmpIndex].setAcierto(false);
            listaCacheVias[indice][tmpIndex].setPalabra(palabra);
            listaCacheVias[indice][tmpIndex].setCont(contador);
            HM += "M, ";    
        }    
    };
    cout << BinAdrss << '\n' << Etiqueta << '\n' << Indice << '\n' << Word << '\n' << HM << endl;
}


void asociativaFull(int tamano){
    vector<BloqueCache> listaCache(tamano, BloqueCache());
    int entrada;
    cout << "Completamente asociativa: \n";
    string BinAdrss,Etiqueta,Indice,HM,Word;
    BinAdrss = "Binary Adress: ";
    Etiqueta = "Etiquetas: ";
    Indice = "Indice: ";
    HM = "Hit/Miss: ";
    Word = "Palabra: ";

    while(cin >> entrada){

        BinAdrss += convertBinary(entrada) + ", ";
        if(listaCache.size() < BinAdrss.size())
        {
            listaCache.resize(BinAdrss.size() + 1);
        }
        if(listaCache[entrada].getEtiqueta() != entrada)
        {
            listaCache[entrada].setEtiqueta(entrada);
            listaCache[entrada].setAcierto(false);
            HM += "M, ";
        }
        else{
            listaCache[entrada].setAcierto(true);
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