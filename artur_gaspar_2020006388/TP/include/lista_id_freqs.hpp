//---------------------------------------------------------------------
// Arquivo      : lista_id_freqs.hpp
// Conteudo     : arquivo de cabecalho para lista de ID_Freqs (id+frequencia).
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef LISTA_ID_FREQS
#define LISTA_ID_FREQS

#include "id_freq.hpp"
#include "indice_termos.hpp"

class ID_Freq_Node
{
public:
    ID_Freq_Node(ID_Freq id_freq);
    ID_Freq id_freq;
    ID_Freq_Node *proximo;
    ~ID_Freq_Node();
};

class Lista_ID_Freqs
{
public:
    Lista_ID_Freqs();
    ID_Freq_Node *get_front();
    void add(ID_Freq id_freq);
    void ordena();
    int get_freq(int id);
    int size();
    ~Lista_ID_Freqs();

private:
    ID_Freq_Node *no_frontal;
    int tamanho;
    void quicksort_interno(int l, int r, ID_Freq *lista);
};

#endif