#include "Mensaje.h"
#include <bits/stdc++.h>
using namespace std;

Mensaje::Mensaje(Usuario* usuario, string contenido)
{
    this->usuario=usuario;
    this->contenido=contenido;
}

void Mensaje::mostrar()
{
    cout<<this->usuario->nombre<<'\n'<<this->contenido<<'\n'<<'\n';
}



