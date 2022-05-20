#include <iostream>

std::string encrypt_caesar (std::string str, int key) {
    bool upCase;
    char lit;
    std::string newStr = "";
    key %= 26;
    for (int i = 0; i < str.length(); i++) {
        lit = str[i];
        upCase = false;
        if (lit >= 'A' && lit <= 'Z') {
            lit -= 'A';
            upCase = true;
        } else if (lit >= 'a' && lit <= 'z') lit -= 'a';
        else {
            newStr += str[i];
            continue;
        }
        lit = (lit + 26 + key) % 26;
        upCase ? lit += 'A' : lit += 'a';
        newStr += lit;
    }
    return newStr;
}

std::string decrypt_caesar (std::string str, int key) {
    return encrypt_caesar (str, - key);
}


int main() {
    std::cout << "Enter the text:" << std::endl;
    std::string str;
    getline (std::cin, str);
    std::cout << "Enter the key:" << std::endl;
    int key;
    std::cin >> key;
    std::cin.ignore ();

    std::cout << "Encrypted text: \n" << encrypt_caesar (str, key) << std::endl << std::endl;

    std::cout << "Enter the encrypted text:" << std::endl;
    std::string str2;
    getline (std::cin, str2);
    std::cout << "Enter the key:" << std::endl;
    int key2;
    std::cin >> key2;

    std::cout << "Decrypted text: \n" << decrypt_caesar (str2, key2) << std::endl;

    return 0;
}
