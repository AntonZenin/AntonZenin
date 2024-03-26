#include "Practice1c.h"
#include <stdlib.h>
#include <stdio.h>

Film* createFilm(char* title, char* director, char* country, int releaseYear, float budget, float boxoffice)
{
    Film* film = (Film*)malloc(sizeof(Film));
    film->title = strdup(title);      
    film->director = strdup(director); 
    film->country = strdup(country); 
    film->releaseYear = releaseYear;
    film->budget = budget; 
    film->boxoffice = boxoffice;
    return film; 
}

void deleteFilm(Film* film)
{
    free(film->title);
    free(film->director);
    free(film->country);
    free(film);
}

Film** readFilmsfromfile(const char* filename, int* numFilms) 
{
    FILE* file = fopen(filename, "r"); 
    if (file == NULL) {
        printf("Unable to open a file\n");
        return NULL;
    } 
    int maxFilms = 10;
    Film** films = (Film**)malloc(maxFilms * sizeof(Film*));
    int count = 0;
    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        char title[100];
        char director[100];
        char country[100];
        int releaseYear;
        float budget;
        float boxoffice;

        sscanf(line, "%[^,], %[^,], %[^,], %d, %f, %f", title, director, country, &releaseYear, &budget, &boxoffice);
        films[count] = createFilm(title, director, country, releaseYear, budget, boxoffice);
        count++;
        if (count >= maxFilms) {
            maxFilms *= 2;
            films = (Film**)realloc(films, maxFilms * sizeof(Film*));
        }

    }

    fclose(file);
    *numFilms = count;
    return films;
}

Film** selectFilmsByDirector(Film** films, int numFilms, char* director, int* numSelectedFilms) {
    Film** selectedFilms = (Film**)malloc(numFilms * sizeof(Film*));
    int count = 0;

    for (int i = 0; i < numFilms; i++) {
        if (strcmp(films[i]->director, director) == 0) { 
            selectedFilms[count] = films[i];
            count++;
        }
    }
    *numSelectedFilms = count;  
    return selectedFilms; 
}

