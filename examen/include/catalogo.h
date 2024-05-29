#ifndef CATALOGO_H
#define CATALOGO_H
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include"alumnos.h"
using namespace std;

class catalogo
{
    public:
        catalogo(string curso, string curso2);


        string setCurso(string curso);
        string getCurso();

        string setCurso2(string curso2);
        string getCurso2();
//metodos


        void insertar(const char* carnet);
		void catalogoCursos(string CursosD);
		void desplegar();
		void desplegarcursosalumno(string carnet);

    protected:

    private:
    string curso, curso2;
};
#endif // catalogo.h
