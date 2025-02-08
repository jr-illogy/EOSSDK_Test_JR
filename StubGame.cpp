// Copyright Epic Games, Inc. All Rights Reserved.

#include <Windows.h>
#include <iostream>
#include <Windows/eos_Windows.h>
#include <eos_init.h>
#include <eos_logging.h>
#include <eos_common.h>
#include <eos_auth.h>
#include <eos_connect.h>
#include <eos_sdk.h>
#include <cassert>
#include <string.h>
#include "SDKConfig.h"
#include "PlatformHandler.h"
#include "AuthHandler.h"

int main()
{
	// Initialize config and platform
	SDKConfig* config = new SDKConfig;
	PlatformHandler* platformInitializer = new PlatformHandler();
	EOS_HPlatform platformHandle = nullptr;
	platformHandle = platformInitializer->InitializePlatform(config);
	assert(platformHandle != nullptr);

	// Login and retrieve a PUID
	AuthHandler* auth = new AuthHandler();
	EOS_ProductUserId puid = nullptr;
	puid = auth->Login(config, platformHandle);
	assert(puid != nullptr);

	std::cout << "Logged in and PUID is: " << puid << std::endl;

	/* ACHIEVEMENTS! */
	// Acquire an EOS_HAchievements handle by calling the EOS_Platform_GetAchievementsInterface function
	EOS_HAchievements achievementHandle = EOS_Platform_GetAchievementsInterface(platformHandle);
	assert(achievementHandle!= nullptr);

	EOS_Achievements_GetPlayerAchievementCountOptions* Options = EOS_Achievements_GetPlayerAchievementCount(EOS_ACHIEVEMENTS_GETPLAYERACHIEVEMENTCOUNT_API_LATEST, puid);

	// EOS_Achievements_DefinitionV2 firstID = achievementHandle.AchievementId;
	// EOS_Achievements_QueryDefinitions(achievementHandle)

	// EOS_HAchievements queryOptions = EOS_Achievements_QueryDefinitionsOptions(EOS_ACHIEVEMENTS_QUERYDEFINITIONS_API_LATEST, puid, nullptr, nullptr, 0);
	// EOS_Achievements_QueryDefinitions(achievementHandle, { EOS_ACHIEVEMENTS_QUERYDEFINITIONS_API_LATEST, puid, nullptr, nullptr, 0 }, 0, 0);

	// while (puid != nullptr) {
		// EOS_Platform_Tick(platformHandle);
	// }
}
