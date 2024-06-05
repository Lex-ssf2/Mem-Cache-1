#ifndef CACHE_H
#define CACHE_H

using namespace std;

class CampoCache{

    private:
        bool validez = false;
        int indice;
        int etiqueta;
        int palabra;

    public:

        void setValidez(bool valor){
            validez = valor;
            return;
        }

        void setIndex(int valor)
        {
            indice = valor;
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

        bool getValidez(){
            return validez;
        }

        int getIndex(){
            return indice;
        }

        int getEtiqueta(){
            return etiqueta;
        }

        int getPalabra(){
            return palabra;
        }

};

#endif