#ifndef Usuario_h
#define Usuario_h
#include <vector>
#include <string>
using namespace std;

class Publicacion;
class Mensaje;
class RedSocial;

class Usuario
{
private:
    int id;
public:
    string nombre;
    int edad;
    string nacionalidad;
    vector<Usuario*> amigos;
    vector<Usuario*> enemigos;
    vector<Publicacion*> publicaciones;
    vector<Mensaje*> mensajes;
    Usuario(string nombre);
    Usuario(string nombre, int edad);
    Usuario(string nombre, int edad, string nacionalidad);
    int getId();
    Usuario* getAmigo(int id);
    void mostrar();
    void mostrarAmigos();
    void mostrarEnemigos();
    void mostrarPublicaciones();
    void crearPublicacion(RedSocial* Red);
    void agregarAmigo(Usuario* nuevoAmigo);
    void agregarEnemigo(Usuario* nuevoEnemigo);
    bool esAmigo(Usuario* usuario);
    bool esEnemigo(Usuario* usuario);
};

#endif
