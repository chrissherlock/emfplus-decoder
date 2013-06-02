CC          = g++
DEBUG       = -g
CXXFILES    = main.cxx $(EMFHDRFILES) $(PRINTFILES) $(EMFRECORDS)
EMFHDRFILES = header.cxx emfrecord.cxx
EMFRECORDS  = emfbitmap.cxx
PRINTFILES  = header_output.cxx
INCLUDE     = include
EXECUTABLE  = emfplus_decode

build: $(CXXFILES)
	$(CC) -o $(EXECUTABLE) $(CXXFILES) -I$(INCLUDE) $(DEBUG)

clean:
	rm -f *.o core $(EXECUTABLE)
	touch $(CXXFILES)
