// COMSC-210 | Lab 19 | Dan Pokhrel
// IDE used: Visual Studio Code
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

const int REVIEW_COUNT = 3;

struct Node { // linked list node
    float rating;
    string comment;
    Node *next = nullptr;
};

class Movie {
private:
    string title;
    Node* head;
public:
    // Constructors
    Movie() {title = ""; head = nullptr;}
    Movie(string t, Node* h) {title = t; head = h;}

    // Getters and setters
    string getTitle() const {return title;}
    Node* getHead() const {return head;}
    void setTitle(string t) {title = t;}
    void setHead(Node* hd) {head = hd;}
};

// Prototypes
void pushFront(Node **head, Node *node); // Adds node to front of list
void deleteList(Node **head); // Deletes entire list

int main() {
    vector<Movie> movies;

    // tmp variables
    string title;
    string buf;
    Node* head = nullptr;
    Node* review = nullptr;
    // Read data
    ifstream fin("data.txt");
    if (!fin.good()) cout << "Input file not found.";
    while (fin.good()){
        getline(fin, title);
        for (int i = 0; i < REVIEW_COUNT; i++){
            review = new Node;
            getline(fin, buf);
            review->rating = stof(buf);
            getline(fin, review->comment);
            pushFront(&head, review);
        }
        Movie m = Movie(title, head);
        movies.push_back(m);
    }

    // output
    cout << "Outputing Movies:\n";
    for (Movie movie : movies){
        cout << "Title: " << movie.getTitle();
    }

    return 0;
}

void pushFront(Node **head, Node *node){
    if (!(*head)) // First node
        *head = node;
    else{ // Add node before head
        node->next = *head;
        *head = node;
    }
}

void deleteList(Node **head){
    Node *current = *head;
    while (current){ // iterate through list
        *head = current->next;
        delete current;
        current = *head;
    }
    *head = nullptr;
}