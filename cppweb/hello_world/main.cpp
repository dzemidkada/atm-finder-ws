#include "crow_all.h"

int main(int argc, char* argv[]) {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")
        ([](){
            return "<div><h1>Hello world!</h1></div>";
        });

    char* port = getenv("PORT");
    uint16_t iport = static_cast<uint16_t>(port != NULL ? std::stoi(port) : 18018);
    std::cout << "PORT = " << iport << "\n";
    app.port(iport).multithreaded().run();
}
