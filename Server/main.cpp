#include <iostream>
#include <cpp-httplib/httplib.h>
#include <string>

using namespace std;

const int PORT = 9999;
const string HOST = "192.168.0.199";

int main() {
    string html = "Connected";
    httplib::Server svr;

    // Define a route for the root path "/"
    svr.Get("/", [html](const httplib::Request &, httplib::Response &res) {
        res.set_content(html, "text/plain");
    });

    // Start the server on 0.0.0.0 (all network interfaces) and port 8000
    svr.listen(HOST, PORT);

    return 0;
}
