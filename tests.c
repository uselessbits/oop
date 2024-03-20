#include <stdlib.h>
#include "tests.h"
#include "service.h"

void test_add()
{
    List lista = create();

//    Materie m0 = createMaterie("","",-5);
//    Materie m10 = createMaterie("zsda","",5);
//    Materie m11 = createMaterie("","asd",5);
//
//    assert(validate(m0)==0);
//    assert(validate(m10)==0);
//    assert(validate(m11)==0);
//
//    destroyMaterie(&m0);
//    destroyMaterie(&m10);
//    destroyMaterie(&m11);

    Materie m1 = createMaterie("zahar", "Prod1", 50);
    Materie m2 = createMaterie("Faina","Prod2", 10);
    assert(validate(m1)==1);
    assert(m1.cantitate==50);
    assert(getLength(lista)==0);
    add(&lista, m1);
    add(&lista, m1);
    assert(getLength(lista)==1);
    assert(findMaterie(lista,m1)!=-1);

    add(&lista, m2);
    assert(getLength(lista)==2);

    destroy(&lista);


}

void test_update()
{
    List lista = create();
    Materie m1 = createMaterie("Nume", "Prod", 30);
    Materie m2 = createMaterie("Materie","Producator", 10);

    add(&lista, m1);
    assert(getLength(lista)==1);
    assert(findMaterie(lista,m1)!=-1);

    update(&lista, 0, m2);
    assert(getLength(lista)==1);

    assert(strcmp(lista.materii[0].name, m2.name)==0);
    assert(strcmp(lista.materii[0].producer, m2.producer)==0);
    assert(lista.materii[0].cantitate == m2.cantitate);

    update(&lista, 4, m2);


    destroy(&lista);

}

void test_delete(){

    List lista = create();
    Materie m1, m2, m3;
    m1 = createMaterie("zahar", "Prod1", 50);
    m2 = createMaterie("Faina","Prod2", 10);
    m3 = createMaterie("ceva","Prod3", 10);

    delete(&lista, 1);

    add(&lista, m1);
    add(&lista, m2);
    add(&lista, m3);

    assert(getLength(lista)==3);
    assert(findMaterie(lista,m1)!=-1);

    delete(&lista, 1);
    delete(&lista, 0);

    assert(getLength(lista)==1);
    //assert(findMaterie(lista,m1)==-1);

    delete(&lista, 0);

    //free(lista.materii);
    destroy(&lista);

}

void test_filter() {
    List lista = create();
    List result, result1;
    Materie m1, m2, m3;
    m1 = createMaterie("zahar", "Prod1", 50);
    m2 = createMaterie("Faina","Prod2", 10);
    m3 = createMaterie("ceva","Prod3", 10);

    add(&lista, m1);
    add(&lista, m2);
    add(&lista, m3);

    assert(getLength(lista) == 3);

    result = filter(lista, 'f', 0);

    assert(getLength(result) == 1);

    result1 = filter(lista, 'z', 200);
    assert(getLength(result1) == 0);
    destroy(&lista);

    free(result.materii);
    free(result1.materii);

}

void test_destroy()
{
    List lista = create();
    Materie m1 = createMaterie("zahar", "Prod1", 50);
    add(&lista, m1);
    destroy(&lista);

}

void test_sort(){
    List lista = create();
    List result, result1;
    Materie m1, m2, m3;
    m1 = createMaterie("zahar", "Prod1", 50);
    m2 = createMaterie("Faina","Prod2", 20);
    m3 = createMaterie("ceva","Prod3", 10);

    add(&lista, m1);
    add(&lista, m2);
    add(&lista, m3);

    result = sorteaza(lista, cantitateMaiMica);

    assert(result.materii[0].cantitate==50);
    assert(result.materii[1].cantitate==20);
    assert(result.materii[2].cantitate==10);

    result1 = sorteaza(lista, cantitateMaiMare);

    assert(result1.materii[0].cantitate==10);
    assert(result1.materii[1].cantitate==20);
    assert(result1.materii[2].cantitate==50);



    destroy(&lista);


}


void runTests()
{
    test_add();
    test_update();
    test_delete();
    test_filter();
    test_sort();
    test_destroy();
}
