#include "ui.h"
#include <iostream>


int main(int argc, char* argv[]) {
    try {
        UserInterface ui(argc, argv);
        ui.run();
    }
    catch (const BasicClientException& e) {
        std::cerr << "Exception: " << e.what() << "\n";
        return 1;
    }
    catch (const std::exception& e) {
        std::cerr << "Unexpected Exception: " << e.what() << "\n";
        return 1;
    }
    return 0;
}