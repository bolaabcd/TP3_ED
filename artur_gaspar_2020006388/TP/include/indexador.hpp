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
    void cria_indice(
        std::string corpus_path,
        std::string stopwords_path,
        Indice_Termos &indice);

private:
    void pega_stopwords(std::string stopwords_path, Stopwords_Set &ans);
    void limpa_pontuacao(std::string &palavra);
    void to_lowercase(std::string &palavra);
};

#endif