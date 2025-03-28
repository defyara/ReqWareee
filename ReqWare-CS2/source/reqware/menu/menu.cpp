#include "menu.h"
#include "../config/config.h"

#include <iostream>
#include <vector>
#include "../config/configmanager.h"

#include "../keybinds/keybinds.h"

#include "../utils/logging/log.h"
#include "../utils/math/vector/vector.h"
#include "fonts.h"
#include <thread>
#include "../../../external/imgui/imgui_internal.h"


void ApplyImGuiTheme() {
    ImGui::StyleColorsDark();

    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;

    style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.05f, 0.05f, 0.08f, 1.0f);
    style.Colors[ImGuiCol_ChildBg] = ImVec4(0.07f, 0.07f, 0.10f, 1.0f);
    style.Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.07f, 0.94f);
    style.Colors[ImGuiCol_Border] = ImVec4(0.10f, 0.10f, 0.20f, 1.0f);
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.10f, 0.10f, 0.20f, 1.0f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.54f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.40f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.00f, 0.00f, 0.00f, 0.67f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.16f, 0.29f, 0.48f, 1.00f);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.00f, 0.00f, 0.12f, 0.94f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(230 / 255.00f, 145 / 255.f, 30 / 255.00f, 0.40f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(230 / 255.00f, 145 / 255.f, 30 / 255.00f, 0.40f);
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(230 / 255.00f, 145 / 255.f, 30 / 255.00f, 0.40f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.24f, 0.52f, 0.88f, 1.00f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    style.Colors[ImGuiCol_Button] = ImVec4(0.10f, 0.10f, 0.20f, 1.0f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.10f, 0.10f, 0.20f, 1.0f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
    style.Colors[ImGuiCol_Header] = ImVec4(0.12f, 0.12f, 0.12f, 1.f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.12f, 0.12f, 0.12f, 1.f);
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.12f, 0.12f, 0.12f, 1.f);
    style.Colors[ImGuiCol_Separator] = ImVec4(0.10f, 0.10f, 0.20f, 1.0f);
    style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.10f, 0.20f, 1.0f);
    style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.30f, 0.30f, 0.30f, 0.90f);
    style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.20f);
    style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
    style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
    style.Colors[ImGuiCol_Tab] = ImVec4(0.10f, 0.10f, 0.10f, 1.f);
    style.Colors[ImGuiCol_TabHovered] = ImVec4(0.10f, 0.10f, 0.10f, 1.f);
    style.Colors[ImGuiCol_TabActive] = ImVec4(0.10f, 0.10f, 0.10f, 1.f);
    style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.10f, 0.10f, 0.10f, 1.f);
    style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.10f, 0.10f, 0.10f, 1.f);

    style.WindowRounding = 5.0f;
    style.FrameRounding = 5.0f;
    style.ScrollbarRounding = 7.0f;
    style.GrabRounding = 8.0f;

    style.ItemSpacing = ImVec2(10, 5);
    style.FramePadding = ImVec2(5, 5);
}




Menu::Menu() {
    activeTab = 0;
    showMenu = true;
}

inline ImFont* arial_font;
inline ImFont* segoe_font;
inline ImFont* Gay;
inline ImFont* roboto_font;
inline ImFont* arial_font_cyr;
inline ImFont* gaychek;

void Menu::init(HWND& window, ID3D11Device* pDevice, ID3D11DeviceContext* pContext, ID3D11RenderTargetView* mainRenderTargetView) {
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;

    ImGui_ImplWin32_Init(window);
    ImGui_ImplDX11_Init(pDevice, pContext);

    ImFontAtlas* const atlas = io.Fonts;
    atlas->Clear();
    ImFontConfig cfg;
    std::error_code ec;
    ApplyImGuiTheme();

    arial_font = atlas->AddFontFromMemoryCompressedTTF(Fonts::ArialFont_compressed_data, Fonts::ArialFont_compressed_size, 15.f, &cfg);
    Gay = atlas->AddFontFromMemoryCompressedTTF(Fonts::GayFont_compressed_data, Fonts::GayFont_compressed_size, 19.f, &cfg);
    roboto_font = atlas->AddFontFromMemoryCompressedTTF(Fonts::RobotoFont_compressed_data, Fonts::RobotoFont_compressed_size, 16.f, &cfg);

    io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\arial.ttf", 16.0f);

    std::cout << "initialized menu\n";
}

