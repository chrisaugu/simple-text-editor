#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <iostream>
#include "libs/httplib.h" // Header-only HTTP library

// g++ -std=c++11 -O2 -o http_server main.cpp
// ./http_server

int main()
{
    try
    {
        httplib::Server svr;

        // Define a GET endpoint
        svr.Get("/", [](const httplib::Request &req, httplib::Response &res)
                { res.set_content("<h1>Hello, World!</h1>", "text/html"); });

        // Define a dynamic endpoint
        svr.Get(R"(/hello/(\w+))", [](const httplib::Request &req, httplib::Response &res)
                {
            std::string name = req.matches[1];
            res.set_content("Hello, " + name + "!", "text/plain"); });

        svr.Get("/hi", [](const httplib::Request &, httplib::Response &res)
                { res.set_content("Hello World!", "text/plain"); });

        // Error handling
        svr.set_error_handler([](const httplib::Request &, httplib::Response &res)
                              {
            res.status = 404;
            res.set_content("404 - Not Found", "text/plain"); });

        std::cout << "Server running at http://localhost:8080\n";
        svr.listen("0.0.0.0", 8080); // Listen on all interfaces, port 8080
    }
    catch (const std::exception &e)
    {
        std::cerr << "Server error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

// #include <httpserver.hpp>
// using namespace httpserver;
// class hello_world_resource : public http_resource
// {
// public:
//     std::shared_ptr<http_response> render(const http_request &)
//     {
//         return std::shared_ptr<http_response>(new string_response("Hello, World!"));
//     }
// };
// int main(int argc, char **argv)
// {
//     webserver ws = create_webserver(8080);
//     hello_world_resource hwr;
//     ws.register_resource("/hello", &hwr);
//     ws.start(true);
//     return 0;
// }