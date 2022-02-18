//---------------------------------------------------------------------
// Arquivo      : string_set.hpp
// Conteudo     : arquivo de cabecalho para set de strings.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef CONJUNTO_DE_STRINGS
#define CONJUNTO_DE_STRINGS

#include <string>

class String_No
{
public:
    String_No(std::string str);
    std::string str;
    String_No *esq;
    String_No *dir;
    ~String_No();
};

// Implementado como arvore binaria
class String_Set
{
public:
    String_Set();
    void add(std::string str);
    void add_auxiliar(String_No **raiz_atual, std::string);
    bool is_in(std::string str);
    bool is_in_auxiliar(String_No **raiz_atual, std::string str);
    int size();
    ~String_Set();

private:
    String_No *raiz;
    int tamanho;
};

#endif