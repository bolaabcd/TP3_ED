//---------------------------------------------------------------------
// Arquivo      : id_freq.cpp
// Conteudo     : arquivo de implementacao para par ID-Frequencia de aparicao.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "id_freq.hpp"
#include "msgassert.hpp"

ID_Freq::ID_Freq(int ID, int fr) : id(ID), freq(fr)
// Descricao: inicializa um ID_Freq com os valores passados.
// Entrada: ID e frequencia.
// Saida: objeto inicializado.
{
    erroAssert(ID >= 0, "IDs negativos nao sao aceitos.");
    erroAssert(fr >= 0, "Frequencias negativas nao sao aceitas");
};

ID_Freq::ID_Freq() 
// Descricao: inicializa um ID_Freq vazio.
// Entrada: nada.
// Saida: objeto inicializado.
{}

bool ID_Freq::operator<(ID_Freq &outro)
// Descricao: compara dois ID_Freq.
// Entrada: outro objeto a comparar com esse.
// Saida: true se o atual eh menor, false caso contrario.
{
    if (this->freq == outro.freq)
        return this->id < outro.id;
    else
        return this->freq < outro.freq;
}