#ifndef NETWORK_CLIENT_H
#define NETWORK_CLIENT_H

class NetworkClient
{
    public:
    void post(const char* url, const char* contentType, const char* body);
};

#endif