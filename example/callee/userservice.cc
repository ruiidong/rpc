#include <iostream>
#include "user.pb.h"
#include "rpcapplication.h"
#include "rpcprovider.h"

using namespace std;

class UserService : public fixbug::UserServiceRpc
{
public:
    bool Login(const string& name, const string& pwd)
    {
        cout << "doing local service: login" << endl;
        cout << "name:" << name << " pwd:" << pwd << endl;
        return true;
    }
    void Login(::google::protobuf::RpcController *controller,
                       const ::fixbug::LoginRequest *request,
                       ::fixbug::LoginResponse *response,
                       ::google::protobuf::Closure *done)
    {
        string name = request->name();
        string pwd = request->pwd();

        bool loginResult = Login(name, pwd);

        fixbug::Response* resp = response->mutable_resp();
        resp->set_errcode(0);
        resp->set_errmsg(0);
        
        done->Run();
    }
};

int main(int argc,char** argv)
{
    RpcApplication::Init(argc, argv);

    RpcProvider provider;
    provider.NotifyService(new UserService());

    provider.Run();

    return 0;
}