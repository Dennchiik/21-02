#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Passport {
protected:
    string fullName;
    string passportNumber;
    string nationality;
    string dateOfBirth;

public:
    Passport(string fullName, string passportNumber, string nationality, string dateOfBirth)
        : fullName(fullName), passportNumber(passportNumber), nationality(nationality), dateOfBirth(dateOfBirth) {}

    void displayInfo() {
        cout << "Full Name: " << fullName << endl;
        cout << "Passport Number: " << passportNumber << endl;
        cout << "Nationality: " << nationality << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
    }
};

class Visa {
private:
    string country;
    string expiryDate;

public:
    Visa(string country, string expiryDate) : country(country), expiryDate(expiryDate) {}

    void displayVisaInfo() {
        cout << "Country: " << country << endl;
        cout << "Expiry Date: " << expiryDate << endl;
    }
};

class ForeignPassport : public Passport {
private:
    string passportNumberInternational;
    vector<Visa> visas;

public:
    ForeignPassport(string fullName, string passportNumber, string nationality, string dateOfBirth, string passportNumberInternational)
        : Passport(fullName, passportNumber, nationality, dateOfBirth), passportNumberInternational(passportNumberInternational) {}

    void addVisa(Visa visa) {
        visas.push_back(visa);
    }

    void displayForeignPassportInfo() {
        displayInfo();
        cout << "International Passport Number: " << passportNumberInternational << endl;
        cout << "Visa Information:" << endl;
        for (const auto& visa : visas) {
            visa.displayVisaInfo();
        }
    }
};

int main() {
    Passport ukrainianPassport("John Doe", "AA123456", "Ukrainian", "01-01-1990");
    ukrainianPassport.displayInfo();

    ForeignPassport foreignPassport("John Doe", "AA123456", "Ukrainian", "01-01-1990", "ABCD123456");
    Visa usVisa("USA", "01-01-2025");
    foreignPassport.addVisa(usVisa);
    foreignPassport.displayForeignPassportInfo();

    return 0;
}
