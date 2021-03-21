#include "AbstractTicket.h"

int AbstractTicket::ID = 0;

AbstractTicket::AbstractTicket()
{
    number = ++ID * 100 + rand() % 100;
}

AbstractTicket::AbstractTicket(Date departDate, Date arriveDate, string departStation,
    string arriveStation, int raceNumber)
{
    number = ++ID * 100 + rand() % 100;
}

AbstractTicket::AbstractTicket(const AbstractTicket& obj)
{
    ID++;
    number = obj.number;
    arriveDate = new Date(*obj.arriveDate);
    departDate = new Date(*obj.departDate);
    departStation = obj.departStation;
    arriveStation = obj.arriveStation;
    raceNumber = obj.raceNumber;
}

AbstractTicket::~AbstractTicket()
{
    if (arriveDate != NULL)
        delete arriveDate;
    if (departDate != NULL)
        delete departDate;

    ID--;
}

int AbstractTicket::getCount()const { return ID; }

int AbstractTicket::getNumber()const { return number; }
Date AbstractTicket::getArriveDate() const { return *arriveDate; }
Date AbstractTicket::getDepartDate() const { return *departDate; }
string AbstractTicket::getDepartStation()const { return departStation; }
string AbstractTicket::getArriveStatiob()const { return arriveStation; }
int AbstractTicket::getRaceNumber()const { return raceNumber; }

void AbstractTicket::setDepartStation(string departStation) { this->departStation = departStation; }
void AbstractTicket::setArriveStation(string arriveStation) { this->arriveStation = arriveStation; }
void AbstractTicket::setRaceNumber(int raceNumber) { this->raceNumber = raceNumber; }

string AbstractTicket::toString()
{
    string res = "Number: " + to_string(number) +
        "\nDepart station: " + departStation +
        "\nDepart date: " + departDate->toString() +
        "\nArrive station: " + arriveStation +
        "\nArrive date: " + arriveDate->toString() +
        "\nRace number: " + to_string(raceNumber) + "\n";
    return res;
}

void AbstractTicket::writeInFile(string fileName)
{
    ofstream file(fileName);

    if (file.is_open())
    {
        file << toString();
        file.close();
    }
}

void AbstractTicket::inputFromKeyboard()
{
    cout << "Depart station > ";
    cin >> departStation;

    cout << "Depart date:\n";
    departDate->inputFromKeyboard();

    cout << "Arrive station > ";
    cin >> arriveStation;

    cout << "Arrive date:\n";
    arriveDate->inputFromKeyboard();

    cout << "Race number:";
    cin >> raceNumber;

    sold = true;
}
