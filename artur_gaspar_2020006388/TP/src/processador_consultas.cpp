//---------------------------------------------------------------------
// Arquivo      : processador_consultas.cpp
// Conteudo     : arquivo de implementacao para processador de consultas.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "processador_consultas.hpp"
#include "ranking_documentos.hpp"
#include "indice_termos.hpp"
#include "leitor_termos.hpp"
#include <string>
#include <cmath>

Processador_Consultas::Processador_Consultas() {}

void Processador_Consultas::consultar(
    Indice_Termos &indice,
    std::string arq_consulta,
    String_Set &stopw,
    Doc_Data &doc_data,
    Ranking_Documentos &rank)
{
    for (int j = 0; j < doc_data.size(); j++)
    {
        rank.set_id(j, doc_data.get_id(j));
        rank.set_val(j, 0);
    }
    Leitor_Termos lei(arq_consulta, &stopw);
    while (1)
    {
        std::string termo = lei.ler();
        if (!lei.ok() || lei.eof())
            break;
        Lista_ID_Freqs *lista = indice.get_lista_id_freqs(termo);
        if (lista == nullptr)
            continue;
        double idf = log(((double)doc_data.size()) / (lista->size()));

        for (int j = 0; j < doc_data.size(); j++)
        {
            double ftd = lista->get_freq(doc_data.get_id(j));
            double wij = ftd * idf;
            double wiq = 1;
            rank.set_val(j, rank.get_val(j) + wij * wiq);
        }
    }
    for (int j = 0; j < doc_data.size(); j++)
    {
        rank.set_val(j, rank.get_val(j) / doc_data.get_Wd(j));
    }
    rank.ordena();
}