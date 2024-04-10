#include "RedSocial.h"
#include "rlutil.h"
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace rlutil;
using namespace std;

RedSocial Red("NoNAME");

void imprimirPrincipal(int &opc);
void perfilUsuario(Usuario* usuario);
void imprimirPerfil(int &opc, Usuario* usuario);
void perfilAmigo(Usuario* amigo);
void imprimirAmigo(int &opc, Usuario* amigo);

int main()
{
    Usuario* p1=new Usuario("Pancracio",24,"Chilena");
    Usuario* p2=new Usuario("Mana",102,"Egipcia");
    Usuario* p3=new Usuario("Homero",42,"India");
    Usuario* p4=new Usuario("Barbara",15,"Turca");
    Red.agregarUsuario(p1);
    Red.agregarUsuario(p2);
    Red.agregarUsuario(p3);
    Red.agregarUsuario(p4);
    int opc=0, tecla;
    MenuPrincipal:
    imprimirPrincipal(opc);
    while(1)
    {
        if(kbhit)
        {
            tecla=getkey();
            if(tecla==14) //arriba
            {
                opc--;
                if(opc<0) opc=4;
                imprimirPrincipal(opc);
            }
            else if(tecla==15) //abajo
            {
                opc++;
                if(opc>4) opc=0;
                imprimirPrincipal(opc);
            }
            else if(tecla==1) //enter
            {
                system("cls");
                switch(opc)
                {
                case 0:
                    Red.mostrarUsuarios();
                    break;
                case 1:
                    Red.mostrarPublicaciones();
                    break;
                case 2:
                    int id;
                    cout<<"Introduzca la ID del usuario: ";
                    cin>>id;
                    if(Red.getUsuario(id))
                    {
                        perfilUsuario(Red.getUsuario(id));
                        goto MenuPrincipal;
                    }
                    break;
                case 3:
                    Red.crearUsuario();
                    break;
                case 4:
                    exit(0);
                }
                cout<<"Presione cualquier tecla para regresar";
                anykey();
                imprimirPrincipal(opc);
            }
        }
    }
}

void imprimirPrincipal(int &opc)
{
    system("cls");
    hidecursor();
        cout<<"Gracias por entrar a "<<Red.nombre<<" :D\n";
        if(opc==0) cout<<'>';
        cout<<"Ver usuarios\n";
        if(opc==1) cout<<'>';
        cout<<"Ver publicaciones\n";
        if(opc==2) cout<<'>';
        cout<<"Entrar al perfil de un usuario\n";
        if(opc==3) cout<<'>';
        cout<<"Agregar usuario\n";
        if(opc==4) cout<<'>';
        cout<<"Salir\n";
}

void perfilUsuario(Usuario* usuario)
{
    int opc=0, tecla, id;
    Menu:
    imprimirPerfil(opc,usuario);
    while(1)
    {
        if(kbhit)
        {
            tecla=getkey();
            if(tecla==14) //arriba
            {
                opc--;
                if(opc<0) opc=11;
                imprimirPerfil(opc,usuario);
            }
            else if(tecla==15) //abajo
            {
                opc++;
                if(opc>11) opc=0;
                imprimirPerfil(opc,usuario);
            }
            else if(tecla==1) //enter
            {
                system("cls");
                hidecursor();
                switch(opc)
                {
                case 0:
                    usuario->mostrarAmigos();
                    break;
                case 1:
                    usuario->mostrarEnemigos();
                    break;
                case 2:
                    usuario->mostrarPublicaciones();
                    break;
                case 3:
                    usuario->crearPublicacion(&Red);
                    break;
                case 4:
                    {
                        string contenido;
                        cout<<"Ingrese la ID del destinatario: ";
                        cin>>id;
                        if(Red.getUsuario(id))
                        {
                            cout<<"Escriba el contenido a continuacion:\n";
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            getline(cin,contenido);
                            Mensaje* pointer=new Mensaje(usuario,contenido);
                            Red.getUsuario(id)->mensajes.push_back(pointer);
                        }
                    break;
                    }
                case 5:
                    cout<<"Introduzca la ID de su amigo: ";
                    cin>>id;
                    if(usuario->getAmigo(id))
                    {
                        perfilAmigo(usuario->getAmigo(id));
                        goto Menu;
                    }
                    break;
                case 6:
                    {
                        for(int i=0; i<usuario->mensajes.size(); i++) usuario->mensajes[i]->mostrar();
                        break;
                    }
                case 7:
                    Red.mostrarUsuarios();
                    cout<<"Introduzca la ID de su futuro amigo: ";
                    cin>>id;
                    usuario->agregarAmigo(Red.getUsuario(id));
                    break;
                case 8:
                    Red.mostrarUsuarios();
                    cout<<"Introduzca la ID de quien sera enemigo: ";
                    cin>>id;
                    usuario->agregarEnemigo(Red.getUsuario(id));
                    break;
                case 9:
                    {
                    int newAge;
                    cout<<"Ingrese su nueva edad: ";
                    cin>>newAge;
                    if(usuario->edad>newAge) cout<<"Rejuvenecio?"<<'\n';
                    cout<<"Su edad ahora es de "<<newAge<<'\n';
                    usuario->edad=newAge;
                    break;
                    }
                case 10:
                    {
                    string newNacion;
                    cout<<"Ingrese su nueva nacionalidad: ";
                    cin>>newNacion;
                    cout<<"Su nueva nacionalidad es"<<newNacion<<'\n';
                    usuario->nacionalidad=newNacion;
                    break;
                    }
                case 11:
                    return;
                }
                cout<<"Presione cualquier tecla para regresar";
                anykey();
                imprimirPerfil(opc,usuario);
            }
        }
    }
}

