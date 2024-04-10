#include "Publicacion.h"
#include <bits/stdc++.h>
using namespace std;

int Id=0;

Publicacion::Publicacion(Usuario* usuario, string fecha, string contenido):Mensaje(usuario,contenido)
{
    this->fecha=fecha;
    this->id=Id;
    Id++;
}

void Publicacion::mostrarPublicacion()
{
    cout<<this->usuario->nombre<<"               "<<this->fecha<<'\n'<<this->contenido<<'\n'<<'\n';
}

