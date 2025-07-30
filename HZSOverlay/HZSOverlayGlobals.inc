enum struct HZSOVERLAY
{
    bool Enable;
    bool EnableHitmarker;
    char HitmarkerPath[PLATFORM_MAX_PATH];

    bool EnableKillOverlay;
    float KillComboWait;
    int Combo0KillCount;
    char ShowKillCombo0Path[PLATFORM_MAX_PATH];
    int Combo1KillCount;
    char ShowKillCombo1Path[PLATFORM_MAX_PATH];
    int Combo2KillCount;
    char ShowKillCombo2Path[PLATFORM_MAX_PATH];
    int Combo3KillCount;
    char ShowKillCombo3Path[PLATFORM_MAX_PATH];
    int Combo4KillCount;
    char ShowKillCombo4Path[PLATFORM_MAX_PATH];
    int Combo5KillCount;
    char ShowKillCombo5Path[PLATFORM_MAX_PATH];
    int MaxComboKillCount;

    bool EnableRoundWinOverlay;
    char RoundWinOverlayPath[PLATFORM_MAX_PATH];

    bool EnableRoundLostOverlay;
    char RoundLostOverlayPath[PLATFORM_MAX_PATH];
}
HZSOVERLAY g_HZSOVERLAYCFG;

Handle g_hClientComboTimers[MAXPLAYERS + 1] = {INVALID_HANDLE, ...};
int KillCombo[MAXPLAYERS + 1];