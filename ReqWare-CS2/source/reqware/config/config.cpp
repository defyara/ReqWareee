#include "config.h"

// CBA to make proper atm, it's 03:42 right now.
// For now just stores config values don't mind it too much
//
// (FYI THIS IS A HORRID SOLUTION BUT FUNCTIONS) 

namespace Config {
	bool esp = false;
	bool glow = false;
	bool showHealth = false;
	bool teamCheck = false;
	bool espFill = false;
	bool showNameTags = false;
	bool showHealthText = false;

	bool espBox = true;
	bool espCorner = true;
	bool espLine = true;
	float espThickness = 1.0f;
	ImVec4 espColor = ImVec4(0.0f, 1.0f, 0.0f, 1.0f);
	float cornerSize = 10.0f;
	float cornerThickness = 2.0f;
	ImVec4 lineColor = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
	float lineThickness = 1.0f;
	bool bunnyhop = false;
	bool thirdperson = false;
	bool Night = false;
	bool jumping = false;

	bool enemyChamsInvisible = false;
	bool enemyChams = false;
	bool teamChams = false;
	bool teamChamsInvisible = false;
	int chamsMaterial = 0;


	bool armChams = false;
	bool viewmodelChams = false;
	ImVec4 colViewmodelChams = ImVec4(1, 0, 0, 1);
	ImVec4 colArmChams = ImVec4(1, 0, 0, 1);

	ImVec4 colVisualChams = ImVec4(1, 0, 0, 1);
	ImVec4 colVisualChamsIgnoreZ = ImVec4(1, 0, 0, 1);
	ImVec4 teamcolVisualChamsIgnoreZ = ImVec4(1, 0, 0, 1);
	ImVec4 teamcolVisualChams = ImVec4(1, 0, 0, 1);

	float espFillOpacity = 0.5f;

	bool fovEnabled = false;
	float fov = 90.0f;

	bool antiflash = false;

	ImVec4 NightColor = ImVec4(0.1, 0.1, 0.1, 1);

	bool aimbot = 0;
	float aimbot_fov = 0;
	bool rcs = 0;
	bool fov_circle = 0;
	ImVec4 fovCircleColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
}
