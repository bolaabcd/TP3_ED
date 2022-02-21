//---------------------------------------------------------------------
// Arquivo      : string_hasher.cpp
// Conteudo     : arquivo de implementacao para hasher de string.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "string_hasher.hpp"
#include "msgassert.hpp"

String_Hasher::String_Hasher()
{
    this->primo_alfabeto = 31;
}

int String_Hasher::get_hash(std::string str, int tamanho)
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

// Exponenciacao rapida
int String_Hasher::modpow(int a, int b, int m)
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