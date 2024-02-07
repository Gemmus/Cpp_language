/*     Smart pointers
Implement class Apartment for storing information about rented apartment. The class must contain a shared_ptr to House
(the class you implemented in an earlier exercise), apartment number, size of the apartment in m2 and the monthly rent.
All data members must be private.

There can be multiple apartments in a house and each apartment has a smart pointer to the house they are in and the
pointer can be used to get the address of the apartment. You need to add a member func2on to House for geCng the address.

The apartment class must implement less than operator that compares apartments by monthly rent.

The apartment class must have a member func2on that prints the apartment information:
• Address and apartment nr
• Size of the apartment
• The monthly rent

Write a program that creates two houses and defines a vector of Apartments. Program adds three apartments of the first
house and four apartments of the second house to the vector. Then program sorts the apartments and prints the apartment
information on separate lines.
*/

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <memory>
#include <functional>

using namespace std;

class House{
public:
    explicit House(string address0="") {
        address = std::move(address0);
    }
    
    string getAddress() {
        return address;
    }

private:
    string address;
};

class Apartment {
public:
    explicit Apartment(shared_ptr<House> housePtr = nullptr, int number = 0, int size = 0, int rent = 0) : housePtr(std::move(housePtr)), apartment_number(number), apartment_size(size), apartment_rent(rent) {}

    bool operator<(const Apartment& right) const {
        return apartment_rent < right.apartment_rent;
    }

    void printInfo() const {
        cout << "\nAddress: " << housePtr->getAddress() << ", apartment number: " << apartment_number << endl;
        cout << "Size: " << apartment_size << " m2" << endl;
        cout << "Rent: " << apartment_rent << " euro/month" << endl << endl;
    }

private:
    shared_ptr<House> housePtr;
    int apartment_number;
    int apartment_size;
    int apartment_rent;
};

int main() {

    House house1("Karaportti 2 02610 Espoo, Finland");
    House house2("Leiritie 1 01600 Vantaa, Finland");
    vector <Apartment> apartments;

    apartments.emplace_back(make_shared<House>(house1), 12, 65, 1500);
    apartments.emplace_back(make_shared<House>(house1), 24, 124, 3280);
    apartments.emplace_back(make_shared<House>(house1), 3, 80, 2700);

    apartments.emplace_back(make_shared<House>(house2), 7, 45, 1100);
    apartments.emplace_back(make_shared<House>(house2), 17, 92, 2950);
    apartments.emplace_back(make_shared<House>(house2), 26, 100, 3100);
    apartments.emplace_back(make_shared<House>(house2), 31, 73, 1720);

    sort(apartments.begin(), apartments.end());

    for (const auto& apartment : apartments) {
        apartment.printInfo();
    }

    return 0;
}
