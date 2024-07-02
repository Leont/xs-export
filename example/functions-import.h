#include "xs-export.h"

#define SYMBOL(...) SYMBOL_DECLARE(__VA_ARGS__)
#include "functions.inc"
#undef SYMBOL

void install_functions(pTHX) {
#define SYMBOL(...) SYMBOL_IMPORT(__VA_ARGS__)
#include "functions.inc"
#undef SYMBOL
}
