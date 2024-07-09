#pragma once

#include <Windows.h>
#include <functional>
#include <string>
#include <unordered_map>

class DllUtils {
public:
    static std::function<void()> loadFunction(const std::string& moduleName, const std::string& procName);

private:
    static std::unordered_map<std::string, HMODULE>& getModuleCache();
    static std::unordered_map<std::string, std::unordered_map<std::string, FARPROC>>& getFunctionCache();
};
