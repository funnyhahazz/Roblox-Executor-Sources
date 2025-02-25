#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "WrapperInternals.h"
#include "Security.h"

using namespace std;

extern int rState;
/*
void validity(int a, bool debug)
{
	if (debug)
	{
		rlua_index2adr = reinterpret_cast<Llua_index2adr>(scan("\x55\x8B\xEC\x56\x8B\x75\x0C\x85\xF6\x7E\x1C", "xxxxxxxxxxx"));
		rlua_getfield_real = reinterpret_cast<Lua_getfield>(unprotect(static_cast<uintptr_t>(scan("\x55\x8B\xEC\x83\xEC\x10\x53\x56\x8B\x75\x08\x57\xFF\x75\x0C\x56\xE8\xEB\x78\xFF\xFF\x8B\x55\x10", "xxxxxxxxxxxxxxxxxxxxxxxx")))); // updated??
		rlua_setfield_r = reinterpret_cast<Lua_setfield>(unprotect(static_cast<uintptr_t>(scan("\x55\x8B\xEC\x83\xEC\x10\x53\x56\x8B\x75\x08\x57\xFF\x75\x0C\x56\xE8\x1B\x5B\xFF\xFF\x8B\x55\x10", "xxxxxxxxxxxxxxxxxxxxxxxx")))); // updated???
		rlua_getmetatable = reinterpret_cast<Lua_getmetatable>(unprotect(static_cast<uintptr_t>(scan("\x55\x8B\xEC\x56\xFF\x75\x0C\x8B\x75\x08\x56\xE8\x00\x00\x00\x00\x83\xC4\x08\x8B", "xxxxxxxxxxxx????xxxx")))); // updated
		rluaS_newlstr = reinterpret_cast<LuaS_newlstr>(scan("\x55\x8B\xEC\x83\xEC\x08\x53\x56\x57\x8B\xC2", "xxxxxxxxxxx")); // updated
		rlua_tolstring = reinterpret_cast<Llua_tolstring>(unprotect(static_cast<uintptr_t>(scan("\x55\x8B\xEC\x56\xFF\x75\x0C\x8B\x75\x08\x56\xE8\x00\x00\x00\x00\x8B\xD0", "xxxxxxxxxxxx????xx")))); // updated
		rlua_rawgeti_real = reinterpret_cast<Llua_rawgeti>(unprotect(static_cast<uintptr_t>(scan("\x55\x8B\xEC\x56\xFF\x75\x0C\x8B\x75\x08\x56\xE8\x00\x00\x00\x00\xFF\x75\x10", "xxxxxxxxxxxx????xxx")))); // updated
		rlua_rawseti = reinterpret_cast<Llua_rawseti>(unprotect(static_cast<uintptr_t>(scan("\x55\x8B\xEC\x83\xEC\x14\x56\xFF\x75\x0C", "xxxxxxxxxx"))));
		rlua_createtable = reinterpret_cast<Llua_createtable>(unprotect(static_cast<uintptr_t>(scan("\x55\x8B\xEC\x56\x57\x8B\x7D\x08\x8D\x47\x0C\x8B\xC8\x2B\x08\x2B\x00\x8B\x40\x44\x3B\x41\x50\x72\x09\x57\xE8\x00\x00\x00\x00\x83\xC4\x04\xFF\x75\x10\x8B\x77\x14", "xxxxxxxxxxxxxxxxxxxxxxxxxxx????xxxxxxxxx")))); // updated
		r_identity = reinterpret_cast<Identity>(ScanAddress(0x17E631C)); // updated
		rlua_pcall_r = reinterpret_cast<Rlua_pcall>(unprotect(static_cast<uintptr_t>(scan("\x55\x8B\xEC\x8B\x45\x14\x83\xEC\x08\x57", "xxxxxxxxxx")))); // updated
		rlua_pushcclosure = reinterpret_cast<pcc>(unprotect(static_cast<uintptr_t>(scan("\x55\x8B\xEC\x53\x56\x8B\x75\x08\x8D\x46", "xxxxxxxxxx")))); // updated
		rlua_next = reinterpret_cast<nxt>(unprotect(static_cast<uintptr_t>(scan("\x55\x8B\xEC\x56\xFF\x75\x0C\x8B\x75\x08\x56\xE8\x00\x00\x00\x00\x8B\x4E\x14\x83\xE9\x10\x51\xFF\x30\x56", "xxxxxxxxxxxx????xxxxxxxxxx")))); // updated
		rlua_getmetafield_real = reinterpret_cast<ona>(scan("\x55\x8B\xEC\x56\xFF\x75\x0C\x8B\x75\x08\x56\xE8\x00\x00\x00\x00\x83\xC4\x08\x8B", "xxxxxxxxxxxx????xxxx")))); // updated
		//rlua_error = reinterpret_cast<err>(scan("\x55\x8B\xEC\x83\xEC\x08\x8B\x55\x0C\x56\xC7\x45", "xxxxxxxxxxxx"));
		rlua_settable = reinterpret_cast<stt>(unprotect(static_cast<uintptr_t>(scan("\x55\x8B\xEC\x56\xFF\x75\x0C\x8B\x75\x08\x56\xE8\x00\x00\x00\x00\x8B\x56\x14\x8D", "xxxxxxxxxxxx????xxxx")))); // updated
		rlua_pushnumber = reinterpret_cast<Llua_pushnumber>(unprotect(static_cast<uintptr_t>(scan("\x55\x8B\xEC\x8B\x4D\x08\x0F\x28", "xxxxxxxx")))); // updated
	}
}
*/

