#include "service.h"

List create(){
    List rez;
    rez.length = 0;
    return rez;

}

int getLength(List list)
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
    strcpy(m.name, nume);
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
    if(list->length < 100)
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

void update(List* list, int index, Materie materie){
    /*
     * Actualizeaza o materie din lista
     * @param index: pozitia dmateriei
     * @param m: materia care se vrea a fi actualizata
     * @param lista: lista in care se adauga
     */
    if(index >= getLength(*list))
        return;

    strcpy(list->materii[index].name, materie.name);
    strcpy(list->materii[index].producer, materie.producer);
    list->materii[index].cantitate=materie.cantitate;

}

void delete(List* list, int index){
    /*
     * Sterge o materie din lista, la indexul dat
     * @param index: pozitia materiei in lista
     * @param lista: lista din care se sterge
     */
    if(getLength(*list)<1)
        return;
    if(getLength(*list)==1)
    {
        list->length--;
        return;
    }

    for(int i=index; i< getLength(*list)-1; i++)
        list->materii[i]=list->materii[i+1];

    list->length--;

}

int cmp(Materie m1, Materie m2, char o)
{
    if(o=='c')
        return m1.cantitate<m2.cantitate;
    if(o=='d')
        return m1.cantitate>m2.cantitate;
}
List sorteaza(List list, char o, char criteriu){
    /*
     * Returneaza lista sortata crescator sau descrescator
     *
     */
    if(criteriu=='c'){
    for(int i=0 ; i< getLength(list)-1;i++)
        for(int j=i+1;j<getLength(list); j++)
            if(cmp(list.materii[i],list.materii[j], o)==0) {
                Materie temp;
                temp = list.materii[i];
                list.materii[i] = list.materii[j];
                list.materii[j] = temp;
            }
    } else
    {
        for(int i=0 ; i< getLength(list)-1;i++)
            for(int j=i+1;j<getLength(list); j++)
                if(strcmp(list.materii[i].name,list.materii[j].name)>0) {
                    Materie temp;
                    temp = list.materii[i];
                    list.materii[i] = list.materii[j];
                    list.materii[j] = temp;
                }
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
    for (int i = 0; i < getLength(list); i++)
        if (list.materii[i].cantitate >= minQuantity)
            if(tolower((int) list.materii[i].name[0]) == tolower(b))

                add(&newList, list.materii[i]);

    return newList;

}

