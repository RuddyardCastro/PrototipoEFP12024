#include "catalogo.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include <vector>

using namespace std;

catalogo::catalogo(string curso2, string curso)
{
    this->curso=curso;
    this->curso2=curso2;
}


string catalogo::getCurso2()
{
    return this -> curso2;
}
string catalogo::setCurso2(string curso2)
{
    this->curso2=curso2;
}

string catalogo::getCurso()
{
    return this->curso;
}



void catalogo::desplegar()
{
    system("cls");
    int total = 0;

    // Imprimir encabezado
    cout << "\n-------------------------Bienvenido-----------------------";
    cout << "\n --- Lista de alumnos registrados en nuestro sistema  ----" << endl<<endl<<endl;

    ifstream fileDesplegar("catalogos.txt"); // Abrir el archivo para lectura

    // Verificar si el archivo se pudo abrir
    if (!fileDesplegar)
    {
        cout << "\n\t\t\tNo hay información..." << endl;
    }
    else
    {

        // Mostrar los datos en el formato deseado
        cout << "|-------------------------------------------|" << endl;
        cout << "|               Curso                       |" << endl;
        cout << "|-------------------------------------------|" << endl;
        string line;
        while (getline(fileDesplegar, line)) // Leer el archivo línea por línea
        {
            // Separar los datos de cada línea utilizando el delimitador '|'
            stringstream ss(line);
            string curso;
            getline(ss, curso, '|');


            cout << curso << setw(35-curso.size())<<"|"<< endl;
            cout<<"----------------------------------------------------------"<<endl;


            total++; // Incrementar el contador de alumnos
        }


       if (total == 0)
        {
            cout << "\n\t\t\tNo hay información..." << endl; // Mostrar un mensaje si no hay datos en el archivo
        }
    }

    fileDesplegar.close(); // Cerrar el archivo
}
void catalogo::catalogoCursos(string cursosD)
{
    system("cls");
    string line;
	ifstream myfile2(cursosD);
	if (myfile2.is_open())
    {
        while(getline(myfile2,line))
        {
            cout<<line<<endl;
        }

        myfile2.close();
        cout << endl << endl << endl ;
        system("pause");

    }

    else
    {
        cout<<"Error FATAL: el archivo no pudo ser cargado"<<endl;
        system("pause");
    }

}
void catalogo::insertar(const char* carnet)
{
    system("cls");
    int opcion=0;
    int numCursos=0;

    cout << "\n-------------------------------------------------Asignacion de cursos-------------------------------------------" << endl;

    this->catalogoCursos("cursos.txt");



    cout << "-----------------------------------------------" << endl;
    cout << "|  A cuantos cursos se desea asignar:          |" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << " 7) SALIR DEL MENU" << endl;
    cin >> numCursos;

    vector<string> cursosSeleccionados;
    for (int i = 0; i < numCursos; ++i)
    {
        cout << "Selecciona el curso " << i + 1 << ": ";
        cin >> opcion;

    string id, curso;

    int linea = 0 ;
    ifstream fileOri("cursos2.txt");
    if (!fileOri)
    {
        cout << "\n\t\t\tNo hay informacion.." << endl;
        return;
    }
    while (
           getline(fileOri, id,'|') &&
           getline(fileOri, curso,'|')
           )
    {

        if (linea == opcion-1)
        {

           cursosSeleccionados.push_back(curso);
        }
    linea ++;
    }
    }


    // Abre el archivo "catalogos.txt" en modo de apendizaje y escritura
    ofstream fileIngresar("catalogos.txt", ios::app);
    if (!fileIngresar)
    {
        cout << "Error al abrir el archivo catalogos.txt" << endl;
        return;
    }

    // Escribe en el archivo los datos del usuario ingresados por el usuario
    for (const string &curso : cursosSeleccionados)
    {

        fileIngresar << carnet << '|' << curso << '|'  << "\n";
    }

    // Cierre del archivo
    fileIngresar.close();

    // Mensaje de éxito
    cout << "\t\t\tAsignado a sus cursos exitosamente." << endl;
}

void catalogo::desplegarcursosalumno(string carnet)
{
    string id, curso;
    ifstream fileOri("catalogos.txt");

    if (!fileOri)
    {
        cout << "\n\t\t\tNo hay informacion.." << endl;
        return;
    }
      string line;
      cout << "CURSOS ASIGNADOS: " << endl << endl ;
      while (getline(fileOri, line)) // Leer el archivo línea por línea
        {
            stringstream ss(line);
            string curso;
            getline(ss, id, '|');
            getline(ss, curso, '|');
            if (id==carnet)
                cout <<  "                      " << curso << endl ;

        }
        cout << "+-----------------------------------------------------------------------------------------+" << endl;

}


