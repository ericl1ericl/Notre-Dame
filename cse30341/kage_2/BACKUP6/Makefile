GCC=/usr/bin/gcc

simplefs: shell.o fs.o disk.o
	$(GCC) shell.o fs.o disk.o -o simplefs -std=gnu99

shell.o: shell.c
	$(GCC) -Wall shell.c -c -o shell.o -g -std=gnu99

fs.o: fs.c fs.h
	$(GCC) -Wall fs.c -c -o fs.o -g -std=gnu99

disk.o: disk.c disk.h
	$(GCC) -Wall disk.c -c -o disk.o -g -std=gnu99

clean:
	rm simplefs disk.o fs.o shell.o -std=gnu99
