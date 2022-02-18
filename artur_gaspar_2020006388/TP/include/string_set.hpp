//---------------------------------------------------------------------
// Arquivo      : string_set.hpp
// Conteudo     : arquivo de cabecalho para set de stopwords.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef CONJUNTO_DE_STOPWORDS
#define CONJUNTO_DE_STOPWORDS

#include <string>

class String_Set
{
public:
    String_Set();
    void add(std::string stopword);
    void remove(std::string stopword);
    void is_in(std::string stopword);
    int size();
};

#endif