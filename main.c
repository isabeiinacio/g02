#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "dados.h"
#include "logica.h"

int main() {

    ESTADO *e = inicializar_estado();

    interpretador(e);

    return 0;
}