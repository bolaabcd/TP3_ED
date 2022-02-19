//---------------------------------------------------------------------
// Arquivo      : processador_consultas.hpp
// Conteudo     : arquivo de cabecalho para processador de consultas.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef PROCESSADOR_DE_CONSULTAS
#define PROCESSADOR_DE_CONSULTAS

#include "ranking_documentos.hpp"
#include "indice_termos.hpp"
#include "string_set.hpp"
#include "doc_data.hpp"
#include <string>

class Processador_Consultas
{
public:
    Processador_Consultas();
    void consultar(
        Indice_Termos &indice,
        std::string arq_consulta,
        String_Set &stopw,
        Doc_Data &doc_data,
        Ranking_Documentos &rank);
};

#endif