#include <iostream>

#include "memLibrary/memDirecta.hpp"
#include "memLibrary/memVias.hpp"
#include "memLibrary/memFullAsoc.hpp"
  
using namespace std;

int main(int argc, const char* argv[])
{
    memFullAsoc memoria(1);
    memoria.imprimir();
    return 0;
}