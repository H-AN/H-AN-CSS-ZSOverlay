
void LoadHZSOverlayConfig()
{
    KeyValues kv = new KeyValues("HZSOverlay");

    char cfgDir[PLATFORM_MAX_PATH];
    BuildPath(Path_SM, cfgDir, sizeof(cfgDir), "configs/HZSOverlay");
    if (!FileExists(cfgDir))
    {
        CreateDirectory(cfgDir, 511);
    }

    char path[PLATFORM_MAX_PATH];
    BuildPath(Path_SM, path, sizeof(path), "configs/HZSOverlay/HZSOverlayConfig.cfg");

    if (!FileExists(path))
    {
        WriteDefaultScenarioConfig(path);
    }

    if (!FileToKeyValues(kv, path))
    {
        PrintToServer("[HZSOverlayConfig] 配置读取失败！");
        delete kv;
        return;
    }

    g_HZSOVERLAYCFG.Enable = KvGetSafeBool(kv, "enable_plugins", true);

    g_HZSOVERLAYCFG.EnableHitmarker = KvGetSafeBool(kv, "Enable_Hitmarker", true);
    KvGetString(kv, "Hitmarker_Path", g_HZSOVERLAYCFG.HitmarkerPath, sizeof(g_HZSOVERLAYCFG.HitmarkerPath), "overlays/hitmarker/hitmarker");

    g_HZSOVERLAYCFG.EnableKillOverlay = KvGetSafeBool(kv, "Enable_KillOverlay", true);

    g_HZSOVERLAYCFG.KillComboWait = KvGetSafeFloat(kv, "Kill_Combo_Wait", 10.0);

    g_HZSOVERLAYCFG.Combo0KillCount = KvGetSafeNum(kv, "Combo0_KillCount", 10);
    KvGetString(kv, "ShowKill_Combo0_Path", g_HZSOVERLAYCFG.ShowKillCombo0Path, sizeof(g_HZSOVERLAYCFG.ShowKillCombo0Path), "overlays/kill/kill_1");

    g_HZSOVERLAYCFG.Combo1KillCount = KvGetSafeNum(kv, "Combo1_KillCount", 20);
    KvGetString(kv, "ShowKill_Combo1_Path", g_HZSOVERLAYCFG.ShowKillCombo1Path, sizeof(g_HZSOVERLAYCFG.ShowKillCombo1Path), "overlays/kill/kill_10");

    g_HZSOVERLAYCFG.Combo2KillCount = KvGetSafeNum(kv, "Combo2_KillCount", 30);
    KvGetString(kv, "ShowKill_Combo2_Path", g_HZSOVERLAYCFG.ShowKillCombo2Path, sizeof(g_HZSOVERLAYCFG.ShowKillCombo2Path), "overlays/kill/kill_20");

    g_HZSOVERLAYCFG.Combo3KillCount = KvGetSafeNum(kv, "Combo3_KillCount", 40);
    KvGetString(kv, "ShowKill_Combo3_Path", g_HZSOVERLAYCFG.ShowKillCombo3Path, sizeof(g_HZSOVERLAYCFG.ShowKillCombo3Path), "overlays/kill/kill_30");

    g_HZSOVERLAYCFG.Combo4KillCount = KvGetSafeNum(kv, "Combo4_KillCount", 50);
    KvGetString(kv, "ShowKill_Combo4_Path", g_HZSOVERLAYCFG.ShowKillCombo4Path, sizeof(g_HZSOVERLAYCFG.ShowKillCombo4Path), "overlays/kill/kill_40");

    g_HZSOVERLAYCFG.Combo5KillCount = KvGetSafeNum(kv, "Combo5_KillCount", 60);
    KvGetString(kv, "ShowKill_Combo5_Path", g_HZSOVERLAYCFG.ShowKillCombo5Path, sizeof(g_HZSOVERLAYCFG.ShowKillCombo5Path), "overlays/kill/kill_50");

    g_HZSOVERLAYCFG.MaxComboKillCount = KvGetSafeNum(kv, "Max_Combo_KillCount", 70);

    g_HZSOVERLAYCFG.EnableRoundWinOverlay = KvGetSafeBool(kv, "Enable_RoundWin_Overlay", true);
    KvGetString(kv, "RoundWin_Overlay_Path", g_HZSOVERLAYCFG.RoundWinOverlayPath, sizeof(g_HZSOVERLAYCFG.RoundWinOverlayPath), "overlays/kill/roundclear");

    g_HZSOVERLAYCFG.EnableRoundLostOverlay = KvGetSafeBool(kv, "Enable_RoundLost_Overlay", true);
    KvGetString(kv, "RoundLost_Overlay_Path", g_HZSOVERLAYCFG.RoundLostOverlayPath, sizeof(g_HZSOVERLAYCFG.RoundLostOverlayPath), "overlays/kill/roundfail");
    

    delete kv;

    PrecacheOverlay();
}



