
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
int var;


//Creo un test con titulo,subtitulo
TEST(CreacionPila, crear)
{
    EXPECT_EQ(0, size(pl));
}

TEST(PilaVacia, operaciones)
{
    //Comprueba si empty devuelve true
    EXPECT_TRUE(empty(pl));
    //compruebo que no va a petar xd
    EXPECT_NO_FATAL_FAILURE (pop(pl));
    EXPECT_FALSE(top(pl,var));
}

TEST(Pila, apilar)
{
    push(pl,1);
    EXPECT_EQ(1,size(pl));
    //compruebo que devuelve el valor correcto
    EXPECT_TRUE( top(pl,var));
    EXPECT_EQ(1,var);

    push(pl, 4);
    EXPECT_EQ(2, size(pl));
    //compruebo que devuelve el valor correcto
    EXPECT_TRUE(top(pl, var));
    EXPECT_EQ(4, var);

    push(pl, -9);
    EXPECT_EQ(3, size(pl));
    //compruebo que devuelve el valor correcto
    EXPECT_TRUE(top(pl, var));
    EXPECT_EQ(-9, var);

    //comprueba devuelve true
    EXPECT_FALSE(empty(pl));
}

TEST(Pila,desapilar){

    pop(pl);
    EXPECT_EQ(2, size(pl));
    //compruebo que devuelve el valor correcto
    EXPECT_TRUE(top(pl, var));
    EXPECT_EQ(4, var);

    pop(pl);
    EXPECT_EQ(1, size(pl));
    //compruebo que devuelve el valor correcto
    EXPECT_TRUE(top(pl, var));
    EXPECT_EQ(1, var);

    pop(pl);
    EXPECT_EQ(0, size(pl));
    //compruebo que devuelve el valor correcto
    EXPECT_FALSE(top(pl, var));
    //comprueba devuelve true
    EXPECT_TRUE(empty(pl));
}
TEST(Pila, mezcla){
    push(pl, 1);
    EXPECT_EQ(1, size(pl));
    EXPECT_TRUE(top(pl, var));
    EXPECT_EQ(1, var);

    pop(pl);
    EXPECT_EQ(0, size(pl));
    EXPECT_FALSE(top(pl, var));
    EXPECT_EQ(1, var);

    EXPECT_TRUE(empty(pl));

    EXPECT_NO_FATAL_FAILURE(pop(pl));
    EXPECT_EQ(0, size(pl));
    EXPECT_FALSE(top(pl, var));

    push(pl, 4);
    EXPECT_EQ(1, size(pl));
    EXPECT_TRUE(top(pl, var));
    EXPECT_EQ(4, var);
    EXPECT_FALSE(empty(pl));

    push(pl, -9);
    EXPECT_EQ(2, size(pl));
    EXPECT_TRUE(top(pl, var));
    EXPECT_EQ(-9, var);
    EXPECT_FALSE(empty(pl));

    pop(pl);
    EXPECT_EQ(1, size(pl));
    EXPECT_TRUE(top(pl, var));
    EXPECT_EQ(4, var);

    pop(pl);
    EXPECT_EQ(0, size(pl));
    EXPECT_FALSE(top(pl, var));
   

    EXPECT_NO_FATAL_FAILURE(pop(pl));
    EXPECT_EQ(0, size(pl));
    EXPECT_FALSE(top(pl, var));
   
}

TEST(Pila, limpiar)
{
    push(pl, 1);
    EXPECT_EQ(1, size(pl));
    //compruebo que devuelve el valor correcto
    EXPECT_TRUE(top(pl, var));
    EXPECT_EQ(1, var);

    push(pl, 4);
    EXPECT_EQ(2, size(pl));
    //compruebo que devuelve el valor correcto
    EXPECT_TRUE(top(pl, var));
    EXPECT_EQ(4, var);

    push(pl, -9);
    EXPECT_EQ(3, size(pl));
    //compruebo que devuelve el valor correcto
    EXPECT_TRUE(top(pl, var));
    EXPECT_EQ(-9, var);

    EXPECT_NO_FATAL_FAILURE(clear(pl));
    EXPECT_TRUE(empty(pl));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}