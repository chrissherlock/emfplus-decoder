include Makefile.inc

DIR         = ${CURDIR}
BUILD       = ${DIR}/build
SUBDIRS     = emf
EXECUTABLE  = emfplus_decode

export BUILD

.PHONY: build ${SUBDIRS}

build: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

clean:
	rm -f ${BUILD}/*
