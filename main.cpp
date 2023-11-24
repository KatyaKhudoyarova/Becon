#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

class Codder {
private:
    std::string key = "aaaaabbbbbabbbaabbababbaaababaab"; // ключ-ланцюжок
    std::string string1 = "abcdefghijklmnopqrstuvwxyz"; // алфавіт

public:
    void codder(const std::string& text) {
        std::cout << "Encoded message using ab-groups:" << std::endl;
        std::string lowerCaseText = text;
        for (char& c : lowerCaseText) {
            c = std::tolower(c); // Перетворення букв у введеному тексті до нижнього регістру
        }

        for (char c : lowerCaseText) {
            if (std::isalpha(c)) {
                int index = c - 'a'; // Отримання порядкового номера літери в алфавіті

                if (index >= 0 && index < key.length() - 4) {
                    std::string code = key.substr(index, 5); // Отримання 5 символів з ключа

                    std::cout << code << " "; // Виведення ab-групи для кожної літери
                } else {
                    std::cout << "Error! Unable to find ab-group for letter: " << c << std::endl;
                }
            } else {
                std::cout << c; // Виведення не-буквених символів як є
            }
        }
    }
};

class Encoder {
public:
    void encoder(const std::string& message) {
        std::cout <<std::endl<< "Encoded message using ab-groups:" << std::endl;

        std::string key = "abbab babab aabba bbaab abbbb babba bbbab abbbb abbaa ababb";

        std::string encodedMessage;
        std::string lowerCaseText = message;

        int count = 0;
        int keyIndex = 0;
        for (char& v : lowerCaseText) {
            if (std::isalpha(v)) {
                // Зміна регістру для кожної букви відповідно до ключа ab-груп
                if (key[keyIndex % key.length()] == 'a') {
                    encodedMessage += std::tolower(v);
                } else {
                    encodedMessage += std::toupper(v);
                }

                count++;
                keyIndex++;
            } else {
                encodedMessage += v;
            }
        }

        std::cout << encodedMessage << std::endl;

        std::string final_result = joinWordsWithSpaces(encodedMessage);
        
    }

    std::string joinWordsWithSpaces(const std::string& input) {
        std::stringstream ss(input);
        std::string word;
        std::string result;

        while (ss >> word) {
            result += word;
        }

        int count = 0;
        std::string final_result;
        for (char character : result) {
            final_result += character;
            count++;

            if (count == 5) {
                final_result += ' ';
                count = 0;
            }
        }


        return final_result;
    }
    std::string restoreSpaces(const std::string& encoded, const std::string& original) {
        std::string restored;
        size_t originalIndex = 0;

        for (char encodedChar : encoded) {
            if (std::isspace(encodedChar)) {
                restored += encodedChar;
            } else {
                while (std::isspace(original[originalIndex])) {
                    restored += original[originalIndex++];
                }
                restored += encodedChar;
                originalIndex++;
            }
        }
        return restored;
    }
};

int main() {
    Codder codderObj;
    std::string inputText;
    std::cout << "Enter a word to encode: ";
    std::getline(std::cin, inputText);
    codderObj.codder(inputText);

    Encoder encoderObj;
    std::string message = "Welcome to the Hotel California Such a lovely place Such a lovely place";

    encoderObj.encoder(message);

    return 0;
}
