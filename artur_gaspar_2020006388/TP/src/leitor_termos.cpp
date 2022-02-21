//---------------------------------------------------------------------
// Arquivo      : leitor_termos.hpp
// Conteudo     : arquivo de implementacao para leitor de termos.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "leitor_termos.hpp"
#include "string_set.hpp"
#include <string>

Leitor_Termos::Leitor_Termos(std::string cam_arquivo, String_Set *proib)
// Descricao: inicializa um leitor de termos.
// Entrada: caminho do arquivo do qual vamos ler e apontador prum conjunto de palavras proibidas.
// Saida: objeto instanciado.
{
    this->arq = std::ifstream(cam_arquivo);
    this->proibidos = proib;
}
std::string Leitor_Termos::ler()
{
    while (this->arq.good())
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
        if (!proibidos->is_in(ans))
            return ans;
    }
    return "";
}
bool Leitor_Termos::ok()
// Descricao: informa se a stream de leitura esta ok.
// Entrada: nada.
// Saida: true se esta, false se nao esta.
{
    return this->arq.good();
}

bool Leitor_Termos::eof()
// Descricao: informa se o fim do arquivo foi atingido.
// Entrada: nada.
// Saida: true se o fim do arquivo foi atingido, false caso contrario.
{
    return this->arq.eof();
}

bool Leitor_Termos::char_ruim(char c)
// Descricao: informa se o caractere passado eh valido.
// Entrada: caractere a avaliar.
// Saida: true se o caractere eh valido, false se nao eh.
{
    if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
        return true;
    else
        return false;
}

void Leitor_Termos::to_lowercase(std::string &palavra)
// Descricao: faz a palavra passada ser de letras minusculas.
// Entrada: palavra.
// Saida: muda a palavra pra ter letras minusculas.
{
    for (int i = 0; i < (int)palavra.length(); i++)
        if (palavra[i] >= 'A' && palavra[i] <= 'Z')
            palavra[i] = palavra[i] - 'A' + 'a';
}

Leitor_Termos::~Leitor_Termos()
// Descricao: destrutor padrao do leitor de termos, que basicamente fecha o arquivo aberto no construtor.
// Entrada: nada.
// Saida: nada.
{
    this->arq.close();
    // nao deleta o ponteiro para proibidos porque nao foi criado aqui.
}