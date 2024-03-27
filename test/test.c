#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Структура для хранения информации о фильме
typedef struct {
    char* title;
    char* directorFirstName;
    char* directorLastName;
    char* country;
    int year;
    float budget;
    float boxOffice;
} Film;

// Функция для создания структуры Film
Film* createFilm() {
    Film* film = (Film*)malloc(sizeof(Film));
    film->title = (char*)malloc(MAX_LEN);
    film->directorFirstName = (char*)malloc(MAX_LEN);
    film->directorLastName = (char*)malloc(MAX_LEN);
    film->country = (char*)malloc(MAX_LEN);
    return film;
}

// Функция для освобождения памяти из-под структуры Film
void freeFilm(Film* film) {
    free(film->title);
    free(film->directorFirstName);
    free(film->directorLastName);
    free(film->country);
    free(film);
}

// Функция для чтения данных о фильме из файла
Film* readFilmFromFile(FILE* file) {
    Film* film = createFilm();
    fscanf(file, "%s %s %s %s %d %f %f",
        film->title, film->directorFirstName, film->directorLastName, film->country,
        &(film->year), &(film->budget), &(film->boxOffice));
    return film;
}

// Функция для загрузки фильмов из файла
Film** loadFilmsFromFile(const char* fileName, int* count) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("File not opened\n");
        return NULL;
    }

    fscanf(file, "%d", count);
    Film** films = (Film**)malloc((*count) * sizeof(Film*));
    for (int i = 0; i < *count; i++) {
        films[i] = readFilmFromFile(file);
    }

    fclose(file);
    return films;
}

// Функция для поиска фильмов по имени и фамилии режиссера
void searchFilmsByDirector(Film** films, int count, const char* directorFirstName, const char* directorLastName) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        Film* film = films[i];
        if (strcmp(film->directorFirstName, directorFirstName) == 0 &&
            strcmp(film->directorLastName, directorLastName) == 0) {
            printf("Name: %s\n", film->title);
            printf("Director: %s %s\n", film->directorFirstName, film->directorLastName);
            printf("Country: %s\n", film->country);
            printf("Year: %d\n", film->year);
            printf("Budget: %.2f\n", film->budget);
            printf("Box office: %.2f\n", film->boxOffice);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Didn t find\n", directorFirstName, directorLastName);
    }
}

// Функция для освобождения памяти из-под массива фильмов
void freeFilms(Film** films, int count) {
    for (int i = 0; i < count; i++) {
        freeFilm(films[i]);
    }
    free(films);
}

int main() {
    int count;
    Film** films = loadFilmsFromFile("films.txt", &count);

    if (films != NULL) {
        char directorFirstName[MAX_LEN], directorLastName[MAX_LEN];
        printf("Input name and surname: ");
        scanf("%s %s", directorFirstName, directorLastName);

        searchFilmsByDirector(films, count, directorFirstName, directorLastName);

        freeFilms(films, count);
    }

    return 0;
}