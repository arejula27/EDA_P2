#include "coleccion.h"
int main(int argc, const char** argv) {

    int dat, num;
    coleccion<int, int> c;
    crear(c);
introducir(c, 2, 1, 1);
introducir(c, 3, 1, 1);

eliminar(c, 2);
    numClaves(c, num);

existe(c, 2);
existe(c, 3);

    return 0;
}