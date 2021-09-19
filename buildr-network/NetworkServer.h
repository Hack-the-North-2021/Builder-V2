#ifndef __NETWORKSERVER_H__
#define __NETWORKSERVER_H__

#include <winsock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

#include <stdio.h>
#include <stdlib.h>

#include <thread>
#include <map>

#include "json.hpp"

typedef struct sockaddr Sockaddr;
typedef struct sockaddr_in SockaddrIn;

typedef void (*NetworkCallback)(int client_id, const nlohmann::json& json_cmd);

class NetworkServer
{
private:
    /* int server_fd; */
    SOCKET server_fd;
    SockaddrIn address;
    int port;
    std::map<int,NetworkCallback> network_callbacks;
public:
    NetworkServer(int port, std::map<int,NetworkCallback> network_callbacks);
    ~NetworkServer();
    void OpenConnection();
    void SendRawMessage(int client_sock, const nlohmann::json& data);
 private:
    void Listen();
    void HandleConnection(int client_sock);
    void DispatchCmd(int client_sock, const std::string& json_string);
};

#endif // __NETWORKSERVER_H__