void WriteDefaultScenarioConfig(const char[] path)
{
    Handle file = OpenFile(path, "w");
    if (file == INVALID_HANDLE)
        return;

    WriteFileLine(file, "// HZSOverlayConfig 大灾变叠加层配置文件");
    WriteFileLine(file, "// enable_plugins 是否开启此插件");
    WriteFileLine(file, "// Enable_Hitmarker 是否开启击中提示");
    WriteFileLine(file, "// Hitmarker_Path 击中提示材质路径");
    WriteFileLine(file, "// Enable_KillOverlay 是否开启击杀提示");
    WriteFileLine(file, "// Kill_Combo_Wait 连杀等待时间 默认 10.0 ");

    WriteFileLine(file, "// Combo0_KillCount 连杀1阶段 小于 x 杀 播放 第一组连杀提示 默认 10 ");
    WriteFileLine(file, "// ShowKill_Combo0_Path 连杀1阶段 材质路径");

    WriteFileLine(file, "// Combo1_KillCount 连杀2阶段 大于 Combo0_KillCount 小于 x 杀 播放 第二组连杀提示 默认 20 ");
    WriteFileLine(file, "// ShowKill_Combo1_Path 连杀2阶段 材质路径");

    WriteFileLine(file, "// Combo2_KillCount 连杀3阶段 大于 Combo1_KillCount 小于 x 杀 播放 第二组连杀提示 默认 30 ");
    WriteFileLine(file, "// ShowKill_Combo2_Path 连杀3阶段 材质路径");

    WriteFileLine(file, "// Combo3_KillCount 连杀4阶段 大于 Combo2_KillCount 小于 x 杀 播放 第二组连杀提示 默认 40 ");
    WriteFileLine(file, "// ShowKill_Combo3_Path 连杀4阶段 材质路径");

    WriteFileLine(file, "// Combo4_KillCount 连杀5阶段 大于 Combo3_KillCount 小于 x 杀 播放 第二组连杀提示 默认 50 ");
    WriteFileLine(file, "// ShowKill_Combo4_Path 连杀5阶段 材质路径");

    WriteFileLine(file, "// Combo5_KillCount 连杀6阶段 大于 Combo4_KillCount 小于 x 杀 播放 第二组连杀提示 默认 60 ");
    WriteFileLine(file, "// ShowKill_Combo5_Path 连杀6阶段 材质路径");

    WriteFileLine(file, "// Max_Combo_KillCount 最大连杀上限 超过此连杀 循环播放连杀6阶段 默认 70 ");

    WriteFileLine(file, "// Enable_RoundWin_Overlay 是否开启胜利叠加层");
    WriteFileLine(file, "// RoundWin_Overlay_Path 胜利叠加层路径");

    WriteFileLine(file, "// Enable_RoundLost_Overlay 是否开启失败叠加层");
    WriteFileLine(file, "// RoundLost_Overlay_Path 失败叠加层路径");

    WriteFileLine(file, "//由于同时存在的叠加层只能有一个所以伤害标记与击杀提示可能会互相冲突闪烁");
    WriteFileLine(file, "//如果无法忍受闪烁可以选择保留其中一个,关闭另一个");

    WriteFileLine(file, "\"HZSOverlay\"");
    WriteFileLine(file, "{");
    WriteFileLine(file, "    \"enable_plugins\"    \"1\"");
    WriteFileLine(file, "    \"Enable_Hitmarker\"    \"1\"");
    WriteFileLine(file, "    \"Hitmarker_Path\"           \"overlays/hitmarker/hitmarker\"");
    WriteFileLine(file, "    \"Enable_KillOverlay\"              \"1\"");
    WriteFileLine(file, "    \"Kill_Combo_Wait\"              \"10.0\"");
    WriteFileLine(file, "    \"Combo0_KillCount\"          \"10\"");
    WriteFileLine(file, "    \"ShowKill_Combo0_Path\"    \"overlays/kill/kill_1\"");
    WriteFileLine(file, "    \"Combo1_KillCount\"          \"20\"");
    WriteFileLine(file, "    \"ShowKill_Combo1_Path\"    \"overlays/kill/kill_10\"");
    WriteFileLine(file, "    \"Combo2_KillCount\"          \"30\"");
    WriteFileLine(file, "    \"ShowKill_Combo2_Path\"    \"overlays/kill/kill_20\"");
    WriteFileLine(file, "    \"Combo3_KillCount\"          \"40\"");
    WriteFileLine(file, "    \"ShowKill_Combo3_Path\"    \"overlays/kill/kill_30\"");
    WriteFileLine(file, "    \"Combo4_KillCount\"          \"50\"");
    WriteFileLine(file, "    \"ShowKill_Combo4_Path\"    \"overlays/kill/kill_40\"");
    WriteFileLine(file, "    \"Combo5_KillCount\"          \"60\"");
    WriteFileLine(file, "    \"ShowKill_Combo5_Path\"    \"overlays/kill/kill_50\"");
    WriteFileLine(file, "    \"Max_Combo_KillCount\"    \"70\"");
    WriteFileLine(file, "    \"Enable_RoundWin_Overlay\"    \"1\"");
    WriteFileLine(file, "    \"RoundWin_Overlay_Path\"    \"overlays/kill/roundclear\"");
    WriteFileLine(file, "    \"Enable_RoundLost_Overlay\"    \"1\"");
    WriteFileLine(file, "    \"RoundLost_Overlay_Path\"    \"overlays/kill/roundfail\"");
    WriteFileLine(file, "}");

    CloseHandle(file);
}


