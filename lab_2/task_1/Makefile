LIB_FOLDER      = lib
DEL_FILE      	= rm -f
LIB_STATIC	= libfunctions_static.a
LIB_DYNAMIC	= libfunctions_dynamic.so
LIB_NAME_STATIC = functions_static
LIB_NAME_DYNAMIC = functions_dynamic

all : create_directory compile_static_libs clean run

create_directory: 
	mkdir -p $(LIB_FOLDER)
	
compile_static_libs: 
	gcc -c *.c
	ar rc  $(LIB_FOLDER)/$(LIB_STATIC) main.o functions.o
	ranlib $(LIB_FOLDER)/$(LIB_STATIC)
	gcc -o app.out *.o -L $(LIB_FOLDER)/ -l$(LIB_NAME_STATIC) -lm
	
compile_dynamic_libs: 
	gcc -fPIC -c *.c
	gcc *.o -I. -fpic -shared -o $(LIB_FOLDER)/$(LIB_DYNAMIC)
	gcc *.o -o app.out -I. -L $(LIB_FOLDER)/ -l$(LIB_NAME_DYNAMIC) -lm
	

compile: 
	gcc main.c functions.c -o app.out -lm 
	
run: 
	./app.out	
clean: 
	$(DEL_FILE) main.o functions.o
	

