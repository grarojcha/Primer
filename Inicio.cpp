#include "Funciones.h"

int main() {
	char continuar;
	int opcion;
	Registro AlumnoBuscar = {0,"",0,0};
	
	do
	{
		system("cls");
		cout << "QUE DESEA HACER:\n\n"
			<< "1: Crear un nuevo archivo\n"
			<< "2: Agregar datos a un nuevo archivo existente\n"
			<< "3: Verificar la cantidad de registros del archivo\n"
			<< "4: Buscar un registro\n"
			<< "5. Mostrar el contenido del archivo\n"
			<< "6. Modificar un registro\n"
			<< "7. Elminar un registro\n"
			<< "8. Salir\n";
		cin >> opcion;
		system("cls");
		switch (opcion)
		{
		case 1:
			CrearArchivo();//crear alchivo sin parámetro crear el archivo 
			//o reemplaza el archivo si ya existe
			break;
		case 2:
			CrearArchivo(1); //al llamar a crear archivo con un 1 se abre en modo app para modificarlo
			break;
		case 3:
			cout<<"El archivo tiene: "<<CantidadRegistros()<<" registros\n";
			break;
		case 4:
			cout << "Digite el nombre del alumno que desea buscar: \n";
			cin >> AlumnoBuscar.nombre;
			if (BuscarRegistro(AlumnoBuscar)) {//si encuentra el registro lo muestra
				cout << "Registro encontrado: \n"
					<< AlumnoBuscar.nombre << "\n"
					<< AlumnoBuscar.edad << "\n"
					<< AlumnoBuscar.altura<<"\n";
			}
			else
			{
				cout << "El registro no se encuentra \n";
			}
			break;
		case 5:
			MostrarArchivo();
			break;
		case 8:
			return 0;
		default:
			break;
		}
		cout << "Desea realizar otro tramite? s/n\n";
		cin >> continuar;
	} while (continuar == 's');
	
	system("pause");
	return 0;
}


