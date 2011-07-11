#ifndef __InputManager_H__
#define __InputManager_H__

/*
*	Reserved for a future InputManager.
*	Below there's a mapping of input from SWT keys to KeyCode but it's not complete.
*/

namespace Waveit
{
	enum KeyCode
	{
		KC_UNASSIGNED  = 0x00,
		KC_ESCAPE      = 0x1B,
		KC_1           = 0x31,
		KC_2           = 0x32,
		KC_3           = 0x33,
		KC_4           = 0x34,
		KC_5           = 0x35,
		KC_6           = 0x36,
		KC_7           = 0x37,
		KC_8           = 0x38,
		KC_9           = 0x39,
		KC_0           = 0x30,
		KC_MINUS       = 0x2D,    // - on main keyboard
		KC_EQUALS      = 0x3D,
		KC_BACK        = 0x08,    // backspace
		KC_TAB         = 0x09,
		KC_Q           = 0x71,
		KC_W           = 0x77,
		KC_E           = 0x65,
		KC_R           = 0x72,
		KC_T           = 0x74,
		KC_Y           = 0x79,
		KC_U           = 0x75,
		KC_I           = 0x69,
		KC_O           = 0x6F,
		KC_P           = 0x70,
		KC_LBRACKET    = 0x1A,
		KC_RBRACKET    = 0x1B,
		KC_RETURN      = 0x0D,    // Enter on main keyboard
		KC_LCONTROL    = 0x1D,
		KC_A           = 0x61,
		KC_S           = 0x73,
		KC_D           = 0x64,
		KC_F           = 0x66,
		KC_G           = 0x67,
		KC_H           = 0x68,
		KC_J           = 0x6A,
		KC_K           = 0x6B,
		KC_L           = 0x6C,
		KC_SEMICOLON   = 0x2C,
		KC_APOSTROPHE  = 0x27,
		KC_GRAVE       = 0x29,    // accent
		KC_LSHIFT      = 0x2A,
		KC_BACKSLASH   = 0x2B,
		KC_Z           = 0x7A,
		KC_X           = 0x78,
		KC_C           = 0x63,
		KC_V           = 0x76,
		KC_B           = 0x62,
		KC_N           = 0x6E,
		KC_M           = 0x6D,
		KC_COMMA       = 0x33,
		KC_PERIOD      = 0x34,    // . on main keyboard
		KC_SLASH       = 0x35,    // / on main keyboard
		KC_RSHIFT      = 0x36,
		KC_MULTIPLY    = 0x37,    // * on numeric keypad
		KC_LMENU       = 0x38,    // left Alt
		KC_SPACE       = 0x20,
		KC_CAPITAL     = 0x3A,
		KC_F1          = 0x100000A,
		KC_F2          = 0x100000B,
		KC_F3          = 0x100000C,
		KC_F4          = 0x100000D,
		KC_F5          = 0x100000E,
		KC_F6          = 0x100000F,
		KC_F7          = 0x1000010,
		KC_F8          = 0x1000011,
		KC_F9          = 0x1000012,
		KC_F10         = 0x1000013,
		KC_NUMLOCK     = 0x45,
		KC_SCROLL      = 0x46,    // Scroll Lock
		KC_NUMPAD7     = 0x47,
		KC_NUMPAD8     = 0x48,
		KC_NUMPAD9     = 0x49,
		KC_SUBTRACT    = 0x100002D,    // - on numeric keypad
		KC_NUMPAD4     = 0x4B,
		KC_NUMPAD5     = 0x4C,
		KC_NUMPAD6     = 0x4D,
		KC_ADD         = 0x100002B,    // + on numeric keypad
		KC_NUMPAD1     = 0x4F,
		KC_NUMPAD2     = 0x50,
		KC_NUMPAD3     = 0x51,
		KC_NUMPAD0     = 0x52,
		KC_DECIMAL     = 0x53,    // . on numeric keypad
		KC_OEM_102     = 0x56,    // < > | on UK/Germany keyboards
		KC_F11         = 0x1000014,
		KC_F12         = 0x1000015,
		KC_F13         = 0x64,    //                     (NEC PC98)
		KC_F14         = 0x65,    //                     (NEC PC98)
		KC_F15         = 0x66,    //                     (NEC PC98)
		KC_KANA        = 0x70,    // (Japanese keyboard)
		KC_ABNT_C1     = 0x73,    // / ? on Portugese (Brazilian) keyboards
		KC_CONVERT     = 0x79,    // (Japanese keyboard)
		KC_NOCONVERT   = 0x7B,    // (Japanese keyboard)
		KC_YEN         = 0x7D,    // (Japanese keyboard)
		KC_ABNT_C2     = 0x7E,    // Numpad . on Portugese (Brazilian) keyboards
		KC_NUMPADEQUALS= 0x8D,    // = on numeric keypad (NEC PC98)
		KC_PREVTRACK   = 0x90,    // Previous Track (KC_CIRCUMFLEX on Japanese keyboard)
		KC_AT          = 0x91,    //                     (NEC PC98)
		KC_COLON       = 0x92,    //                     (NEC PC98)
		KC_UNDERLINE   = 0x93,    //                     (NEC PC98)
		KC_KANJI       = 0x94,    // (Japanese keyboard)
		KC_STOP        = 0x95,    //                     (NEC PC98)
		KC_AX          = 0x96,    //                     (Japan AX)
		KC_UNLABELED   = 0x97,    //                        (J3100)
		KC_NEXTTRACK   = 0x99,    // Next Track
		KC_NUMPADENTER = 0x9C,    // Enter on numeric keypad
		KC_RCONTROL    = 0x9D,
		KC_MUTE        = 0xA0,    // Mute
		KC_CALCULATOR  = 0xA1,    // Calculator
		KC_PLAYPAUSE   = 0xA2,    // Play / Pause
		KC_MEDIASTOP   = 0xA4,    // Media Stop
		KC_VOLUMEDOWN  = 0xAE,    // Volume -
		KC_VOLUMEUP    = 0xB0,    // Volume +
		KC_WEBHOME     = 0xB2,    // Web home
		KC_NUMPADCOMMA = 0xB3,    // , on numeric keypad (NEC PC98)
		KC_DIVIDE      = 0xB5,    // / on numeric keypad
		KC_SYSRQ       = 0xB7,
		KC_RMENU       = 0xB8,    // right Alt
		KC_PAUSE       = 0xC5,    // Pause
		KC_HOME        = 0xC7,    // Home on arrow keypad
		KC_UP          = 0x1000001,    // UpArrow on arrow keypad
		KC_PGUP        = 0xC9,    // PgUp on arrow keypad
		KC_LEFT        = 0x1000003,    // LeftArrow on arrow keypad
		KC_RIGHT       = 0x1000004,    // RightArrow on arrow keypad
		KC_END         = 0xCF,    // End on arrow keypad
		KC_DOWN        = 0x1000002,    // DownArrow on arrow keypad
		KC_PGDOWN      = 0xD1,    // PgDn on arrow keypad
		KC_INSERT      = 0xD2,    // Insert on arrow keypad
		KC_DELETE      = 0xD3,    // Delete on arrow keypad
		KC_LWIN        = 0xDB,    // Left Windows key
		KC_RWIN        = 0xDC,    // Right Windows key
		KC_APPS        = 0xDD,    // AppMenu key
		KC_POWER       = 0xDE,    // System Power
		KC_SLEEP       = 0xDF,    // System Sleep
		KC_WAKE        = 0xE3,    // System Wake
		KC_WEBSEARCH   = 0xE5,    // Web Search
		KC_WEBFAVORITES= 0xE6,    // Web Favorites
		KC_WEBREFRESH  = 0xE7,    // Web Refresh
		KC_WEBSTOP     = 0xE8,    // Web Stop
		KC_WEBFORWARD  = 0xE9,    // Web Forward
		KC_WEBBACK     = 0xEA,    // Web Back
		KC_MYCOMPUTER  = 0xEB,    // My Computer
		KC_MAIL        = 0xEC,    // Mail
		KC_MEDIASELECT = 0xED     // Media Select
	};


	enum MouseButtonID
	{
		MB_Left,
		MB_Right,
		MB_Middle
	};
}
#endif


