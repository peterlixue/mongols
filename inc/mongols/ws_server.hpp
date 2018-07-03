#ifndef WS_SERVER_HPP
#define WS_SERVER_HPP

#include "tcp_server.hpp"



namespace mongols {

    class ws_server {
    public:
        typedef std::function<std::string(
                const std::string&
                , bool&
                , bool&
                , std::pair<size_t, size_t>&
                , tcp_server::filter_handler_function&) > handler_function;
    public:
        ws_server() = delete;
        virtual~ws_server() = default;
        ws_server(const std::string& host, int port, int timeout = 5000
                , size_t buffer_size = 1024, size_t thread_size = 0, int max_event_size = 64);

    public:
        void run(const handler_function&);
        void run();
    private:
        virtual std::pair < std::string, bool> work(const handler_function&
                , const std::string&
                , bool&
                , std::pair<size_t, size_t>&
                , tcp_server::filter_handler_function&);
        std::string ws_json_parse(const std::string&
                , bool&
                , bool&
                , std::pair<size_t, size_t>&
                , tcp_server::filter_handler_function&);
    private:
        mongols::tcp_server server;

    };
}

#endif /* WS_SERVER_HPP */
