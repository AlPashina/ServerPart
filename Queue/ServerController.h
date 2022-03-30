
#pragma once
#include "PatientController.h"
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

class ServerController
{
private:
    PatientController pc;
    std::string ip = "127.0.0.1";
    int port = 8080;

    std::string ParseResp() {
        Patient pat = pc.GetPatient();
        std::string s_pat;
        s_pat = s_pat+ pat.FIO + "\n";
        s_pat = s_pat + pat.Born_Date + "\n";
        s_pat = s_pat + pat.Gender;
        return s_pat;
    }

public:
    void Run() {
        boost::asio::io_service ios;

        boost::asio::streambuf buff;
        std::ostringstream copy;
        boost::asio::ip::tcp::endpoint ep = boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(ip), port);
        boost::asio::ip::tcp::acceptor acceptor(ios, ep);
        std::string msg("");

        while (true) {
            boost::asio::ip::tcp::socket sock(ios);
            acceptor.accept(sock);
            size_t bytes = read_until(sock, buff, '\n');

            msg = ParseResp();
            std::cout << "server transmits message: " << std::endl << msg << std::endl << std::unitbuf;
            sock.write_some(boost::asio::buffer(msg));
            sock.close();
        }
    }
};
