#include <iostream>
#include <queue>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

class Concert {
private:
	int num_seats; // Total number of seats in the theater
	int seatsAvailable; // Number of available seats
	std::queue<string> students; // Queue to manage assigned student IDs
public:
	Concert(int num_seats) : num_seats(num_seats), seatsAvailable(num_seats) {}
	void addStudent(string studentID) {
		if (seatsAvailable > 0) {

			cout << "Enter student's full name: ";
			cin.ignore();
			getline(cin, studentID);

			students.push(studentID); // Assign a seat to the student and enqueue their ID
				seatsAvailable--; // Decrement available seats
			cout << endl << "Student " << studentID << " has been assigned a seat."
				<< endl;
		}
		else {
			cout << endl << "Sorry, the theater is now full. No more students can be seated." << endl;
		}
	}
	void removeStudent() {
		int choice = 0;
		string studentID = students.front();

		cout << "Please Note: You will be removing " << studentID << ". Are you certain of this decision? Type '1' if you are, or '0' if you want to cancel the operation" << endl;
		cin >> choice;

		// Consume the newline character from the buffer
		cin.ignore();

		if (choice == 1) {
			if (!students.empty()) {
				 // Get the student ID from the front of the queue
				students.pop(); // Dequeue the student
				seatsAvailable++; // Increment available seats
				cout << endl << "Student " << studentID << " has left the theater." << endl
					<< endl;
			}
			else {
				cout << endl << "The theater is empty. No students to remove." << endl
					<< endl;
			}
		}
		else {
			cout << "Operation Cancelled" << endl;
		}
	}

	int getRemainingSeats() {
		return seatsAvailable; // Return the number of remaining seats
	}
	bool isTheaterFull() {
		return seatsAvailable == 0; // Check if the theater is full
	}
};

void setRedColor() {
#ifdef _WIN32
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
#endif
}

void setYellowColor() {
#ifdef _WIN32
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
#else
	cout << YELLOW_TEXT;
#endif
}




// Function to reset text color to default in Windows
void resetColor() {
#ifdef _WIN32
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
#endif
}

int main() {
	int numSeats;
	setYellowColor(); // Set text color to yellow
	cout << "Music Theatre Attendence System " << endl;
	cout << "-----------------------------------------" << endl;
	resetColor(); // Reset text color to default
	cout << endl << "Enter the number of seats available in the theater: ";
	cin >> numSeats;
	cout << endl;

	Concert concert(numSeats); // Create a Concert object with the specified number of seats
		int choice;
	do {
		setRedColor(); // Set text color to red
		
		cout << endl << " Music Theatre Attendance Register " << endl;
		cout << "---------------------------------------" << endl;
		resetColor(); // Reset text color to default
		cout << endl;
		cout << "1. Add student" << endl << "2. Remove student" << endl << "3. Get remaining seats" << endl << "4. Check if theater is full" << endl << "5. Quit" << endl << endl;
			cout << "Enter your choice: ";
		cin >> choice;
		string studentID;
		

		switch (choice) {
		case 1:
			
			int option;
		
			do {
				// Check if the theater is full before attempting to add a student
				if (concert.isTheaterFull()) {
					setRedColor();
					cout << "The theater is full. No more students can be seated." << endl << endl;
					resetColor();
					break; // Exit the loop if the theater is full
				}

				
				concert.addStudent(studentID);

				// Ask if the user wants to add more students
				cout << "Want to assign seats to more students? " << endl;
				cout << "1. Yes" << endl;
				cout << "2. No" << endl << endl;
				cout << "Enter your option: ";
				cin >> option;

			} while (option != 2);
			break;
		case 2:
				concert.removeStudent();
				break;
		
			
		case 3:
			cout << endl << "Remaining seats: " << concert.getRemainingSeats() <<
				endl << endl;
			break;
		case 4:
			if (concert.isTheaterFull()) {
				cout << endl << "The theater is full." << endl << endl;
			}
			else {
				cout << endl << "The theater is not full." << endl << endl;
			}
			break;
		case 5:
			cout << "Quitting the program..." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	} while (choice != 5);
	return 0;
}