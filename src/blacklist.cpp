#include <array>
#include <string>
#include <algorithm>

#include "blacklist.hpp"

static bool check_blacklisted() {
    static const std::array<const char *, 16> blacklist {
        "Agent.exe",
        "Battle.net.exe",
        "BethesdaNetLauncher.exe",
        "EpicGamesLauncher.exe",
        "ffxivlauncher.exe",
        "ffxivlauncher64.exe",
        "IGOProxy.exe",
        "IGOProxy64.exe",
        "Origin.exe",
        "OriginThinSetupInternal.exe",
        "steam",
        "steamwebhelper",
        "gldriverquery",
        "vulkandriverquery",
        "Steam.exe",
        "UplayService.exe",
    };

    std::string p(program_invocation_name);
    std::string proc_name = p.substr(p.find_last_of("/\\") + 1);
    const bool blacklisted = std::find(blacklist.begin(), blacklist.end(), proc_name) != blacklist.end();
#ifndef NDEBUG
    fprintf(stderr, "VKBASALT: process %s is blacklisted: %d\n", proc_name.c_str(), blacklisted);
#endif
    return blacklisted;
}

bool is_blacklisted() {
    static bool blacklisted = check_blacklisted();
    return blacklisted;
}
