
//problema6
#include <stdio.h>
#include <stdlib.h>


#include "service.h"
#include "tests.h"


void menu(){

    /*
     * Afiseaza meniul aplicatiei
     */
    printf("1.Adauga Materie\n");
    printf("2.Modifica Materie\n");
    printf("3.Sterge Materie\n");
    printf("4.Filteaza Materii\n");
    printf("5.Sorteaza Materii\n");

}

void printMaterii(List list)
{
    /*
     * Prints a list
     * @list- Lista de materii prime
     */
    for(int i=0;i<getLength(list);i++)
        printf("[%d]:%s, %s, %d \n",i, list.materii[i].name,list.materii[i].producer, list.materii[i].cantitate );
}

void addMaterie(List* lista)
{

    /*
     * Adauga o noua materie in lista
     *
     * @lista - Lista la care se va adauga materia
     */
    char nume[MAX_LEN_CHAR], prod[MAX_LEN_CHAR];
    int cantitate;

    printf("Introdu numele materiei:");
    scanf("%s", nume);
    printf("Introdu numele producatorului:");
    scanf("%s", prod);
    printf("Introdu cantitatea:");

    char cantitate_str[MAX_LEN_CHAR];
    fgets(cantitate_str, sizeof(cantitate_str), stdin);
    cantitate = (int)strtol(cantitate_str, NULL, 10);
    Materie materie = createMaterie(nume, prod, cantitate);
    if(validate(materie))
    add(lista, materie);



}

void updateMaterie(List* lista)
{
    /*
     * Actualizeaza o materie din lista cu una noua
     * @param lista - Lista care se va actualiza
     * @type - pointer
     */
    printMaterii(*lista);
    int input;
    char input_str[MAX_LEN_CHAR];
    printf("Intodu indexul materieri care trebuie actualizata: ");
    fgets(input_str, sizeof(input_str), stdin);
    input = (int)strtol(input_str, NULL, 10);

    char nume[MAX_LEN_CHAR], prod[MAX_LEN_CHAR];
    int cantitate;

    printf("Introdu noul nume");
    scanf("%s", nume);
    printf("Introdu noul producator:");
    scanf("%s", prod);
    printf("Introdu noua cantitate:");
    fgets(input_str, sizeof(input_str), stdin);
    cantitate = (int)strtol(input_str, NULL, 10);
    Materie materie = createMaterie(nume, prod, cantitate);
    update(lista, input, materie);


}

void deleteMaterie(List* lista){
    /*
     * Sterge un entry din o lista data
     * @param lista - pointer catre Lista din care se va sterge
     */

    printMaterii(*lista);
    int input;
    char input_str[MAX_LEN_CHAR];
    printf("Intodu indexul materieri care trebuie stearsa: ");
    fgets(input_str, sizeof(input_str), stdin);
    input = (int)strtol(input_str, NULL, 10);
    delete(lista, input);
}

void sorteazaMaterii(List* lista) {
    /*
     * Afiseaza lista sortata dupa cantitati
     * @param - lista- pointer
     */
    printf("Intordu n pentru sortare dupa nume | c pentru cantitate");
    List sortat = sorteaza(*lista, cantitateMaiMica);
    printMaterii(sortat);
}

void filteazaMaterii(List *lista){
    /*
     * Filtreaza o lista, dupa o cantitate minima si o prima litera data
     * @param  - lista - pointer
     */
    char first;
    int minQuant;
    List filtered;
    printf("Introdu o cantitate minima: ");

    char cantitate_str[MAX_LEN_CHAR];
    fgets(cantitate_str, sizeof(cantitate_str), stdin);
    minQuant = (int) strtol(cantitate_str, NULL, 10);

    printf("Introdu o litera: ");
    scanf("%c", &first);

    filtered = filter(*lista, first, minQuant);
    printMaterii(filtered);

}

void runApp() {
    List list = create();
    char input;
    while(1)
    {
        menu();
        scanf(" %c", &input);
        switch (input) {
            case '1':
                addMaterie(&list);
                break;
            case '2':
                updateMaterie(&list);
                break;
            case '3':
                deleteMaterie(&list);
                break;
            case '4':
                filteazaMaterii(&list);
                break;
            case '5':
                sorteazaMaterii(&list);
                break;

            default:
                printf("No other option selected");
                return;

        }

    }
}

int main() {

    runTests();
    //runApp();


}
