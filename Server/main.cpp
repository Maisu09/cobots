#include <iostream>
#include <cpp-httplib/httplib.h>
#include <string>

using namespace std;

const int PORT = 9999;
const string HOST = "192.168.0.199";

int main() {
    string html = R"({"status": "ok", "message": "Hello, ESP32!"})";
    httplib::Server svr;

    // Define a route for the root path "/"
    svr.Get("/", [html](const httplib::Request &, httplib::Response &res) {
        res.set_content(html, "application/json");
    });

    svr.Post("/data", [](const httplib::Request& req, httplib::Response& res) {
    std::cout << "Received data: " << req.body << std::endl;
    res.set_content("{\"status\": \"received\"}", "application/json");
});

    // svr.set_logger([](const auto& req, const auto& res) {
    //   your_logger(req, res);
    // });

    svr.listen(HOST, PORT);
    return 0;
}
