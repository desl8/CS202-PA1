//Author: Chris Collum
//main.cpp driver for the main menu and calling all the variant helper files

#include "helpers.h"

int main(int argc, char** argv){
    //check for the correct number of arguments in the command line.  Format should be <executable> <moviefile.csv>
    if(argc != 2){
        cout << "Incorrect format.  Expected a filename." << endl;
        return 1;
    }

    //Create an array of movies to hold data from csv file
    Movie movies[500];

    //Open the file stream and pass in the command line argument
    //Check for whether the file exists. If not, return 1 and exit program
    ifstream fin(argv[1]);
    if(!fin.is_open()){
        cout << "File not found..." << endl;
        return 1;
    }
    
    //Read from file and fill movie array
    int movieCount = readFile(fin, movies);
    fin.close();

    //Create the the array of genre options for the user to select from
    string genreOptions[9] = {"Sci-Fi", "Fantasy", "Biography", "Romance", "Comedy", "Horror", "Drama", "Family", "Exit"};

    //Outside do while loop. This loop controls the main menu
    int userChoice = 0;
    do{
        for(int i = 0; i < 9; i++){
            cout << i+1 << ". " << genreOptions[i] << endl;
        }
        cout << "=============================================" << endl;
        cout << "Which genre of movies would you like to view? ";
        cin >> userChoice;
        //Option to exit program
        if(userChoice == 9){
            return 0;
        }
        //Invalid choice error checking. Continue looping on incorrect selection
        else if(userChoice < 1 || userChoice > 9){
            cout << "Invalid choice. Select an option between 1-9" << endl;
        }
        //Valid choice drops into a new menu
        else{
            int sortChoice = 0;
            Genre genChoice = constructGenre(movies, movieCount, genreOptions[userChoice-1]);
            //This do while loop controls how the user chooses to sort the movies.
            do{
                cout << endl;
                cout << "1. Alphabetically by title" << endl;
                cout << "2. Numerically by year" << endl;
                cout << "3. Numerically by rating" << endl;
                cout << "4. Exit" << endl;
                cout << "=====================================" << endl;
                cout << "How would you like to sort the " << genreOptions[userChoice - 1] << " movies? ";
                cin >> sortChoice;
                //This choice causes program to exit completely
                if(sortChoice == 4){
                    return 0;
                }
                //This choice checks invalid options. Continues to loop until a valid option is selected
                else if(sortChoice < 1 || sortChoice > 4){
                    cout << "Invalid choice. Select an option between 1-4" << endl;
                }
                //Prompts user to select a movie to display. Then prompts user to choose to exit or choose another movie.
                else{
                    int movieChoice;
                    bubbleSortSelection(sortChoice, genChoice);
                    cout << endl;
                    genChoice.displayMovies();
                    cout << genChoice.getNumMoviesInGenre() + 1 << ". Exit" << endl;
                    cout << "===================================" << endl;
                    cout << "Which movie would you like to view? ";
                    cin >> movieChoice;
                    if(movieChoice == genChoice.getNumMoviesInGenre()+1){
                        return 0;
                    }
                    cout << endl;
                    genChoice.getMoviesOfGenre()[movieChoice-1].displayMovieData();

                    char select;
                    do{
                        cout << "Would you like to select another movie(y/n)? ";
                        cin >> select;
                        select = tolower(select);
                    }while(select != 'y' && select != 'n');

                    if(select == 'n'){
                        return 0;
                    }
                    else{
                        userChoice = 0;
                    }
                }
            }while(sortChoice < 1 || sortChoice > 6);
        }
    }while(userChoice < 1 || userChoice > 9);

    return 0;
}