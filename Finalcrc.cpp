#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
    
string message, generator;
cout << "Enter message bits: ";
cin >> message;
cout << "Enter generator: ";
cin >> generator;

vector<int> data(message.length() + generator.length() - 1);
vector<int> divisor(generator.length());

for (int i = 0; i < message.length(); i++)
data[i] = message[i] - '0';
for (int i = 0; i < generator.length(); i++)
divisor[i] = generator[i] - '0';

// Calculation of CRC
for (int i = 0; i < message.length(); i++) {
    if (data[i] == 1) {
        for (int j = 0; j < divisor.size(); j++)
            data[i + j] ^= divisor[j];
    }
}

// Display CRC
cout << "The checksum code is: ";
for (int i = 0; i < message.length(); i++)
    data[i] = message[i] - '0';
for (int i = 0; i < data.size(); i++)
    cout << data[i];
cout << endl;

// Check for input CRC code
cout << "Enter checksum code: ";
cin >> message;
cout << "Enter generator: ";
cin >> generator;
data.resize(message.length() + generator.length() - 1);
divisor.resize(generator.length());
for (int i = 0; i < message.length(); i++)
    data[i] = message[i] - '0';
for (int i = 0; i < generator.length(); i++)
    divisor[i] = generator[i] - '0';

// Calculation of remainder
for (int i = 0; i < message.length(); i++) {
    if (data[i] == 1) {
        for (int j = 0; j < divisor.size(); j++)
            data[i + j] ^= divisor[j];
    }
}

// Display validity of data
bool valid = true;
for (int i = 0; i < data.size(); i++)
    if (data[i] == 1) {
        valid = false;
        break;
    }

if (valid)
    cout << "Data stream is valid" << endl;
else
    cout << "Data stream is invalid. CRC error occurred." << endl;
return 0;
}