void validity(int a, bool debug)
{
	if (debug)
	{
		rlua_index2adr = reinterpret_cast<Llua_index2adr>(unprotect(ScanAddress(0x748730))); // updated __cdecl
		rlua_getfield_real = reinterpret_cast<Lua_getfield>(unprotect(ScanAddress(0x750E30))); // updated __stdcall
		rlua_setfield_r = reinterpret_cast<Lua_setfield>(unprotect(ScanAddress(0x752C00))); // updated __stdcall
		rlua_getmetatable = reinterpret_cast<Lua_getmetatable>(unprotect(ScanAddress(0x751100))); // updated __cdecl
		rluaS_newlstr = reinterpret_cast<LuaS_newlstr>(unprotect(ScanAddress(0x74C880))); // updated __Fastcall
		rlua_tolstring = reinterpret_cast<Llua_tolstring>(unprotect(ScanAddress(0x753220))); // updated __cdecl
		rlua_rawgeti_real = reinterpret_cast<Llua_rawgeti>(unprotect(ScanAddress(0x752560))); // updated __cdecl
		rlua_rawseti = reinterpret_cast<Llua_rawseti>(unprotect(ScanAddress(0x7526D0))); // updated __cdecl
		rlua_createtable = reinterpret_cast<Llua_createtable>(unprotect(ScanAddress(0x750AE0))); // updated __cdecl
		r_identity = reinterpret_cast<Identity>(unprotect(ScanAddress(0x17E631C))); // updated
		rlua_pcall_r = reinterpret_cast<Rlua_pcall>(unprotect(ScanAddress(0x751C10))); // updated __cdecl
		rlua_pushcclosure = reinterpret_cast<pcc>(unprotect(ScanAddress(0x751D60))); // updated __cdecl
		rlua_next = reinterpret_cast<nxt>(unprotect(ScanAddress(0x751A90))); // updated __cdecl
		rlua_getmetafield_real = reinterpret_cast<ona>(unprotect(ScanAddress(0x751100))); // updated __cdecl
		rlua_settable = reinterpret_cast<stt>(unprotect(ScanAddress(0x752F50))); // updated __cdecl
		rlua_pushnumber = reinterpret_cast<Llua_pushnumber>(unprotect(ScanAddress(0x752160))); // updated __stdcall
	}
}

void init()
{
	DWORD Console;
	VirtualProtect((LPVOID)&FreeConsole, 1, PAGE_EXECUTE_READWRITE, &Console);
	*(LONG_PTR*)(&FreeConsole) = 195;
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	freopen("CONIN$", "r", stdin);
	SetWindowLong(GetConsoleWindow(), GWL_STYLE, (WS_CAPTION | DS_MODALFRAME | WS_MINIMIZEBOX | WS_SYSMENU));
	SetWindowPos(GetConsoleWindow(), HWND_TOPMOST, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOSIZE | SWP_NOMOVE | SWP_SHOWWINDOW);
	ShowWindow(GetConsoleWindow(), SW_NORMAL);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	validity(0, true);
	int SCV = ScanAddress(0x115AFA4); // updated
	ScriptContext = Scan(PAGE_READWRITE, (char*)&SCV, (char*)"xxxx");
	if (ScriptContext == 0x20)
		std::cout << "Script context is very wrong my friend." << std::endl;
	std::cout << "SCV " << SCV << " SC " << ScriptContext << std::endl;
	rState = *(DWORD *)(ScriptContext + 56 * 1 + 164) - (ScriptContext + 56 * 1 + 164); // updated
	BypassCallCheck();
	//WinApiApplyHook(RyseExitMessage, (PCHAR)"MessageBoxA", (PCHAR)"user32.dll");
	//HookLocation(LocateNTFunction((PCHAR)"KiUserExceptionDispatcher"),
	          // (LocateNTFunction((PCHAR)"KiUserExceptionDispatcher") + 0x18));
	std::string src;

	lua_state = luaL_newstate();
	lua_newtable(lua_state);
	lua_setmetatable(lua_state, -10002);
	lua_getmetatable(lua_state, -10002);
	lua_pushcfunction(lua_state, WrapperInternals::RobloxGlobalIndex);
	lua_setfield(lua_state, -2, "__index");

	while (std::getline(std::cin, src))
	{
		cout << "WrapperInternals::execute(src.c_str()" << "\r\n" << endl;
		WrapperInternals::execute(src.c_str());
		cout << "script:" << "\r\n" << endl;
		cout << src << endl;
	}
}

std::vector<std::string> split_string(const std::string& str, char delimiter)
{
	std::vector<std::string> tokens;
	std::stringstream ss(str);
	std::string tok;

	while (std::getline(ss, tok, delimiter))
		tokens.push_back(tok);

	return tokens;
}

static void erase_peheaders()
{
	HMODULE hdll;
	char cpath[MAX_PATH];
	GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
	                  (LPCSTR)split_string, &hdll);
	GetModuleFileName(hdll, cpath, MAX_PATH);

	DWORD old;
	VirtualProtect(hdll, 0x500, PAGE_READWRITE, &old);
	memset(hdll, 0, 0x500);
	VirtualProtect(hdll, 0x500, old, &old);
}


BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD ul_reason_for_call,
                      LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)erase_peheaders, nullptr, NULL, nullptr);
		CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)init, nullptr, NULL, nullptr);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
