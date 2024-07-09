#include "dllutils.h"
#include <iostream>

std::unordered_map<std::string, HMODULE>& DllUtils::getModuleCache() {
    static std::unordered_map<std::string, HMODULE> moduleCache;
    return moduleCache;
}

std::unordered_map<std::string, std::unordered_map<std::string, FARPROC>>& DllUtils::getFunctionCache() {
    static std::unordered_map<std::string, std::unordered_map<std::string, FARPROC>> functionCache;
    return functionCache;
}

std::function<void()> DllUtils::loadFunction(const std::string& moduleName, const std::string& procName) {
    auto& moduleCache = getModuleCache();
    auto& functionCache = getFunctionCache();

    auto moduleIt = moduleCache.find(moduleName);
    if (moduleIt == moduleCache.end()) {
        HMODULE hModule = LoadLibraryA(moduleName.c_str());
        if (!hModule) {
            std::cout << "Failed to load module: " << moduleName << std::endl;
            return nullptr;
        }
        moduleIt = moduleCache.emplace(moduleName, hModule).first;
    }

    auto& funcCache = functionCache[moduleName];
    auto funcIt = funcCache.find(procName);
    if (funcIt == funcCache.end()) {
        FARPROC procAddr = GetProcAddress(moduleIt->second, procName.c_str());
        if (!procAddr) {
            std::cout << "Failed to get address of function: " << procName << std::endl;
            return nullptr;
        }
        funcIt = funcCache.emplace(procName, procAddr).first;
    }

    return reinterpret_cast<std::function<void()>>(funcIt->second);
}
