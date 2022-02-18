//---------------------------------------------------------------------
// Arquivo      : processador_consultas.hpp
// Conteudo     : arquivo de cabecalho para processador de consultas.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------


#ifndef PROCESSADOR_DE_CONSULTAS
#define PROCESSADOR_DE_CONSULTAS

#include "ranking_documentos.hpp"
#include <string>

class Processador_Consultas
{
public:
    Processador_Consultas();
    Ranking_Documentos consultar(Indice_Termos& indice,std::string arq_consulta, int num_posicoes);
};

#endif