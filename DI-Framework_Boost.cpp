#include "MVC.h"
#include "BoostDI.hpp"


// DI Main with Boost DI framework
int main() {
    auto injector = boost::di::make_injector();
    
    auto config = injector.create<Configuration>();
    auto logger = injector.create<Logger>();
    auto model = injector.create<Model>();
    auto view = injector.create<View>();
    auto controller = injector.create<Controller>();

    logger.log("App Name: " + config.app_name + " - BoostDI");
    controller.run();
    
    return 0;
}