#include "rpcprovider.h"
#include "rpcapplication.h"
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <string>
#include <functional>

void RpcProvider::NotifyService(::google::protobuf::Service *serive)
{
    
}

void RpcProvider::onConnection(const muduo::net::TcpConnectionPtr& conn)
{

}

void RpcProvider::onMessage(const muduo::net::TcpConnectionPtr& conn,
                            muduo::net::Buffer* buf,
                            muduo::Timestamp timestamp)
{

}

void RpcProvider::Run()
{
    std::string ip = RpcApplication::GetInstance().getRpcConfig().Load("rpcserverip");
    unsigned short port = stoi(RpcApplication::GetInstance().getRpcConfig().Load("rpcserverport"));
    muduo::net::InetAddress addr(ip,port);
    muduo::net::EventLoop loop;
    muduo::net::TcpServer server(&loop,addr,"rpcprovider");

    server.setConnectionCallback(std::bind(&RpcProvider::onConnection,this,std::placeholders::_1));
    server.setMessageCallback(std::bind(&RpcProvider::onMessage,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3));

    cout << "rpcprovider start at ip:" << ip << " port:" << port << endl;
    server.setThreadNum(4);
    server.start();
    loop.loop();
}