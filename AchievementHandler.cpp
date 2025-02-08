#include <Windows.h>
#include <iostream>
#include <Windows/eos_Windows.h>
#include <eos_achievements.h>
#include <eos_logging.h>
#include <eos_common.h>
#include <cassert>
#include <string.h>

#include "AchievementHandler.h"

EOSAchievements::EOSAchievements()
{

}

// Get query definitions from the Dev portal
void EOSAchievements::QueryDefinitions(EOS_HAchievements AchievementsHandle, const EOS_Achievements_QueryDefinitionsOptions* Options, void* ClientData, const EOS_Achievements_OnQueryDefinitionsCompleteCallback CompletionDelegate, EOS_ProductUserId puid)
{
	if (puid == nullptr)
	{
		std::cout << "Puid in QueryDefinitions is null! Returning..." << std::endl;
		return;
	}

	EOS_Achievements_QueryDefinitionsOptions QueryDefinitionsOptions = {};
	QueryDefinitionsOptions.ApiVersion = EOS_ACHIEVEMENTS_QUERYDEFINITIONS_API_LATEST;
	QueryDefinitionsOptions.LocalUserId = puid;

	EOS_Achievements_QueryDefinitions(AchievementsHandle, &QueryDefinitionsOptions, nullptr, DefinitionsReceivedCallback);
}

void EOS_CALL EOSAchievements::DefinitionsReceivedCallback(const EOS_Achievements_OnQueryDefinitionsCompleteCallbackInfo* Data)
{
	assert(Data != NULL);
	if (Data->ResultCode != EOS_EResult::EOS_Success)
	{
		std::cout << "Error: Data->ResultCode in the DefinitionsReceivedCallback is not successful" << std::endl;
		return;
	}
}

// Unlock achievements
// void EOSAchievements::UnlockAchievements(const std::vector<std::wstring>& AchievementIds);