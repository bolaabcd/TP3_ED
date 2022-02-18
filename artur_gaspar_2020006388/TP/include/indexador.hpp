//---------------------------------------------------------------------
// Arquivo      : indexador.hpp
// Conteudo     : arquivo de cabecalho para indexador de termos.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef INDEXADOR_DOCUMENTOS
#define INDEXADOR_DOCUMENTOS

#include <string>
#include "stopwords_set.hpp"
#include "indice_termos.hpp"

class Indexador
{
public:
    Indexador();
    Indice_Termos cria_indice(std::string corpus_path, std::string stopwords_path);

private:
    Stopwords_Set pega_stopwords();
};

#endif