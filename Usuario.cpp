#include "Usuario.h"
#include "Publicacion.h"
#include "Mensaje.h"
#include "RedSocial.h"
#include <bits/stdc++.h>
using namespace std;

int ID=0;

Usuario::Usuario(string nom)
{
    this->nombre=nom;
    this->edad=-1;
    this->nacionalidad="";
    this->amigos={};
    this->publicaciones={};
    this->id=ID;
    ID++;
}

Usuario::Usuario(string nom, int ed)
{
    this->nombre=nom;
    this->edad=ed;
    this->nacionalidad="";
    this->amigos={};
    this->publicaciones={};
    this->id=ID;
    ID++;
}

Usuario::Usuario(string nom, int ed, string nacion)
{
    this->nombre=nom;
    this->edad=ed;
    this->nacionalidad=nacion;
    this->amigos={};
    this->publicaciones={};
    this->id=ID;
    ID++;
}

int Usuario::getId()
{
    return id;
}

Usuario* Usuario::getAmigo(int id)
{
    for(int i=0; i<this->amigos.size(); i++)
    {
        if(this->amigos[i]->getId()==id) return this->amigos[i];
    }
    cout<<"No existe un amigo con ID="<<id<<" :(\n";
    return nullptr;
}

void Usuario::mostrar()
{
    cout<<"ID: "<<this->id<<" Nombre: "<<this->nombre<<" Edad: "<<this->edad<<" Nacionalidad: "<<this->nacionalidad<<'\n';
}

void Usuario::mostrarAmigos()
{
    for(int i=0; i<this->amigos.size(); i++) this->amigos[i]->mostrar();
}

void Usuario::mostrarEnemigos()
{
    for(int i=0; i<this->enemigos.size(); i++) this->enemigos[i]->mostrar();
}

void Usuario::mostrarPublicaciones()
{
    for(int i=0; i<this->publicaciones.size(); i++) this->publicaciones[i]->mostrarPublicacion();
}

void Usuario::crearPublicacion(RedSocial* Red)
{
    string fecha, contenido;
    cout<<"Ingrese la fecha: ";
    cin>>fecha;
    cout<<"Escriba el contenido a continuacion:\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,contenido);
    Publicacion* pointer=new Publicacion(this,fecha,contenido);
    this->publicaciones.push_back(pointer);
    Red->agregarPublicacion(pointer);
}

void Usuario::agregarAmigo(Usuario* nuevoAmigo)
{
    if(nuevoAmigo)
    {
        if(this->esAmigo(nuevoAmigo)) cout<<nuevoAmigo->nombre<<" ya es tu amigo\n";
        else
        {
            this->amigos.push_back(nuevoAmigo);
            nuevoAmigo->amigos.push_back(this);
            cout<<"Ahora tu y "<<nuevoAmigo->nombre<<" son amigos :D\n";
        }
    }
}

void Usuario::agregarEnemigo(Usuario* nuevoEnemigo)
{
    if(nuevoEnemigo)
    {
        if(this->esEnemigo(nuevoEnemigo)) cout<<nuevoEnemigo->nombre<<" ya es tu enemigo\n";
        else
        {
            this->enemigos.push_back(nuevoEnemigo);
            cout<<"Ahora eres enemigo de "<<nuevoEnemigo->nombre<<" :D\n";
        }
    }
}

bool Usuario::esAmigo(Usuario* usuario)
{
    for(int i=0; i<this->amigos.size(); i++)
    {
        if(this->amigos[i]==usuario) return 1;
    }
    return 0;
}

bool Usuario::esEnemigo(Usuario* usuario)
{
    for(int i=0; i<this->enemigos.size(); i++)
    {
        if(this->enemigos[i]==usuario) return 1;
    }
    return 0;
}
