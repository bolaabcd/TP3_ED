//---------------------------------------------------------------------
// Arquivo      : lista_lista_id_freqs.cpp
// Conteudo     : arquivo de implementacao para lista de lista de ID_Freqs (id+frequencia).
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "lista_lista_id_freqs.hpp"

Lista_ID_Freqs_Node::Lista_ID_Freqs_Node() : proximo(nullptr) 
// Descricao: inicializa um no de lista de ID_Freqs.
// Entrada: nada.
// Saida: objeto inicializado.
{}

Lista_ID_Freqs_Node::~Lista_ID_Freqs_Node()
// Descricao: destrutor padrao do tipo, que limpa a memoria alocada recursivamente.
// Entrada: nada.
// Saida: nada.
{
    if (this->proximo != nullptr)
    {
        delete this->proximo;
    }
}

Lista_Lista_ID_Freqs::Lista_Lista_ID_Freqs()
// Descricao: inicializa uma lista de lista de ID_Freqs (usado para tratamento de colisao).
// Entrada: nada.
// Saida: objeto inicializado.
{
    this->tamanho = 0;
    this->no_frontal = nullptr;
}

Lista_ID_Freqs *Lista_Lista_ID_Freqs::get_certo(std::string termo)
// Descricao: aponta para onde esta a lista correspondente ao termo, efetivamente tratando colisoes do hash.
// Entrada: termo associado a lista retornada.
// Saida: apontador para a lista de ID_Freqs adequada.
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
// Descricao: adiciona um na frequencia de aparicao do termo no documento de id iddoc.
// Entrada: termo associado e id do documento.
// Saida: nada.
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
// Descricao: informa a quantidade de listas presente.
// Entrada: nada.
// Saida: quantidade de listas presentes, efetivamente o numero de listas colidintes jah que se nao houvesse colisao teriamos tamanho=1.
{
    return this->tamanho;
}

Lista_Lista_ID_Freqs::~Lista_Lista_ID_Freqs()
// Descricao: destrutor padrao do tipo, que inicializa liberacao de memoria recursiva.
// Entrada: nada.
// Saida: nada.
{
    if (this->no_frontal != nullptr)
    {
        delete this->no_frontal;
    }
}