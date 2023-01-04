// Copyright (c) 2022 Peter Sobowale All rights reserved.
//
// Created by: Peter Sobowale
// Created on: January 3, 2023
// This program asks the user to enter a sentence, then it parses
// the sentence and returns a list of words. Finally, the program
// displays the words one per line.
#include <iostream>
#include <list>
#include <string>


// ParseString function
// Accepts a string and returns a list of words
std::list<std::string> ParseString(std::string aString) {
    std::list<std::string> words;
    std::string word = "";
    for (int i = 0; i < aString.length(); i++) {
        if (aString[i] == ' ') {
            words.push_back(word);
            word = "";
        } else {
            word = word + aString[i];
        }
    }
    words.push_back(word);
    return words;
}

// DisplayWords function
// Accepts a list of words and displays them, one per line
void DisplayWords(std::list<std::string> words) {
    for (const std::string& word : words) {
        std::cout << word << std::endl;
    }
}

int main() {
    // Ask user to enter a sentence
    std::cout << "Enter a sentence: ";
    std::string userInput;
    std::getline(std::cin, userInput);
    std::cout << "\n";

    // Catch any invalid input
    if (userInput.length() == 0) {
        std::cout << "Invalid input. Please try again." << std::endl;
    }

    // Call function to parse the string and return a list of words
    std::list<std::string> words = ParseString(userInput);

    // Call function to display the words, one per line
    DisplayWords(words);
}
