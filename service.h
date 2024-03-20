
#ifndef LAB2_4_SERVICE_H
#define LAB2_4_SERVICE_H

#define MAX_LEN_CHAR 20
#include "string.h"
#include <ctype.h>

typedef struct {
    int cantitate;
    char *name;
    char *producer;

}Materie;



typedef struct {

    Materie* materii;
    long length,capacity;


}List;


void destroyMaterie(Materie* m);

List create();

/*
 * Dealoca memoria atribuita unei liste
 */
void destroy(List* lista);

/*
     * Creaza o materie be baza campurilor
     * @param nume: nume-adresa la care se afla numele materiei
     * @param producator: adresa la care se afla numele producatorului
     * @param cantitatea materiei
     */
Materie createMaterie(char *nume, char *producator, int cantitate);
/*
     * Cauta o materie prima in lista
     * @param m: materia care se vrea a fi cautata
     * @param lista: lista in care se cauta
*/
int findMaterie(List lista, Materie m);

/*
 * Returneaza lungimea listei
 * Lista-oarecare
 */
long getLength(List list);


/*
 * Afiseaza lista de materii
 * @param list: Lista oarecare
 *
 */
void printMaterii(List list);


     /*
     * Adauga o materie in lista
     * @param m: materia care se vrea a fi adaugata
     * @param lista: lista in care se adauga
     */
void add(List* list, Materie materie);


/*
     * Actualizeaza o materie din lista
     * @param index: pozitia dmateriei
     * @param m: materia care se vrea a fi actualizata
     * @param lista: lista in care se adauga
     */
int update(List* list, int index, Materie materie);



/*
     * Sterge o materie din lista, la indexul dat
     * @param index: pozitia materiei in lista
     * @param lista: lista din care se sterge
     */
void delete(List* list, int index);

/*
 * Returneaza lista sortata crescator sau descrescator
 *@param: list: o lista oarecare
 *
 */
List sorteaza(List list,int (*f)(Materie m1, Materie m2));
/*
 * Filteaza lista dupa o litera de inceput si o cantitate minima
 * @list : lista de materii prime
 * @b: caracterul dupa care se filtreaza
 * @minQuantity: cantitatea minima de la care se vor afisa
 *
 */
List filter(List list, char b, int minQuantity);

/*
 * Valideaza o materie
 * pre:materie orice Materie
 */
int validate(Materie materie);

int cantitateMaiMica(Materie m1, Materie m2);
int cantitateMaiMare(Materie m1, Materie m2);

#endif //LAB2_4_SERVICE_H
