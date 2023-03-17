#pragma once

class RpcApplication
{
public:
    static void Init(int argc, char** argv);
    static RpcApplication& GetInstance();
private:
    RpcApplication(){}
    RpcApplication(const RpcApplication& rhs) = delete;
    RpcApplication(RpcApplication&& rhs) = delete;
};