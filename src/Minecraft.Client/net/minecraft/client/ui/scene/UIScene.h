#pragma once

#include "NX/Render/C4JRender.h"
#include "net/minecraft/client/ui/scene/control/UIControl_Base.h"
#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

enum EUIMessage {};
class fuiFile;
class fuiRect;
class UILayer;
class UIControl;

enum EUIScene {
    eUIScene_Intro = 1,
    eUIScene_SaveMessage = 2,
    eUIScene_MainMenu = 3,
    eUIScene_FullscreenProgress = 4,
    eUIScene_PauseMenu = 5,
    eUIScene_CraftingMenu = 6,
    eUIScene_FurnaceMenu = 8,
    eUIScene_ContainerMenu = 9,
    eUIScene_InventoryMenu = 11,
    eUIScene_DispenserMenu = 12,
    eUIScene_HelpAndOptionsMenu = 15,
    eUIScene_HowToPlay = 16,
    eUIScene_HowToPlayMenu = 17,
    eUIScene_ControlsMenu = 18,
    eUIScene_SettingsListMenu = 19,
    eUIScene_InGameSettingsListMenu = 20,
    eUIScene_SettingsMenu = 21,
    eUIScene_LeaderboardsMenu = 22,
    eUIScene_Credits = 23,
    eUIScene_DeathMenu = 24,
    eUIScene_CreateWorldMenu = 26,
    eUIScene_LoadCreateJoinMenu = 27,
    eUIScene_JoinMenu = 28,
    eUIScene_SignEntryMenu = 29,
    eUIScene_InGameInfoMenu = 30,
    eUIScene_ConnectingProgress = 31,
    eUIScene_DLCOffersMenu = 32,
    eUIScene_TrialExitUpsell = 34,
    eUIScene_LoadMenu = 35,
    eUIScene_ReinstallMenu = 37,
    eUIScene_SkinSelectMenu = 38,
    eUIScene_InGameHostOptionsMenu = 40,
    eUIScene_InGamePlayerOptionsMenu = 41,
    eUIScene_CreativeMenu = 42,
    eUIScene_LaunchMoreOptionsMenu = 43,
    eUIScene_DLCMainMenu = 44,
    eUIScene_NewUpdateMessage = 45,
    eUIScene_EnchantingMenu = 46,
    eUIScene_BrewingStandMenu = 47,
    eUIScene_EndPoem = 48,
    eUIScene_TradingMenu = 50,
    eUIScene_AnvilMenu = 51,
    eUIScene_TeleportMenu = 52,
    eUIScene_HopperMenu = 53,
    eUIScene_BeaconMenu = 54,
    eUIScene_HorseInventoryMenu = 55,
    eUIScene_ClassicCraftingMenu = 56,
    eUIScene_SuperFlatMenu = 57,
    eUIScene_SuperFlatEditLayer = 58,
    eUIScene_SuperFlatPresets = 59,
    eUIScene_GameModeScoreboardMenu = 60,
    eUIScene_WritableBookMenu = 61,
    eUIScene_MapVoteMenu = 62,
    eUIScene_MapSelectMenu = 63,
    eUIScene_BiomePreviewMenu = 64,
    eUIScene_Keyboard = 72,
    eUIScene_QuadrantSignin = 73,
    eUIScene_MessageBox = 74,
    eUIScene_Timer = 75,
    eUIScene_EULA = 76,
    eUIScene_InGameSaveManagementMenu = 77,
    eUIScene_LanguageSelector = 78,
    eUIScene_AchievementsMenu = 79,
    eUIScene_BedrockUpsell = 80,
    eUIScene_DefaultMAYBE = 81,

    eUIComponent_TutorialPopup = 25,
    eUIComponent_Chat = 36,
    eUIScene_HUD = 49,
    eUIComponent_Panorama = 65,
    eUIComponent_Logo = 66,
    eUIComponent_DebugUIConsole = 67,
    eUIComponent_DebugUIMarketingGuide = 68,
    eUIComponent_Tooltips = 69,
    eUIComponent_PressStartToPlay = 70,
    eUIComponent_MenuBackground = 71
};

class UIScene {
public:
    class _CachedSlotDrawData;
    class _TimerInfo {
    public:
        int mTimeDelay;
        int mNextTickTime;
        bool mEnabled;
    };

