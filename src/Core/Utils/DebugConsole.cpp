#include "DebugConsole.h"

DebugConsole::DebugConsole() {

}

/**
 * Prints a Fatal Error Message to the screen and halts operation
 * @param msg message to print to the console
 */
void DebugConsole::FatalErrorMessage(const std::string msg) {
    AddMessage(msg, MAROON);
}

/**
 * Prints an Error Message (red)
 * @param msg message to print to the console
 */
void DebugConsole::ErrorMessage(const std::string msg) {
    AddMessage(msg, RED);
}

/**
 * Prints an Warning Message (yellow)
 * @param msg message to print to the console
 */
void DebugConsole::WarningMessage(const std::string msg) {
    AddMessage(msg, YELLOW);
}

/**
 * Prints an Success Message (green)
 * @param msg message to print to the console
 */
void DebugConsole::SuccessMessage(const std::string msg) {
    AddMessage(msg, GREEN);
}

/**
 * Adds a message to the screen
 * @param msg message to print to the console
 */
void DebugConsole::AddMessage(const std::string msg, Color color) {
    hasError = true;
    errors.push_front(std::make_pair(msg, color));

}

/**
 * Draw Loop for error console
 */
void DebugConsole::DrawErrorConsole() {
    int y = 0;
    std::list<std::pair<std::string, Color>>::iterator it;
    for (it = errors.begin(); it != errors.end(); ++it){
        DrawText(it->first.c_str(), 10, y + fontSize, fontSize, it->second);
        y += fontSize;
    }
}

/**
 * Clears the console
 */
void DebugConsole::ClearConsole(){
    hasError = false;
    errors.clear();
}

/**
 * Sets the font size of the console
 * @param size font size px
 */
void DebugConsole::SetFontSize(const int &size){
    fontSize = size;
}


