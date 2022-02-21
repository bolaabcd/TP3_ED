//---------------------------------------------------------------------
// Arquivo      : lista_lista_id_freqs.cpp
// Conteudo     : arquivo de implementacao para lista de lista de ID_Freqs (id+frequencia).
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "lista_lista_id_freqs.hpp"

Lista_ID_Freqs_Node::Lista_ID_Freqs_Node() : proximo(nullptr) {}

Lista_ID_Freqs_Node::~Lista_ID_Freqs_Node()
{
    if (this->proximo != nullptr)
    {
        delete this->proximo;
    }
}

Lista_Lista_ID_Freqs::Lista_Lista_ID_Freqs()
{
    this->tamanho = 0;
    this->no_frontal = nullptr;
}

Lista_ID_Freqs *Lista_Lista_ID_Freqs::get_certo(std::string termo)
{
    Lista_ID_Freqs_Node *ifn = this->no_frontal;
    if (ifn == nullptr)
    {
        return nullptr;
    }
    else
    {
        while (ifn->proximo != nullptr && ifn->termo_associado != termo)
        {
            ifn = ifn->proximo;
        }
        if (ifn->termo_associado == termo)
            return &ifn->lista_id_freq;
        else
            return nullptr;
    }
}

void Lista_Lista_ID_Freqs::add_certo(std::string termo, int iddoc)
{
    Lista_ID_Freqs_Node *ifn = this->no_frontal;
    ID_Freq val(iddoc, 1);
    if (ifn == nullptr)
    {
        ifn = new Lista_ID_Freqs_Node();
        ifn->termo_associado = termo;
        ifn->lista_id_freq.add(val);
        this->no_frontal = ifn;
    }
    else
    {
        while (ifn->proximo != nullptr && ifn->termo_associado != termo)
            ifn = ifn->proximo;
        if (ifn->termo_associado == termo)
        {
            ifn->lista_id_freq.add(val);
            this->tamanho--;
        }
        else
        {
            ifn->proximo = new Lista_ID_Freqs_Node();
            ifn->proximo->termo_associado = termo;
            ifn->proximo->lista_id_freq.add(val);
        }
    }
    this->tamanho++;
}

int Lista_Lista_ID_Freqs::get_tamanho()
{
    return this->tamanho;
}

Lista_Lista_ID_Freqs::~Lista_Lista_ID_Freqs()
{
    if (this->no_frontal != nullptr)
    {
        delete this->no_frontal;
    }
}