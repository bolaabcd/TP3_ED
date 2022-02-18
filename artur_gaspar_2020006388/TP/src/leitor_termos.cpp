//---------------------------------------------------------------------
// Arquivo      : leitor_termos.hpp
// Conteudo     : arquivo de implementacao para leitor de termos.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "leitor_termos.hpp"
#include "string_set.hpp"
#include <string>

Leitor_Termos::Leitor_Termos(std::string cam_arquivo, String_Set *proibidos)
{
    this->arq = std::ifstream(cam_arquivo);
    this->proibidos = proibidos;
}
std::string Leitor_Termos::ler()
{
    std::string ans;

    // Ignora caracteres invalidos
    while (this->arq.good())
    {
        char next = this->arq.peek();
        if (this->char_ruim(next))
            this->arq.get();
        else
            break;
    }

    while (this->arq.good())
    {
        char next = this->arq.peek();
        if (this->char_ruim(next))
            break;
        else
            ans.push_back(this->arq.get());
    }

    this->to_lowercase(ans);
    return ans;
}
bool Leitor_Termos::ok()
{
    return this->arq.good();
}

bool Leitor_Termos::char_ruim(char c)
{
    if (
        c == ',' ||
        c == '.' ||
        c == ';' ||
        c == ':' ||
        c == '?' ||
        c == '!' ||
        c == '(' ||
        c == ')' ||
        c == '[' ||
        c == ']' ||
        c == '{' ||
        c == '}' ||
        c == '=' ||
        c == '-' ||
        c == '+' ||
        c == '_' ||
        c == "'"[0] ||
        c == '"' ||
        c == '@' ||
        c == '#' ||
        c == '$' ||
        c == '%' ||
        c == '&' ||
        c == '|' ||
        c == '\\' ||
        c == '/' ||
        c == 'º' ||
        c == '°' ||
        c == 'ª' ||
        c == '<' ||
        c == '>' ||
        c == '~' ||
        c == '*' ||
        c == '^' ||
        c == ' ' ||
        c == '   ' ||
        c == '\n' ||
        c == '\r')
        return true;
    else
        return false;
}

void Leitor_Termos::to_lowercase(std::string &palavra)
{
    for (int i = 0; i < palavra.length(); i++)
        if (palavra[i] >= 'A' && palavra[i] <= 'Z')
            palavra[i] = palavra[i] - 'A' + 'a';
}
