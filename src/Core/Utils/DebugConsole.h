#pragma once
#include "raylib.h"
#include <iostream>
#include "string"
#include "list"
/**
 * A class for Drawing Debug Messages to the screen
 * Should be swapped out per scene
 */
class DebugConsole {
private:
    int fontSize = 10;
    std::list<std::pair<std::string, Color>> errors;

public:
    bool hasError = false;
    DebugConsole();
    ~DebugConsole();

    // Add message
    void FatalErrorMessage(const std::string msg);
    void ErrorMessage(const std::string msg);
    void WarningMessage(const std::string msg);
    void SuccessMessage(const std::string msg);
    void AddMessage(const std::string msg, Color color);

    // Draw methods
    void DrawErrorConsole();

    // Setters
    void SetFontSize(const int &size);
    void ClearConsole();
};
