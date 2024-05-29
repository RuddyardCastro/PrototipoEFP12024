#include "Login_Alumno.h"
#include<iostream> // Biblioteca estándar para la entrada y salida
#include<fstream> // Biblioteca para manejo de archivos
#include<stdlib.h> // Biblioteca estándar de funciones generales
#include<cstdlib> // Biblioteca estándar
#include<conio.h> // Biblioteca para la manipulación de la consola
#include<iomanip> // Biblioteca para la manipulación de la entrada/salida formateada
using namespace std;

// Constructor de la clase Login_Alumno
Login_Alumno::Login_Alumno(string usuario, string contrasena)//parametros de la clase
{
    this -> usuarios=usuarios;
    this -> contrasena=contrasena;
}

// Método para establecer el nombre de usuario
string Login_Alumno::setUser(string usuarios)
{
    this -> usuarios=usuarios;
}

// Método para obtener el nombre de usuario
string Login_Alumno::getUser()
{
    return this->usuarios;
}

// Método para establecer la contraseña
string Login_Alumno::setContrasena(string contrasena)
{
    this -> contrasena=contrasena;
}

// Método para obtener la contraseña
string Login_Alumno::getContrasena()
{
    return this->contrasena;
}

// Método para verificar el usuario
bool Login_Alumno::VerificarUsuario()
{
    string usuario,contrasena;
    int contador= 0; // contador de intentos
    bool encontrado =false; // indica si encontro user y contra

    while(contador<3 && !encontrado)
    {
         system("cls");
    cout <<"\t\t\t+-----------------------------------+"<<endl;
    cout <<"\t\t\t|          LOGIN ALUMNOS            |"<<endl;
    cout <<"\t\t\t+-----------------------------------+"<<endl;
    cout <<"\t\t\t|Solo tienes permitido 3 intentos   |"<<endl;
    cout <<"\t\t\t+-----------------------------------+"<<endl;
    cout <<"\t\t\tIngrese el usuario: ";
    cin >> usuario;
    cout <<"\t\t\tIngrese la contrasena: ";

    //ocualta la contrasenia con caracteres
    char caracter;
    caracter = getch(); //obtiene el primer caracter

    contrasena="";
        while (caracter!=13)//ascci enter
        {
        if(caracter !=8)//ascci backs pace
            {
                contrasena.push_back(caracter);//Regresa a su posicion
                cout<<"*"; // Muestra el * en lugar del caracter
            }
        else
            {
                if(contrasena.length()>0)
                {
                    cout<<"\b \b"; //elimina el ultimo asterisco en pantalla
                    contrasena=contrasena.substr(0,contrasena.length()-1); // Elimina el último carácter de la contraseña
                }
            }
            caracter=getch(); //captura el siguiente caracter
        }

    //Ingresa el archivo que contiene los usuarios y contrasenas
    ifstream fileU_P;
    fileU_P.open("UsuariosAlumnos.txt",ios::in);


    if (!fileU_P)
    {
        cout<<"\n\t\t\t No es posible abrir el archivo."<<endl;
        fileU_P.close();
        return false;
    }

    //busca el usuario en el archivo---------------------------------
    string users,pass;
    while (fileU_P>>users>>pass)
    {
        if (users==usuario && pass==contrasena)
        {
            encontrado=true;

            fstream file;
            file.open("BitacoraLoA.txt", ios::app | ios::out);
            file <<left<<users<<"\n";
            file.close();
            break;
        }
    }
     fileU_P.close();

    //si no encuentra user y pass , el contador incrementara------------------------
    if(!encontrado)
    {
        cout << "\n\n\t\t\tUSUARIO Y/O CONTRASEÑA INCORRECTOS" << endl;
        cout << "\n\n\t\t\tPerdio un intento, Intente de nuevo\n" << endl;
        contador++;
        system("pause");
    }
}

   if (encontrado)
    {
    	         system("cls");

    cout << "\n\t----- Bienvenido " << usuario << " -----" << endl;
     system("pause");
    return true;
    }
   else
    {
	system("cls");
    cout << "\n\n\t\t\tPERDIO LOS 3 INTENTOS" << endl; //muestra un mensaje de error
     system("pause");
     exit(0); //finaliza el programa

    return false;
    }
}
