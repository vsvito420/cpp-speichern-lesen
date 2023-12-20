//Einlesen Auslesen
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person
{
public:
    Person()
    {
        string vorname;
        string nachname;
    }

    void setVorname(string vorname)
    {
        this->vorname = vorname;
    }

    void setNachname(string nachname)
    {
        this->nachname = nachname;
    }
    //get
    string getVorname()
    {
        return vorname;
    }
    string getNachname()
    {
        return nachname;
    }
private:
    string nachname;
    string vorname;
};

Person loadPerson(Person p1)
{
    ifstream file;
    file.open("person.txt");
    if (file.is_open())
    {
        string line;
        getline(file, line);
        p1.setVorname(line);
        getline(file, line);
        p1.setNachname(line);
    }
    else
    {
        cout << "Datei konnte nicht geoeffnet werden" << endl;
    }
    file.close();
    return p1;
}

Person printPerson(Person p1)
{
    cout << "Vorname: " << p1.getVorname() << endl;
    cout << "Nachname: " << p1.getNachname() << endl;
    return p1;
}

Person savePerson(Person p1)
{
    ofstream file;
    file.open("person.txt");
    if (file.is_open())
    {
        file << p1.getVorname() << endl;
        file << p1.getNachname() << endl;
    }
    else
    {
        cout << "Datei konnte nicht geoeffnet werden" << endl;
    }
    file.close();
    return p1;
}

int main()
{
    // Load Person
    Person p1;
    Person p2;

    // Save Person
    p1.setVorname("Max");
    p1.setNachname("Mustermann");
    savePerson(p1);
    // Print Person
    printPerson(p1);
    // Load Person
    p2 = loadPerson(p1);
    // Print Person
    printPerson(p2);


    return 0;
}