    UIScene(int, UILayer*);

    void setSafeZone(double, double, double, double);
    void tickTimers();
    void initialiseMovie();
    void loadMovie();
    void doHorizontalResizeCheck();
    void navigateBack();
    void sendInputToMovie(int, bool, bool, bool);
    int convertGameActionToFuiKeycode(int);
    // void handleFocusChange(int, int);
    bool controlHasFocus(UIControl_Base*);
    bool controlHasFocus(int);
    void addTimer(int, int);
    void killTimer(int);
    bool hasTimer(int);
    void* GetCallbackUniqueId();

    fuiFile* getFuiFile() { return this->mFuiFile; }

    virtual void reloadMovie(bool);
    virtual bool needsReloaded();
    virtual bool hasMovie();
    virtual void updateSafeZone();
    virtual void updateViewportTouchOffset();
    virtual double getSafeZoneHalfHeight();
    virtual double getSafeZoneHalfWidth();
    virtual std::wstring getMoviePath() = 0;
    virtual bool mapElementsAndNames();
    virtual ~UIScene();
    virtual EUIScene getSceneType() = 0;
    virtual int getSubSceneType() const;
    virtual void tick();
    virtual void SetFocusToElement(int);
    virtual void handleTimerComplete(int);
    virtual bool stealsFocus();
    virtual bool hasFocus(int);
    virtual void updateTooltips();
    virtual void updateComponents();
    virtual void handleGainFocus(bool);
    virtual void handleLoseFocus();
    virtual bool hidesLowerScenes();
    virtual bool blocksInput();
    virtual void* GetMainPanel();
    virtual void render(int, int, C4JRender::eViewportType);
    virtual void customDraw(const char*, fuiRect*);
    virtual bool allowRepeat(int);
    virtual void handleInput(int, int, bool, bool, bool, bool&);
    virtual void handleDestroy();
    virtual void handlePreUnloadForReload();
    virtual void handlePreReload();
    virtual void handleReload();
    virtual void handlePress(int, int);
    virtual void handleFocusChange(int, int);
    virtual void handleInitFocus(int, int);
    virtual void handleCheckboxToggled(int, bool);
    virtual void handleCheckboxElementToggled(int, int, bool);
    virtual void handleSliderMove(int, int);
    virtual void handleSliderElementMove(int, int, int);
    virtual void handleAnimationEnd();
    virtual void handleSelectionChanged(int);
    virtual void handleRequestMoreData(int, bool);
    virtual void handleTouchBoxRebuild();
    virtual void HandleDLCMountingComplete();
    virtual void HandleDLCInstalled();
    virtual void HandleDLCLicenseChange();
    virtual void HandleTMSBanFileRetrieved();
    virtual void HandleMessage(EUIMessage, void*);
    virtual void HandleSaveDeviceRemoved(int);
    virtual void handleUnlockFullVersion();
    virtual void handleTouchInput(unsigned int, int, int, int, bool, bool, bool);
    virtual void isReadyToDelete();

    static void customDrawFui(void*, const char*, fuiRect*);

    std::wstring wstring_8;
    fuiFile* mFuiFile;
    bool bool_28;
    char gap_29[3];
    void* qword30;
    std::unordered_map<std::wstring, bool> map1;
    std::unordered_map<int, UIScene::_TimerInfo> mTimersMap;
    int mControlFocused;
    int mControlChildFocus;
    float mOpacity;
    bool mIsInitializedMovie;
    bool mVisible;
    bool byte_96;
    bool bool_97;
    UIScene* mBackScene;
    void* mCallbackUniqueId;
    int mResType;  // 0 - 1080p | 1 - 720p
    bool mHidden;
    bool bool_ad;
    int mStageWidth;
    int mStageHeight;
    int mStageWidth2;
    int mStageHeight2;
    std::vector<UIControl*> mUIControls;
    UILayer* mUILayer;
    bool mFocusRelated;
    int mPadID;
    bool mHideLowerScenes;
    bool byte_e9;
    bool byte_ea;
    bool byte_eb;
    int dwordF8;
    std::vector<UIScene::_CachedSlotDrawData*> mCachedSlotDrawData;
};
