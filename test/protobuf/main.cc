#include <iostream>
#include "test.pb.h"

using namespace std;
using namespace fixbug;

int main()
{
    GetFriendListResponse fresp;
    Response* resp = fresp.mutable_resp();
    resp->set_errcode(1);
    resp->set_errmsg("pwd is wrong");
    User* user = fresp.add_users();
    user->set_age(18);
    user->set_name("zhangsan");
    user->set_sex(User::Sex::User_Sex_M);
    cout << fresp.users_size() << endl;

    User* user1 = fresp.add_users();
    user1->set_age(20);
    user1->set_name("lisi");
    user1->set_sex(User::Sex::User_Sex_W);
    cout << fresp.users_size() << endl;

    string data;
    if(fresp.SerializeToString(&data))
    {
        cout << data << endl;
    }

    GetFriendListResponse result;
    
    if(result.ParseFromString(data))
    {
        cout << result.users_size() << endl;

        const Response& r = result.resp();
        cout << r.errcode() << endl;
        cout << r.errmsg() << endl;

        for(int i = 0;i < result.users_size();i++)
        {
            cout << "-------------------------" << endl;
            const User& user = result.users(i);
            cout << user.name() << endl;
            cout << user.age() << endl;
            cout << user.sex() << endl;
        }
    }

    return 0;
}

int main1()
{
    LoginRequest req;
    req.set_name("admin");
    req.set_pwd("123456");

    string data;
    req.SerializeToString(&data);
    cout << data.c_str() << endl;

    LoginRequest resp;
    if(resp.ParseFromString(data))
    {
        cout << resp.name() << endl;
        cout << resp.pwd() << endl;
    }

    return 0;
}