static std::unordered_map<ImGuiID, float> hover_anim;
static std::unordered_map<ImGuiID, float> select_anim;

ImVec4 buttonColor = ImVec4(0.05f, 0.05f, 0.08f, 1.0f);
ImVec4 buttonHoveredColor = ImVec4(0.2f, 0.2f, 0.3f, 1.0f);
ImVec4 buttonSelectedColor = ImVec4(0.1f, 0.1f, 0.2f, 1.0f);
ImVec4 textColor = ImVec4(0.6f, 0.6f, 0.7f, 1.0f);
ImVec4 iconColor = ImVec4(0.6f, 0.5f, 0.9f, 1.0f);
ImVec4 iconSelectedColor = ImVec4(0.7f, 0.6f, 1.0f, 1.0f);

bool renderer_tab(const char* icon, const char* text, bool selected)
{
    ImGuiWindow* window = ImGui::GetCurrentWindow();
    if (window->SkipItems)
        return false;

    const ImGuiID id = window->GetID(text);
    ImVec2 pos = window->DC.CursorPos;
    ImVec2 size = { 80, 31 };

    const ImRect bb(pos, ImVec2(pos.x + size.x, pos.y + size.y));
    ImGui::ItemSize(size, 0);

    if (!ImGui::ItemAdd(bb, id))
        return false;

    bool hovered, held;
    bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, NULL);

    ImVec4 bgColor = selected ? buttonSelectedColor : buttonColor;
    if (hovered) bgColor = buttonHoveredColor;

    ImGui::GetWindowDrawList()->AddRectFilled(bb.Min, bb.Max, ImColor(bgColor), 5.0f);

    if (selected)
        ImGui::GetWindowDrawList()->AddRect(bb.Min, bb.Max, ImColor(0.2f, 0.2f, 0.3f, 1.0f), 5.0f, 0, 2.0f);

    ImVec2 iconPos = ImVec2(bb.Min.x + 5, bb.Min.y + 6);
    ImVec2 textPos = ImVec2(bb.Min.x + 28, bb.Min.y + 9);

    ImGui::PushFont(Gay);
    ImGui::GetWindowDrawList()->AddText(iconPos, ImColor(selected ? iconSelectedColor : iconColor), icon);
    ImGui::PopFont();
    ImGui::PushFont(roboto_font);
    ImGui::GetWindowDrawList()->AddText(textPos, ImColor(textColor), text);
    ImGui::PopFont();

    return pressed;
}

float AnimateSliderPos(float& sliderPosX, float targetPosX, float animationSpeed) {
    sliderPosX += (targetPosX - sliderPosX) * animationSpeed;
    return sliderPosX;
}

float AnimateActiveWidth(float& activeWidth, float targetWidth, float animationSpeed) {
    activeWidth += (targetWidth - activeWidth) * animationSpeed;
    return activeWidth;
}

float AnimateGrabRadius(float& grabRadius, float targetRadius, float animationSpeed) {
    grabRadius += (targetRadius - grabRadius) * animationSpeed;
    return grabRadius;
}

float AnimateAlpha(float& alphaValue, bool hovered, float animationSpeed) {
    alphaValue += (hovered ? (1.0f - alphaValue) : (0.0f - alphaValue)) * animationSpeed;
    return alphaValue;
}

float AnimateBorderWidth(float current, float target, float speed)
{
    return current + (target - current) * speed;
}


