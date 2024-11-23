#include <core/logger.h>
#include <core/assert.h>

int main(void){
    KFATAL("teste fatal");
    KERRO("teste erro");
    KALERTA("teste alerta");
    KINFORMACAO("teste informacao");
    KTRACO("teste traco");

    KASSERCAO(1 == 0);
    return 0;
}