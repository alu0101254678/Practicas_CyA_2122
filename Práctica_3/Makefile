compilar: main.cpp alfabeto.cpp cadena.cpp lenguaje.cpp
	g++ -Wall main.cpp alfabeto.cpp cadena.cpp lenguaje.cpp -o main

ejecutar_longitud_cadena: main
	./main "entrada.txt" "salida.txt" 1

ejecutar_inversa: main
	./main "entrada.txt" "salida.txt" 2

ejecutar_prefijos: main
	./main "entrada.txt" "salida.txt" 3

ejecutar_sufijos: main
	./main "entrada.txt" "salida.txt" 4

ejecutar_subcadenas: main
	./main "entrada.txt" "salida.txt" 5

ejecutar_comparacion_cadenas: main
	./main "entrada.txt" "salida.txt" 6

ejecutar_concatenacion_cadenas: main
	./main "entrada.txt" "salida.txt" 7

ejecutar_potencia_cadenas: main
	./main "entrada.txt" "salida.txt" 8

ejecutar_concatenacion_cadenas_alternativa: main
	./main "entrada.txt" "salida.txt" 9

limpiar_ejecutable:
	rm main
	cat /dev/null > salida.txt