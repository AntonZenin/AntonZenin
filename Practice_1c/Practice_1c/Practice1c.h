#ifndef FUNC

#define FUNC

typedef struct {
    char* title;
    char* directorLastName;
    char* directorFirstName;
    char* country;
    int releaseYear;
    double budget;
    double boxOffice;
} Film;

Film* loadFilmsFromFile(const char* filename, int* count);
void findFilmsByDirector(const Film* films, int count, const char* directorLastName);
void freeFilms(Film* films, int count);

#endif 
