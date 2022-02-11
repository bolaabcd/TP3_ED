//---------------------------------------------------------------------
// Arquivo      : indexador.hpp
// Conteudo     : arquivo de cabeçalho para indexador de termos.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef INDEXADOR_DOCUMENTOS
#define INDEXADOR_DOCUMENTOS

#include <fstream>
#include "stopwords_set.hpp"
#include "indice_termos.hpp"

class Indexador
{
public:
    Indexador(Stopwords_Set stopwords);
    Indice_Termos cria_indice(std::ifstream corpus);
};

#endif