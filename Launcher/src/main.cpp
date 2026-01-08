#include <iostream>
#include <vector>
#include <windows.h>
#include <filesystem>
#include <map>
#include <thread>


namespace fs = std::filesystem;


std::map<std::string, std::vector<fs::path>> dependencies = {
    {"engine", {"bin\\VoxCore"}},
    {"game", {"bin\\MyVoxelGame"}}
};

int main() {
    char exePathBuffer[MAX_PATH];
    if (!GetModuleFileNameA(nullptr, exePathBuffer, MAX_PATH)) {
        std::cerr << "Failed to get executable path\n";
        return -1;
    }
    fs::path exePath = fs::path(exePathBuffer).parent_path();

    for (const auto& enginePath : dependencies["engine"]) {
        fs::path fullEnginePath = exePath / enginePath;
        if (!SetDllDirectoryA(fullEnginePath.string().c_str())) {
            std::cerr << "Failed to set DLL directory: " << fullEnginePath << "\n";
        }
        LoadLibraryA(fullEnginePath.string().c_str());
    }
    fs::path gameDllPath = exePath / (dependencies["game"][0].string() + ".dll");
    HMODULE lib = LoadLibraryA(gameDllPath.string().c_str());
    if (!lib) {
        DWORD err = GetLastError();
        std::cout << "LoadLibrary failed, error = " << err << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(10));
        return -1;
    }
    using GameEntryFn = int(*)();
    auto entry = reinterpret_cast<GameEntryFn>(GetProcAddress(lib, "GameEntry"));
    if (!entry) {
        std::cerr << "No GameEntry in " << gameDllPath << "\n";
        return -1;
    }
    return entry();
}