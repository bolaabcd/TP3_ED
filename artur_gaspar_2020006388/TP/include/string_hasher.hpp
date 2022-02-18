//---------------------------------------------------------------------
// Arquivo      : string_hasher.hpp
// Conteudo     : arquivo de cabecalho para hasher de string.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef HASHER_DE_STRING
#define HASHER_DE_STRING

#include <string>

class String_Hasher
{
public:
    String_Hasher();
    int get_hash(std::string string, int tamanho);

private:
    const int primo_alfabeto = 31;
    int modpow(int a, int b, int mod);
};

#endif