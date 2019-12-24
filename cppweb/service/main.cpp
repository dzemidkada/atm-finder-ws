#include <string>
#include <iostream>
#include <filesystem>
#include "crow_all.h"

void send_file(crow::response& res, std::string filename, std::string content_type) {
    std::ifstream in("../public/" + filename, std::ifstream::in);
    if (in) {
        std::ostringstream contents;
        contents << in.rdbuf();
        in.close();
        res.set_header("Content-Type", content_type);
        res.write(contents.str());
    } else {
        res.code = 404;
        res.write("Not found");
    }
    res.end();
}

void send_html(crow::response& res, std::string filename) {
    std::cout << "filename = " << filename << "\n";

    send_file(res, filename + ".html", "text/html");
}

void send_image(crow::response& res, std::string filename) {
    send_file(res, "images/" + filename, "image/jpeg");
}

void send_script(crow::response& res, std::string filename) {
    send_file(res, "scripts/" + filename, "text/javascript");
}

void send_style(crow::response& res, std::string filename) {
    send_file(res, "styles/" + filename, "text/css");
}

int main(int argc, char* argv[]) {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")
        ([](const crow::request& req, crow::response& res){
            std::string path = "/usr/src/cppweb/public";
            for (const auto & entry : std::filesystem::directory_iterator(path)) {
                std::cout << entry.path() << std::endl;
            }

            send_html(res, "index");
        });

    CROW_ROUTE(app, "/styles/<string>")
        ([](const crow::request& req, crow::response& res, std::string filename){
            send_style(res, filename);
        });

    CROW_ROUTE(app, "/scripts/<string>")
        ([](const crow::request& req, crow::response& res, std::string filename){
            send_script(res, filename);
        });

    CROW_ROUTE(app, "/images/<string>")
        ([](const crow::request& req, crow::response& res, std::string filename){
            send_image(res, filename);
        });

    char* port = getenv("PORT");
    uint16_t iport = static_cast<uint16_t>(port != NULL ? std::stoi(port) : 18018);
    std::cout << "PORT = " << iport << "\n";
    app.port(iport).multithreaded().run();
}
