#pragma once
#include "../../../external/imgui/imgui.h"

// CBA to make proper atm, it's 03:42 right now.
// For now just stores config values don't mind it too much
//
// (FYI THIS IS A HORRID SOLUTION BUT FUNCTIONS) 

namespace Config {
	extern bool esp;
	extern bool showHealth;
	extern bool teamCheck;
	extern bool espFill;
	extern float espThickness;
	extern float espFillOpacity;
	extern ImVec4 espColor;
	extern bool showNameTags;
	extern bool showHealthText;
	inline bool bhopEnabled;
	inline bool BombTimerEnabled;
	extern bool espCorner;
	extern bool espLine;
	extern float espThickness;
	extern ImVec4 espColor;
	extern float cornerSize;
	extern float cornerThickness;
	extern ImVec4 lineColor;
	extern float lineThickness;

	extern bool Night;
	extern ImVec4 NightColor;

	extern bool enemyChamsInvisible;
	extern bool enemyChams;
	extern bool teamChams;
	extern bool teamChamsInvisible;
	extern int chamsMaterial;

	extern ImVec4 colVisualChams;
	extern ImVec4 colVisualChamsIgnoreZ;
	extern ImVec4 teamcolVisualChamsIgnoreZ;
	extern ImVec4 teamcolVisualChams;

	extern bool armChams;
	extern bool viewmodelChams;
	extern ImVec4 colViewmodelChams;
	extern ImVec4 colArmChams;

	extern bool thirdperson;

	extern bool fovEnabled;
	extern float fov;

	extern bool bunnyhop;

	extern bool antiflash;

	extern bool Night;

	extern bool aimbot;
	extern float aimbot_fov;
	extern bool rcs;
	extern bool fov_circle;
	extern ImVec4 fovCircleColor;
}
