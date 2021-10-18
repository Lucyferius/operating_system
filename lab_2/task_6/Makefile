LIB_FOLDER      = lib
DEL_FILE      	= rm -f
LIB_STATIC	= libmatrix.a
LIB_NAME_STATIC = matrix

all : create_directory compile_static_libs clean run

create_directory: 
	mkdir -p $(LIB_FOLDER)
	
compile_static_libs: 
	gcc -w -c *.c
	ar rc  $(LIB_FOLDER)/$(LIB_STATIC) main.o matrix.o
	ranlib $(LIB_FOLDER)/$(LIB_STATIC)
	gcc -o app.out *.o -I. -L $(LIB_FOLDER)/ -l$(LIB_NAME_STATIC) -lm
	
run: 
	./app.out	
clean: 
	$(DEL_FILE) main.o matrix.o
	

