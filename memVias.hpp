#ifndef MEM_CONJUNTOS_H
#define MEM_CONJUNTOS_H

#include "memoria.hpp"
#include <vector>
#include <iostream>

using namespace std;

class memVias : public Memoria
{
private:
    vector<vector<BloqueCache>> listaCacheVias;
public:
    memVias(int tam, int palabras,int vias = 1);
    ~memVias();

    int getLRUindex(int index);
    void start();
    void acierto(int index, int etiqueta, int palabra);
};

memVias::memVias(int tam, int palabras,int vias)
{
    this->type = "Correspondencia por vias:";
    init(tam,palabras,vias);
    cout << viasMax << "\n";
    listaCacheVias.resize(cantPalabras * tamanoBloque, vector<BloqueCache>(viasMax + 1));
    start();
}

memVias::~memVias()
{
    listaCacheVias.clear();
}

void memVias::start(){
    
    int entrada;
    while(cin >> entrada){

        int etiqueta,indice,palabra;
        spliceData(entrada,etiqueta,indice,palabra);
        updateTable(entrada,etiqueta,indice,palabra);
        acierto(indice,etiqueta,palabra);
    };

}

void memVias::acierto(int index, int etiqueta, int palabra){

    bool encontrado = false;
    int contador = listaCacheVias[index][viasMax].getCont() + 1;
    listaCacheVias[index][viasMax].setCont(contador);

    //Busqueda en las vias
    for (size_t i = 0; i < viasMax && !encontrado; i++)
    {
        if(listaCacheVias[index][i].getEtiqueta() == etiqueta){
            encontrado = true;
            listaCacheVias[index][i].setCont(contador);
            HM += "H, ";
            return;
        }
    }

    int tmpIndex = getLRUindex(index);
    listaCacheVias[index][tmpIndex].setEtiqueta(etiqueta);
    listaCacheVias[index][tmpIndex].setAcierto(false);
    listaCacheVias[index][tmpIndex].setPalabra(palabra);
    listaCacheVias[index][tmpIndex].setCont(contador);
    HM += "M, ";
    
}

int memVias::getLRUindex(int index){

    int tmpCont = listaCacheVias[index][0].getCont();
    int tmpIndex = 0;
    for (size_t i = 0; i < viasMax; i++)
    {
        if(listaCacheVias[index][i].getCont() < tmpCont){
            tmpIndex = i;
            tmpCont = listaCacheVias[index][i].getCont();
        }
    }
    return tmpIndex;
}

#endif