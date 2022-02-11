#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa ordena
# Autor		: Artur Gaspar da Silva (artur.gaspar@dcc.ufmg.br)
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

# Diretórios
INCLUDE_FOLDER = ./include/
BIN_FOLDER = ./bin/
OBJ_FOLDER = ./obj/
SRC_FOLDER = ./src/

# Opções do compilador
CC = g++
CFLAGS = -Wall -c -I$(INCLUDE_FOLDER)
LIBS = -lm

# Arquivos
TARGET = $(BIN_FOLDER)/ordena
HDR_FILES = $(INCLUDE_FOLDER)/heap_url_acessos.hpp $(INCLUDE_FOLDER)/heapsort_recursivo.hpp $(INCLUDE_FOLDER)/memlog.hpp $(INCLUDE_FOLDER)/mergesort_nao_recursivo.hpp $(INCLUDE_FOLDER)/mergesort_recursivo.hpp $(INCLUDE_FOLDER)/msgassert.hpp $(INCLUDE_FOLDER)/ordenador.hpp $(INCLUDE_FOLDER)/quicksort_nao_recursivo.hpp $(INCLUDE_FOLDER)/quicksort_recursivo.hpp $(INCLUDE_FOLDER)/rodada_intercalator.hpp $(INCLUDE_FOLDER)/rodada_manipulator.hpp $(INCLUDE_FOLDER)/url_acessos.hpp $(INCLUDE_FOLDER)/pilha_par_int.hpp $(INCLUDE_FOLDER)/fila_par_int.hpp
OBJ_FILES = $(OBJ_FOLDER)/ordena.o $(OBJ_FOLDER)/heap_url_acessos.o $(OBJ_FOLDER)/heapsort_recursivo.o $(OBJ_FOLDER)/memlog.o $(OBJ_FOLDER)/mergesort_nao_recursivo.o $(OBJ_FOLDER)/mergesort_recursivo.o $(OBJ_FOLDER)/ordenador.o $(OBJ_FOLDER)/quicksort_nao_recursivo.o $(OBJ_FOLDER)/quicksort_recursivo.o $(OBJ_FOLDER)/rodada_intercalator.o $(OBJ_FOLDER)/rodada_manipulator.o $(OBJ_FOLDER)/url_acessos.o $(OBJ_FOLDER)/pilha_par_int.o $(OBJ_FOLDER)/fila_par_int.o

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) -o $(TARGET) $(LIBS) $(OBJ_FILES)

$(OBJ_FOLDER)/memlog.o: $(HDR_FILES) $(SRC_FOLDER)/memlog.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/memlog.o $(SRC_FOLDER)/memlog.cpp

$(OBJ_FOLDER)/ordena.o: $(HDR_FILES) $(SRC_FOLDER)/ordena.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/ordena.o $(SRC_FOLDER)/ordena.cpp

$(OBJ_FOLDER)/heap_url_acessos.o: $(HDR_FILES) $(SRC_FOLDER)/heap_url_acessos.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/heap_url_acessos.o $(SRC_FOLDER)/heap_url_acessos.cpp

$(OBJ_FOLDER)/heapsort_recursivo.o: $(HDR_FILES) $(SRC_FOLDER)/heapsort_recursivo.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/heapsort_recursivo.o $(SRC_FOLDER)/heapsort_recursivo.cpp

$(OBJ_FOLDER)/mergesort_nao_recursivo.o: $(HDR_FILES) $(SRC_FOLDER)/mergesort_nao_recursivo.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/mergesort_nao_recursivo.o $(SRC_FOLDER)/mergesort_nao_recursivo.cpp

$(OBJ_FOLDER)/mergesort_recursivo.o: $(HDR_FILES) $(SRC_FOLDER)/mergesort_recursivo.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/mergesort_recursivo.o $(SRC_FOLDER)/mergesort_recursivo.cpp

$(OBJ_FOLDER)/ordenador.o: $(HDR_FILES) $(SRC_FOLDER)/ordenador.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/ordenador.o $(SRC_FOLDER)/ordenador.cpp

$(OBJ_FOLDER)/quicksort_nao_recursivo.o: $(HDR_FILES) $(SRC_FOLDER)/quicksort_nao_recursivo.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/quicksort_nao_recursivo.o $(SRC_FOLDER)/quicksort_nao_recursivo.cpp

$(OBJ_FOLDER)/quicksort_recursivo.o: $(HDR_FILES) $(SRC_FOLDER)/quicksort_recursivo.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/quicksort_recursivo.o $(SRC_FOLDER)/quicksort_recursivo.cpp

$(OBJ_FOLDER)/rodada_intercalator.o: $(HDR_FILES) $(SRC_FOLDER)/rodada_intercalator.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/rodada_intercalator.o $(SRC_FOLDER)/rodada_intercalator.cpp

$(OBJ_FOLDER)/url_acessos.o: $(HDR_FILES) $(SRC_FOLDER)/url_acessos.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/url_acessos.o $(SRC_FOLDER)/url_acessos.cpp

$(OBJ_FOLDER)/pilha_par_int.o: $(HDR_FILES) $(SRC_FOLDER)/pilha_par_int.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/pilha_par_int.o $(SRC_FOLDER)/pilha_par_int.cpp

$(OBJ_FOLDER)/fila_par_int.o: $(HDR_FILES) $(SRC_FOLDER)/fila_par_int.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/fila_par_int.o $(SRC_FOLDER)/fila_par_int.cpp

$(OBJ_FOLDER)/rodada_manipulator.o: $(HDR_FILES) $(SRC_FOLDER)/rodada_manipulator.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/rodada_manipulator.o $(SRC_FOLDER)/rodada_manipulator.cpp 

clean:
	rm $(TARGET) $(OBJ_FILES) 
