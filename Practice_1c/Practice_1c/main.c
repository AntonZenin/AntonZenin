#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Practice1c.h"




int main() {
    char firstName[100], lastName[100]; 
    FilmLib* lib = createFilmLib(10);//Assume we have 10 films in the file

    readFilmDataFromFile("films.txt", lib);

   
    printf("Enter director's first name: ");
    scanf("%s", firstName);
    printf("Enter director's last name: ");
    scanf("%s", lastName);

    printf("\nFilms by %s %s:\n", firstName, lastName);
    printFilmsByDirector(lib, firstName, lastName);

    //freeFilms; 

    return 0;
}

   


