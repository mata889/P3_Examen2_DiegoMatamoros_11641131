#include <fstream>
#include <istream>
#include <string>
#include <iostream>
#include <cstdlib>
#include "Archivo.h"
#include "ArrayStack.h"
using namespace std;

int main(){
	int menu;
	string nombreArchivo;
	do {
		cout<<"1.Crea un Nuevo archivo de texto\n2.Modificar archivo ya existente\n0.SALIR"<<endl;
		cin>>menu;
		switch (menu) {
			case 1:{
				//char escri[100];
				string escribir;
				cout<<"Introduzca el nombre que le quiere poner al archivo de texto,sin el .txt"<<endl;
				cin>>nombreArchivo;
				nombreArchivo+=".txt";
				bool resp=true;
				while (resp==true) {
					cout<<"Introduzca lo que va a escribir"<<endl;
					cin.ignore();
					getline(cin,escribir);
					//getline(cin,escribir);
					//escribir+=escri;
					//cout<<escribir<<endl;
					int menuLinea;
					cout<<"1.Desea escribir otra linea\n2.Dejarlo"<<endl;
					cin>>menuLinea;
					if (menuLinea==1) {
						resp=true;
						escribir+="\n";
					}else {
						cout<<"Entro"<<endl;
						resp=false;
					}
				}
				ofstream salida(nombreArchivo, ios::app );
				Archivo archivo(escribir);
				salida<<archivo;
				salida.close();
			}break;
			case 2:{
				string archivoTexto;
				cout<<"Introduzca el nombre del archivo de texto, sin el .txt"<<endl;
				cin>>archivoTexto;
			}break;
		}
	} while(menu!=0);


	return 0;
}