bool ColorPicker(const char* name, ImVec4& color, float animationSpeed = 0.1f) {
    static ImVec4 backup_color;
    static std::unordered_map<std::string, float> borderAnim_map;
    static std::unordered_map<std::string, float> alphaAnim_map;
    static std::unordered_map<std::string, ImVec2> trianglePos_map;

    std::string picker_id(name);

    if (borderAnim_map.find(picker_id) == borderAnim_map.end()) {
        borderAnim_map[picker_id] = 2.0f;
        alphaAnim_map[picker_id] = 0.5f;
        trianglePos_map[picker_id] = ImVec2(0.0f, 0.0f);
    }

    float& borderAnimation = borderAnim_map[picker_id];
    float& hoverAnimation = alphaAnim_map[picker_id];
    ImVec2& trianglePos = trianglePos_map[picker_id];

    ImVec2 square_size = ImVec2(20.0f, 20.0f);

    ImGui::Text("%s", name);
    ImGui::SameLine();
    bool hovered = ImGui::IsItemHovered();
    float targetBorder = hovered ? 4.0f : 2.0f;
    borderAnimation = AnimateBorderWidth(borderAnimation, targetBorder, animationSpeed);
    float targetHoverAlpha = hovered ? 1.0f : 0.5f;
    hoverAnimation = AnimateAlpha(hoverAnimation, hovered, animationSpeed);

    ImDrawList* drawList = ImGui::GetWindowDrawList();
    ImVec2 cursorPos = ImGui::GetCursorScreenPos();
    ImVec2 squarePosEnd = ImVec2(cursorPos.x + square_size.x, cursorPos.y + square_size.y);

    drawList->AddRectFilled(cursorPos, squarePosEnd, ImColor(color), 5.0f);

    drawList->AddRect(
        ImVec2(cursorPos.x - borderAnimation, cursorPos.y - borderAnimation),
        ImVec2(squarePosEnd.x + borderAnimation, squarePosEnd.y + borderAnimation),
        ImColor(255, 255, 255, (int)(255 * hoverAnimation)),
        5.0f,
        borderAnimation
    );

    ImVec2 targetTrianglePos = ImVec2(cursorPos.x + square_size.x / 2, cursorPos.y + square_size.y / 2);
    trianglePos.x = AnimateSliderPos(trianglePos.x, targetTrianglePos.x, animationSpeed);
    trianglePos.y = AnimateSliderPos(trianglePos.y, targetTrianglePos.y, animationSpeed);

    float triangleSize = 10.0f;
    ImVec2 v1 = ImVec2(trianglePos.x, trianglePos.y - triangleSize / 2);
    ImVec2 v2 = ImVec2(trianglePos.x - triangleSize / 2, trianglePos.y + triangleSize / 2);
    ImVec2 v3 = ImVec2(trianglePos.x + triangleSize / 2, trianglePos.y + triangleSize / 2);
    drawList->AddTriangleFilled(v1, v2, v3, ImColor(111, 111, 111, (int)(111 * hoverAnimation)));

    bool open_popup = ImGui::ColorButton(
        (std::string(name) + "##color_button").c_str(),
        color,
        ImGuiColorEditFlags_NoTooltip,
        square_size
    );

    if (open_popup) {
        ImGui::OpenPopup((std::string(name) + "##popup").c_str());
        backup_color = color;
    }

    bool color_changed = false;

    if (ImGui::BeginPopup((std::string(name) + "##popup").c_str())) {
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(10, 10));
        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(5, 5));
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 1.0f);

        ImGui::PushStyleColor(ImGuiCol_PopupBg, ImVec4(0.1f, 0.1f, 0.1f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.8f, 0.3f, 0.3f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.2f, 0.2f, 0.2f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0.4f, 0.4f, 0.4f, 1.0f));

        if (ImGui::ColorPicker4(
            (std::string(name) + "##picker").c_str(),
            (float*)&color,
            ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoSmallPreview |
            ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel)) {
            color_changed = true;
        }
        ImGui::Separator();
        ImGui::PopStyleColor(4);
        ImGui::PopStyleVar(3);
        ImGui::EndPopup();
    }
    return color_changed;
}

