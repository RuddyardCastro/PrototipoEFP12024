#ifndef LOGIN_ALUMNO_H
#define LOGIN_ALUMNO_H
#include<iostream> // Biblioteca estándar para la entrada y salida
#include<fstream> // Biblioteca para manejo de archivos
#include<stdlib.h> // Biblioteca estándar de funciones generales
#include<cstdlib> // Biblioteca estándar
#include<conio.h> // Biblioteca para la manipulación de la consola
#include<iomanip> // Biblioteca para la manipulación de la entrada/salida formateada
using namespace std;

class Login_Alumno
{
public:
        Login_Alumno(string usuarios,string contrasena); // Constructor que inicializa las variables de usuario y contraseña

        string setUser(string usuarios); // Encargado de pedir datos
        string getUser(); // Encargado de obtener datos

        string setContrasena(string contrasena); // Encargado de pedir datos
        string getContrasena(); // Encargado de obtener datos

        // Método para verificar validacion de usuario
        bool VerificarUsuario();


    private:
        //Variables privadas para mantener la seguridad de contrasanias y usuarios
        string usuarios,contrasena;

};
#endif // LOGIN_ALUMNO_H
