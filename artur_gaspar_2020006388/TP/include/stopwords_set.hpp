//---------------------------------------------------------------------
// Arquivo      : stopwords_set.hpp
// Conteudo     : arquivo de cabeçalho para set de stopwords.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef CONJUNTO_DE_STOPWORDS
#define CONJUNTO_DE_STOPWORDS

#include <string>

class Stopwords_Set
{
public:
    Stopwords_Set();
    void add(std::string stopword);
    void remove(std::string stopword);
    void is_in(std::string stopword);
};

#endif