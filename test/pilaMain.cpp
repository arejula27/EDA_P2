
//compile: make pilatest

#include <iostream>
#include "pila.h"
#include <gtest/gtest.h>

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
pila<int> pl;

int fallo(){
    int *a;
    a =nullptr;
    return *a;
}
//Creo un test con titulo,subtitulo


TEST(CreacionPila, crear)
{
    

    EXPECT_EQ(0, size(pl));
    
   
}
TEST(PilaVacia, desapilar)
{
    //Comprueba si empty devuelve true
    EXPECT_TRUE(empty(pl));
    //compruebo que no va a petar xd
    EXPECT_NO_FATAL_FAILURE (pop(pl));
    EXPECT_THAT("Hello", "Hello");
    
}
TEST(PilaVacia, situacionVacia)
{
    //compruebo que hay 0 elementos
    EXPECT_EQ(0, size(pl));
    //comprueba devuelve true
    EXPECT_TRUE(empty(pl));
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}