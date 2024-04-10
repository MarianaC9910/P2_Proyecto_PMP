#include "RedSocial.h"
#include "rlutil.h"
#include <bits/stdc++.h>
using namespace rlutil;
using namespace std;

RedSocial::RedSocial(string nombre)
{
    this->nombre=nombre;
    this->usuarios={};
    this->numeroDeUsuarios=0;
    this->publicaciones={};
    this->numeroDePublicaciones=0;
}

RedSocial::RedSocial(string nombre, vector<Usuario*> usuarios)
{
    this->nombre=nombre;
    this->usuarios=usuarios;
    this->numeroDeUsuarios=usuarios.size();
    this->publicaciones={};
    this->numeroDePublicaciones=0;
}

RedSocial::RedSocial(string nombre, vector<Usuario*> usuarios, vector<Publicacion*> publicaciones)
{
    this->nombre=nombre;
    this->usuarios=usuarios;
    this->numeroDeUsuarios=usuarios.size();
    this->publicaciones=publicaciones;
    this->numeroDePublicaciones=publicaciones.size();
}

/*void RedSocial::eliminarUsuario(Usuario* )
{
    this->publicaciones.push_back(nuevaPublicacion);
}*/

void RedSocial::crearUsuario()
{
    int opc=0, tecla, edad;
    string nombre, nacionalidad;
    imprimirOpciones(opc);
    while(1)
    {
        if(kbhit)
        {
            tecla=getkey();
            if(tecla==14) //arriba
            {
                opc--;
                if(opc<0) opc=2;
                imprimirOpciones(opc);
            }
            else if(tecla==15) //abajo
            {
                opc++;
                if(opc>2) opc=0;
                imprimirOpciones(opc);
            }
            else if(tecla==1) break; //enter
        }
    }
    cout<<"Insertar nombre: ";
    cin>>nombre;
    switch(opc)
    {
        case 0:
        {
            Usuario* pointer=new Usuario(nombre);
            agregarUsuario(pointer);
            break;
        }
        case 1:
        {
            cout<<"Insertar edad: ";
            cin>>edad;
            Usuario* pointer=new Usuario(nombre,edad);
            agregarUsuario(pointer);
            break;
        }
        case 2:
        {
            cout<<"Insertar edad: ";
            cin>>edad;
            cout<<"Insertar nacionalidad: ";
            cin>>nacionalidad;
            Usuario* pointer=new Usuario(nombre,edad,nacionalidad);
            agregarUsuario(pointer);
            break;
        }
    }
    cout<<"El usuario "<<nombre<<" ha sido creado exitosamente\n";
}

void RedSocial::agregarUsuario(Usuario* nuevoUsuario)
{
    this->usuarios.push_back(nuevoUsuario);
}

void RedSocial::agregarPublicacion(Publicacion* nuevaPublicacion)
{
    this->publicaciones.push_back(nuevaPublicacion);
}

void RedSocial::mostrarUsuarios()
{
    for(int i=0; i<this->usuarios.size(); i++) this->usuarios[i]->mostrar();
}

void RedSocial::mostrarPublicaciones()
{
    for(int i=0; i<this->publicaciones.size(); i++) this->publicaciones[i]->mostrarPublicacion();
}

Usuario* RedSocial::getUsuario(int id)
{
    for(int i=0; i<this->usuarios.size(); i++)
    {
        if(this->usuarios[i]->getId()==id) return this->usuarios[i];
    }
    cout<<"No existe un usuario con ID="<<id<<" :(\n";
    return nullptr;
}

void imprimirOpciones(int opc)
{
    system("cls");
    hidecursor();
    cout<<"Con que informacion creara al usuario:\n";
        if(opc==0) cout<<'>';
        cout<<"Nombre\n";
        if(opc==1) cout<<'>';
        cout<<"Nombre y edad\n";
        if(opc==2) cout<<'>';
        cout<<"Nombre, edad y nacionalidad\n";
}
