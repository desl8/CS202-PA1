//Author: Chris Collum
//header file for the helper functions. Students will be expected to implement the code for these themselves

#ifndef HELPERS_H
#define HELPERS_H

#include "genre.h"

//function to the read from the csv file. it take a file stream object and an array of movies
int readFile(ifstream& file, Movie* movies);

//function to sort the movie array according to what the user chooses.
void bubbleSortSelection(int userChoice, Genre &genreObject);

//function to construct a genre object based on what the user chooses.
Genre constructGenre(Movie* movies, int numMovies, string genreName);

#endif