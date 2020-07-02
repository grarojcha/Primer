#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Registro {
	int codigo;
	char nombre[30];
	int edad;
	float altura;
};

bool CrearArchivo(int tipo=0) {
	char resp = 's';
	int cod = 1;
	Registro Alumno; //estructura que se utilizar para manipular registros
	ofstream Escribir;
	if(tipo==0)
		Escribir.open("prueba.dat", ios::out | ios::binary);
	else
		Escribir.open("prueba.dat", ios::out | ios::binary | ios::app);
	if(!Escribir.fail()) {
		do {
			Alumno.codigo = cod++;
			cout << "Digite el nombre\n";
			cin >> Alumno.nombre;
			cout << "Digite la edad\n";
			cin >> Alumno.edad;
			cout << "Digite la altura\n";
			cin >> Alumno.altura;
			Escribir.write((char *)&Alumno, sizeof(Registro));
			cout << "Desea agregar otro alumno? s/n\n";
			cin >> resp;
		} while (resp == 's' && Escribir.good());
		Escribir.close();
		return true;
	}
	else {
		return false;
	}
}

int CantidadRegistros() {
	ifstream Leer("prueba.dat", ios::in | ios::binary);
	Leer.seekg(0, Leer.end);
	long length = (long) Leer.tellg() / (long) sizeof(Registro);
	Leer.close();
	return length;
}

bool BuscarRegistro(Registro &Datos) {
	ifstream Leer("prueba.dat", ios::in | ios::binary);
	bool encontrado = false;
	char Alumno[30];
	strcpy_s(Alumno, Datos.nombre);
	if(!Leer.fail()){
		Leer.read((char *)&Datos, sizeof(Registro));
		while (!Leer.eof() && encontrado==false) {
			if (strcmp(Alumno, Datos.nombre) == 0)
				encontrado = true;
			else
				Leer.read((char *)&Datos, sizeof(Registro));
		}
		Leer.close();
	}
	return encontrado;
}

void MostrarArchivo() {
	Registro Alumno;
	ifstream Leer("prueba.dat", ios::in | ios::binary);
	cout << "Codigo\t\tNombre\t\tEdad\t\tAltura" << endl;
	Leer.read((char *)&Alumno, sizeof(Registro));
	while (!Leer.eof() && !Leer.fail()) {
		cout << Alumno.codigo << "\t\t" << Alumno.nombre << "\t\t" 
			<< Alumno.edad << "\t\t" << Alumno.altura << endl;
		Leer.read((char *)&Alumno, sizeof(Registro));
	}
	Leer.close();
}

bool ModificarRegistro() {
	/*
	Esta función debe solicitar al usuario el código del alumno que se desea modificar
	una vez encontrado debe mostrar los datos almacenados y solicitar los nuevos valores para este registro
	y modificar el archivo. Para modificar el archivo utilice el siguiente método:
	1. crear un archivo auxiliar, en donde va a copiar todos los datos del archivo original
	2. cuando encuentre el registro debe guardar en el archivo auxiliar los nuevos valores solicitados
	3.cuando termine el copiar el archivo con los nuevos valores se deben cerrar ambos archivos
	4.eliminar el archivo original y renombrar el archivo auxiliar con el nombre del archivo original

	La función debe retornar un valor booleano (true si se completa el proceso, false si ocurre algún error)
	*/

	return 0;
}

bool EliminarRegistro() {
	/*
	Esta función debe solicitar al usuario el código del alumno que se desea eliminar. 
	Para eliminar el registro utilice el siguiente método:
	1. crear un archivo auxiliar, en donde va a copiar todos los datos del archivo original
	2. cuando encuentre el registro a eliminar no copiarlo en el archivo auxiliar
	3.cuando termine el copiar todos los registros que se desean mantener, cerrar ambos archivos
	4.eliminar el archivo original y renombrar el archivo auxiliar con el nombre del archivo original

	La función debe retornar un valor booleano (true si se completa el proceso, false si ocurre algún error)
	*/

	return 0;
}