#pragma once
#include "google/protobuf/service.h"
#include <muduo/net/TcpConnection.h>
#include <muduo/base/Timestamp.h>

class RpcProvider
{
public:
    void NotifyService(::google::protobuf::Service* serive);
    void Run();
private:
    void onConnection(const muduo::net::TcpConnectionPtr& conn);
    void onMessage(const muduo::net::TcpConnectionPtr& conn,
                            muduo::net::Buffer* buf,
                            muduo::Timestamp timestamp);
};