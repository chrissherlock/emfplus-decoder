include Makefile.inc

DIR     = ${CURDIR}
BUILD   = $(DIR)/build
SUBDIRS = emf
TARGET  = emfplus_decode

export BUILD

.PHONY: build ${SUBDIRS}

build: $(SUBDIRS)
	cd $(BUILD)
	$(CC) -o $(TARGET) $(BUILD)/*.o

$(SUBDIRS):
	$(MAKE) -C $@
	cp $@/*.o $(BUILD)

clean:
    