bool SliderIntCustom(const char* label, int* value, int min, int max)
{
    static std::unordered_map<std::string, float> sliderPosX_map;
    static std::unordered_map<std::string, float> grab_radius_map;
    static std::unordered_map<std::string, float> active_width_map;
    static std::unordered_map<std::string, float> alpha_value_map;
    std::string slider_id(label);
    if (sliderPosX_map.find(slider_id) == sliderPosX_map.end()) {
        sliderPosX_map[slider_id] = 0.0f;
        grab_radius_map[slider_id] = 3.0f;
        active_width_map[slider_id] = 0.0f;
        alpha_value_map[slider_id] = 0.0f;
    }
    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    float width = 200.0f;
    float height = 3.0f;
    float radius = height * 2.5f;
    ImVec2 p = ImGui::GetCursorScreenPos();
    ImGui::TextUnformatted(label);
    ImGui::SetCursorScreenPos(ImVec2(p.x, p.y + ImGui::GetTextLineHeight() + 5.0f));
    p = ImGui::GetCursorScreenPos();
    ImVec2 sliderStart = p;
    ImVec2 sliderEnd = ImVec2(p.x + width, p.y + height);
    float normalized_value = (*value - min) / float(max - min);
    float& sliderPosX = sliderPosX_map[slider_id];
    float& grab_radius = grab_radius_map[slider_id];
    float& active_width = active_width_map[slider_id];
    float& alpha_value = alpha_value_map[slider_id];
    ImRect slider_bb(p, ImVec2(p.x + width, p.y + height));
    ImGui::InvisibleButton(label, ImVec2(width, height));
    bool is_active = ImGui::IsItemActive();
    bool is_hovered = ImGui::IsItemHovered();
    if (is_active && ImGui::GetIO().MouseDown[0]) {
        normalized_value = (ImGui::GetIO().MousePos.x - p.x) / width;
        normalized_value = ImClamp(normalized_value, 0.0f, 1.0f);
        *value = min + int(normalized_value * (max - min));
    }
    sliderPosX = AnimateSliderPos(sliderPosX, p.x + normalized_value * width, 0.15f);
    active_width = AnimateActiveWidth(active_width, width * normalized_value, 0.1f);
    float target_radius = is_hovered ? radius * 1.2f : radius;
    grab_radius = AnimateGrabRadius(grab_radius, target_radius, 0.1f);
    alpha_value = AnimateAlpha(alpha_value, is_hovered, 0.1f);
    ImU32 slider_bg_col = ImGui::GetColorU32(ImVec4(0.2f, 0.2f, 0.2f, 1.0f));
    ImU32 slider_active_col = ImGui::GetColorU32(ImVec4(255.0f, 255.0f, 255.0f, 1.0f));
    ImU32 slider_grab_col = is_active || is_hovered
        ? ImGui::GetColorU32(ImVec4(1.21f, 1.21f, 1.21f, 1.0f))
        : ImGui::GetColorU32(ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
    draw_list->AddRectFilled(sliderStart, sliderEnd, slider_bg_col, radius);
    draw_list->AddRectFilled(sliderStart, ImVec2(sliderStart.x + active_width, sliderStart.y + height), slider_active_col, radius);
    draw_list->AddCircleFilled(ImVec2(sliderPosX, sliderStart.y + radius - 5), grab_radius, slider_grab_col);
    char value_text[32];
    snprintf(value_text, sizeof(value_text), "%d", *value);
    ImVec2 textPos = ImVec2(sliderEnd.x + 10.0f, sliderStart.y - 6);
    ImVec4 text_color = ImVec4(1.0f, 1.0f, 1.0f, alpha_value);
    draw_list->AddText(textPos, ImGui::GetColorU32(text_color), value_text);
    return is_active;
}

bool SliderFloatCustom(const char* label, float* value, float min, float max, const char* format = "%.1f")
{
    int intValue = static_cast<int>(*value);
    int intMin = static_cast<int>(min);
    int intMax = static_cast<int>(max);
    bool changed = SliderIntCustom(label, &intValue, intMin, intMax);
    *value = static_cast<float>(intValue);
    return changed;
}


void Menu::render() {
    if (GetAsyncKeyState(VK_INSERT) & 1) {
        showMenu = !showMenu;
    }

    keybind.pollInputs();
    if (showMenu) {
        ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse |
            ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar;

        ImGui::SetNextWindowSize(ImVec2(800, 450), ImGuiCond_Once);
        ImGui::SetNextWindowPos(ImVec2(50, 50), ImGuiCond_Once);

        ImGui::Begin("ReqWare | Free", nullptr, window_flags);

        ImGui::PushFont(roboto_font);
        ImGui::Text("ReqWare [build: Free] [Counter-Strike 2]");
        ImGui::PopFont();
        ImGui::Separator();
        ImGui::Spacing();

        ImGui::BeginChild("Sidebar", ImVec2(100, 0), true);
        {
            ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 10));
            if (renderer_tab("3", "Aim", activeTab == 0)) activeTab = 0;
            if (renderer_tab("2", "Visual", activeTab == 1)) activeTab = 1;
            if (renderer_tab("4", "Misc", activeTab == 2)) activeTab = 2;
            if (renderer_tab("5", "View", activeTab == 3)) activeTab = 3;
            if (renderer_tab("5", "Cloud", activeTab == 5)) activeTab = 5;
            ImGui::PopStyleVar();
        }
        ImGui::EndChild();

        ImGui::SameLine();
        ImGui::BeginChild("Main Content", ImVec2(0, 0), true);
        switch (activeTab) {
        case 0: {
            ImGui::BeginChild("Aim", ImVec2(0, 0), true);
            ImGui::Text("Aim");
            ImGui::Separator();
            ImGui::Checkbox("Aimbot", &Config::aimbot); ImGui::SameLine();
            keybind.menuButton(Config::aimbot);
            SliderFloatCustom("FOV", &Config::aimbot_fov, 0.f, 90.f);
            ImGui::Checkbox("DrawFOV", &Config::fov_circle);
            if (Config::fov_circle) {
                ColorPicker("FOV Color", Config::fovCircleColor);
            }
            ImGui::EndChild();
            break;
        }
        case 1: {
            ImGui::BeginChild("ESP ", ImVec2(ImGui::GetContentRegionAvail().x * 0.6f, 0), true);
            ImGui::Text("ESP");
            ImGui::Separator();

            ImGui::Checkbox("Box", &Config::esp);
            ImGui::SameLine();
            ColorPicker("ColorB", Config::espColor);
            ImGui::Checkbox("Line", &Config::espLine);
            ImGui::SameLine();
            ColorPicker("ColorL", Config::lineColor);
            ImGui::Checkbox("BoxFill", &Config::espFill);
            ImGui::Checkbox("Teamcheck", &Config::teamCheck);
            ImGui::Checkbox("Health", &Config::showHealth);
            ImGui::Checkbox("Name", &Config::showNameTags);
            ImGui::Separator();

            ImGui::BeginChild("Chams", ImVec2(0, 150), true);
            ImGui::Text("Chams");
            ImGui::Checkbox("Chams", &Config::enemyChams);
            const char* chamsMaterials[] = { "Flat", "Illuminate", "Glow" };
            ImGui::Combo("Material", &Config::chamsMaterial, chamsMaterials, IM_ARRAYSIZE(chamsMaterials));
            ColorPicker("Chams", Config::colVisualChams);
            if (Config::enemyChams) {
            }
            ImGui::Checkbox("Chams Enemy", &Config::enemyChamsInvisible);
            ImGui::SameLine();
            if (Config::enemyChamsInvisible) {
            }

            ImGui::Checkbox("HandChams", &Config::armChams);
            ImGui::SameLine();
            ColorPicker("Hand", Config::colArmChams);
            if (Config::armChams) {
            }
            ImGui::Checkbox("ViewmodelChams", &Config::viewmodelChams);
            ImGui::SameLine();
            ColorPicker("Viewmodel", Config::colArmChams);
            ImGui::EndChild();
            ImGui::EndChild();

            ImGui::SameLine();
            ImGui::BeginChild("ESP p", ImVec2(0, 0), true);
            ImGui::Text("ESP Preview");
            ImGui::Separator();

            ImVec2 previewSize = ImGui::GetContentRegionAvail();
            ImVec2 previewPos = ImGui::GetCursorScreenPos();
            ImVec2 center = ImVec2(previewPos.x + previewSize.x * 0.5f, previewPos.y + previewSize.y * 0.5f);
            ImDrawList* drawList = ImGui::GetWindowDrawList();

            if (Config::esp) {
                float boxWidth = 150.0f;
                float boxHeight = 200.0f;
                ImVec2 boxMin = ImVec2(center.x - boxWidth * 0.5f, center.y - boxHeight * 0.5f);
                ImVec2 boxMax = ImVec2(center.x + boxWidth * 0.5f, center.y + boxHeight * 0.5f);

                if (Config::espFill) {
                    drawList->AddRectFilled(boxMin, boxMax,
                        ImColor(Config::espColor.x, Config::espColor.y, Config::espColor.z, Config::espFillOpacity));
                }

                drawList->AddRect(boxMin, boxMax, ImColor(Config::espColor), 0, 0, Config::espThickness);

                if (Config::showNameTags) {
                    const char* name = "ReqWare";
                    ImVec2 textSize = ImGui::CalcTextSize(name);
                    ImVec2 textPos = ImVec2(center.x - textSize.x * 0.5f, boxMin.y - textSize.y - 5.0f);
                    drawList->AddText(textPos, IM_COL32_WHITE, name);
                }
                if (Config::showHealth) {
                    float healthLineWidth = 2.0f;
                    float healthLineLength = boxHeight;
                    ImVec2 lineStart = ImVec2(boxMin.x - 10.0f, boxMin.y);
                    ImVec2 lineEnd = ImVec2(boxMin.x - 10.0f, boxMin.y + healthLineLength);

                    drawList->AddLine(lineStart, lineEnd, IM_COL32(60, 60, 60, 255), healthLineWidth);

                    float healthPercentage = 1.0f;
                    ImVec2 healthEnd = ImVec2(lineEnd.x, lineEnd.y - healthLineLength * (1.0f - healthPercentage));
                    drawList->AddLine(lineStart, healthEnd, IM_COL32(0, 255, 0, 255), healthLineWidth);

                    if (Config::showHealthText) {
                        const char* healthText = "100";
                        ImVec2 textSize = ImGui::CalcTextSize(healthText);
                        ImVec2 textPos = ImVec2(
                            lineStart.x - textSize.x - 5.0f,
                            lineEnd.y - healthLineLength * 0.5f - textSize.y * 0.5f
                        );
                        drawList->AddText(textPos, IM_COL32_WHITE, healthText);
                    }
                }
            }
            ImGui::EndChild();
            break;
        }
        case 2: {
            ImGui::BeginChild("Misc", ImVec2(0, 0), true);
            ImGui::Text("Misc");
            ImGui::Separator();
            ImGui::Checkbox("NightMode", &Config::Night);
            if (Config::Night)
                ColorPicker("Color", Config::NightColor);
            ImGui::EndChild();
            break;
        }
        case 4: {
            ImGui::BeginChild("View", ImVec2(0, 0), true);
            ImGui::Text("View");
            ImGui::Separator();

            ImGui::Checkbox("Antiflash", &Config::antiflash);

            ImGui::Checkbox("Fov", &Config::fovEnabled);
            if (Config::fovEnabled) {
                SliderFloatCustom("##FovSlider", &Config::fov, 20.0f, 160.0f, "%1.0f");
            }

            ImGui::EndChild();
            break;
        }
        case 5: {
            ImGui::BeginChild("Config", ImVec2(0, 0), true);
            ImGui::Text("Config");
            ImGui::Separator();
            static char configName[128] = "";
            static std::vector<std::string> configList = internal_config::ConfigManager::ListConfigs();
            static int selectedConfigIndex = -1;
            ImGui::InputText("Config Name", configName, IM_ARRAYSIZE(configName));
            if (ImGui::Button("Refresh Config List"))
                configList = internal_config::ConfigManager::ListConfigs();
            ImGui::SameLine();
            if (ImGui::Button("Load"))
                internal_config::ConfigManager::Load(configName);
            ImGui::SameLine();
            if (ImGui::Button("Save")) {
                internal_config::ConfigManager::Save(configName);
                configList = internal_config::ConfigManager::ListConfigs();
            }
            ImGui::SameLine();
            if (ImGui::Button("Delete")) {
                internal_config::ConfigManager::Remove(configName);
                configList = internal_config::ConfigManager::ListConfigs();
            }
            ImGui::Separator();
            ImGui::Text("Saved Configs:");
            for (int i = 0; i < static_cast<int>(configList.size()); i++) {
                if (ImGui::Selectable(configList[i].c_str(), selectedConfigIndex == i)) {
                    selectedConfigIndex = i;
                    strncpy_s(configName, sizeof(configName), configList[i].c_str(), _TRUNCATE);
                }
            }
            ImGui::EndChild();
            ImGui::End();
            break;
        }
        }
    }
}


void Menu::toggleMenu() {
    showMenu = !showMenu;
}
