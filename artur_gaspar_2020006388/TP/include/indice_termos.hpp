//---------------------------------------------------------------------
// Arquivo      : indice_termos.hpp
// Conteudo     : arquivo de cabecalho para indice de termos.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef INDICE_TERMOS
#define INDICE_TERMOS

#include <string>
#include "string_hasher.hpp"
#include "lista_id_freqs.hpp"
#include "lista_lista_id_freqs.hpp"
#include "string_set.hpp"

class Indice_Termos
{
public:
    Indice_Termos(String_Hasher hasher, int tamanho_inicial);
    Lista_ID_Freqs *get_lista_id_freqs(std::string termo);
    void ordena_tudo();
    void add_documento(
        std::string corpus,
        std::string documento,
        String_Set &stopw);
    int getiddoc(std::string nome);
    ~Indice_Termos();

private:
    String_Hasher hasher;
    Lista_Lista_ID_Freqs *mapa;
    int *tamanhos_primos_validos;
    int tamanho_atual;
    int get_next_tamanho(int tam);
    void make_primos();
};

#endif