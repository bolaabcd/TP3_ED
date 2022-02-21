//---------------------------------------------------------------------
// Arquivo      : indexador.hpp
// Conteudo     : arquivo de cabecalho para indexador de termos.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef INDEXADOR_DOCUMENTOS
#define INDEXADOR_DOCUMENTOS

#include <string>
#include "string_set.hpp"
#include "indice_termos.hpp"
#include "doc_data.hpp"

class Indexador
{
public:
    Indexador(std::string corpus_path, std::string stopwords_path);
    void cria_indice(Indice_Termos &indice);
    void cria_doc_data(Doc_Data &doc_data, Indice_Termos &indice);
    int quantos_termos();
    int quantos_docs();
    String_Set &get_stopw();

private:
    int ndocs;
    std::string stopwords;
    std::string corpus;
    String_Set termos;
    String_Set stopw;
    void arq_pra_set(std::string caminho, String_Set &ans, String_Set &proibidos);
};

#endif