#include "MVC.h"

// Main entry point with manual DI
int main() {
    Configuration config;
    auto logger = std::make_shared<Logger>();
    auto model = std::make_shared<Model>();
    auto view = std::make_shared<View>();
    Controller controller(model, view, logger);

    logger->log("App Name: " + config.app_name + " - Manual DI");
    controller.run();
    return 0;
}

