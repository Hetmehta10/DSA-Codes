#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SEATS 30
#define MAX_NAME_LENGTH 30

// Data structure to represent a ticket
typedef struct {
    int seat_number;
    char passenger_name[MAX_NAME_LENGTH];
    bool booked;
} Ticket;

// Function prototypes
void initializeTickets(Ticket tickets[], int num_tickets);
void displayAvailableSeats(Ticket tickets[], int num_tickets);
void bookTicket(Ticket tickets[], int num_tickets);
void cancelTicket(Ticket tickets[], int num_tickets);
int findAvailableSeat(Ticket tickets[], int num_tickets);

// Main function
int main() {
    Ticket tickets[MAX_SEATS];
    int num_tickets = MAX_SEATS;
    char choice;

    initializeTickets(tickets, num_tickets);

    do {
        printf("\n------ Ticket Booking Management System ------\n");
        printf("1. Display available seats\n");
        printf("2. Book a ticket\n");
        printf("3. Cancel a ticket\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
        case '1':
            displayAvailableSeats(tickets, num_tickets);
            break;
        case '2':
            bookTicket(tickets, num_tickets);
            break;
        case '3':
            cancelTicket(tickets, num_tickets);
            break;
        case '4':
            printf("Exiting the program. Thank you!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != '4');

    return 0;
}

// Initialize all tickets as available
void initializeTickets(Ticket tickets[], int num_tickets) {
    for (int i = 0; i < num_tickets; i++) {
        tickets[i].seat_number = i + 1;
        strcpy(tickets[i].passenger_name, "");
        tickets[i].booked = false;
    }
}

// Display available seats
void displayAvailableSeats(Ticket tickets[], int num_tickets) {
    printf("\nAvailable Seats:\n");
    for (int i = 0; i < num_tickets; i++) {
        if (!tickets[i].booked) {
            printf("Total seat %d is available\n", tickets[i].booked - 1);
        }
    }
}

// Book a ticket
void bookTicket(Ticket tickets[], int num_tickets) {
    int seat_number = findAvailableSeat(tickets, num_tickets);

    if (seat_number != -1) {
        printf("Enter passenger name: ");
        char passenger_name[MAX_NAME_LENGTH];
        scanf(" %[^\n]s", passenger_name);

        tickets[seat_number - 1].booked = true;
        strcpy(tickets[seat_number - 1].passenger_name, passenger_name);

        printf("Ticket booked successfully for seat %d\n", seat_number);
    } else {
        printf("Sorry, no seats available for booking.\n");
    }
}

// Cancel a ticket
void cancelTicket(Ticket tickets[], int num_tickets) {
    printf("Enter seat number to cancel booking: ");
    int seat_number;
    scanf("%d", &seat_number);

    if (seat_number >= 1 && seat_number <= num_tickets && tickets[seat_number - 1].booked) {
        tickets[seat_number - 1].booked = false;
        strcpy(tickets[seat_number - 1].passenger_name, "");
        printf("Booking canceled successfully for seat %d\n", seat_number);
    } else {
        printf("Invalid seat number or no booking found for this seat.\n");
    }
}

// Find an available seat for booking
int findAvailableSeat(Ticket tickets[], int num_tickets) {
    for (int i = 0; i < num_tickets; i++) {
        if (!tickets[i].booked) {
            return tickets[i].seat_number;
        }
    }
    return -1; // No available seats
}
