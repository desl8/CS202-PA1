//Author: Chris Collum
//header file associated with the genre object.

#ifndef GENRE_H
#define GENRE_H

#include "movie.h"

class Genre{
    string nameOfGenre;
    Movie moviesOfGenre[500];
    int numMoviesInGenre;

    public:
        //constructors
        Genre();
        Genre(string name, Movie* movies, int num);
        Genre(const Genre &rhs);

        //getters
        string getNameOfGenre();
        Movie* getMoviesOfGenre();
        int getNumMoviesInGenre();

        //setter
        void setNameOfGenre(string name);

        //replaces setter for arrays. adds a movie object to the last position in the movie array
        void addMovieOfGenre(Movie movie);

        //function to swap the position of two movies. should be used in the bubblesort helper function
        void swapMovies(int mov1, int mov2);

        //display a list of all movies in the genre
        void displayMovies();
};

#endif