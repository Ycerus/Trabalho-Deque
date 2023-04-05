all: app_main

app_main: app_main.o lista_duplamente_ligada.o  
gcc obj/app_main.o obj/lista_ligada.o -o bin/app_main.exe	


lista_duplamente_ligada.o: src/lista_duplamente_ligada.c include/lista_duplamente_ligada.h
	gcc -I include -Wall -Werror -c src/lista_duplamente_ligada.c -o obj/lista_duplamente_ligada.o

app_main.o: apps/app_main.c include/lista_duplamente_ligada.h
	gcc -I include -Wall -Werror -c apps/app_main.c -o obj/app_main.o

run:
./bin/app_main.exe	

clean:
del bin\app_main.exe obj\*.o 	