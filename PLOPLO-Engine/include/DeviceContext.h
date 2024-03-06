#pragma once 

#include "Prerequisites.h" 

// Definición de la clase DeviceContext
class DeviceContext
{
public:
	// Constructor y destructor
	DeviceContext() = default;
	~DeviceContext() { SAFE_RELEASE(m_deviceContext); };

	// Métodos públicos de la clase DeviceContext

	// Inicializa el contexto del dispositivo
	void init();

	void update();

	void render();

	void destroy();

	// Limpia la vista de profundidad y stencil
	void ClearDepthStencilView(ID3D11DepthStencilView* pDepthStencilView,
		unsigned int ClearFlags,
		float Depth,
		unsigned int Stencil);

	// Establece los recursos de sombreador de píxel
	void PSSetShaderResources(unsigned int StartSlot,
		unsigned int NumViews,
		ID3D11ShaderResourceView* const* ppShaderResourceViews);

	void ClearRenderTargetView(ID3D11RenderTargetView* pRenderTargetView,
		const float ColorRGBA[4]);

	void OMSetRenderTargets(unsigned int NumViews,
		ID3D11RenderTargetView* const* ppRenderTargetViews,
		ID3D11DepthStencilView* pDepthStencilView);

	void  RSSetViewports(unsigned int NumViewports,
		const D3D11_VIEWPORT* pViewports);

	void IASetInputLayout(ID3D11InputLayout* pInputLayout);

	void  VSSetShader(ID3D11VertexShader* pVertexShader,
		ID3D11ClassInstance* const* ppClassInstances,
		unsigned int NumClassInstances);

	void PSSetShader(ID3D11PixelShader* pPixelShader,
		ID3D11ClassInstance* const* ppClassInstances,
		unsigned int NumClassInstances);

	void DeviceContext::UpdateSubresource(ID3D11Resource* pDstResource,
		unsigned int DstSubresource,
		const D3D11_BOX* pDstBox,
		const void* pSrcData,
		unsigned int SrcRowPitch,
		unsigned int SrcDepthPitch);

public:

	// Puntero al contexto del dispositivo
	ID3D11DeviceContext* m_deviceContext = nullptr;
};