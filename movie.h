//Author: Chris Collum
//Header file for the movie class file. Creates properties and sets up all getters and setter and constructors.

#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <fstream>

using namespace std;

class Movie{
    //Properties to hold data entries from the csv
    string title, director, description;
    string actors[5];
    string genres[5];
    int year, metascore;
    float rating;

    //Counters to keep track of number of actors and genres per movie
    int actorCount;
    int genreCount;

    public:
        //constructors
        Movie();
        Movie(string t, string di, string de, string* act, string* gen, int y, int m, float r, int aCount, int gCount);
        Movie(const Movie &rhs);
        
        //getters
        string getTitle();
        string getDirector();
        string getDescription();
        string* getActors();
        string* getGenres();
        int getYear();
        int getMetascore();
        float getRating();
        int getActorCount();
        int getGenreCount();

        //setters
        void setTitle(string t);
        void setDirector(string di);
        void setDescription(string de);
        void setYear(int y);
        void setMetascore(float m);
        void setRating(int r);

        //These replace setters for arrays. Instead we add only one item to the end of the array
        void addActor(string act);
        void addGenre(string gen);

        //method to display the movie data
        void displayMovieData();
};

#endif