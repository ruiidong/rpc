#pragma once

#include <string>
#include <unordered_map>

using namespace std;

class RpcConfig
{
public:
    void LoadConfig(const char* configfile);
    string Load(const string& key);
private:
    unordered_map<string,string> configMap_;
};