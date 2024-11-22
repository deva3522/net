#include <stdio.h>

// Function to encrypt a single word using Caesar Cipher
void caesarCipherEncrypt(char word[], int shift) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            word[i] = (word[i] - 'A' + shift) % 26 + 'A';
        } else if (word[i] >= 'a' && word[i] <= 'z') {
            word[i] = (word[i] - 'a' + shift) % 26 + 'a';
        }
    }
}

// Function to decrypt a single word using Caesar Cipher
void caesarCipherDecrypt(char word[], int shift) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            word[i] = (word[i] - 'A' - shift + 26) % 26 + 'A';
        } else if (word[i] >= 'a' && word[i] <= 'z') {
            word[i] = (word[i] - 'a' - shift + 26) % 26 + 'a';
        }
    }
}

int main() {
    char word[100];
    int shift, choice;

    // Input single word and shift value
    printf("Enter a word: ");
    scanf("%s", word);
    printf("Enter shift value: ");
    scanf("%d", &shift);

    // Choose encryption or decryption
    printf("Choose an option:\n1. Encrypt\n2. Decrypt\nYour choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        caesarCipherEncrypt(word, shift);
        printf("Encrypted word: %s\n", word);
    } else if (choice == 2) {
        caesarCipherDecrypt(word, shift);
        printf("Decrypted word: %s\n", word);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
