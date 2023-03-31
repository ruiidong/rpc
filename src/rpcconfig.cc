#include "rcpconfig.h"
#include <iostream>

using namespace std;

void RpcConfig::LoadConfig(const char* configfile)
{
    FILE* fp = fopen(configfile,"r");
    if(fp == nullptr)
    {
        cout << "配置文件打开失败" << endl;
        exit(EXIT_FAILURE);
    }
    while(!feof(fp))
    {
        char buf[512];
        fgets(buf,512,fp);

        string tmp = buf;
        int idx = tmp.find_first_not_of(' ');
        if(idx != -1)
        {
            tmp = tmp.substr(idx,tmp.size()-idx);
        }
        idx = tmp.find_last_not_of(' ');
        if(idx != -1)
        {
            tmp = tmp.substr(0,idx+1);
        }

        if(tmp[0]=='#' || tmp.empty())
        {
            continue;
        }

        idx = tmp.find('=');
        if(idx == -1)
        {
            continue;
        }

        int cr = tmp.find('\n');
        if(cr != -1)
        {
            cr = 1;
        }
        else
        {
            cr = 0;
        }

        string key = tmp.substr(0,idx);
        string value = tmp.substr(idx+1,tmp.size()-idx-1-cr);
        configMap_[key] = value;
    }
}

string RpcConfig::Load(const string& key)
{
    const auto& it = configMap_.find(key);
    if(it != configMap_.end())
    {
        return it->second;
    }
    return "";
}