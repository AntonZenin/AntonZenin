#include <stdio.h>
#include <stdlib.h>
#include "Practice1c.h"

int main() {
    int numFilms = 0; 
    Film** films = readFilmsfromfile("films.txt", &numFilms);   
    if (films != NULL) {
        int numSelectedFilms;
        char director[100]; 
        printf("Input name and surname of director: "); 
        scanf("%s", director); 
        Film** selectedFilms = selectFilmsByDirector(films, numFilms, director, &numSelectedFilms);

        for (int i = 0; i < numSelectedFilms; i++) { 
            Film* film = selectedFilms[i];
            printf("Film: %s\n", film->title);  
            printf("Director: %s\n", film->director); 
            printf("Country: %s\n", film->country); 
            printf("Release year: %s\n", film->releaseYear);  
            printf("Budget: %.2f\n", film->budget); 
            printf("Box office: %.2f\n", film->boxoffice); 
            printf("\n");
        }

        for (int i = 0; i < numSelectedFilms; i++) {
            deleteFilm(selectedFilms[i]);
        }
        free(selectedFilms);

        for (int i = 0; i < numFilms; i++) {
            deleteFilm(films[i]);
        }
        free(films); 

    }

    return 0;
}