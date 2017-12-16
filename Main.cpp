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
				string escribir,temp;
				cout<<"Introduzca el nombre que le quiere poner al archivo de texto,sin el .txt"<<endl;
				cin>>nombreArchivo;
				nombreArchivo+=".txt";
				ifstream ifile(nombreArchivo.c_str());
				if (ifile) {
					cout<<"Ya existe el archivo"<<endl;
				}else{
					bool resp=true;
					while (resp==true) {
						cout<<"Introduzca lo que va a escribir"<<endl;
						cin.ignore();
						getline(cin,temp);
						escribir+=temp;
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
					ofstream salida(nombreArchivo.c_str(), ios::app );
					Archivo archivo(escribir);
					salida<<archivo;
					salida.close();
				}

			}break;
			case 2:{
				string archivoTexto,textoLeido;
				cout<<"Introduzca el nombre del archivo de texto que quiere buscar, sin el .txt PORFAVOR"<<endl;
				cin>>archivoTexto;
				archivoTexto+=".txt";
				nombreArchivo=archivoTexto;

				string line;
				int cont = 0;

				ifstream contador (nombreArchivo.c_str());

				if (contador.is_open()){
					while ( getline (contador, line) ){
						cont++;
					}

					contador.close();
				}
				//cout<<cont<<endl;
				//cout<<"entro"<<endl;
				ArrayStack* contenido = new ArrayStack(cont);

				ifstream myfile (nombreArchivo.c_str());
				bool seguir=true;
				if (myfile.is_open()){
					int cuantasVeces=0;

						while (seguir &&cuantasVeces<5) {
							if (cuantasVeces<5) {
								int contador=0;
								while ( getline (myfile,line) ){
									cout<<contador<<")";
									cout << line << '\n';
									contenido->push(line);
									contador++;
								}

								int pos;
								cout<<"Que linea desea editar?"<<endl;
								cin>>pos;

								string lugar = contenido->posicion(pos);
								cout<<"usted escogio:"<<lugar<<endl;

								string cambio;

								cout<<"Ingrese lo que desea sustituir"<<endl;
								cin.ignore();
								getline(cin, cambio);
								contenido->sustitucion(cambio, pos);
								lugar = contenido->posicion(pos);
								int menuChiqui;
								cout<<"1.Quiere seguir cambiando cosas?? o 2.Quiere guardarlo"<<endl;
								cin>>menuChiqui;
								cuantasVeces++;
								if (menuChiqui==1) {
									seguir=true;
								}else{
									seguir=false;
								}
							}


						}
						if (cuantasVeces>=5) {
							cout<<"Se paso del limite,solo puede hacer 5 veces"<<endl;
						}


					//aqui es donde se guarda en el archvio
					string escribir;
					for (size_t i = 0; i < cont; i++) {
						escribir+=contenido->posicion(i);
						if (i==cont-1) {

						}else{
							escribir+="\n";
						}

					}
					ofstream salida(nombreArchivo.c_str(), ios::out | ios::trunc );
					Archivo archivo(escribir);
					salida<<archivo;
					salida.close();
					//cout<<lugar<<endl;
					//cout<<"entro"<<endl;
					delete contenido;



					myfile.close();
				}else{
					cout<<"archivo no existe"<<endl;
				}
			}break;
		}
	} while(menu!=0);


	return 0;
}
