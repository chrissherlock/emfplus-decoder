CC          = g++
DEBUG       = -g
CXXFILES    = main.cxx header.cxx record.cxx
INCLUDE     = include
EXECUTABLE  = emfplus_decode

build: $(CXXFILES)
	$(CC) -o $(EXECUTABLE) $(CXXFILES) -I$(INCLUDE) $(DEBUG)

clean:
	rm -f *.o core emfplus_decode
