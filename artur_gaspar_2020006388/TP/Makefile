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
CFLAGS = -Wall -c -I$(INCLUDE_FOLDER) -fsanitize=address,undefined -fno-omit-frame-pointer -Wshadow -std=c++17 -Wno-unused-result -Wno-sign-compare -Wno-char-subscripts -g
LFLAGS = -Wall -fsanitize=address,undefined -fno-omit-frame-pointer -Wshadow -std=c++17 -Wno-unused-result -Wno-sign-compare -Wno-char-subscripts -g
LIBS = -lm

# Arquivos
TARGET = $(BIN_FOLDER)/buscar
HDR_FILES = $(INCLUDE_FOLDER)/doc_data.hpp $(INCLUDE_FOLDER)/id_freq.hpp $(INCLUDE_FOLDER)/indexador.hpp $(INCLUDE_FOLDER)/indice_termos.hpp $(INCLUDE_FOLDER)/leitor_termos.hpp $(INCLUDE_FOLDER)/lista_id_freqs.hpp $(INCLUDE_FOLDER)/lista_lista_id_freqs.hpp $(INCLUDE_FOLDER)/memlog.hpp $(INCLUDE_FOLDER)/msgassert.hpp $(INCLUDE_FOLDER)/processador_consultas.hpp $(INCLUDE_FOLDER)/ranking_documentos.hpp $(INCLUDE_FOLDER)/string_hasher.hpp $(INCLUDE_FOLDER)/string_set.hpp
OBJ_FILES = $(OBJ_FOLDER)/buscar.o $(OBJ_FOLDER)/doc_data.o $(OBJ_FOLDER)/id_freq.o $(OBJ_FOLDER)/indexador.o $(OBJ_FOLDER)/indice_termos.o $(OBJ_FOLDER)/leitor_termos.o $(OBJ_FOLDER)/lista_id_freqs.o $(OBJ_FOLDER)/lista_lista_id_freqs.o $(OBJ_FOLDER)/memlog.o $(OBJ_FOLDER)/processador_consultas.o $(OBJ_FOLDER)/ranking_documentos.o $(OBJ_FOLDER)/string_hasher.o $(OBJ_FOLDER)/string_set.o

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) -o $(TARGET) $(LFLAGS) $(LIBS) $(OBJ_FILES)

$(OBJ_FOLDER)/memlog.o: $(HDR_FILES) $(SRC_FOLDER)/memlog.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/memlog.o $(SRC_FOLDER)/memlog.cpp

$(OBJ_FOLDER)/buscar.o: $(HDR_FILES) $(SRC_FOLDER)/buscar.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/buscar.o $(SRC_FOLDER)/buscar.cpp

$(OBJ_FOLDER)/doc_data.o: $(HDR_FILES) $(SRC_FOLDER)/doc_data.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/doc_data.o $(SRC_FOLDER)/doc_data.cpp

$(OBJ_FOLDER)/id_freq.o: $(HDR_FILES) $(SRC_FOLDER)/id_freq.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/id_freq.o $(SRC_FOLDER)/id_freq.cpp

$(OBJ_FOLDER)/indexador.o: $(HDR_FILES) $(SRC_FOLDER)/indexador.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/indexador.o $(SRC_FOLDER)/indexador.cpp

$(OBJ_FOLDER)/indice_termos.o: $(HDR_FILES) $(SRC_FOLDER)/indice_termos.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/indice_termos.o $(SRC_FOLDER)/indice_termos.cpp

$(OBJ_FOLDER)/leitor_termos.o: $(HDR_FILES) $(SRC_FOLDER)/leitor_termos.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/leitor_termos.o $(SRC_FOLDER)/leitor_termos.cpp

$(OBJ_FOLDER)/lista_id_freqs.o: $(HDR_FILES) $(SRC_FOLDER)/lista_id_freqs.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/lista_id_freqs.o $(SRC_FOLDER)/lista_id_freqs.cpp

$(OBJ_FOLDER)/lista_lista_id_freqs.o: $(HDR_FILES) $(SRC_FOLDER)/lista_lista_id_freqs.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/lista_lista_id_freqs.o $(SRC_FOLDER)/lista_lista_id_freqs.cpp

$(OBJ_FOLDER)/processador_consultas.o: $(HDR_FILES) $(SRC_FOLDER)/processador_consultas.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/processador_consultas.o $(SRC_FOLDER)/processador_consultas.cpp

$(OBJ_FOLDER)/url_acessos.o: $(HDR_FILES) $(SRC_FOLDER)/url_acessos.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/url_acessos.o $(SRC_FOLDER)/url_acessos.cpp

$(OBJ_FOLDER)/ranking_documentos.o: $(HDR_FILES) $(SRC_FOLDER)/ranking_documentos.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/ranking_documentos.o $(SRC_FOLDER)/ranking_documentos.cpp

$(OBJ_FOLDER)/string_hasher.o: $(HDR_FILES) $(SRC_FOLDER)/string_hasher.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/string_hasher.o $(SRC_FOLDER)/string_hasher.cpp

$(OBJ_FOLDER)/string_set.o: $(HDR_FILES) $(SRC_FOLDER)/string_set.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/string_set.o $(SRC_FOLDER)/string_set.cpp 

clean:
	rm $(TARGET) $(OBJ_FILES) 
