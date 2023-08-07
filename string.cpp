#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Movie {
protected:
    string title;
    string genre;
    int duration;

public:
    Movie(string title, string genre, int duration) {
        this->title = title;
        this->genre = genre;
        this->duration = duration;
    }

    void displayDetails() {
        cout << "Movie Title: " << title << endl;
        cout << "Genre: " << genre << endl;
        cout << "Duration: " << duration << " minutes" << endl;
    }
};

class Theater : public Movie {
public:
    string theaterName;
    int seatCapacity;

public:
    Theater(string theaterName, int seatCapacity, string title, string genre, int duration)
        : Movie(title, genre, duration) {
        this->theaterName = theaterName;
        this->seatCapacity = seatCapacity;
    }

    void bookTicket(int numSeats, string userName) {
        if (numSeats > seatCapacity) {
            throw runtime_error("Sorry, " + to_string(numSeats) + " seats are not available in " + theaterName);
        }

        seatCapacity -= numSeats;
        cout << numSeats << " seats have been booked in " << theaterName << " for " << userName << endl;

        ofstream ticketFile;
        ticketFile.open("ticket.txt");
        ticketFile << "User Name: " << userName << endl;
        ticketFile << "Theater Name: " << theaterName << endl;
        ticketFile << "Movie Title: " << title << endl;
        ticketFile << "Number of Seats: " << numSeats << endl;
        ticketFile << "--------------------------" << endl;
        ticketFile.close();
    }

    int getSeatCapacity() {
        return seatCapacity;
    }
};

void displayTicketDetails(string userName) {
    ifstream ticketFile;
    ticketFile.open("ticket.txt");

    bool ticketFound = false;

    if (ticketFile.is_open()) {
        string line;
        while (getline(ticketFile, line)) {
            if (line.find("User Name: " + userName) != string::npos) {
                ticketFound = true;
            }

            if (ticketFound) {
                cout << line << endl;

                if (line == "--------------------------") {
                    cout << endl;
                }
            }
        }
        ticketFile.close();

        if (!ticketFound) {
            cout << "No ticket has been booked for user " << userName << "." << endl;
        }
    }
    else {
        cout << "No ticket has been booked yet." << endl;
    }
}

int main() {
    Theater theaters[] = {
        Theater("PVR", 100, "Spider-Man: No Way Home", "Action", 150),
        Theater("INOX", 80, "The Matrix Resurrections", "Science Fiction", 148),
        Theater("Cinepolis", 120, "No Time to Die", "Action", 163)
    };

    int choice, numSeats;
    string userName;
    while (true) {
        cout << "Choose a movie:" << endl;
        cout << "1. Spider-Man: No Way Home" << endl;
        cout << "2. The Matrix Resurrections" << endl;
        cout << "3. No Time to Die" << endl;
        cout << "4. Display Booked Ticket Details" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;


        if (choice == 1 || choice == 2 || choice == 3) {
            cout << "Enter user name: ";
            cin >> userName;

            if (choice == 1) {
                theaters[0].displayDetails();
            }
            else if (choice == 2) {
                theaters[1].displayDetails();
            }
            else {
                theaters[2].displayDetails();
            }

            cout << "Available seats: " << endl;
            cout << "Theater Name: " << theaters[choice - 1].theaterName << endl;
            cout << "Seat Capacity: " << theaters[choice - 1].getSeatCapacity() << endl;

            cout << "Do you want to book tickets? (y/n): ";
            char confirm;
            cin >> confirm;

            if (confirm == 'y') {
                cout << "Enter number of seats to book: ";
                cin >> numSeats;
                theaters[choice - 1].bookTicket(numSeats, userName);
            }
        }
        else if (choice == 4) {
            cout << "Enter user name: ";
            cin >> userName;
            displayTicketDetails(userName);
        }
        else if (choice == 5) {
            break;
        }
        else {
            cout << "Invalid choice" << endl;
        }

        cout << endl;
    }

    return 0;
}
