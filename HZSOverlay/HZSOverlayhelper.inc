void CreateKillComboTimer(client)
{
    if(client <= 0 || client > MaxClients || !IsClientInGame(client) || !IsPlayerAlive(client) || IsFakeClient(client)) 
        return;

	if (g_hClientComboTimers[client] != INVALID_HANDLE)
	{
		KillTimer(g_hClientComboTimers[client]);
	}
	g_hClientComboTimers[client] = CreateTimer(g_HZSOVERLAYCFG.KillComboWait, RemoveCombo, client);

}

public Action RemoveCombo(Handle timer, any client)
{
    if(client <= 0 || client > MaxClients || !IsClientInGame(client) || !IsPlayerAlive(client) || IsFakeClient(client)) 
        return Plugin_Continue;

	ClientComboDisconnect(client);

    return Plugin_Continue;
}



void ClientComboDisconnect(int client)
{
	g_hClientComboTimers[client] = INVALID_HANDLE;
	KillCombo[client] = 0;
}

void ClearOverlay(int client)
{
	if (client <= 0 || !IsClientInGame(client) || IsFakeClient(client) || IsClientSourceTV(client) || IsClientReplay(client)) 
		return;

	int iFlag = GetCommandFlags("r_screenoverlay") & (~FCVAR_CHEAT);
	SetCommandFlags("r_screenoverlay", iFlag);
	ClientCommand(client, "r_screenoverlay \"\"");
}

public Action ShowWinTimer(Handle timer)
{
    if(!g_HZSOVERLAYCFG.Enable || !g_HZSOVERLAYCFG.EnableRoundWinOverlay)
        return Plugin_Continue;

	ShowOverlayAll(g_HZSOVERLAYCFG.RoundWinOverlayPath, 10.0);
    return Plugin_Continue;
}
public Action ShowFailTimer(Handle timer)
{
    if(!g_HZSOVERLAYCFG.Enable || !g_HZSOVERLAYCFG.EnableRoundLostOverlay)
        return Plugin_Continue;

	ShowOverlayAll(g_HZSOVERLAYCFG.RoundLostOverlayPath, 10.0);
    return Plugin_Continue;
}

void ShowKillCombo(client)
{
    if(client <= 0 || client > MaxClients || !IsClientInGame(client) || !IsPlayerAlive(client) || IsFakeClient(client)) 
        return;

    if(!g_HZSOVERLAYCFG.Enable || !g_HZSOVERLAYCFG.EnableKillOverlay)
        return;

	if(KillCombo[client] <= g_HZSOVERLAYCFG.Combo0KillCount)
	{
		ShowOverlay(client, g_HZSOVERLAYCFG.ShowKillCombo0Path, 0.2);
	}
	else if(KillCombo[client] > g_HZSOVERLAYCFG.Combo0KillCount && KillCombo[client] <= g_HZSOVERLAYCFG.Combo1KillCount)
	{
		ShowOverlay(client, g_HZSOVERLAYCFG.ShowKillCombo1Path, 0.2);
	}
	else if(KillCombo[client] > g_HZSOVERLAYCFG.Combo1KillCount && KillCombo[client] <= g_HZSOVERLAYCFG.Combo2KillCount)
	{
		ShowOverlay(client, g_HZSOVERLAYCFG.ShowKillCombo2Path, 0.2);
	}
	else if(KillCombo[client] > g_HZSOVERLAYCFG.Combo2KillCount && KillCombo[client] <= g_HZSOVERLAYCFG.Combo3KillCount)
	{
		ShowOverlay(client, g_HZSOVERLAYCFG.ShowKillCombo3Path, 0.2);
	}
	else if(KillCombo[client] > g_HZSOVERLAYCFG.Combo3KillCount && KillCombo[client] <= g_HZSOVERLAYCFG.Combo4KillCount)
	{
		ShowOverlay(client, g_HZSOVERLAYCFG.ShowKillCombo4Path, 0.2);
	}
	else if(KillCombo[client] > g_HZSOVERLAYCFG.Combo4KillCount && KillCombo[client] <= g_HZSOVERLAYCFG.Combo5KillCount)
	{
		ShowOverlay(client, g_HZSOVERLAYCFG.ShowKillCombo5Path, 0.2);
	}
    else if(KillCombo[client] > g_HZSOVERLAYCFG.Combo5KillCount && KillCombo[client] <= g_HZSOVERLAYCFG.MaxComboKillCount)
    {
		ShowOverlay(client, g_HZSOVERLAYCFG.ShowKillCombo5Path, 0.2);
    }
    else
    {
		ShowOverlay(client, g_HZSOVERLAYCFG.ShowKillCombo0Path, 0.2);
    }

}

void ShowHitMarker(int client)
{
    if(client <= 0 || client > MaxClients || !IsClientInGame(client) || !IsPlayerAlive(client) || IsFakeClient(client)) 
        return;

    if(!g_HZSOVERLAYCFG.Enable || !g_HZSOVERLAYCFG.EnableHitmarker)
        return;

    ShowOverlay(client, g_HZSOVERLAYCFG.HitmarkerPath, 0.1);
}

void PrecacheModelSafe(const char[] modelPath)
{
    if (strlen(modelPath) > 0)
    {
        PrecacheModel(modelPath, true);
    }
}