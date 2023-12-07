/*
Part B) (string class and handling xml)
---------------------------------------------------------------------------------------------------------------------------
Let’s use build-in C++ class string for string handling.
Develop the program that finds and extracts specified items from the xml-string using start and end tags.

Now we find and extract and display first the location information and then the temperature information.
Location can be found between the tags <location> and </location>.
The temperature is between the tags <temp_c> and </temp_c>.

Remark 1. To make it easy to find whatever information from the xml-string, write a function that takes the xml-string
and the "inner" text (same for start tag and end tag) of the tags as parameters and returns the text from between
the start tag and end tags.

For example, if you name the function as find_field, then it would be called as follows if you wanted to find the location:
location = find_field(page, "location");
and to get the temperature you could call it as follows:
temperature = find_field(page, "temp_c");
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string find_field(const string& xml, const string& tag);

int main() {
    string page, line, location, temperature;
    ifstream inputFile("weather.xml");

    while (getline(inputFile, line)) {
        page.append(line);
        line.erase();
    } // Now page is a string that contains the whole xml page

    // Here you need to write something that finds and extracts location and temperature from the XML data
    // in the string page and stores them in the strings location and temperature respectively.

    location = find_field(page, "location");
    temperature = find_field(page, "temp_c");

    cout << "Location: " << location << endl;
    cout << "Temperature: " << temperature << endl;
}

string find_field(const string& xml, const string& tag) {

    int start_pos, end_pos;
    string start_tag, end_tag, retval;

    start_tag = "<"; start_tag.append(tag); start_tag.append(">");
    end_tag = "</"; end_tag.append(tag); end_tag.append(">");

    start_pos = xml.find(start_tag) + start_tag.length();
    end_pos = xml.find(end_tag);

    retval = xml.substr(start_pos, end_pos - start_pos);

    return retval;
}
