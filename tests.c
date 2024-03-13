
#include "tests.h"
#include "service.h"

void test_add()
{
    List lista = create();
    Materie m;
    strcpy(m.name, "Nume");
    strcpy(m.producer, "producator");
    m.cantitate = 5;

    assert(m.cantitate==5);
    assert(getLength(lista)==0);
    add(&lista, m);
    assert(getLength(lista)==1);
    assert(findMaterie(lista,m)!=-1);

    Materie m2;
    strcpy(m2.name, "Nume23");
    strcpy(m2.producer, "producator");
    m2.cantitate = 5;
    add(&lista, m2);
    assert(getLength(lista)==2);
    assert(findMaterie(lista,m)!=-1);

    Materie m3;
    strcpy(m3.name, "Nume23");
    strcpy(m3.producer, "producator");
    m3.cantitate = 10;
    add(&lista, m3);
    assert(getLength(lista)==2);
    assert(findMaterie(lista,m)!=-1);
    assert(lista.materii[1].cantitate==10);

}

void test_update()
{
    List lista = create();
    Materie m1;
    strcpy(m1.name, "Nume");
    strcpy(m1.producer, "Prod");
    add(&lista, m1);
    assert(getLength(lista)==1);
    assert(findMaterie(lista,m1)!=-1);

    Materie m2;
    strcpy(m2.name, "Materie");
    strcpy(m2.producer, "Producator");
    m2.cantitate = 10;

    update(&lista, 0, m2);
    assert(getLength(lista)==1);
    assert(findMaterie(lista,m1)==-1);
    assert(strcmp(lista.materii[0].name, m2.name)==0);
    assert(strcmp(lista.materii[0].producer, m2.producer)==0);
    assert(lista.materii[0].cantitate == m2.cantitate);



}

void test_delete(){

    List lista = create();
    Materie m1;
    strcpy(m1.name, "Nume");
    strcpy(m1.producer, "Prod");
    add(&lista, m1);
    assert(getLength(lista)==1);
    assert(findMaterie(lista,m1)!=-1);

    delete(&lista, 0);
    assert(getLength(lista)==0);
    assert(findMaterie(lista,m1)==-1);
}

void test_filter() {
    List lista = create();
    List result, result1;
    Materie m1, m2, m3;
    strcpy(m1.name, "zahar");
    strcpy(m1.producer, "Prod1");
    m1.cantitate=50;
    add(&lista, m1);

    strcpy(m2.name, "Faina");
    strcpy(m2.producer, "Prod2");
    m2.cantitate=10;
    add(&lista, m2);

    strcpy(m3.name, "faina");
    strcpy(m3.producer, "Prod3");
    m3.cantitate=10;
    add(&lista, m3);
    assert(getLength(lista) == 3);

//    result = filter(lista, 'f', 0);
//    assert(getLength(result) == 2);

    result1 = filter(lista, 'z', 200);
    assert(getLength(result1) == 0);

}


void test_sort(){
    List lista = create();
    List result, result1;
    Materie m1, m2, m3;
    strcpy(m1.name, "zahar");
    strcpy(m1.producer, "Prod1");
    m1.cantitate=50;
    add(&lista, m1);

    strcpy(m2.name, "Faina");
    strcpy(m2.producer, "Prod2");
    m2.cantitate=20;
    add(&lista, m2);

    strcpy(m3.name, "faina");
    strcpy(m3.producer, "Prod3");
    m3.cantitate=10;
    add(&lista, m3);
    result = sorteaza(lista, 'c', 'c');
    assert(result.materii[0].cantitate==10);

    result1 = sorteaza(lista, 'd', 'c');
    assert(result1.materii[0].cantitate==50);
}
void runTests()
{
    test_add();
    test_update();
    test_delete();
    test_filter();
    test_sort();
}
