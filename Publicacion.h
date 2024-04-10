#ifndef Publicacion_h
#define Publicacion_h
#include "Mensaje.h"
#include <string>
using namespace std;

class Publicacion: public Mensaje
{
private:
    int id;
public:
    string fecha;
    Publicacion(Usuario* usuario, string fecha, string contenido);
    void mostrarPublicacion();
};

#endif
