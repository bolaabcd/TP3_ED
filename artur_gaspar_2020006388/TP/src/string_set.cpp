//---------------------------------------------------------------------
// Arquivo      : string_set.cpp
// Conteudo     : arquivo de implementacao para set de stopwords.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "string_set.hpp"
#include "msgassert.hpp"
#include <string>

String_No::String_No(std::string stri)
// Descricao: inicializa um no de string.
// Entrada: string do no.
// Saida: objeto inicializado.
{
    this->str = stri;
    this->esq = nullptr;
    this->dir = nullptr;
}

String_No::~String_No()
// Descricao: destrutor padrao do tipo, que limpa a memoria alocada recursivamente.
// Entrada: nada.
// Saida: nada.
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
// Descricao: inicializa um conjunto de strings implementado como arvore binaria nao balanceada.
// Entrada: nada.
// Saida: objeto inicializado.
{
    this->raiz = nullptr;
    this->tamanho = 0;
}

void String_Set::add(std::string str)
// Descricao: adiciona um elemento ao conjunto.
// Entrada: string a adicionar.
// Saida: nada.
{
    this->add_auxiliar(&(this->raiz), str);
}

void String_Set::add_auxiliar(String_No **raiz_atual, std::string str)
// Descricao: funcao auxiliar para adicionar um elemento na subarvore da raiz_atual.
// Entrada: raiz_atual e string a adicionar.
// Saida: nada.
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
// Descricao: informa se a string esta no conjunto.
// Entrada: string a procurar.
// Saida: verdadeiro se ela esta no conjunto, falso caso contrario.
{
    return this->is_in_auxiliar(&(this->raiz), str);
}

bool String_Set::is_in_auxiliar(String_No **raiz_atual, std::string str)
// Descricao: informa se a string esta na subarvore de raiz_atual.
// Entrada: raiz_atual e string a procurar.
// Saida: verdadeiro se a string esta na arvore dessa raiz, falso caso contrario.
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
// Descricao: informa a quantidade de elementos na arvore.
// Entrada: nada.
// Saida: quantidade de elementos na arvore.
{
    return this->tamanho;
}

String_Set::~String_Set()
// Descricao: destrutor padrao do tipo, que inicia uma cadeia de destruicao recursiva.
// Entrada: nada.
// Saida: nada.
{
    if (this->raiz != nullptr)
    {
        delete this->raiz;
        this->raiz = nullptr;
    }
}