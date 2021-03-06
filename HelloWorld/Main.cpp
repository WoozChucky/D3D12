﻿#define WIN32_LEAN_AND_MEAN

#define _DISABLE_EXTENDED_ALIGNED_STORAGE

#pragma comment(lib, "D3DCompiler.lib")
#pragma comment(lib, "Shlwapi.lib")

#include <Windows.h>
#include <Shlwapi.h>
#include <dxgidebug.h>

#include "SampleGame.h"

#include <base_application.h>
#include <Application.h>


void ReportLiveObjects()
{
	IDXGIDebug1* dxgiDebug;
	DXGIGetDebugInterface1(0, IID_PPV_ARGS(&dxgiDebug));

	dxgiDebug->ReportLiveObjects(DXGI_DEBUG_ALL, DXGI_DEBUG_RLO_IGNORE_INTERNAL);
	dxgiDebug->Release();
}

int CALLBACK wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nCmdShow)
{
	auto retCode = 0;

	

	// Set the working directory to the path of the executable.
	WCHAR path[MAX_PATH];
	HMODULE hModule = GetModuleHandleW(NULL);

	if (GetModuleFileNameW(hModule, path, MAX_PATH) > 0)
	{
		PathRemoveFileSpecW(path);
		SetCurrentDirectoryW(path);
	}

	Application::Create(hInstance);
	{
		auto demo = std::make_shared<SampleGame>(L"Window Title", 1280, 720);
		retCode = Application::Get().Run(demo);
	}

	Application::Destroy();

	atexit(&ReportLiveObjects);

	return retCode;
}