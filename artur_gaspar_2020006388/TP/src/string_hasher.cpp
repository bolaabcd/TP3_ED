//---------------------------------------------------------------------
// Arquivo      : string_hasher.cpp
// Conteudo     : arquivo de implementacao para hasher de string.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "string_hasher.hpp"
#include "msgassert.hpp"

String_Hasher::String_Hasher()
// Descricao: inicializa com o valor do primo adequado para o alfabeto em questao.
// Entrada: nada.
// Saida: objeto inicializado.
{
    this->primo_alfabeto = 31;
}

int String_Hasher::get_hash(std::string str, int tamanho)
// Descricao: informa o hash da string.
// Entrada: hash e tamanho da hashtable em que a string sera encaixada.
// Saida: posicao da string na hashtable.
{
    long long ans = 0;

    for (int i = 0; i < (int)str.length(); i++)
    {
        ans = ((long long)ans +
               (long long)(str[i] - 'a') *
                   (long long)this->modpow(this->primo_alfabeto, i, tamanho)) %
              (long long)tamanho;
        erroAssert(ans <= INT32_MAX && ans >= 0, "Limite de inteiro alcancado!");
    }

    return ans;
}

int String_Hasher::modpow(int a, int b, int m)
// Descricao: calcula pow(a,b)%b em O(log(b)).
// Entrada: a, b e m.
// Saida: valor resultante da operacao.
{
    long long ans = 1, r = a, s = b, mod = m;
    r = r % mod;
    while (s > 0)
    {
        if (s & 1)
            ans = (ans * r) % mod;
        s = s >> 1;
        r *= r;
        r = r % mod;
        erroAssert(ans <= INT32_MAX, "Limite de inteiro alcancado!");
    }
    return ans;
}