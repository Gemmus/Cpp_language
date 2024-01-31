/* Operator overloading

Implement class House for storing housing information.

The class must use std::string for storing the address of the house, a double for the size (area in m2) of the house and
an int for the price of the house in euros. All data member must be private.

Class must define a constructor that takes the house information as parameters and there must be default constructor.

The class must have the following operators:
• Output operator for printing the housing information with minimal formatting. No newlines may be printed by the operator.
• Input operator for reading the housing information from a stream. The operator must accept the format produced by the
  output operator. The address of the house may contain spaces so the operator must be able to read an address with spaces
  in it.
• Less than operator that compares two houses by price/m2

Class must define the following member functions:
• setAddress for seDng the address of the house
• setArea for seDng the area of the house
• setPrice for seDng the price of the house

Write a program that defines a vector of House.

The program asks user to enter information of five houses and stores them in the vector. The houses must be asked in the
following ways:
• Ask user to enter the house information (address, area, price) and use constructor to create a house by passing the
  information as parameters
• Create a house using default constructor, ask user to enter the house information and use setter functions before adding
  the house to the vector
• Create house using default constructor and read values using the input operator

You can decide the mix between the five houses but at least one house must be asked using each of the above ways.

Then sort the vector using std::sort and print the house information one house per line.

Notes:
To read a string from a stream using other that default delimiter (white space) you can use std::getline. It has
overload that takes three parameters: stream to read from, reference to a string, and delimiting character.
For example:
std::getline(std::cin, my_str, ':');
*/

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>

#define maxN 5

using namespace std;

class House{
    friend ostream& operator<<(ostream& out, const House& house1) {
        out << house1.address << ": " << house1.size << " " << house1.price;
        return out;
    }

    friend istream& operator>>(istream& in, House& house2) {
        getline(in, house2.address, ':');
        in >> house2.size >> house2.price;
        return in;
    }

public:
    explicit House(string address0="", double size0=0, int price0=0) {
        address = std::move(address0);
        size = size0;
        price = price0;
    }

    bool operator<(const House &rightHouse) const {
        return price/size < rightHouse.price/rightHouse.size;
    }

    void setAddress(string &address0) {
        address = address0;
    }

    void setArea(double size0) {
        size = size0;
    }

    void setPrice(int price0) {
        price = price0;
    }

private:
    string address;
    double size;
    int price;
};

int main() {

    vector<House> houseVector;
    string address;
    double size;
    int price;

    /* Ask user to enter the house information (address, area, price) and use constructor to create a house by passing */
    /* the information as parameters */
    for (int i = 0; i < maxN - 2; i++) {
        cout << "Enter the house information (address, area, price): ";
        getline(cin, address, ':');
        cin >> size >> price;
        House house1(address, size, price);
        houseVector.push_back(house1);
    }

    /* Create a house using default constructor, ask user to enter the house information and use setter functions before */
    /* adding the house to the vector */
    cout << "Enter the house information (address, area, price): ";
    getline(cin, address, ':');
    cin >> size >> price;
    House house2;
    house2.setAddress(address);
    house2.setArea(size);
    house2.setPrice(price);
    houseVector.push_back(house2);

    /* Create house using default constructor and read values using the input operator */
    House house3;
    cout << "Enter the house information (address, area, price): ";
    cin >> house3;
    houseVector.push_back(house3);

    cout << "Sorted house information:";
    sort(houseVector.begin(), houseVector.end());
    for (int i = 0; i < maxN; i++) {
        cout << houseVector[i] << endl;
    }

    return 0;
}
