#pragma once
#include "Prerequisites.h"
class Device;
class DeviceContext;

class
Texture {
public:
	Texture() = default;
	~Texture();

	// Cargar ek archivo de textura 
	void
	init(Device device, std::string textureName);

	//La funcion inicia la textura con parámetros como ancho, alto, formato y banderas de enlace
	void 
	init(Device device,
		unsigned int width,
		unsigned int height,
		DXGI_FORMAT Format,
		unsigned int BindFlags);

	//Cambios dinamicos en la textura 
	void
		update();

	//Renderiza la textura
	void
		render(DeviceContext & deviceContext, unsigned int StartSlot);

	//Destruye la textura, liberando los recursos asociados
	void
		destroy();

public:
	//This variable is in change of handle a texture resorce as data
	ID3D11Texture2D* m_texture = nullptr;
	//This variable is in change of handle a texture resource as image data
	ID3D11ShaderResourceView* m_textureFromImg = nullptr;
};