#include <iostream>
#include <string>
using namespace std;

// Function to encrypt the plaintext using Caesar Cipher
string encryptCaesarCipher(string plaintext, int key) {
    string ciphertext = "";
    for (size_t i = 0; i < plaintext.length(); ++i) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            char encryptedChar = ((plaintext[i] - base + key) % 26) + base;
            ciphertext += encryptedChar;
        } else {
            ciphertext += plaintext[i]; // Leave non-alphabetic characters unchanged
        }
    }
    return ciphertext;
}

// Function to decrypt the Caesar Cipher ciphertext
string decryptCaesarCipher(string ciphertext, int key) {
    // Decrypting a Caesar Cipher is the same as encrypting with a negative key
    return encryptCaesarCipher(ciphertext, -key);
}

int main() {
    string plaintext, ciphertext;
    int key;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the key (a positive integer): ";
    cin >> key;

    ciphertext = encryptCaesarCipher(plaintext, key);
    cout << "Encrypted ciphertext: " << ciphertext << endl;

    string decryptedText = decryptCaesarCipher(ciphertext, key);
    cout << "Decrypted plaintext: " << decryptedText << endl;

    return 0;
}

