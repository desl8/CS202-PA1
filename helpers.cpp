#include "helpers.h"

int readFile(ifstream& file, Movie* movies){
    int count = 0;

    string junk;
    //example get line to read in the first line of the csv file. 
    //this reads the line indicating the categories and gets rid of it as it's not needed
    getline(file, junk);

    //basic while loop to read through the file until the end of it is hit
    while(!file.eof()){
        //getline with the delimiter provided. Reads the value with the rank category and gets rid of it
        getline(file, junk, ',');
        
        //Create a series of string variables to store the needed categories to create a movie object
        //Create two string arrays to hold the genres and actors.
        //Create two integer variables to keep track of the number of actors and genres per line. for example guardians would have 3 actors and 3 genres

        string t, di, de;
        int y, m, r;
        string y_str, m_str, r_str;
        string act[5], gen[5];
        int aCount, gCount;
        aCount = 0;
        gCount = 0;

        //implement getlines to read and store the appropriate info until you reach the list of genres.

        getline(file, t, ',');

        //use a do while to parse the list of genres
            //inside the do  while use getline to parse the genres. each genre will be stored into the created genre array. the genre count variable should be used to keep track of which index to store the genre at
            //up the genre count variable
        //genres[genCount-1][genres[genCount-1].length() - 1] != '"' is the termination check for how to exit the do while
        //essentially you are going to check for whether there is a " on the last genre, as that determines if we have reached the end of the list
        //genres[genCount-1].pop_back(); is an example of how to remove the " after exiting the do while loop

        //The above instructions is a suggestion for how to parse the list of genres. if something else works better for you, then you are free to use a different method

        do{
            getline(file, gen[gCount], ',');
            gCount++;
        }
        while(gen[gCount-1][gen[gCount-1].length() - 1] != '"');

        gen[gCount-1].pop_back();

        //use getlines to continue reading from file until you hit the list of actors
        //the implementation will look nearly identical to the genres list

        getline(file, de, ',');
        getline(file, di, ',');
        
        do{
            getline(file, act[aCount], ',');
            aCount++;
        }
        while(act[aCount-1][act[aCount-1].length() - 1] != '"');

        act[aCount-1].pop_back();
        
        //continue reading with getline until the end of the line

        getline(file, y_str, ',');
        getline(file, junk, ',');
        getline(file, r_str, ',');
        getline(file, junk, ',');
        getline(file, junk, ',');
        getline(file, m_str);

        y = std::stoi(y_str);
        m = std::stoi(m_str);
        r = std::stof(r_str);

        //Create a temporary movie object and pass in the stored variables we read from the file using either the parameterized constructor or setters
        Movie temp_mv(t, di, de, act, gen, y, m, r, aCount, gCount);
        movies[count] = temp_mv;

        count++;
    }

    return count;
}

void bubbleSortSelection(int userChoice, Genre &genreObject){
    //bubble sort is a common sorting algorithm
    //you are free to find an implementation online and converting it for use here

    //a swap method has been implemented to make swapping movies in the array easier
    
    //you will need three implementations of the bubble sort
    //one will be for sorting alphabetically by title
    //one will be for sorting numerically by year (earliest year first)
    //one will be for sorting numerically by rating (highest rating first)
    //if there is a tie in the numerical sorts, break the tie using alphabetically by title

    //recommend using a switch statement here but if statements will work
    bool swapped;
    int n = genreObject.getNumMoviesInGenre();
    switch(userChoice){
        case 1:
            for (int i = 0; i < n-1; i++) {
                swapped = false;
                for (int j = 0; j < n-i - 1; j++){
                    if(genreObject.getMoviesOfGenre()[j].getTitle() > genreObject.getMoviesOfGenre()[j+1].getTitle()){
                        genreObject.swapMovies(j, j+1);
                        swapped = true;
                    }
                }
                // If no two elements were swapped, then break
                if (!swapped)
                break;
            }
            break;
        case 2:
            for (int i = 0; i < n-1; i++) {
                swapped = false;
                for (int j = 0; j < n-i - 1; j++){
                    if(genreObject.getMoviesOfGenre()[j].getYear() > genreObject.getMoviesOfGenre()[j+1].getYear()){
                        genreObject.swapMovies(j, j+1);
                        swapped = true;
                    }
                    else if(genreObject.getMoviesOfGenre()[j].getYear() == genreObject.getMoviesOfGenre()[j+1].getYear()){
                        if(genreObject.getMoviesOfGenre()[j].getTitle() > genreObject.getMoviesOfGenre()[j+1].getTitle()){
                            genreObject.swapMovies(j, j+1);
                            swapped = true;
                        }
                    }
                }
                // If no two elements were swapped, then break
                if (!swapped)
                break;
            }
            break;
        case 3:
            for (int i = 0; i < n-1; i++) {
                swapped = false;
                for (int j = 0; j < n-i - 1; j++){
                    if(genreObject.getMoviesOfGenre()[j].getRating() > genreObject.getMoviesOfGenre()[j+1].getRating()){
                        genreObject.swapMovies(j, j+1);
                        std::cout << "Swapping " << j << " & " << j+1 << std::endl;
                        swapped = true;
                    }
                    else if(genreObject.getMoviesOfGenre()[j].getRating() == genreObject.getMoviesOfGenre()[j+1].getRating()){
                        if(genreObject.getMoviesOfGenre()[j].getTitle() > genreObject.getMoviesOfGenre()[j+1].getTitle()){
                            genreObject.swapMovies(j, j+1);
                            swapped = true;
                        }
                    }
                }
                // If no two elements were swapped, then break
                if (!swapped)
                break;
            }
            break;
    }
}

Genre constructGenre(Movie* movies, int numMovies, string genreName){
    //This function is designed to take an option from the user and construct a genre object with all movies that have that particular genre in their list
    //for example, if the user selects action, all movies with the action genre will be added to the object

    //create a new movie array
    //create a new integer counter to keep track of the number of movies in this genre

    Movie moviesInGenre[500];
    int numMoviesInGenre = 0;

    //you will use a nested for loop
    //the outside for loop will go through the entire list of movies read from the csv
    //the inside for loop will go through the list of genres per movie
    //each iteration of this inside for loop will check if the genre for that movie is equal to the genreName variable
    //if it is, add it to the newly created movie array
    //if not, skip
    //each succesfully added movie ups the count by one

    std::cout << "Testing1 " << numMovies << std::endl;

    int numGenres;
    for(int i=0;i<numMovies;i++){
        numGenres = movies[i].getGenreCount();
        for(int j=0;j<numGenres;j++){
            if(movies[i].getGenres()[j] == genreName){
                moviesInGenre[numMoviesInGenre] = movies[i];
                numMoviesInGenre++;
            }
        }
    }

    //create a new genreobject with the created array and the generated count
    //return this genreobject

    Genre genreobject(genreName, moviesInGenre, numMoviesInGenre);
    return genreobject;
}