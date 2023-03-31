#pragma once
#include "rcpconfig.h"

class RpcApplication
{
public:
    static void Init(int argc, char** argv);
    static RpcApplication& GetInstance();
    RpcConfig& getRpcConfig();
private:
    RpcApplication(){}
    RpcApplication(const RpcApplication& rhs) = delete;
    RpcApplication(RpcApplication&& rhs) = delete;
    static RpcConfig rpcConfig_;
};