#include <stdio.h>
#include <stdlib.h>
#include "Practice1c.h"


int main() {
    int choice;
    int filmCount;
    char directorLastName[100]; 

    Film* films = loadFilmsFromFile("films.txt", &filmCount);

    if (films == NULL) {
        return 1;
    }

    do {
        printf("Input choice for operatinos: 1 - search for films, 2 - close the program\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1: 
            printf("Input name: ");
            scanf("%s", directorLastName); 
            findFilmsByDirector(films, filmCount, directorLastName);
            
            break;
        case 2:
            break;
        default:
            printf("Wrong choice\n");
        }

    } while (choice != 2);

    freeFilms(films, filmCount); 
    
    

    return 0;
}