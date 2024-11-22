#include <iostream>
#include <string>
using namespace std;

// Function to encrypt the message
void encryptMsg(string msg, int key) {
    string encrypted = ""; // To store the encrypted message
    int msgLen = msg.length();

    // Loop through each row in the Rail Fence
    for (int i = 0; i < key; ++i) {
        int step1 = (key - i - 1) * 2; // Step down
        int step2 = i * 2;            // Step up
        int pos = i;

        bool toggle = true; // Toggle between step1 and step2
        while (pos < msgLen) {
            encrypted += msg[pos]; // Add the character to the encrypted message

            if (step1 == 0)        // If step1 is 0, always use step2
                pos += step2;
            else if (step2 == 0)   // If step2 is 0, always use step1
                pos += step1;
            else {
                pos += (toggle ? step1 : step2); // Alternate steps
                toggle = !toggle;               // Flip the toggle
            }
        }
    }

    cout << "Encrypted Message: " << encrypted << endl;
}

// Function to decrypt the message
void decryptMsg(string enMsg, int key) {
    string decrypted(enMsg.length(), '*'); // To store the decrypted message
    int msgLen = enMsg.length();

    int idx = 0; // Index for the encrypted message
    for (int i = 0; i < key; ++i) {
        int step1 = (key - i - 1) * 2; // Step down
        int step2 = i * 2;            // Step up
        int pos = i;

        bool toggle = true; // Toggle between step1 and step2
        while (pos < msgLen) {
            decrypted[pos] = enMsg[idx++]; // Fill the decrypted message

            if (step1 == 0)
                pos += step2;
            else if (step2 == 0)
                pos += step1;
            else {
                pos += (toggle ? step1 : step2);
                toggle = !toggle;
            }
        }
    }

    cout << "Decrypted Message: " << decrypted << endl;
}

int main() {
    string msg, enMsg;
    int key;

    cout << "Enter message to be encrypted: ";
    cin >> msg; // Input the message to encrypt
    cout << "Enter the key: ";
    cin >> key; // Input the number of rails
    encryptMsg(msg, key);

    cout << "Enter message to be decrypted: ";
    cin >> enMsg; // Input the encrypted message
    cout << "Enter the key: ";
    cin >> key; // Input the number of rails
    decryptMsg(enMsg, key);

    return 0;
}
