/*Universidad de La Laguna
Escuela Superior de Ingeniería y Tecnología
Grado en Ingeniería Informática
Asignatura: Computabilidad y Algoritmia
Curso: 2º
Práctica 2: Símbolos, alfabetos y cadenas
Autor: Yago Pérez Molanes
Correo: alu0101254678@ull.edu.es
Fecha: 13/10/2021
Archivo Práctica_2/main.cpp: programa principal,
se apoya en las clases alfabeto y cadena
lo que hace es que lee un fichero de entrada en donde se encuentran
lineas que incluyen alfabetos y cadenas, y tiene que ir leyendo linea a linea,
y realizar una opcion segun se le indica por argumentos del programa:

./main entrada.txt salida.txt 3, seria un ejemplo, en este caso estamos indicandole, 
que queremos calcular los prefijos de la cadena, que esta en entrada,txt, y queremos 
visualizarlos en salida.txt

las opciones se manejan segun un switch-case, y se hace un bucle while que no finaliza
hasta que se hayan leido todas las lineas del fichero de entrada
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>

#include "./alfabeto.hpp"
#include "./cadena.hpp"
#include "./lenguaje.hpp"

int main(int argc, char *argv[]) {

  if (argc != 4) {
    std::cout << "Modo de uso correcto del programa: " << std::endl; 
    std::cout << "/main  nombre_fichero_entrada  nombre_fichero_salida  opcion" << std::endl;
    return 1;
  }
  
  std::string str_1 = "hola";
  cadena cad_1 = cadena(str_1);

  std::string str_2 = "adios";
  cadena cad_2 = cadena(str_2);

  cad_1.concatenacion_alternativa(cad_2);

  std::ifstream fe(argv[1]); //flujo de entrada
  std::ofstream fs; //flujo de salida
  int opcion = atoi(argv[3]); //obtenemos la opcion, 1, 2, 3, 4 o 5, 6, 7, 8

  std::string aux; //cadena que introduce el usuario para concatenar
  int potencia; //potencia nesima 

  if (opcion == 6 || opcion == 7 || opcion == 9) {
    std::cout << "Escribe la cadena auxiliar: ";
    std::cin >> aux;
  }

  if (opcion == 8) {
    std::cout << "Escribe la potencia nesima: ";
    std::cin >> potencia;
  }
  
  fs.open(argv[2]); //abtrimos el fichero de salida
  
  std::string linea; //representa una linea del fichero
  std::vector<std::string> aux_pal; //para manipular la linea, 
  // (separar alfabetos, cadenas)

  while(getline(fe, linea)) {

    /** creamos un flujo de entrada para procesar cada
     * linea que lee del archivo de entrada, segun sus espacios
     * y lo ponemos en el vector hasta que lea la linea segun 
     * los espacios
     **/
    alfabeto alfab = alfabeto();
    cadena cad = cadena();
    std::stringstream linestream(linea);
    std::string datos;

    switch (opcion) {
      // calcular la longitud
      case 1: {
        while (getline(linestream, datos, ' ')) {
          aux_pal.push_back(datos);
        }

        if (aux_pal.size() == 1) {
          cad.set_cadena(aux_pal[0]);
          alfab = cad.anadir_alfabeto(alfab);

          fs << cad.longitud_cadena() << std::endl;
          break;
        } else {
            for (unsigned int i = 0; i < aux_pal.size(); i++) {
              if (i == aux_pal.size() - 1) {
                cad.set_cadena(aux_pal[i]);
              } else {
                alfab.add(aux_pal[i]);
              } 
            }
            fs << cad.longitud_cadena() << std::endl;
          }
          break;
      }

      //calcular la inversa
      case 2: {
        while (getline(linestream, datos, ' ')) {
          aux_pal.push_back(datos);
        }

        if (aux_pal.size() == 1) {
          cad.set_cadena(aux_pal[0]);
          alfab = cad.anadir_alfabeto(alfab);

          cadena cadena_invertida = cad.inversa();
          fs << cadena_invertida.get_cadena() << "\n";

          break;
        } else {
            for (unsigned int i = 0; i < aux_pal.size(); i++) {
              if (i == aux_pal.size() - 1) {
                cad.set_cadena(aux_pal[i]);
              } else {
                alfab.add(aux_pal[i]);
              } 
            }
            cadena cadena_invertida = cad.inversa();
            fs << cadena_invertida.get_cadena() << "\n";
          }
          break;
      }

      //calcular los prefijos de la cadena
      case 3: {
        while (getline(linestream, datos, ' ')) {
          aux_pal.push_back(datos);
        }

        if (aux_pal.size() == 1) {
          cad.set_cadena(aux_pal[0]);
          alfab = cad.anadir_alfabeto(alfab);

          std::vector <std::string> vector_prefijos;
          vector_prefijos = cad.prefijos();

          lenguaje lenguaje1 = lenguaje();

          for (unsigned int i = 0; i < vector_prefijos.size(); i++) {
            lenguaje1.add(vector_prefijos[i]);
          }
          lenguaje1.operator<<(fs);
          break;
        } else {
            for (unsigned int i = 0; i < aux_pal.size(); i++) {
              if (i == aux_pal.size() - 1) {
                cad.set_cadena(aux_pal[i]);
              } else {
                alfab.add(aux_pal[i]);
              } 
            }
            std::vector <std::string> vector_prefijos;
            vector_prefijos = cad.prefijos();

            lenguaje lenguaje1 = lenguaje();

            for (unsigned int i = 0; i < vector_prefijos.size(); i++) {
              lenguaje1.add(vector_prefijos[i]);
            }
            lenguaje1.operator<<(fs);
            break;
          }
      }

      //calcular los sufijos
      case 4: {
        while (getline(linestream, datos, ' ')) {
          aux_pal.push_back(datos);
        }

        if (aux_pal.size() == 1) {
          cad.set_cadena(aux_pal[0]);
          alfab = cad.anadir_alfabeto(alfab);

          std::vector <std::string> vector_sufijos;
          vector_sufijos = cad.sufijos();

          lenguaje lenguaje1 = lenguaje();

          for (unsigned int i = 0; i < vector_sufijos.size(); i++) {
            lenguaje1.add(vector_sufijos[i]);
          }
          lenguaje1.operator<<(fs);
          break;
        } else {
            for (unsigned int i = 0; i < aux_pal.size(); i++) {
              if (i == aux_pal.size() - 1) {
                cad.set_cadena(aux_pal[i]);
              } else {
                alfab.add(aux_pal[i]);
              } 
            }
            std::vector <std::string> vector_sufijos;
            vector_sufijos = cad.sufijos();

            lenguaje lenguaje1 = lenguaje();

            for (unsigned int i = 0; i < vector_sufijos.size(); i++) {
              lenguaje1.add(vector_sufijos[i]);
            }
            lenguaje1.operator<<(fs);
            break;
          }
      }

      //calcular las subcadenas
      case 5: {
        while (getline(linestream, datos, ' ')) {
          aux_pal.push_back(datos);
        }

        if (aux_pal.size() == 1) {
          cad.set_cadena(aux_pal[0]);
          alfab = cad.anadir_alfabeto(alfab);

          std::vector <std::string> vector_subcadenas;
          vector_subcadenas = cad.subcadenas();

          lenguaje lenguaje1 = lenguaje();

          for (unsigned int i = 0; i < vector_subcadenas.size(); i++) {
            lenguaje1.add(vector_subcadenas[i]);
          }
          
          lenguaje1.operator<<(fs);
          break;
        } else {
            for (unsigned int i = 0; i < aux_pal.size(); i++) {
              if (i == aux_pal.size() - 1) {
                cad.set_cadena(aux_pal[i]);
              } else {
                alfab.add(aux_pal[i]);
              } 
            }
            std::vector <std::string> vector_subcadenas;
            vector_subcadenas = cad.subcadenas();

            lenguaje lenguaje1 = lenguaje();

            for (unsigned int i = 0; i < vector_subcadenas.size(); i++) {
              lenguaje1.add(vector_subcadenas[i]);
            }
            lenguaje1.operator<<(fs);
            break;
          }
      }

       case 6: {
        while (getline(linestream, datos, ' ')) {
          aux_pal.push_back(datos);
        }

        if (aux_pal.size() == 1) {
          cad.set_cadena(aux_pal[0]);
          alfab = cad.anadir_alfabeto(alfab);

          cadena cadena_usuario = cadena(aux);

          if ((cad==cadena_usuario) == false && (cad>cadena_usuario) == false && (cad<cadena_usuario) == false) {
            fs << cad.get_cadena() << " " << "!=" << " " << aux << "\n"; 
          } else if ((cad==cadena_usuario) == true) {
            fs << cad.get_cadena() << " " << "=" << " " << aux << "\n";
          } else if ((cad>cadena_usuario) == true) {
            fs << cad.get_cadena() << " " << ">" << " " << aux << "\n"; 
          } else if ((cad<cadena_usuario) == true) {
            fs << cad.get_cadena() << " " << "<" << " " << aux << "\n"; 
          }
          
          break;
        } else {
            for (unsigned int i = 0; i < aux_pal.size(); i++) {
              if (i == aux_pal.size() - 1) {
                cad.set_cadena(aux_pal[i]);
              } else {
                alfab.add(aux_pal[i]);
              } 
            }

          cadena cadena_usuario = cadena(aux);

          if ((cad==cadena_usuario) == false && (cad>cadena_usuario) == false && (cad<cadena_usuario) == false) {
            fs << cad.get_cadena() << " " << "!=" << " " << aux << "\n"; 
          } else if ((cad==cadena_usuario) == true) {
            fs << cad.get_cadena() << " " << "=" << " " << aux << "\n";
          } else if ((cad>cadena_usuario) == true) {
            fs << cad.get_cadena() << " " << ">" << " " << aux << "\n"; 
          } else if ((cad<cadena_usuario) == true) {
            fs << cad.get_cadena() << " " << "<" << " " << aux << "\n"; 
          }
            
            break;
          }
      }

      case 7: {
        /*std::string aux;
        std::cout << "Escribe la cadena auxiliar: ";
        std::cin >> aux;*/

        while (getline(linestream, datos, ' ')) {
          aux_pal.push_back(datos);
        }

        if (aux_pal.size() == 1) {
          cad.set_cadena(aux_pal[0]);
          alfab = cad.anadir_alfabeto(alfab);

          cadena cad_aux = cadena(aux);
          cad.concatenacion(cad_aux);
          fs << cad.get_cadena() << "\n";

          break;
        } else {
            for (unsigned int i = 0; i < aux_pal.size(); i++) {
              if (i == aux_pal.size() - 1) {
                cad.set_cadena(aux_pal[i]);
              } else {
                alfab.add(aux_pal[i]);
              } 
            }
            
            cadena cad_aux = cadena(aux);
            cad.concatenacion(cad_aux);
            fs << cad.get_cadena() << "\n";
            break;
          }
      }

      case 8: {
        while (getline(linestream, datos, ' ')) {
          aux_pal.push_back(datos);
        }

        if (aux_pal.size() == 1) {
          cad.set_cadena(aux_pal[0]);
          alfab = cad.anadir_alfabeto(alfab);

          cad.potencia(potencia);
          fs << cad.get_cadena() << "\n";

          break;
        } else {
            for (unsigned int i = 0; i < aux_pal.size(); i++) {
              if (i == aux_pal.size() - 1) {
                cad.set_cadena(aux_pal[i]);
              } else {
                alfab.add(aux_pal[i]);
              } 
            }
            
            cad.potencia(potencia);
            fs << cad.get_cadena() << "\n";
            break;
          }
      }

       case 9: { //opcion para modificacion de clase
        /*std::string aux;
        std::cout << "Escribe la cadena auxiliar: ";
        std::cin >> aux;*/

        while (getline(linestream, datos, ' ')) {
          aux_pal.push_back(datos);
        }

        if (aux_pal.size() == 1) {
          cad.set_cadena(aux_pal[0]);
          alfab = cad.anadir_alfabeto(alfab);

          cadena cad_aux = cadena(aux);
          cad.concatenacion_alternativa(cad_aux);
          fs << cad.get_cadena() << "\n";

          break;
        } else {
            for (unsigned int i = 0; i < aux_pal.size(); i++) {
              if (i == aux_pal.size() - 1) {
                cad.set_cadena(aux_pal[i]);
              } else {
                alfab.add(aux_pal[i]);
              } 
            }
            
            cadena cad_aux = cadena(aux);
            cad.concatenacion_alternativa(cad_aux);
            fs << cad.get_cadena() << "\n";
            break;
          }
      }

      default:
        break;
    }

    //limpiamos el vector en donde se encontraba
    //la linea
    aux_pal.clear();
 
  }
  fs.close();

}
