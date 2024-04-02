#ifndef FUNC

#define FUNC

// Структура для хранения информации о фильме
typedef struct {
    char* title;
    char* directorSurname;
    char* directorName;
    char* country;
    int year;
    double budget;
    double gross;
} Film;

void readFilmData(FILE* file, Film* film);
void printFilmData(Film* film);
//Film* readFilmsFromFile(const char* fileName, int* count);
void findFilmByDirector(FILE* file, const char* directorName, const char* directorSurname);
//void freeFilms(Film* film);  

#endif 
