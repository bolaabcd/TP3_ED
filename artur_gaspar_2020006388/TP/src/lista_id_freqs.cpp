//---------------------------------------------------------------------
// Arquivo      : lista_id_freqs.cpp
// Conteudo     : arquivo de implementacao para lista de ID_Freqs (id+frequencia).
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "lista_id_freqs.hpp"
#include "msgassert.hpp"
#include "memlog.hpp"

ID_Freq_Node::ID_Freq_Node(ID_Freq id_freq) : id_freq(id_freq), proximo(nullptr) {}

ID_Freq_Node::~ID_Freq_Node()
{
    if (this->proximo == nullptr)
        return;
    else
    {
        this->proximo->~ID_Freq_Node();
        delete this->proximo;
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

void Lista_ID_Freqs::ordena()
{
    ID_Freq copia[this->tamanho];
    int i = 0;

    ID_Freq_Node *ifn = this->no_frontal;
    while (ifn->proximo != nullptr)
    {
        copia[i++] = ifn->id_freq;
        ifn = ifn->proximo;
    }

    this->quicksort_interno(0, this->tamanho - 1, copia);
}

void Lista_ID_Freqs::quicksort_interno(int l, int r, ID_Freq *lista)
{
    if (l >= r)
        return;
    erroAssert(l < r, "Intervalo invalido no quicksort recursivo.");

    int meio = (l + r) / 2;
    int pivo = meio;
    if (lista[l] < lista[r])
    {
        if (lista[meio] < lista[l])
            pivo = l;
        else if (lista[r] < lista[meio])
            pivo = r;
    }
    else
    {
        if (lista[meio] < lista[r])
            pivo = r;
        else if (lista[l] < lista[meio])
            pivo = l;
    }

    ID_Freq aux = lista[pivo];
    leMemLog((long int)&lista[pivo], sizeof(ID_Freq), 0);
    int i, j;
    for (i = l, j = r;;)
    {
        for (; i <= j && aux < lista[i]; i++)
            leMemLog((long int)&lista[i], sizeof(ID_Freq), 1);
        for (; i <= j && lista[j] < aux; j--)
            leMemLog((long int)&lista[j], sizeof(ID_Freq), 1);

        if (i > j)
            break;

        // Trocando elementos
        ID_Freq a = lista[i];
        leMemLog((long int)&lista[i], sizeof(ID_Freq), 0);
        lista[i++] = lista[j];
        leMemLog((long int)&lista[j], sizeof(ID_Freq), 0);
        escreveMemLog((long int)&lista[i - 1], sizeof(ID_Freq), 0);
        lista[j--] = a;
        escreveMemLog((long int)&lista[j + 1], sizeof(ID_Freq), 0);
    }

    quicksort_interno(l, j, lista);
    quicksort_interno(i, r, lista);
}

Lista_ID_Freqs::~Lista_ID_Freqs()
{
    if (this->no_frontal != nullptr)
    {
        this->no_frontal->~ID_Freq_Node();
        delete this->no_frontal;
    }
}