//---------------------------------------------------------------------
// Arquivo      : string_set.cpp
// Conteudo     : arquivo de implementacao para set de stopwords.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "string_set.hpp"
#include <string>

String_No::String_No(std::string str)
{
    this->str = str;
    this->esq = nullptr;
    this->dir = nullptr;
}

String_No::~String_No()
{
    if (this->esq != nullptr)
    {
        this->esq->~String_No();
        delete this->esq;
    }
    if (this->dir != nullptr)
    {
        this->dir->~String_No();
        delete this->dir;
    }
}

String_Set::String_Set()
{
    raiz = nullptr;
    tamanho = 0;
}

void String_Set::add(std::string str)
{
    this->add_auxiliar(&(this->raiz), str);
}

void String_Set::add_auxiliar(String_No **raiz_atual, std::string str)
{
    if (*raiz_atual == nullptr)
        *raiz_atual = new String_No(str);
    else
    {
        if ((*raiz_atual)->str < str)
            add_auxiliar(&((*raiz_atual)->dir), str);
        else if ((*raiz_atual)->str > str)
            add_auxiliar(&((*raiz_atual)->esq), str);
    }
}

bool String_Set::is_in(std::string str)
{
    return this->is_in_auxiliar(&(this->raiz), str);
}

bool String_Set::is_in_auxiliar(String_No **raiz_atual, std::string str)
{
    if (*raiz_atual == nullptr)
        return false;
    else
    {
        if ((*raiz_atual)->str < str)
            return is_in_auxiliar(&((*raiz_atual)->dir), str);
        else if ((*raiz_atual)->str > str)
            return is_in_auxiliar(&((*raiz_atual)->esq), str);
    }
}

int String_Set::size()
{
    return this->tamanho;
}

String_Set::~String_Set()
{
    if (this->raiz != nullptr)
    {
        this->raiz->~String_No();
        delete this->raiz;
    }
}