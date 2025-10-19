#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5   // Maximum number of tickets that can be booked at a time

typedef struct {
    int ticketID;
    char name[50];
} Ticket;

Ticket queue[MAX];
int front = -1, rear = -1;

// Function to check if queue is full
int isFull() {
    return (front == (rear + 1) % MAX);
}

// Function to check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to book a ticket (Enqueue)
void bookTicket() {
    if (isFull()) {
        printf("\nBooking Full! No more tickets can be booked.\n");
        return;
    }

    Ticket t;
    printf("\nEnter Passenger Name: ");
    scanf("%s", t.name);
    t.ticketID = rand() % 1000 + 1;  // Generate random ticket ID

    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = t;
    printf("Ticket booked successfully! Ticket ID: %d\n", t.ticketID);
}

// Function to cancel a ticket (Dequeue)
void cancelTicket() {
    if (isEmpty()) {
        printf("\nNo bookings to cancel.\n");
        return;
    }

    printf("\nTicket cancelled for Passenger: %s (Ticket ID: %d)\n", queue[front].name, queue[front].ticketID);
    
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Function to display all bookings
void displayBookings() {
    if (isEmpty()) {
        printf("\nNo current bookings.\n");
        return;
    }

    printf("\n--- Current Bookings ---\n");
    int i = front;
    while (1) {
        printf("Passenger: %-15s | Ticket ID: %d\n", queue[i].name, queue[i].ticketID);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
}

// Function to show total bookings
void showStatus() {
    if (isEmpty()) {
        printf("\nNo tickets booked yet.\n");
        return;
    }

    int count = (rear >= front) ? (rear - front + 1) : (MAX - front + rear + 1);
    printf("\nTotal Tickets Booked: %d/%d\n", count, MAX);
}

// Main function
int main() {
    int choice;

    printf("========== Ticket Booking System (Circular Queue) ==========\n");

    while (1) {
        printf("\n1. Book Ticket");
        printf("\n2. Cancel Ticket");
        printf("\n3. View All Bookings");
        printf("\n4. Check Booking Status");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: bookTicket(); break;
            case 2: cancelTicket(); break;
            case 3: displayBookings(); break;
            case 4: showStatus(); break;
            case 5: 
                printf("\nExiting... Thank you for using the Ticket Booking System!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
} 
