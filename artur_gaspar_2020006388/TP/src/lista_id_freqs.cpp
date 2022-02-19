//---------------------------------------------------------------------
// Arquivo      : lista_id_freqs.cpp
// Conteudo     : arquivo de implementacao para lista de ID_Freqs (id+frequencia).
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "lista_id_freqs.hpp"
#include "msgassert.hpp"
#include "memlog.hpp"

ID_Freq_Node::ID_Freq_Node(ID_Freq ifr) : id_freq(ifr), proximo(nullptr) {}

ID_Freq_Node::~ID_Freq_Node()
{
    if (this->proximo == nullptr)
        return;
    else
    {
        delete this->proximo;
        this->proximo = nullptr;
    }
}

Lista_ID_Freqs::Lista_ID_Freqs()
{
    this->tamanho = 0;
    this->no_frontal = nullptr;
}

ID_Freq_Node *Lista_ID_Freqs::get_front()
{
    return this->no_frontal;
}

int Lista_ID_Freqs::get_freq(int id)
{
    ID_Freq_Node *ifn = this->no_frontal;
    if (ifn == nullptr)
    {
        return 0;
    }
    else
    {
        while (ifn->proximo != nullptr && ifn->id_freq.id != id)
            ifn = ifn->proximo;

        if (ifn->id_freq.id == id)
        {
            return ifn->id_freq.freq;
        }
        else
            return 0;
    }
    this->tamanho++;
}

void Lista_ID_Freqs::add(ID_Freq id_freq)
{
    ID_Freq_Node *ifn = this->no_frontal;
    if (ifn == nullptr)
    {
        this->no_frontal = new ID_Freq_Node(id_freq);
    }
    else
    {
        while (ifn->proximo != nullptr && ifn->id_freq.id != id_freq.id)
            ifn = ifn->proximo;

        if (ifn->id_freq.id == id_freq.id)
        {
            ifn->id_freq.freq += id_freq.freq;
            this->tamanho--;
        }
        else
            ifn->proximo = new ID_Freq_Node(id_freq);
    }
    this->tamanho++;
}

int Lista_ID_Freqs::size()
{
    return this->tamanho;
}

Lista_ID_Freqs::~Lista_ID_Freqs()
{
    if (this->no_frontal != nullptr)
    {
        delete this->no_frontal;
        this->no_frontal = nullptr;
    }
}