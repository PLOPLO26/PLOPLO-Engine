#pragma once
#include "Prerequisites.h"
class Device;
class DeviceContext;

/* brief: Esta clase textura esta encargasa de almacenar proporcionar, recursos
 de texturas (textels)*/

 /*Un recurso textura es una coleccion de datos dise;ada para almacenar texels

  TIPOS DE TEXTURAS
   D3D11_TEXTURE2D_DESC
   Es la estrutura donde se guardan */

class
	Texture {
public:
	Texture() = default;
	~Texture();


	//<summary>
	// Brief: Crea una textura a partir de una imagen (.dds) dedes nuestro ordenador
	// </summary>
	// <param name = " device> llamamos al device para poder generar los recursos en memoria. </param>
	// <param name="tectureName'>: Almacenamos el nombre de la textura , para cargarla desde memoria </param>
	// Cargar ek archivo de textura 
	void
		init(Device device, std::string textureName);


	//<summry?
	// brief: Esta funcion esta encargada de crear una Textura2D a partir de datos proporcionados
	// por el desarrollador.
	// </summary
	// <param name =device> Esta encargado de proporcionar los recursos para crear la textura 2D. </param>
	// <param name = width > Tomara el ancho de nuestra ventana </param>
	// <param name = heihgt> Tomara el alto de nuestra ventana </param>
	// <param name = format> Es un clasificador que permitira crear los espacios de bits
	// correctamente ne la memoria. </param>
	// <param name = BindFlags> Es una caracteristica para clasificar el tipo de textura
	// que se esta creando. </param>
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


	//<summary>
	// brief: Este metodo esta encargado de dibujar los recursos en pantalla (solo si es necesario).
	// <param name = deviceContext> Esta encragado de asignar recursos para ser utilizados. </param>
	// <param name = StartSlot> Esta encargado de asignar el punto de inicio en memoria. 
	//Renderiza la textura
	void
		render(DeviceContext& deviceContext, unsigned int StartSlot, unsigned int NumViews);


	//This method is in change of releasing the resources stored in the class's memory
	//Destruye la textura, liberando los recursos asociados
	void
		destroy();

public:
	//This variable is in change of handle a texture resorce as data
	ID3D11Texture2D* m_texture = nullptr;
	//This variable is in change of handle a texture resource as image data
	ID3D11ShaderResourceView* m_textureFromImg = nullptr;
};