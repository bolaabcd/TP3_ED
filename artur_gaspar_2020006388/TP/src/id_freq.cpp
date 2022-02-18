//---------------------------------------------------------------------
// Arquivo      : id_freq.cpp
// Conteudo     : arquivo de implementacao para par ID-Frequencia de aparicao.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "id_freq.hpp"

ID_Freq::ID_Freq(int id, int freq) : id(id), freq(freq){};

ID_Freq::ID_Freq() {}

bool ID_Freq::operator<(ID_Freq &outro)
{
    if (this->freq == outro.freq)
        return this->id < outro.id;
    else
        return this->freq < outro.freq;
}