#pragma once

#include <eos_sdk.h>
#include "eos_achievements.h"
#include "string.h"
#include <iostream>

class EOSAchievements
{
public:
	// Constructor
	EOSAchievements() noexcept(false);

	// Get query definitions from the Dev portal
	void QueryDefinitions(EOS_HAchievements AchievementsHandle, const EOS_Achievements_QueryDefinitionsOptions* Options, void* ClientData, const EOS_Achievements_OnQueryDefinitionsCompleteCallback CompletionDelegate, EOS_ProductUserId puid);


	// OnQueryDefinitionsCompleteCallbackInfo, to be used with QueryDefinitionOptions
	void EOS_CALL DefinitionsReceivedCallback(const EOS_Achievements_OnQueryDefinitionsCompleteCallbackInfo* Data);

	// Unlock achievements
	// void UnlockAchievements(const std::vector<std::wstring>& AchievementIds);

private:
	// Callback called after achievement definitions have been retrieved
	static void EOS_CALL AchievementDefinitionsReceivedCallbackFn(const EOS_Achievements_OnQueryDefinitionsCompleteCallbackInfo* Data);

	// Callback called after player achievements data has been retrieved
	static void EOS_CALL PlayerAchievementsReceivedCallbackFn(const EOS_Achievements_OnQueryPlayerAchievementsCompleteCallbackInfo* Data);

	// Callback called after achievements have been unlocked
	static void EOS_CALL UnlockAchievementsReceivedCallbackFn(const EOS_Achievements_OnUnlockAchievementsCompleteCallbackInfo* Data);

	// Callback called after stats have been ingested
	static void EOS_CALL StatsIngestCallbackFn(const EOS_Stats_IngestStatCompleteCallbackInfo* Data);

	// Callback called after stats have been queried
	static void EOS_CALL StatsQueryCallbackFn(const EOS_Stats_OnQueryStatsCompleteCallbackInfo* Data);

	// Callback called after achievement has been unlocked
	static void EOS_CALL AchievementsUnlockedReceivedCallbackFn(const EOS_Achievements_OnAchievementsUnlockedCallbackV2Info* Data);
};