compilar: main.cpp alfabeto.cpp cadena.cpp
	g++ -Wall main.cpp alfabeto.cpp cadena.cpp -o main

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

limpiar_ejecutable:
	rm main
	cat /dev/null > salida.txt