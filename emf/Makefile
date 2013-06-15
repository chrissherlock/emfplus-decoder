include ../Makefile.inc
CXXFILES    = main.cxx $(EMFHDRFILES) $(PRINTFILES) $(EMFRECORDS)
EMFHDRFILES = header.cxx emfrecord.cxx emfclipping.cxx
EMFRECORDS  = emfbitmap.cxx
PRINTFILES  = header_output.cxx
INCLUDE     = include
EXECUTABLE  = emfplus_decode

build: $(CXXFILES)
	$(CC) -c $(CXXFILES) -I$(INCLUDE) $(DEBUG)

clean:
	rm -f *.o core
	touch $(CXXFILES)
