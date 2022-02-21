//---------------------------------------------------------------------
// Arquivo      : lista_id_freqs.cpp
// Conteudo     : arquivo de implementacao para lista de ID_Freqs (id+frequencia).
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "lista_id_freqs.hpp"
#include "msgassert.hpp"
#include "memlog.hpp"

ID_Freq_Node::ID_Freq_Node(ID_Freq ifr) : id_freq(ifr), proximo(nullptr) 
// Descricao: inicializa um noh de ID_Freq.
// Entrada: ID_Freq do noh.
// Saida: objeto instanciado.
{}

ID_Freq_Node::~ID_Freq_Node()
// Descricao: destrutor padrao do tipo, limpa a memoria alocada recursivamente.
// Entrada: nada.
// Saida: nada.
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
// Descricao: inicializa uma lista de ID_Freqs.
// Entrada: nada.
// Saida: objeto inicializado.
{
    this->tamanho = 0;
    this->no_frontal = nullptr;
}

ID_Freq_Node *Lista_ID_Freqs::get_front()
// Descricao: indica como chegar no primeiro noh da lista.
// Entrada: nada.
// Saida: ponteiro para o primeiro no da lista.
{
    return this->no_frontal;
}

int Lista_ID_Freqs::get_freq(int id)
// Descricao: retorna a frequencia salva no noh com id especificado.
// Entrada: id usado pra achar a frequencia.
// Saida: frequencia associada, 0 se nao esta presente.
{
    erroAssert(id >= 0, "IDs de arquivo negativos nao sao permitidos.");

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
// Descricao: adiciona a frequencia passada como argumento no id passado como argumento, ou o cria se nao existia ainda.
// Entrada: id e frequencia, na forma de ID_Freq.
// Saida: nada.
{
    erroAssert(id_freq.id >= 0 && id_freq.freq >= 0, "IDs e frequencias nao podem ser negativos.");

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
// Descricao: informa o tamanho da lista.
// Entrada: nada.
// Saida: quantidade de nos atualmente na lista.
{
    return this->tamanho;
}

Lista_ID_Freqs::~Lista_ID_Freqs()
// Descricao: destrutor padrao da lista de ID_Freqs.
// Entrada: nada.
// Saida: nada.
{
    if (this->no_frontal != nullptr)
    {
        delete this->no_frontal;
        this->no_frontal = nullptr;
    }
}