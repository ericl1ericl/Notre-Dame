# DO NOT EDIT -------------------------------
CPP=/afs/nd.edu/user14/csesoft/new/bin/gcc
CPPFLAGS=-Wall
LD=/afs/nd.edu/user14/csesoft/new/bin/gcc
LDFLAGS=-L/afs/nd.edu/user14/csesoft/2018-spring/lib -lzmq
INCLUDE=/afs/nd.edu/user14/csesoft/2018-spring/include
# ---------------------------- END DO NOT EDIT


CPPFLAGS += -std=c99 -g   # Add your own flags here, or leave blank
LDFLAGS +=                  # Add your own flags here, or leave blank

OBJECTS=main.o

project1: $(OBJECTS)
	$(LD) $^ $(LDFLAGS) -o $@

%.o: %.c
	$(CPP) -I$(INCLUDE) $(CPPFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o project1


