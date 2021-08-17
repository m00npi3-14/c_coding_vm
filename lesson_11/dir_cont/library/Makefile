SRCS += dircontents.c
LIBNAME += libdircontents.so

all:
	gcc $(SRCS) -o $(LIBNAME) -shared -fPIC

install:
	cp $(LIBNAME) /usr/lib
	cp dircontents.h /usr/include

uninstall:
	rm -f /usr/lib$(LIBNAME) /usr/include/dircontents.h

clean:
	rm -f $(LIBNAME) *.o