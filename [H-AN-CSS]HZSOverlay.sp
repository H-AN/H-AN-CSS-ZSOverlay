#include <sourcemod>
#include <sdktools>
#include <sdkhooks>
#include <cstrike>
#include <overlays> 
#include <HanZombieScenarioAPI>

#include "HZSOverlay/HZSOverlayGlobals"
#include "HZSOverlay/HZSOverlayConfig"
#include "HZSOverlay/HZSOverlayhelper"

public Plugin:myinfo =
{
    name = "[华仔]CS起源大灾变Overlay", 
    author = "华仔 H-AN", 
    description = "华仔 H-AN CS起源大灾变Overlay", 
    version = "1.0", 
    url = "[华仔]CS起源大灾变Overlay, QQ群107866133, github https://github.com/H-AN"
};

public void OnPluginStart()
{
    HookEvent("round_start", Event_RoundStart);
    HookEvent("round_end", EventRoundEnd);
    HookEvent("player_death", Event_PlayerDeath);
}



public void OnMapStart()
{
    LoadHZSOverlayConfig();
}

public Action EventRoundEnd(Handle event, const String:name[], bool dontBroadcast) 
{
	int winner_team = GetEventInt(event, "winner");
    if(winner_team == CS_TEAM_T)
    {
        CreateTimer(0.5, ShowFailTimer);
    }
    else if(winner_team == CS_TEAM_CT)
    {
       CreateTimer(0.5, ShowWinTimer);
    }

    return Plugin_Handled;
}

public Action Event_RoundStart(Handle event, const String:name[], bool dontBroadcast)
{
    for (int i = 1; i <= MaxClients; i++)
	{
        ClearOverlay(i);
        ClientComboDisconnect(i);
    }

    return Plugin_Handled;
}

public Action Event_PlayerDeath(Handle event, const String:name[], bool dontBroadcast) 
{   
	new client = GetClientOfUserId(GetEventInt(event, "userid"));
    if(client <= 0 || client > MaxClients || !IsClientInGame(client) || IsFakeClient(client)) 
        return Plugin_Continue;

    ClearOverlay(client);
	ClientComboDisconnect(client); 

    return Plugin_Handled;
}

public void Han_OnZombieDeath(int zombie, int killer) 
{
    if(killer <= 0 || killer > MaxClients || !IsClientInGame(killer) || !IsPlayerAlive(killer) || IsFakeClient(killer)) 
        return;

    if(!g_HZSOVERLAYCFG.Enable || !g_HZSOVERLAYCFG.EnableKillOverlay)
        return;

    if(KillCombo[killer] < g_HZSOVERLAYCFG.MaxComboKillCount)
    {
        KillCombo[killer]++;
    }

    ShowKillCombo(killer);
    CreateKillComboTimer(killer);
}


public void Han_OnZombieHurt(int zombie, int attacker)  
{
    if(attacker <= 0 || attacker > MaxClients || !IsClientInGame(attacker) || !IsPlayerAlive(attacker) || IsFakeClient(attacker)) 
        return;

    if(!g_HZSOVERLAYCFG.Enable || !g_HZSOVERLAYCFG.EnableHitmarker)
        return;

    ShowHitMarker(attacker);

}


public void OnClientDisconnect(int client)
{
	ClientComboDisconnect(client);
}