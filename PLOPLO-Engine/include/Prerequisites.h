#pragma once
 // std lib
# include <iostream>
# include <sstream>
# include <vector>
# include <string>
# include <chrono>
# include <unordered_map>
// External lib
//// Incluimos las bibliotecas externas necesarias para DirectX
# include <d3d11.h>
# include <d3dx11.h>
# include <d3dcompiler.h>
# include <xnamath.h>

// windows
# include <windows.h>

// Internal Includes
 #include  "Resource.h"

// MACRO for safe release of resources
#define SAFE_RELEASE(x) if(x != nullptr) x->Release(); x = nullptr;

//Macro para imprimir mensajes de depuración
// * To check monster
#define OutputLOG(_ClassName, _FunctionName, _OutputMessage)           \
OutputDebugStringA(_ClassName);                                        \
OutputDebugStringA(" : In Function : ");                               \
OutputDebugStringA(_FunctionName);                                     \
OutputDebugStringA(" : ");                                             \
OutputDebugStringA(_OutputMessage);                                    \
OutputDebugStringA("\n");

// Macro para imprimir advertencias en el depurador
#define WARNING( s )                         \
{                                            \
   std::wostringstream os_;                  \
   os_ << s;                                 \
   OutputDebugStringW( os_.str().c_str() );  \
}

struct SimpleVertex

{
	XMFLOAT3 Pos;
	XMFLOAT2 Tex;
	XMFLOAT3 Nor;
};

__declspec(align(16)) struct LightConfig
{
	XMFLOAT4 LightPos;
	XMFLOAT3 LightColor;
	float AmbientIntensity;
	float padding;
	float LightIntensity;
};

__declspec(align(16)) struct CBChangesEveryFrame
{
	XMMATRIX mWorld;
	XMFLOAT4 vMeshColor;
};

struct Camera
{
	XMMATRIX mView;
	XMMATRIX mProjection;
};

struct Mesh {

	std::string name;
	std::vector <SimpleVertex> vertex;
	std::vector <unsigned int> index;
	int numVertex;
	int numIndex;

};
