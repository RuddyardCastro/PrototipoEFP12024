#ifndef ASIGCURSOS_ALUMNOS_H
#define ASIGCURSOS_ALUMNOS_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct Alumno {
    char id[20];          // Almacena la id de los alumnos ingresados
    char nombre[50];      // Almacena el nombre  del alumno ingresado
    char Genero[10];      // Almacena el género del alumno ingresado
    char DPI[20];         // Almacena el DPI del alumno ingresado
    char direccion[100];  // Almacena la dirección del alumno ingresado
    char nacionalidad[50];// Almacena la nacionalidad del alumno ingresado
    char telefono[15];    // Almacena el número de teléfono del alumno ingresado
    char civil[20];       // Almacena el estado civil del alumno ingresado
    char fechanaci[20];   // Almacena la fecha de nacimiento del alumno ingresado
    char anoingre[10];    // Almacena el año de ingreso del alumno ingresado
};

class AsigCursos_Alumnos {
private:
    string id,codigo_alumno, nombre_Alumno, nom_Alumno, curso, jornada, aula, seccion, nacionalidad;

public:
    AsigCursos_Alumnos() {}
    AsigCursos_Alumnos(string id, string codigo_alumno, string nombre_Alumno, string nom_Alumno, string curso, string jornada, string aula, string seccion, string nacionalidad);

    string setid(string id);
    string getid();

    string setnom_Alumno(string nom_Alumno);
    string getnom_alumno();

    string setcurso(string curso);
    string getcurso();

    string setjornada(string jornada);
    string getjornada();

    string setaula(string aula);
    string getaula();

    string setseccion(string seccion);
    string getseccion();

    string setnacionalidad(string nacionalidad);
    string getnacionalidad();

    void desplegarBoleta(const char* carnet,string nombre);
    void Menu_alumno();
    void asignacion_alumno(const char* carnet); // Corregido
    void mostrar_cursos();
    bool validarCarnet(); // Corregido
    bool ValidarJO(int codigo);
    bool ValidarAU(int codigo);
    bool ValidarSECC(int codigo);
    bool ValidaAsignacion(const char* carnet);
    string ObtenerJornada(int codigo);
    string ObtenerAula(int codigo);
    string ObtenerSeccion(int codigo);

    struct Asignacion {
        char carnet[20];
        int codigoJornada;
        int codigoAula;
        int codigoSeccion;
    };
};

#endif // ASIGCURSOS_ALUMNOS_H
