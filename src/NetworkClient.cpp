#include "NetworkClient.h"
#include <HTTPClient.h>

void NetworkClient::post(const char* url, const char* contentType, const char* body)
{
    HTTPClient client;
    client.begin(url);
    client.addHeader("Content-Type", contentType);
    client.POST(body);
    client.end();
}