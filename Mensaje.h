#ifndef Mensaje_h
#define Mensaje_h
#include "Usuario.h"
using namespace std;

class Mensaje
{
public:
    Usuario* usuario;
    string contenido;
    Mensaje(Usuario* usuario, string contenido);
    void mostrar();
};

#endif

