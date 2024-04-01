#include "Practice1c.h"
#include <stdlib.h>
#include <stdio.h>

Film* loadFilmsFromFile(const char* filename, int* count) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open\n");
        return NULL;
    }

    // Определяем количество фильмов в файле
    fscanf(file, "%d", count);

    // Выделяем память для массива структур
    Film* films = (Film*)malloc(*count * sizeof(Film));

    // Читаем информацию о каждом фильме из файла
    for (int i = 0; i < *count; i++) {
        Film* film = &films[i];

        // Выделяем память для строковых полей
        film->title = (char*)malloc(100 * sizeof(char));
        film->directorLastName = (char*)malloc(100 * sizeof(char));
        film->directorFirstName = (char*)malloc(100 * sizeof(char));
        film->country = (char*)malloc(100 * sizeof(char));

        // Читаем данные из файла
        fscanf(file, "%s %s %s %s %d %lf %lf",
            film->title,
            film->directorLastName,
            film->directorFirstName,
            film->country,
            &(film->releaseYear),
            &(film->budget),
            &(film->boxOffice)
        );
    }

    fclose(file);
    return films;
}

void findFilmsByDirector(const Film* films, int count, const char* directorLastName) {
    int found = 0;

    // Проходим по всем фильмам и ищем фильмы с указанным режиссером
    for (int i = 0; i < count; i++) {
        const Film* film = &films[i];
        if (strcmp(film->directorLastName, directorLastName) == 0) {
            found = 1;
            printf("Title: %s\n", film->title);
            printf("Director: %s %s\n", film->directorLastName, film->directorFirstName);
            printf("Country: %s\n", film->country);
            printf("Year: %d\n", film->releaseYear);
            printf("Budget: %.2lf\n", film->budget);
            printf("Box office: %.2lf\n", film->boxOffice);
            printf("\n");
        }
    }

    if (!found) {
        printf("Didn't find\n", directorLastName);
    }
}

void freeFilms(Film* films, int count) {
    for (int i = 0; i < count; i++) {
        Film* film = &films[i];
        free(film->title);
        free(film->directorLastName);
        free(film->directorFirstName);
        free(film->country);
    }
    free(films);
}
 