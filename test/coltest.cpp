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
 coleccion<int,int> c;

//Creo un test con titulo,subtitulo
TEST(CreacionPila, crear)
{
    EXPECT_NO_FATAL_FAILURE(crear(c););
    EXPECT_FALSE(existe(c, 1));
    EXPECT_NO_FATAL_FAILURE(quitarRep(c,1));
    int val;
    numCardinal(c,val);
    EXPECT_EQ(0,val);
    numClaves(c,val);
    EXPECT_EQ(0, val);
}



int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}