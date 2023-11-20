#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>

class Vigenere {
public:
    // Constructor
    Vigenere(std::string key) : key(key) {}

    // Destructor
    ~Vigenere() {}

    // Encrypts the given message using the key
    std::string encrypt(std::string msg) {
        std::string encrypted_message = "";
        size_t key_index = 0;

        for (char c : msg) {
            if (isalpha(c)) {
                char key_char = toupper(key[key_index % key.length()]);
                int shift = key_char - 'A';
                char encrypted_char = shiftChar(c, shift);
                encrypted_message += encrypted_char;
                key_index++;
            } else {
                encrypted_message += c;
            }
        }

        return encrypted_message;
    }

    // Decrypts the given encrypted message using the key
    std::string decrypt(std::string msg) {
        std::string decrypted_message = "";
        size_t key_index = 0;

        for (char c : msg) {
            if (isalpha(c)) {
                char key_char = toupper(key[key_index % key.length()]);
                int shift = key_char - 'A';
                char decrypted_char = shiftChar(c, -shift);
                decrypted_message += decrypted_char;
                key_index++;
            } else {
                decrypted_message += c;
            }
        }

        return decrypted_message;
    }

    // Checks if the encryption and decryption are consistent
    bool isEncrypted(std::string encryptedMsg, std::string decryptedMessage) {
        return encrypt(decryptedMessage) == encryptedMsg;
    }

    // Allows the user to change the key used for encryption and decryption
    void setKey(std::string key) {
        this->key = key;
    }

private:
    // Helper function to shift characters based on the key
    static char shiftChar(char c, int shift) {
        if (isupper(c)) {
            return ((c - 'A' + shift + 26) % 26) + 'A';
        } else {
            return c;
        }
    }

    std::string key;
};

#endif // VIGENERE_H
