#ifndef CACHE_H
#define CACHE_H

#include <vector>
using namespace std;

class BloqueCache{

    private:
        bool acierto = false;
        int etiqueta = -1;
        int palabra;
        int cacheCont = -1;

    public:

        void setAcierto(bool valor){
            acierto = valor;
            return;
        }

        void setEtiqueta(int valor){
            etiqueta = valor;
            return;
        }

        void setPalabra(int valor){
            palabra = valor;
            return;
        }

        void setCont(int valor){
            cacheCont = valor;
            return;
        }

        bool getAcierto(){
            return acierto;
        }

        int getEtiqueta(){
            return etiqueta;
        }

        int getPalabra(){
            return palabra;
        }

        int getCont(){
            return cacheCont;
        }

};
#endif