#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

struct Passenger {
    std::string name;
    int age;
    std::string gender;
    int seatNumber;
};

class Train {
private:
    std::string trainNumber;
    std::string trainName;
    std::string source;
    std::string destination;
    int totalSeats;
    int availableSeats;
    double baseFare;
    std::vector<Passenger> bookedPassengers;

public:
    Train(std::string num, std::string name, std::string src, std::string dest, int seats, double fare)
        : trainNumber(num), trainName(name), source(src), destination(dest), 
          totalSeats(seats), availableSeats(seats), baseFare(fare) {}
    std::string getTrainNumber() const { return trainNumber; }
    std::string getTrainName() const { return trainName; }
    int getAvailableSeats() const { return availableSeats; }
    double getBaseFare() const { return baseFare; }
    void displayTrainRoute() const {
        std::cout << std::left << std::setw(12) << trainNumber 
                  << std::setw(22) << trainName 
                  << std::setw(15) << source 
                  << std::setw(15) << destination 
                  << std::setw(10) << availableSeats 
                  << std::fixed << std::setprecision(2) << baseFare << " INR\n";
    }
    void bookRailwayTicket() {
        if (availableSeats <= 0) {
            std::cout << "\nReservation Failed: No seats available on this route!\n";
            return;
        }

        int ticketsToBook;
        std::cout << "\nEnter number of passengers: ";
        std::cin >> ticketsToBook;

        if (ticketsToBook > availableSeats) {
            std::cout << "Error: Only " << availableSeats << " seats are available.\n";
            return;
        }
        long long pnr = 1000000000LL + (rand() % 9000000000LL);
        double totalCost = ticketsToBook * baseFare;

        std::cout << "\n--- Enter Passenger Details ---\n";
        for (int i = 0; i < ticketsToBook; ++i) {
            Passenger p;
            std::cout << "\nPassenger " << i + 1 << " Name: ";
            std::cin.ignore();
            std::getline(std::cin, p.name);
            std::cout << "Passenger Age: ";
            std::cin >> p.age;
            std::cout << "Passenger Gender (M/F/O): ";
            std::cin >> p.gender;
            p.seatNumber = totalSeats - availableSeats + 1;
            availableSeats--;

            bookedPassengers.push_back(p);
        }
        std::cout << "\n==================================================\n";
        std::cout << "               RAILWAY E-TICKET                   \n";
        std::cout << "==================================================\n";
        std::cout << "PNR Number     : " << pnr << "\n";
        std::cout << "Train          : " << trainName << " (" << trainNumber << ")\n";
        std::cout << "Route          : " << source << " -> " << destination << "\n";
        std::cout << "Total Fare     : " << std::fixed << std::setprecision(2) << totalCost << " INR\n";
        std::cout << "--------------------------------------------------\n";
        std::cout << std::left << std::setw(18) << "Name" << std::setw(8) << "Age" << std::setw(10) << "Gender" << "Seat No.\n";
        std::cout << "--------------------------------------------------\n";
        for (size_t i = bookedPassengers.size() - ticketsToBook; i < bookedPassengers.size(); ++i) {
            std::cout << std::left << std::setw(18) << bookedPassengers[i].name 
                      << std::setw(8) << bookedPassengers[i].age 
                      << std::setw(10) << bookedPassengers[i].gender 
                      << bookedPassengers[i].seatNumber << "\n";
        }
        std::cout << "==================================================\n";
        std::cout << "Ticket status: CONFIRMED\n";
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0)));
    std::vector<Train> schedule;
    schedule.emplace_back("12424", "NDLS DBRT RAJDHANI", "New Delhi", "Dibrugarh", 50, 2450.00);
    schedule.emplace_back("12002", "NDLS BPL SHATABDI", "New Delhi", "Bhopal", 40, 1150.00);

    int choice;
    do {
        std::cout << "\n===== Indian Railways Passenger Terminal =====\n";
        std::cout << "1. View Train Schedules\n";
        std::cout << "2. Reserve Tickets\n";
        std::cout << "3. Exit Application\n";
        std::cout << "==============================================\n";
        std::cout << "Enter choice (1-3): ";

        while (!(std::cin >> choice)) {
            std::cout << "Invalid entry. Enter a valid option: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        if (choice == 1) {
            std::cout << "\n---------------------------------------------------------------------------------\n";
            std::cout << std::left << std::setw(12) << "Train No." 
                      << std::setw(22) << "Train Name" 
                      << std::setw(15) << "Source" 
                      << std::setw(15) << "Destination" 
                      << std::setw(10) << "Available" 
                      << "Base Fare\n";
            std::cout << "---------------------------------------------------------------------------------\n";
            for (const auto& train : schedule) {
                train.displayTrainRoute();
            }
            std::cout << "---------------------------------------------------------------------------------\n";
        } 
        else if (choice == 2) {
            std::string searchNum;
            std::cout << "\nEnter Train Number to book ticket: ";
            std::cin >> searchNum;

            bool found = false;
            for (auto& train : schedule) {
                if (train.getTrainNumber() == searchNum) {
                    train.bookRailwayTicket();
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Error: Train number not recognized in system routing maps.\n";
            }
        } 
        else if (choice == 3) {
            std::cout << "\nThank you for journeying with Indian Railways. Safe travels!\n";
        } 
        else {
            std::cout << "Selection out of bounds.\n";
        }

    } while (choice != 3);

    return 0;
}
