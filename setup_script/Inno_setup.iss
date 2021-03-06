; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "project-kakapos"
#define MyAppVersion "0.5.9"
#define MyAppPublisher "Kvar_ispw17"
#define MyAppURL "https://www.github.com/enkerewpo/project-kakapos"
#define MyAppExeName "kakapos.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{D6C8CE16-F433-42BE-8867-B92F79D26792}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\project-kakapos
DisableProgramGroupPage=yes
LicenseFile=G:\Projects\project-kakapos\LICENSE
OutputBaseFilename=project_kakapos_0.5.9_test_setup
SetupIconFile=G:\Projects\project-kakapos\ui\kakapos.ico
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked; OnlyBelowVersion: 0,6.1

[Files]
Source: "G:\Projects\build-kakapos-Desktop_Qt_5_9_1_MinGW_32bit-Release\release\kakapos.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "G:\Projects\build-kakapos-Desktop_Qt_5_9_1_MinGW_32bit-Release\release\AStyle.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "G:\Projects\build-kakapos-Desktop_Qt_5_9_1_MinGW_32bit-Release\release\Config\*"; DestDir: "{app}\Config"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "G:\Projects\build-kakapos-Desktop_Qt_5_9_1_MinGW_32bit-Release\release\libs\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "G:\Projects\build-kakapos-Desktop_Qt_5_9_1_MinGW_32bit-Release\release\init_window.py"; DestDir: "{app}"; Flags: ignoreversion
Source: "G:\Projects\build-kakapos-Desktop_Qt_5_9_1_MinGW_32bit-Release\release\plugin_manager.py"; DestDir: "{app}"; Flags: ignoreversion
Source: "G:\Qt\Qt5.9.1\5.9.1\mingw53_32\bin\libgcc_s_dw2-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "G:\Qt\Qt5.9.1\5.9.1\mingw53_32\bin\libstdc++-6.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "G:\Qt\Qt5.9.1\5.9.1\mingw53_32\bin\Qt5Core.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "G:\Qt\Qt5.9.1\5.9.1\mingw53_32\bin\Qt5Gui.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "G:\Qt\Qt5.9.1\5.9.1\mingw53_32\bin\Qt5Widgets.dll"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{commonprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

