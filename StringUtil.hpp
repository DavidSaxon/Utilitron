#ifndef UTILITRON_STRINGUTIL_H_
#   define UTILITRON_STRINGUTIL_H_

#include <iostream>
#include <sstream>

namespace util {

/********************************\
| Functions relating to strings. |
\********************************/
namespace str {

//FUNCTIONS
/*!Concatenates the second string in front of the first string
@param a the string to be extended
@param the string to concatenate on to the front of the other string*/
inline void concatenateFront(std::string& a, const std::string& b) {

    //create a new string stream
    std::stringstream ss;
    //add the strings to it
    ss << b << a;

    //set the new string
    a = ss.str();
}

/*!Concatenates the second string on to the end of the first string
@param a the string to be extended
@param the string to concatenate on to the end of the other string*/
inline void concatenateBack(std::string& a, const std::string& b) {

    //create a new string stream
    std::stringstream ss;
    //add the strings to it
    ss << a << b;

    //set the new string
    a = ss.str();
}

/*!Generates a string containing the given amount of characters
the given number of times
@param c the character to repeat
@param n the number of times to repeat the character
@return the generated string*/
inline std::string generateRepeat(char c, unsigned n) {

    //create a new character array as the length
    char* str = new char[n + 1];
    //fill the array
    for (unsigned i = 0; i < n; ++i) {

        str[i] = c;
    }
    //add the return character
    str[n] = '\0';

    //create the string
    std::string rStr(str);
    //delete the character array
    delete str;

    //return
    return rStr;
}

/*!Centres the given string so that it occupies that given amount of characters
@str the string to centre
@charCount the number of characters to make the string full
@return the number of lines the string has been made into*/
inline unsigned centre(std::string& str, unsigned charNum) {

    //TODO: centre a string on multiple lines

    //check the length of the string
    if (str.length() < charNum) {

        //find the number of characters to add
        int addLength = charNum - str.length();

        //generate the spaces to add
        std::string whiteSpace = generateRepeat(' ', addLength / 2);

        //add the white space to the string
        concatenateFront(str, whiteSpace);
        concatenateBack(str, whiteSpace);

        //if odd add an extra space to the end
        if (addLength % 2) {

            concatenateBack(str, " ");
        }

        return 1;
    }
    else if (str.length() > charNum) {

        //TODO:
    }

    //if we are equal there is nothing to do
    return 1;
}

} } //util //str

#endif