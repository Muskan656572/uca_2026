#include <iostream>
#include <string>

using namespace std;

class Base64Encoder {
private:

    const string table =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";

public:

    string encode(const string& input) {

        string result;

        for (int i = 0; i < input.length(); i += 3) {

            // First byte is always available
            int b1 = input[i];

            // Second and third bytes may not exist
            int b2 = 0;
            int b3 = 0;

            if (i + 1 < input.length()) {
                b2 = input[i + 1];
            }

            if (i + 2 < input.length()) {
                b3 = input[i + 2];
            }

            // Create four 6-bit values

            int index1 = b1 >> 2;

            int index2 = ((b1 & 3) << 4) | (b2 >> 4);

            int index3 = ((b2 & 15) << 2) | (b3 >> 6);

            int index4 = b3 & 63;

            // First two characters are always added
            result += table[index1];
            result += table[index2];

            // Third character
            if (i + 1 < input.length()) {
                result += table[index3];
            } else {
                result += '=';
            }

            // Fourth character
            if (i + 2 < input.length()) {
                result += table[index4];
            } else {
                result += '=';
            }
        }

        return result;
    }
};

int main() {

    string input;

    getline(cin, input);

    Base64Encoder encoder;

    cout << encoder.encode(input) << endl;

    return 0;
}