void imprimirPerfil(int &opc, Usuario* usuario)
{
    system("cls");
    hidecursor();
    usuario->mostrar();
        if(opc==0) cout<<'>';
        cout<<"Ver lista de amigos\n";
        if(opc==1) cout<<'>';
        cout<<"Ver lista de enemigos\n";
        if(opc==2) cout<<'>';
        cout<<"Ver publicaciones\n";
        if(opc==3) cout<<'>';
        cout<<"Crear publicacion\n";
        if(opc==4) cout<<'>';
        cout<<"Enviar mensaje\n";
        if(opc==5) cout<<'>';
        cout<<"Entrar a perfil de amigo\n";
        if(opc==6) cout<<'>';
        cout<<"Notificaciones\n";
        if(opc==7) cout<<'>';
        cout<<"Mandar solicitud de amistad\n";
        if(opc==8) cout<<'>';
        cout<<"Hacerse enemigo de alguien\n";
        if(opc==9) cout<<'>';
        cout<<"Modificar edad\n";
        if(opc==10) cout<<'>';
        cout<<"Modificar nacionalidad\n";
        if(opc==11) cout<<'>';
        cout<<"Salir\n";
}

void perfilAmigo(Usuario* amigo)
{
    int opc=0, tecla;
    imprimirAmigo(opc,amigo);
    while(1)
    {
        if(kbhit)
        {
            tecla=getkey();
            if(tecla==14) //arriba
            {
                opc--;
                if(opc<0) opc=3;
                imprimirAmigo(opc,amigo);
            }
            else if(tecla==15) //abajo
            {
                opc++;
                if(opc>3) opc=0;
                imprimirAmigo(opc,amigo);
            }
            else if(tecla==1) //enter
            {
                system("cls");
                hidecursor();
                switch(opc)
                {
                case 0:
                    amigo->mostrarAmigos();
                    break;
                case 1:
                    amigo->mostrarEnemigos();
                    break;
                case 2:
                    amigo->mostrarPublicaciones();
                    break;
                case 3:
                    return;
                }
                cout<<"Presione cualquier tecla para regresar";
                anykey();
                imprimirAmigo(opc,amigo);
            }
        }
    }
}

void imprimirAmigo(int &opc, Usuario* amigo)
{
    system("cls");
    hidecursor();
    cout<<"Amigo:\n";
    amigo->mostrar();
        if(opc==0) cout<<'>';
        cout<<"Ver lista de sus amigos\n";
        if(opc==1) cout<<'>';
        cout<<"Ver lista de sus enemigos\n";
        if(opc==2) cout<<'>';
        cout<<"Ver sus publicaciones\n";
        if(opc==3) cout<<'>';
        cout<<"Salir\n";
}
