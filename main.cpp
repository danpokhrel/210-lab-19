// COMSC-210 | Lab 18 | Dan Pokhrel
// IDE used: Visual Studio Code
#include <iostream>
#include <string>
using namespace std;

struct Movie { // linked list node
    float rating;
    string comment;
    Movie *next = nullptr;
};

// Prototypes
void pushFront(Movie **head, Movie *node); // Adds node to front of list
void pushBack(Movie **head, Movie *node); // Adds node to back of list
void deleteList(Movie **head); // Deletes entire list

int main() {
    Movie *moviesHd = nullptr;

    // Get linked list input preference
    cout << "Which linked list method should we use?";
    cout << "\n\t[1] New nodes are added at the head of the linked list";
    cout << "\n\t[2] New nodes are added at the tail of the linked list";
    cout << "\n\tChoice: ";
    int choice;
    cin >> choice;
    if (choice < 1 || choice > 2){ // Input validation
        cout << "Invalid Input";
        return 0;
    }

    //  Input Movie Data
    bool stop = false;
    while (!stop){
        // Variables
        Movie *tmp = new Movie;
        tmp->next = nullptr;
        char another;

        // Inputs
        cout << "\nEnter review rating 0-5: ";
        cin >> tmp->rating;
        if (tmp->rating < 0 || tmp->rating > 5){ // Input validation
            cout << "\nInvalid Input";
            return 0;
        }
        cout << "\nEnter review comments: ";
        cin.ignore();
        getline(cin, tmp->comment);

        cout << "\nEnter another review? Y/N: ";
        cin >> another;
        if (another == 'N' || another == 'n')
            stop = true;
        else if (another != 'Y' && another != 'y'){
            cout << "\nInvalid Input";
            stop = true;
        }

        // Processing
        if (choice == 1)
            pushFront(&moviesHd, tmp);
        else
            pushBack(&moviesHd, tmp);
    }

    // Output
    cout << "\nOutputting all reviews:";
    Movie *curr = moviesHd;
    int i = 1;
    float average = 0;
    while (curr){ // loop through linked list
        cout << "\n\t> Review #" << i << ": " << curr->rating << ": " << curr->comment;
        average += curr->rating;
        curr = curr->next;
        i++;
    }
    average = average / (i-1);
    cout << "\n\t> Average: " << average;

    return 0;
}

void pushFront(Movie **head, Movie *node){
    if (!(*head)) // First node
        *head = node;
    else{ // Add node before head
        node->next = *head;
        *head = node;
    }
}

void pushBack(Movie **head, Movie *node){
    if (!(*head)){ // First node
        *head = node;
        return;
    }
    Movie *current = *head;
    while (current->next) // iterate through list
        current = current->next;

    current->next = node;
}

void deleteList(Movie **head){
    Movie *current = *head;
    while (current){ // iterate through list
        *head = current->next;
        delete current;
        current = *head;
    }
    *head = nullptr;
}