#pragma once

#include "definicoes.h"

#define KASSERCOES_ATIVAS

#ifdef KASSERCOES_ATIVAS
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __builtin_trap()
#endif

KAPI void reportar_assercao_falha(const char* expressao, const char* mensagem, const char* arquivo, i32 linha);

#define KASSERCAO(expressao)                                            \
{                                                                       \
    if(expressao){                                                      \
    } else{                                                             \
        reportar_assercao_falha(#expressao, "", __FILE__, __LINE__);    \
        debugBreak();                                                   \
    }                                                                   \
                                                                        \
}                                                                       \

#define KASSERCAO_MENSAGEM(expressao, mensagem)                             \
{                                                                           \
    if(expressao){                                                          \
    } else{                                                                 \
        reportar_assercao_falha(#expressao, mensagem, __FILE__, __LINE__);  \
        debugBreak();                                                       \
    }                                                                       \
                                                                            \
}                                                                           \

#ifdef DEBUG
#define KASSERCAO_DEBUG(expressao)                                      \
{                                                                       \
    if(expressao){                                                      \
    } else{                                                             \
        reportar_assercao_falha(#expressao, "", __FILE__, __LINE__);    \
        debugBreak();                                                   \
    }                                                                   \
                                                                        \
}                                                                       \
#else
#define KASSERCAO_DEBUG(expressao)
#endif
#else
#define KASSERCAO(expressao)
#define KASSERCAO_MENSAGEM(expressao)
#define KASSERCAO_DEBUG(expressao)
#endif