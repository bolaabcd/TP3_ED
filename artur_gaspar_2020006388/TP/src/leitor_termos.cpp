//---------------------------------------------------------------------
// Arquivo      : leitor_termos.hpp
// Conteudo     : arquivo de implementacao para leitor de termos.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------
void Indice_Termos::limpa_pontuacao(std::string &palavra)
{
    for (int i = 0; i < palavra.length(); i++)
        if (
            palavra[i] == ',' ||
            palavra[i] == '.' ||
            palavra[i] == ';' ||
            palavra[i] == ':' ||
            palavra[i] == '?' ||
            palavra[i] == '!' ||
            palavra[i] == '(' ||
            palavra[i] == ')' ||
            palavra[i] == '[' ||
            palavra[i] == ']' ||
            palavra[i] == '{' ||
            palavra[i] == '}' ||
            palavra[i] == '=' ||
            palavra[i] == '-' ||
            palavra[i] == '+' ||
            palavra[i] == '_' ||
            palavra[i] == "'"[0] ||
            palavra[i] == '"' ||
            palavra[i] == '@' ||
            palavra[i] == '#' ||
            palavra[i] == '$' ||
            palavra[i] == '%' ||
            palavra[i] == '&' ||
            palavra[i] == '|' ||
            palavra[i] == '\\' ||
            palavra[i] == '/' ||
            palavra[i] == 'º' ||
            palavra[i] == '°' ||
            palavra[i] == 'ª' ||
            palavra[i] == '<' ||
            palavra[i] == '>' ||
            palavra[i] == '~' ||
            palavra[i] == '*' ||
            palavra[i] == '^')
            palavra[i] = ' ';
}

void Indice_Termos::to_lowercase(std::string &palavra)
{
    for (int i = 0; i < palavra.length(); i++)
        if (palavra[i] >= 'A' && palavra[i] <= 'Z')
            palavra[i] = palavra[i] - 'A' + 'a';
}
