#include "service.h"
#include "stdlib.h"

List create(){

    List rez;
    rez.length = 0;
    rez.capacity = 2;
    rez.materii = malloc(rez.capacity * sizeof(Materie));
    return rez;

}

void destroyMaterie(Materie* m)
{
    free(m->name);
    free(m->producer);
}


void destroy(List *list) {
    for(int i = 0; i < list->length; i++) {
        destroyMaterie(&(list->materii[i]));
    }

    free(list->materii);
    list->length = 0;
    list->capacity = 0;
}
List resize(List list){

    List newList;
    newList.capacity=2*list.capacity;
    newList.length=list.length;
    newList.materii = malloc(newList.capacity * sizeof(Materie));
    for(int i=0;i<list.length;i++) {
        newList.materii[i] = list.materii[i];
    }
    free(list.materii);

    return newList;

}

long getLength(List list)
{
    return list.length;
}


Materie createMaterie(char *nume, char *producator, int cantitate)
{
    /*
     * Creaza o materie be baza campurilor
     * @param nume: nume-adresa la care se afla numele materiei
     * @param producator: adresa la care se afla numele producatorului
     * @param cantitatea materiei
     */
    Materie m;
    m.name = malloc((strlen(nume)+1)*sizeof(char ));
    strcpy(m.name, nume);
    m.producer = malloc((strlen(producator)+1)*sizeof(char ));
    strcpy(m.producer, producator);
    m.cantitate = cantitate;

    return m;

}


int findMaterie(List lista, Materie m)
{
    /*
     * Cauta o materie prima in lista
     * @param m: materia care se vrea a fi cautata
     * @param lista: lista in care se cauta
     */
    for(int i=0; i< getLength(lista);i++)
    {

        if(strcmp(lista.materii[i].name, m.name) == 0)
            return i;
    }
    return -1;
}

int validate(Materie materie)
{
    if(materie.cantitate<=0)return 0;
    if(strcmp(materie.name,"")==0)return 0;
    if(strcmp(materie.producer,"")==0)return 0;
    return 1;
}

void add(List* list, Materie materie)
{
    /*
     * Adauga o materie in lista
     * @param m: materia care se vrea a fi adaugata
     * @param lista: lista in care se adauga
     */
    if(list->length == list->capacity)
        *list = resize(*list);

    if(list->length < list->capacity)
    {

        int i = findMaterie(*list, materie);

        if(i!=-1)
        {

            list->materii[i]=materie;
        } else
        {
        list->materii[list->length]=materie;
        list->length++;
        }
    }

}

int update(List* list, int index, Materie materie){
    /*
     * Actualizeaza o materie din lista
     * @param index: pozitia dmateriei
     * @param m: materia care se vrea a fi actualizata
     * @param lista: lista in care se adauga
     */
    if(index >= getLength(*list))
        return 0;
    destroyMaterie(&list->materii[index]);
    list->materii[index]=materie;
    return 1;
}

void delete(List* list, int index){
    /*
     * Sterge o materie din lista, la indexul dat
     * @param index: pozitia materiei in lista
     * @param lista: lista din care se sterge
     */
    if(getLength(*list)<1)
        return;


    destroyMaterie(&list->materii[index]);
    for(int i=index; i< getLength(*list)-1; i++)
        list->materii[i]=list->materii[i+1];


    list->length--;

}

int cantitateMaiMica(Materie m1, Materie m2)
{
    if(m1.cantitate<m2.cantitate)return -1;
    if(m1.cantitate==m2.cantitate)return 0;
    if(m1.cantitate>m2.cantitate)return 1;

    return 1;
}

int cantitateMaiMare(Materie m1, Materie m2)
{
    if(m1.cantitate<m2.cantitate)return 1;
    if(m1.cantitate==m2.cantitate)return 0;
    if(m1.cantitate>m2.cantitate)return -1;

    return 1;
}


List sorteaza(List list,int (*f)(Materie m1, Materie m2)){
    /*
     * Returneaza lista sortata crescator sau descrescator
     *
     */

    for(int i=0 ; i< getLength(list)-1;i++)
        for(int j=i+1;j<getLength(list); j++)
            if(f(list.materii[i],list.materii[j])<0) {
                Materie temp;
                temp = list.materii[i];
                list.materii[i] = list.materii[j];
                list.materii[j] = temp;
            }

    return list;
}


List filter(List list, char b, int minQuantity)
{
    /*
     * Filteaza lista dupa o litera de inceput si o cantitate minima
     * @list : lista de materii prime
     * @b: caracterul dupa care se filtreaza
     * @minQuantity: cantitatea minima de la care se vor afisa
     *
     */
    List newList;
    newList = create();
    for (int i = 0; i < getLength(list); i++)
        if (list.materii[i].cantitate >= minQuantity)
            if(tolower(list.materii[i].name[0]) == tolower(b))
                //printf("Addded %s", list.materii[i].name);
                add(&newList, list.materii[i]);

    return newList;

}

