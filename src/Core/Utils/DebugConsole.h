#pragma once
#include "raylib.h"
#include <iostream>
#include "string"
#include "list"

class DebugConsole {
private:
    int fontSize = 10;
    std::list<std::pair<std::string, Color>> errors;

public:
    DebugConsole();
    ~DebugConsole();
    bool hasError = false;
    // Add message
    void FatalErrorMessage(const std::string msg);
    void ErrorMessage(const std::string msg);
    void WarningMessage(const std::string msg);
    void SuccessMessage(const std::string msg);
    void AddMessage(const std::string msg, Color color);

    void DrawErrorConsole();
    void ClearConsole();

    void SetFontSize(const int &size);
};
