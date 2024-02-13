#include "DeviceContext.h"

//Se utiliza DirectX11 para renderizar graficos

//La funcion se encarga de borrar
//*La funcion verifica primero si pDepthStencilView es nulo. Si lo es, muestra un mensaje 
// de advertencia indicando el error y termina el programa. Si no es nulo, utiliza el 
// contexto de dispositivo m_deviceContext para llamar la funcion ClearDepthStencilView
//de DirectX11 para borrar
void DeviceContext::ClearDepthStencilView(ID3D11DepthStencilView* pDepthStencilView, 
	                                      unsigned int ClearFlags, 
	                                      float Depth, 
	                                      unsigned int Stencil)
{
	if (pDepthStencilView == nullptr)
	{
		WARNING("ERROR: DeviceContex::ClearDepthStencilView : Error in data from params [ CHECK FOR ID3D11DepthStencilView* pDepthStencilView] \n");
		exit(1);
	}
	else
	{
		m_deviceContext->ClearDepthStencilView(pDepthStencilView, ClearFlags, Depth, Stencil);
	}
}

//La funcion se utiliza para establecer una matriz de recursos de sombreador de 
//pixeles (Pixel Shader Resources) en el contexto de dispositivo.
//Es un recurso para los pixeles que se estan renderizando, como texturas, buffers, etc.

//Verifica si ppShaderResourceViewses nulo. Si lo es, muestra un mensaje de advertencia 
// indicando el error y termina el programa. Si no es nulo, utiliza el contexto 
// de dispositivo m_deviceContext para llamar a la función PSSetShaderResources de DirectX 
// 11 para establecer los recursos de sombreador de píxeles.

void 
DeviceContext::PSSetShaderResources(unsigned int StartSlot, 
	                                unsigned int NumViews, 
	                                ID3D11ShaderResourceView* const* ppShaderResourceViews)
{
	if (ppShaderResourceViews == nullptr)
	{
		WARNING("ERROR: DeviceContex::PPSetShaderResources : Error in data from params [ CHECK FOR ID3D11ShaderResourceView* const* ppShaderResourceViews] \n");
		exit(1);
	}
	else
	{
		m_deviceContext->PSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}
}
