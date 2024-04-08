#ifndef FUNC

#define FUNC

typedef struct {
    char* directorFirstName;
    char* directorLastName;
} Director;

typedef struct {
    char* filmName;
    Director* director;
    char* country;
    int year;
    float budget;
    float boxOffice;
} Film;

typedef struct {
    Film* films;
    int numFilms;
} FilmLib; 

FilmLib* createFilmLib(int size); 
void readFilmDataFromFile(char* fileName, FilmLib* lib); //добавить функцию чтобы выводила списки фильмов всех режиссеров
void printFilmInfo(Film* film);
void printFilmsByDirector(FilmLib* lib, char* firstName, char* lastName);
//void freeFilms(Film* film); 

//void readFilmData(FILE* file, Film* film); // -> FilmLib
//void printFilmData(Film* film); // + FilmLib
//void findFilmByDirector(FILE* file, const char* directorName, const char* directorSurname); // <- FilmLib, name; -> FilmLib
//void freeFilms(Film* film); 


#endif 
