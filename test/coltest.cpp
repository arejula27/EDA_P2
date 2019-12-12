#include <iostream>
#include "coleccion.h"
#include <gtest/gtest.h>
using namespace std;

/*****
 * Prueba                    Demuestra
 * EXPECT_EQ(int val1, int val2);	val1 == val2
 * EXPECT_NE(int val1, int val2);   val1 != val2
 * EXPECT_LT(int val1, int val2);	val1 < val2
 * EXPECT_LE(int val1, int val2);	val1 <= val2
 * EXPECT_GT(int val1, int val2);	val1 > val2
 * EXPECT_GE(int val1, int val2);	val1 >= val2
 * 
 * EXPECT_TRUE(bool val1 )          true
 * EXPECT_FALSE(bool val1)          false
 * 
 * EXPECT_NO_FATAL_FAILURE() lo ejecuta y mira que finaliza 
 * 
 * EXPECT_STREQ(str1,str2);	dos strings son iguales
 * EXPECT_STRNE(str1,str2);	dos strings son distintos
 * EXPECT_STRCASEEQ(str1,str2);	dos strings son iguales, da igual mayusculas y minusculas
 * EXPECT_STRCASENE(str1,str2);	dos strings son distintos, da igual mayusculas y minusculas
 * 
 *****/

//creo el dato de tipo pila
 

//Creo un test con titulo,subtitulo
TEST(Coleccion, crear)
{
    coleccion<int, int> c;
    EXPECT_NO_FATAL_FAILURE(crear(c););
    EXPECT_FALSE(existe(c, 1));
    EXPECT_NO_FATAL_FAILURE(quitarRep(c,1));
    int val;
    numCardinal(c,val);
    EXPECT_EQ(0,val);
    numClaves(c,val);
    EXPECT_EQ(0, val);
}

TEST(Introducir, positivos)
{
    int dat,num;
    coleccion<int, int> c;
    EXPECT_NO_FATAL_FAILURE(crear(c););
    EXPECT_NO_FATAL_FAILURE(introducir(c,1,1,1));
    EXPECT_TRUE(existe(c,1));
    EXPECT_NO_FATAL_FAILURE(agnadirRep(c,1));
    obtenerInfo(c,1,dat,num);
    EXPECT_EQ(2,num);
    numClaves(c,num);
    EXPECT_EQ(1,num);
    numCardinal(c,num);
    EXPECT_EQ(2, num);

    EXPECT_NO_FATAL_FAILURE(introducir(c, 2, 1, 1));
    EXPECT_TRUE(existe(c, 1));
    EXPECT_TRUE(existe(c, 2));
    EXPECT_NO_FATAL_FAILURE(agnadirRep(c, 2));
    obtenerInfo(c, 2, dat, num);
    EXPECT_EQ(2, num);
    numClaves(c, num);
    EXPECT_EQ(2, num);
    numCardinal(c, num);
    EXPECT_EQ(4, num);

    EXPECT_NO_FATAL_FAILURE(introducir(c, 3, 1, 1));
    EXPECT_TRUE(existe(c, 1));
    EXPECT_TRUE(existe(c, 2));
    EXPECT_TRUE(existe(c, 3));
    EXPECT_NO_FATAL_FAILURE(agnadirRep(c, 3));
    obtenerInfo(c, 3, dat, num);
    EXPECT_EQ(2, num);
    numClaves(c, num);
    EXPECT_EQ(3, num);
    numCardinal(c, num);
    EXPECT_EQ(6, num);
}

TEST(Introducir, cero)
{
    int  num;
    coleccion<int, int> c;
    EXPECT_NO_FATAL_FAILURE(crear(c););
    EXPECT_NO_FATAL_FAILURE(introducir(c, 0, 1, 1));
    EXPECT_FALSE(existe(c, 0));
    EXPECT_NO_FATAL_FAILURE(agnadirRep(c, 0));
    numClaves(c, num);
    EXPECT_EQ(0, num);
    numCardinal(c, num);
    EXPECT_EQ(0, num);

}

TEST(Introducir, negativos)
{
    int  num;
    coleccion<int, int> c;
    EXPECT_NO_FATAL_FAILURE(crear(c););
    EXPECT_NO_FATAL_FAILURE(introducir(c, -1, 1, 1));
    EXPECT_FALSE(existe(c, 0));
    EXPECT_NO_FATAL_FAILURE(agnadirRep(c, -1));
    numClaves(c, num);
    EXPECT_EQ(0, num);
    numCardinal(c, num);
    EXPECT_EQ(0, num);
}

TEST(Eliminar, eliminar_sin_hijos)
{
    int  num;
    coleccion<int, int> c;
    EXPECT_NO_FATAL_FAILURE(crear(c););
    EXPECT_NO_FATAL_FAILURE(introducir(c, 2, 1, 1));



    EXPECT_NO_FATAL_FAILURE(eliminar(c,2));
    numClaves(c,num);
    EXPECT_EQ(2,num);
    EXPECT_FALSE(existe(c,2));
}

TEST(Eliminar, eliminar_solo_izq)
{
    int  num;
    coleccion<int, int> c;
    EXPECT_NO_FATAL_FAILURE(crear(c););
    EXPECT_NO_FATAL_FAILURE(introducir(c, 2, 1, 1));
    EXPECT_NO_FATAL_FAILURE(introducir(c, 1, 1, 1));
    

    EXPECT_NO_FATAL_FAILURE(eliminar(c, 2));
    numClaves(c, num);
    EXPECT_EQ(2, num);
    EXPECT_FALSE(existe(c, 2));
    EXPECT_TRUE(existe(c, 1));
}

TEST(Eliminar, eliminar_solo_der)
{
    int  num;
    coleccion<int, int> c;
    EXPECT_NO_FATAL_FAILURE(crear(c););
    EXPECT_NO_FATAL_FAILURE(introducir(c, 2, 1, 1));
    EXPECT_NO_FATAL_FAILURE(introducir(c, 3, 1, 1));

    EXPECT_NO_FATAL_FAILURE(eliminar(c, 2));
    numClaves(c, num);
    EXPECT_EQ(2, num);
    EXPECT_FALSE(existe(c, 2));
    EXPECT_TRUE(existe(c, 3));
}

TEST(Eliminar, eliminar_dos_hijos)
{
    int  num;
    coleccion<int, int> c;
    EXPECT_NO_FATAL_FAILURE(crear(c););
    EXPECT_NO_FATAL_FAILURE(introducir(c, 2, 1, 1));
    EXPECT_NO_FATAL_FAILURE(introducir(c, 1, 1, 1));
    EXPECT_NO_FATAL_FAILURE(introducir(c, 3, 1, 1));

    EXPECT_NO_FATAL_FAILURE(eliminar(c, 2));
    numClaves(c, num);
    EXPECT_EQ(2, num);
    EXPECT_FALSE(existe(c, 2));
    EXPECT_TRUE(existe(c, 3));
    EXPECT_TRUE(existe(c, 1));
}

TEST(quitarRep, no_se_elimina)
{
    //int dat, num;
    //coleccion<int, int> c;
    EXPECT_FALSE(true);
}

TEST(quitarRep, elimina)
{
    //int dat, num;
    //coleccion<int, int> c;
    EXPECT_FALSE(true);
}


TEST(Iterador,iterador){

    //int dat, num;
    //coleccion<int, int> c;
    EXPECT_FALSE(true);
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}