float KvGetSafeFloat(KeyValues kv, const char[] key, float default_val)
{
    char buf[64];
    KvGetString(kv, key, buf, sizeof(buf), "");

    if (StrEqual(buf, "")) 
    {
        return default_val; 
    }

    return StringToFloat(buf); 
}

int KvGetSafeNum(KeyValues kv, const char[] key, int default_val)
{
    char buf[64];
    KvGetString(kv, key, buf, sizeof(buf), "");

    if (StrEqual(buf, "")) 
    {
        return default_val;
    }

    return StringToInt(buf); 
}

bool KvGetSafeBool(KeyValues kv, const char[] key, bool default_val)
{
    return KvGetSafeNum(kv, key, default_val ? 1 : 0) != 0;
}





void PrecacheOverlay()
{
    PrecacheModelSafe(g_HZSOVERLAYCFG.HitmarkerPath); 
    PrecacheModelSafe(g_HZSOVERLAYCFG.ShowKillCombo0Path); 
    PrecacheModelSafe(g_HZSOVERLAYCFG.ShowKillCombo1Path); 
    PrecacheModelSafe(g_HZSOVERLAYCFG.ShowKillCombo2Path); 
    PrecacheModelSafe(g_HZSOVERLAYCFG.ShowKillCombo3Path); 
    PrecacheModelSafe(g_HZSOVERLAYCFG.ShowKillCombo4Path); 
    PrecacheModelSafe(g_HZSOVERLAYCFG.ShowKillCombo5Path); 
    PrecacheModelSafe(g_HZSOVERLAYCFG.RoundWinOverlayPath); 
    PrecacheModelSafe(g_HZSOVERLAYCFG.RoundLostOverlayPath); 
}

