//---------------------------------------------------------------------
// Arquivo      : lista_lista_id_freqs.hpp
// Conteudo     : arquivo de cabecalho para lista de lista de ID_Freqs (id+frequencia).
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef LISTA_LISTA_ID_FREQS
#define LISTA_LISTA_ID_FREQS

#include <string>
#include "lista_id_freqs.hpp"

class Lista_ID_Freqs_Node
{
public:
    Lista_ID_Freqs_Node();
    std::string termo_associado;
    Lista_ID_Freqs lista_id_freq;
    Lista_ID_Freqs_Node *proximo;
    ~Lista_ID_Freqs_Node();
};

class Lista_Lista_ID_Freqs
{
public:
    Lista_Lista_ID_Freqs();
    Lista_ID_Freqs *get_certo(std::string termo);
    void add_certo(std::string termo, int iddoc);
    ~Lista_Lista_ID_Freqs();

private:
    Lista_ID_Freqs_Node *no_frontal;
    int tamanho;
};

#endif