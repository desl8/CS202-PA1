//Source file for the movie class
//students need to implement the values here

#include "movie.h"

Movie::Movie(){
    //default constructor
    //set all values in header to a specific value here
    //you do not need to set any value for the arrays
    title = "Movie";
    director = "John Director";
    description = "A Movie";
    year = 1970;
    metascore = 100;
    rating = 10.0;
    actorCount = 0;
    genreCount = 0;
}

Movie::Movie(string t, string di, string de, string* act, string* gen, int y, int m, float r, int aCount, int gCount){
    //parameterized constructor
    //set the properties equal to the passed in parameters provided above
    //both the arrays need to be set using for loops to go through each individual value in the array
    title = t;
    director = di;
    description = de;
    year = y;
    metascore = m;
    rating = r;
    actorCount = aCount;
    genreCount = gCount;
    for(int i = 0; i < aCount; i++){
        actors[i] = act[i];
    }
    for(int i = 0; i < gCount; i++){
        genres[i] = gen[i];
    }
}

Movie::Movie(const Movie& rhs){
    //copy constructor
    //set the properties equal to the properties found in the passed in object.
    //to access the properties of the original copy use the dot operator.  For example rhs.title
    //both arrays need to be set using for loops
    title = rhs.title;
    director = rhs.director;
    description = rhs.description;
    year = rhs.year;
    metascore = rhs.metascore;
    rating = rhs.rating;
    actorCount = rhs.actorCount;
    genreCount = rhs.genreCount;
    for(int i = 0; i < rhs.actorCount; i++){
        actors[i] = rhs.actors[i];
    }
    for(int i = 0; i < rhs.genreCount; i++){
        genres[i] = rhs.genres[i];
    }
}

//implement all getters

string Movie::getTitle(){
    return title;
}
string Movie::getDirector(){
    return director;
}
string Movie::getDescription(){
    return description;
}
string* Movie::getActors(){
    return actors;
}
string* Movie::getGenres(){
    return genres;
}
int Movie::getYear(){
    return year;
}
int Movie::getMetascore(){
    return metascore;
}
float Movie::getRating(){
    return rating;
}
int Movie::getActorCount(){
    return actorCount;
}
int Movie::getGenreCount(){
    return genreCount;
}

//implement all setters

void Movie::setTitle(string t){
    title = t;
}
void Movie::setDirector(string di){
    director = di;
}
void Movie::setDescription(string de){
    description = de;
}
void Movie::setYear(int y){
    year = y;
}
void Movie::setMetascore(float m){
    metascore = m;
}
void Movie::setRating(int r){
    rating = r;
}

void Movie::addActor(string act){
    //first check for whether the actorCount variable has exceeded the size of the array
    //if not add the actor to the array at the last position
    //move the actor count up by one
    if(actorCount < 5){
        actors[actorCount] = act;
        actorCount++;
    }
}

void Movie::addGenre(string gen){
    //first check for whether the genreCount variable has exceeded the size of the array
    //if not add the genre to the array at the last position
    //move the genre count up by one
    if(genreCount < 5){
        genres[genreCount] = gen;
        genreCount++;
    }
}

void Movie::displayMovieData(){
    cout << title << endl;
    cout << "Director: " << director << endl;
    cout << "Actors: ";
    for(int i = 0; i < actorCount - 1; i++){
        cout << actors[i] << " * ";
    }
    cout << actors[actorCount - 1] << endl;
    cout << "Year: " << year << " Rating: " << rating << " Meta Score: " << metascore << endl;
    cout << "Description: " << description << endl;
}