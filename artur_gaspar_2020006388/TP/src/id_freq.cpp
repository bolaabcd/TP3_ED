//---------------------------------------------------------------------
// Arquivo      : id_freq.hpp
// Conteudo     : arquivo de implementacao para par ID-Frequencia de aparicao.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "id_freq.hpp"

ID_Freq::ID_Freq(int id, int freq) : id(id), freq(freq){};

int ID_Freq::get_id()
{
    return this->id;
}

int ID_Freq::get_freq()
{
    return this->freq;
}

bool ID_Freq::operator<(ID_Freq &outro)
{
    if (this->freq == outro.freq)
        return this->id < outro.id;
    else
        return this->freq < outro.freq;
}