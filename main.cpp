#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "Date.h"
#include "Ticket.h"
#include "ControlledTicket.h"

using namespace std;

void printTicketsList(AbstractTicket** tickets, int size)
{
    cout << "Tickets:\n\n";

    for (int i = 0; i < size; i++)
    {
        cout << tickets[i]->toString() << endl;
    }
}

void ticketFilling(AbstractTicket** tickets, int size)
{
    cout << "Filling tickers:\n";

    for (int i = 0; i < size; i++)
    {
        cout << "\nSelect type:\n";
        cout << "1. Ticket\n";
        cout << "2. Controlled ticket\n";
        int menu;
        cin >> menu;

        if (menu == 1)
        {
            Ticket* ticket = new Ticket();
            ticket->inputFromKeyboard();
            tickets[i] = ticket;
        }
        else
        {
            ControlledTicket* ticket = new ControlledTicket();
            ticket->inputFromKeyboard();

            bool b;
            cout << "Is controlled (1-yes 0-no) > ";
            cin >> b;

            ticket->setControlled(b);
            tickets[i] = ticket;
        }
    }
}

int main()
{
    srand(time(NULL));

    int size;

    cout << "Size > ";
    cin >> size;

    AbstractTicket** tickets = new AbstractTicket * [size];

    ticketFilling(tickets, size);

    cout << endl << endl;
    printTicketsList(tickets, size);



    return 0;
}
