#include <iostream>
#include <string>
using namespace std;

string encrypt(string text, int shift) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (isalpha(ch)) {
            int new_ch = ch + shift;
            if (isupper(ch)) {
                if (new_ch > 'Z') {
                    new_ch = new_ch - 26;
                } else if (new_ch < 'A') {
                    new_ch = new_ch + 26;
                }
            } else if (islower(ch)) {
                if (new_ch > 'z') {
                    new_ch = new_ch - 26;
                } else if (new_ch < 'a') {
                    new_ch = new_ch + 26;
                }
            }
            result += new_ch;
        } else {
            result += ch;  
        }
    }
    return result;
}

string decrypt(string text, int shift) {
    shift = 26 - shift;
    return encrypt(text, shift);
}

int main() {
    string text;
    int shift;
    cout << "Enter the text you want to encrypt:" << endl;
    getline(cin, text);
    cout << "Enter the key: ";
    cin >> shift;
    cin.ignore(); 

    string ciphertext = encrypt(text, shift);
    cout << "\nCiphertext: " << ciphertext << endl;

    string decryptedText = decrypt(ciphertext, shift);
    cout << "\nDecrypted Text: " << decryptedText << endl;

    return 0;
}

