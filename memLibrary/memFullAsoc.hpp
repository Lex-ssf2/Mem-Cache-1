#ifndef MEM_FULL_ASOC_H
#define MEM_FULL_ASOC_H

#include "memoria.hpp"
#include <vector>

using namespace std;

class memFullAsoc : public Memoria
{
private:
    vector<BloqueCache> listaCache;
public:
    memFullAsoc(int tam);
    ~memFullAsoc();

    void start();
    void acierto(int index);
    void updateTable(int entrada);
};

memFullAsoc::memFullAsoc(int tam)
{
    this->type = "Completamente Asociativa:";
    init(tam);
    this->offsetBit = 0;
    this->offsetPalabra = 0;
    listaCache.resize(tamanoBloque, BloqueCache());
    start();
}

memFullAsoc::~memFullAsoc()
{
    listaCache.clear();
}

void memFullAsoc::start(){
    
    int entrada;
    while(cin >> entrada){

        if(listaCache.size() < convertBinary(entrada).size())
        {
            listaCache.resize(convertBinary(entrada).size() + 1);
        }
        updateTable(entrada);
        acierto(entrada);
    };
}

void memFullAsoc::acierto(int index){

    if(listaCache[index].getEtiqueta() != index)
    {
        listaCache[index].setEtiqueta(index);
        listaCache[index].setAcierto(false);
        HM += "M, ";
        return;
    }
    listaCache[index].setAcierto(true);
    HM += "H, ";
    
}

void memFullAsoc::updateTable(int entrada){

    string enBin = convertBinary(entrada);
    this->BinAdrss.resize(this->BinAdrss.size() + enBin.size());
    this->Etiqueta.resize(this->Etiqueta.size() + enBin.size());
    this->BinAdrss += enBin + ", ";
    this->Etiqueta += enBin + ", ";
}

#endif