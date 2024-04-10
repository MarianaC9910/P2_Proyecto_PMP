#ifndef RedSocial_h
#define RedSocial_h
#include "Publicacion.h"
#include "Usuario.h"
#include <vector>
#include <string>
using namespace std;

class RedSocial
{
private:
    vector<Usuario*> usuarios;
    vector<Publicacion*> publicaciones;
public:
    string nombre;
    int numeroDeUsuarios;
    int numeroDePublicaciones;
    RedSocial(string nombre);
    RedSocial(string nombre, vector<Usuario*> usuarios);
    RedSocial(string nombre, vector<Usuario*> usuarios, vector<Publicacion*> publicaciones);
    void eliminarUsuario();
    void crearUsuario();
    void agregarUsuario(Usuario* nuevoUsuario);
    void agregarPublicacion(Publicacion* nuevaPublicacion);
    void mostrarUsuarios();
    void mostrarPublicaciones();
    Usuario* getUsuario(int id);
};

void imprimirOpciones(int opc);

#endif
