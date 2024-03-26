#ifndef FUNC

#define FUNC

typedef struct { 
    char* title; 
    char* director;  
    char* country;
    int releaseYear;  
    float budget;
    float boxoffice; 
}Film;

Film* createFilm(char* title, char* director, char* country, int releaseYear, float budget, float boxoffice);
void deleteFilm(Film* film); 
Film** readFilmsfromfile(const char* filename, int* numFilms);   
Film** selectFilmsByDirector(Film** films, int numFilms, const char* director, int* numSelectedFilms);  

#endif 