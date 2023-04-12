all: app_main

app_main: app_main.o tad_deque.o  
	gcc obj/app_main.o obj/tad_deque.o -o bin/app_main.out	
# para o windows comentar a linha acima e descomentar a linha abaixo
#gcc obj/app_main.o obj/lista_ligada.o -o bin/app_main.exe	


tad_deque.o: src/tad_deque.c include/tad_deque.h
	gcc -I include -Wall -Werror -c src/tad_deque.c -o obj/tad_deque.o

app_main.o: apps/app_main.c include/tad_deque.h
	gcc -I include -Wall -Werror -c apps/app_main.c -o obj/app_main.o

run:
	./bin/app_main.out
# para o windows comentar a linha acima e descomentar a linha abaixo
#./bin/app_main.exe	

clean:
	rm -f bin/app_main.out obj/*.o	
# para o windows comentar a linha acima e descomentar a linha abaixo
#del bin\app_main.exe obj\*.o 	