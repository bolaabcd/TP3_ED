//---------------------------------------------------------------------
// Arquivo      : string_set.cpp
// Conteudo     : arquivo de implementacao para set de stopwords.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "string_set.hpp"
#include "msgassert.hpp"
#include <string>

String_No::String_No(std::string stri)
{
    this->str = stri;
    this->esq = nullptr;
    this->dir = nullptr;
}

String_No::~String_No()
{
    if (this->esq != nullptr)
    {
        delete this->esq;
        this->esq = nullptr;
    }
    if (this->dir != nullptr)
    {
        delete this->dir;
        this->dir = nullptr;
    }
}

String_Set::String_Set()
{
    this->raiz = nullptr;
    this->tamanho = 0;
}

void String_Set::add(std::string str)
{
    this->add_auxiliar(&(this->raiz), str);
}

void String_Set::add_auxiliar(String_No **raiz_atual, std::string str)
{
    if (*raiz_atual == nullptr)
    {
        *raiz_atual = new String_No(str);
        this->tamanho++;
    }
    else
    {
        if ((*raiz_atual)->str < str)
        {
            add_auxiliar(&((*raiz_atual)->dir), str);
        }
        else if ((*raiz_atual)->str > str)
        {
            add_auxiliar(&((*raiz_atual)->esq), str);
        }
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
    else if ((*raiz_atual)->str == str)
        return true;
    else
    {
        if ((*raiz_atual)->str < str)
            return is_in_auxiliar(&((*raiz_atual)->dir), str);
        else if ((*raiz_atual)->str > str)
            return is_in_auxiliar(&((*raiz_atual)->esq), str);
    }
    erroAssert(false, "Estado invalido atingido");
    return false;
}

int String_Set::size()
{
    return this->tamanho;
}

String_Set::~String_Set()
{
    if (this->raiz != nullptr)
    {
        delete this->raiz;
        this->raiz = nullptr;
    }
}