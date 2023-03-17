#include "rpcapplication.h"
#include <stdlib.h>
#include <iostream>
#include <unistd.h>

using namespace std;

void ShowArgsHelp()
{
    cout << "Usage: provider -i <configfile>" << endl;
}

void RpcApplication::Init(int argc, char **argv)
{
    if(argc < 2)
    {
        ShowArgsHelp();
        exit(EXIT_FAILURE);       
    }

    int c = 0;
    string config_file;
    while(c = getopt(argc, argv, "i:") != -1)
    {
        switch (c)
        {
        case 'i':
            config_file = optarg;
            break;
        case '?':
            ShowArgsHelp();
            exit(EXIT_FAILURE);     
            break;
        case ':':
            ShowArgsHelp();
            exit(EXIT_FAILURE);     
            break;
        default:
            break;
        }
    }
}

RpcApplication &RpcApplication::GetInstance()
{
    static RpcApplication app;
    return app;
}