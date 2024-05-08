#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Practice1c.h"

#define L 255  


int main(int argc, char** argv)
{
    char firstName[L]; 
    char lastName[L];
    FilmLib Lib;
    char* infilename;
    if (argc < 2)
    {
        printf("Incorrect arguments!");
        return 0;
    }
    infilename = argv[1];
    
    readFilmDataFromFile(infilename, &Lib);  
    
    
    printf("Enter director's first name: "); 
    scanf("%s", firstName); 
    printf("Enter director's last name: "); 
    scanf("%s", lastName); 
    
    printf("\nFilms by %s %s:\n", firstName, lastName);  
    printFilmsByDirector(&Lib, firstName, lastName); 

    

    freeFilmLibrary(&Lib);  

    return 0;
}




