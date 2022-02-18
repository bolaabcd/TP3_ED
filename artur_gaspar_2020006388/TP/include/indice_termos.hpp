//---------------------------------------------------------------------
// Arquivo      : indice_termos.hpp
// Conteudo     : arquivo de cabecalho para indice de termos.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef INDICE_TERMOS
#define INDICE_TERMOS

#include <string>
#include <fstream>
#include "string_hasher.hpp"
#include "lista_id_freqs.hpp"

class Indice_Termos
{
public:
    Indice_Termos(String_Hasher hasher, int tamanho_inicial);
    Lista_ID_Freqs get_lista_id_freqs(std::string termo);
    void add_documento(std::ifstream documento);
};

#endif