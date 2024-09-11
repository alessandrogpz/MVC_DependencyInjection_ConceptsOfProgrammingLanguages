#include "MVC.h"
#include <iostream>
#include <map>
#include <functional>
#include <memory>

// Simple DI container
class DIContainer {
public:
    template<typename T>
    void registerType() {
        creators_[typeid(T).name()] = [this]() -> std::shared_ptr<void> {
            return std::make_shared<T>();
        };
    }

    // For types with dependencies (e.g., Controller)
    template<typename T, typename... Args>
    void registerTypeWithDependencies() {
        creators_[typeid(T).name()] = [this]() -> std::shared_ptr<void> {
            return std::make_shared<T>(resolve<Args>()...);
        };
    }
    
    template<typename T>
    std::shared_ptr<T> resolve() {
        auto it = creators_.find(typeid(T).name());
        if (it != creators_.end()) {
            auto resolved_object = std::static_pointer_cast<T>(it->second());
            //std::cout << "[LOG]: Resolved object of type: " << typeid(T).name() << "\n";
            return resolved_object;
        }
        throw std::runtime_error("Type not registered in DI container.");
    }


private:
    std::map<std::string, std::function<std::shared_ptr<void>()>> creators_;
};

int main() {
    DIContainer container;
    
    // Register types
    container.registerType<Logger>();
    container.registerType<Model>();
    container.registerType<View>();
    container.registerType<Configuration>();
    
    // Register Controller with dependencies
    container.registerTypeWithDependencies<Controller, Model, View, Logger>();

    // Resolve and use the objects
    auto config = container.resolve<Configuration>();
    auto logger = container.resolve<Logger>();
    auto model = container.resolve<Model>();
    auto view = container.resolve<View>();
    auto controller = container.resolve<Controller>();

    logger->log("App Name: " + config->app_name + " - Custom DI Framework");
    controller->run();

    return 0;
}
