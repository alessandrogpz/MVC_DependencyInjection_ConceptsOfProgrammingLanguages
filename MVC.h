#pragma once
#include <iostream>
#include <string>

// Logger object
class Logger {
public:
    void log(const std::string& message);
};

// Configuration object
class Configuration {
public:
    Configuration() : app_name("HelloApp") {}
    std::string app_name;
};

// Model
class Model {
public:
    void setName(const std::string& name);
    std::string getName() const;
    std::string name_;
};

// View
class View {
public:
    std::string askForName();

    void displayGreeting(const std::string& name);
};

// Controller
class Controller {
public:
    // Use shared_ptr for dependencies
    Controller(std::shared_ptr<Model> model, std::shared_ptr<View> view, std::shared_ptr<Logger> logger)
        : model_(model), view_(view), logger_(logger) {}

    void run() const;

private:
    std::shared_ptr<Model> model_;
    std::shared_ptr<View> view_;
    std::shared_ptr<Logger> logger_;
};