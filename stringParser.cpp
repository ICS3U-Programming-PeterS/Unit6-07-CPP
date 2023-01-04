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


int main() {
    // User interface
    std::cout << "This program will ask the user for a sentence and then"
              << std::endl;
    std::cout << "display each word, without spaces, one per line. \n"
              << std::endl;

    // Ask user to enter a sentence
    std::cout << "Enter a string: ";
    std::string userInput;
    std::getline(std::cin, userInput);

    // Catch any invalid input
    if (userInput.length() == 0) {
        std::cout << "Invalid input. Please try again." << std::endl;
        return 0;
    }

    // Call function to parse the string and return a list of words
    std::list<std::string> words = ParseString(userInput);

    // display words
    std::cout << "The words in your sentence, without spaces, are:"
              << std::endl;
    for (const std::string& word : words) {
        std::cout << word << std::endl;
    }
}
