#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_SEATS 50
#define TICKET_PRICE 12

typedef struct {
    int ticket_id;
    char customer_name[50];
    int seat_number;
} Ticket;

Ticket bookings[TOTAL_SEATS];
int seat_status[TOTAL_SEATS] = {0};
int next_ticket_id = 1001;

void display_menu() {
    printf("\n=== TICKET BOOKING SYSTEM ===\n");
    printf("1. View Available Seats\n");
    printf("2. Book a Ticket\n");
    printf("3. Cancel a Ticket\n");
    printf("4. View All Bookings\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void view_seats() {
    printf("\n--- Seating Layout ---\n");
    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (seat_status[i] == 0) {
            printf("[%02d] ", i + 1);
        } else {
            printf("[XX] ");
        }
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n[XX] = Booked\n");
}

void book_ticket() {
    int seat_num;
    char name[50];

    view_seats();
    printf("\nEnter seat number to book (1-%d): ", TOTAL_SEATS);
    if (scanf("%d", &seat_num) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }

    if (seat_num < 1 || seat_num > TOTAL_SEATS) {
        printf("Error: Invalid seat number!\n");
        return;
    }

    if (seat_status[seat_num - 1] == 1) {
        printf("Error: Seat already booked!\n");
        return;
    }

    printf("Enter customer name: ");
    while (getchar() != '\n');
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    int index = seat_num - 1;
    bookings[index].ticket_id = next_ticket_id++;
    bookings[index].seat_number = seat_num;
    strcpy(bookings[index].customer_name, name);
    seat_status[index] = 1;

    printf("\nBooking Confirmed Successfully!\n");
    printf("Ticket ID  : %d\n", bookings[index].ticket_id);
    printf("Passenger  : %s\n", bookings[index].customer_name);
    printf("Seat Number: %d\n", bookings[index].seat_number);
    printf("Total Price: $%d\n", TICKET_PRICE);
}

void cancel_ticket() {
    int id, found = 0;
    printf("\nEnter Ticket ID to cancel: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }

    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (seat_status[i] == 1 && bookings[i].ticket_id == id) {
            seat_status[i] = 0;
            printf("Ticket ID %d has been cancelled successfully.\n", id);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Error: Ticket ID not found.\n");
    }
}

void view_bookings() {
    int found = 0;
    printf("\n=== Active Bookings ===\n");
    printf("%-10s %-25s %-10s\n", "Ticket ID", "Customer Name", "Seat Num");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (seat_status[i] == 1) {
            printf("%-10d %-25s %-10d\n", bookings[i].ticket_id, bookings[i].customer_name, bookings[i].seat_number);
            found = 1;
        }
    }

    if (!found) {
        printf("No active reservations found.\n");
    }
}

int main() {
    int choice;
    while (1) {
        display_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection. Exiting.\n");
            break;
        }
        switch (choice) {
            case 1:
                view_seats();
                break;
            case 2:
                book_ticket();
                break;
            case 3:
                cancel_ticket();
                break;
            case 4:
                view_bookings();
                break;
            case 5:
                printf("Thank you for using the ticket booking system.\n");
                exit(0);
            default:
                printf("Invalid selection! Please choose between 1 and 5.\n");
        }
    }
    return 0;
}
