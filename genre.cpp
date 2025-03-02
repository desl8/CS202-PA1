#include "genre.h"

Genre::Genre(){
    //default constructor
    //set all values in header to a specific value here
    //you do not need to set any value for the arrays
    nameOfGenre = "Genre";
    numMoviesInGenre = 0;
}

Genre::Genre(string name, Movie* movies, int num){
    //parameterized constructor
    //set the properties equal to the passed in parameters provided above
    //the values in the array need to be set using a for loop
    nameOfGenre = name;
    numMoviesInGenre = num;
    for(int i = 0;i < num;i++){
        moviesOfGenre[i] = movies[i];
    }
}

Genre::Genre(const Genre &rhs){
    //copy constructor
    //to access the properties of the original copy use the dot operator.  For example rhs.nameOfGenre
    //the values in the array need to be set using a for loop
    nameOfGenre = rhs.nameOfGenre;
    numMoviesInGenre = rhs.numMoviesInGenre;
    for(int i = 0;i < rhs.numMoviesInGenre;i++){
        moviesOfGenre[i] = rhs.moviesOfGenre[i];
    }
}

//implement getters

string Genre::getNameOfGenre(){
    return nameOfGenre;
}

Movie* Genre::getMoviesOfGenre(){
    return moviesOfGenre;
}

int Genre::getNumMoviesInGenre(){
    return numMoviesInGenre;
}

//implement setter

void Genre::setNameOfGenre(string name){
    nameOfGenre = name;
}

void Genre::addMovieOfGenre(Movie movie){
    //first check for whether the numMovieInGenre variable has exceeded the size of the array
    //if not add the movie to the array at the last position
    //move the count up by one
    if(numMoviesInGenre < 500){
        moviesOfGenre[numMoviesInGenre] = movie;
        numMoviesInGenre++;
    }
}

//function to swap the movie positions based on passed in index values
void Genre::swapMovies(int mov1, int mov2){
    Movie temp(moviesOfGenre[mov1]);
    moviesOfGenre[mov1] = moviesOfGenre[mov2];
    moviesOfGenre[mov2] = temp;
}

//displays a list all movies in the genre
void Genre::displayMovies(){
    for(int i = 0; i < numMoviesInGenre; i++){
        cout << i+1 << ". " << moviesOfGenre[i].getTitle() << endl;
    }
}