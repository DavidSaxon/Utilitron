#ifndef UTILITRON_MESSAGEUTIL_H_
    #define UTILITRON_MESSAGEUTIL_H_

#include <iostream>

#include "StringUtil.hpp"

namespace util {

/*****************************************************\
| Functions for printing different priority messages. |
\*****************************************************/
namespace msg {

//FUNCTIONS
/*!Prints a primary level message to the given output
@output the output stream to print to
@message the message to print*/
inline void primary(std::ostream& output, const std::string& message) {

    //print out the top bar
    output << "/++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" <<
        "++++++++++++++++++\\" << std::endl;
    output << "|                                                            " <<
        "                  |" << std::endl;

    //make a copy of the message
    std::string messageCopy = message;
    //centre the message
    util::str::centre(messageCopy, 76);
    //add to the pipe to the start and the end of the message
    util::str::concatenateFront(messageCopy, "| ");
    util::str::concatenateBack(messageCopy, " |");

    //print the message
    output << messageCopy << std::endl;

    //print out the bottom bar
    output << "|                                                            " <<
        "                  |" << std::endl;
    output << "\\+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" <<
        "+++++++++++++++++++/" << std::endl;
}

/*!Prints a secondary level message to the given output
@output the output stream to print to
@message the message to print*/
inline void secondary(std::ostream& output, const std::string& message) {

    //print out the top bar
    output << "-------------------------------------------------------------" <<
        "-------------------" << std::endl;

    //make a copy of the message
    std::string messageCopy = message;
    //centre the message
    util::str::centre(messageCopy, 80);

    //print the message
    output << messageCopy << std::endl;

    //print out the bottom bar
    output << "-------------------------------------------------------------" <<
        "-------------------" << std::endl;

}

/*!Prints a tertiary level message to the given output
@ouput the output stream to print to
@message the message to print*/
inline void tertiary(std::ostream& output, const std::string& message) {

    //make a copy of the message
    std::string messageCopy = message;
    //centre the message
    util::str::centre(messageCopy, 74);

    //add the arrows either side
    util::str::concatenateFront(messageCopy, "-> ");
    util::str::concatenateBack(messageCopy, " <-");

    //print the message
    output << messageCopy << std::endl;
}

} } //util //msg

#endif