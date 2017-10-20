all: music.c
	gcc -o musiclib music.c
clean:
	rm *~
	rm *.dSYM
run: all
	./musiclib
