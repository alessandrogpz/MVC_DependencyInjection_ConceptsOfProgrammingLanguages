#include "MVC.h"

// Logger object
void Logger::log(const std::string& message) {
    std::cout << "[LOG]: " << message << "\n";
    }

// Configuration object

// Model
void Model::setName(const std::string& name) { name_ = name; }
std::string Model::getName() const { return name_; }

// View
std::string View::askForName() {
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    return name;
}

void View::displayGreeting(const std::string& name) {
    std::cout << "Hello " << name << "!" << "\n";
}

// Controller
void Controller::run() const {
    logger_->log("Starting application...");
    std::string name = view_->askForName();
    model_->setName(name);
    view_->displayGreeting(model_->getName());
    logger_->log("Application finished.");
}