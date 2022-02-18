//---------------------------------------------------------------------
// Arquivo      : leitor_termos.hpp
// Conteudo     : arquivo de cabecalho para leitor de termos.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef LEITOR_DE_TERMOS
#define LEITOR_DE_TERMOS

#include <string>
#include <fstream>
#include <iostream>

class Leitor_Termos
{
public:
    Leitor_Termos(std::string cam_arquivo, String_Set* proibidos);
    std::string ler();
    bool ok();
private:
    std::ifstream arq;
    String_Set* proibidos;
};

#endif