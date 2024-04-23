#pragma once
#include "Prerequisites.h"
#include "Commons.h"

class
	Device;

class
	DeviceContext;

class
	ConstantBuffer {

public:
	ConstantBuffer() = default;
	~ConstantBuffer() {};


	/* This function initializes a constant buffer by creating it using the "CreateBuffer"
	* function of the "Device" object
	*
	* The function initializes a constant buffer by creating it using the "CreateBuffer"
	* function of the "Device" object.
	*
	* The function then calls the "CreateBuffer" function of the "Device" object,
	* passing in the "ConstantBufferDesc" object and a pointer to the "m_constantBuffer"
	* member variable of the "ConstantBuffer" class.
	*/
	void
		init(Device device, unsigned int ByteWidth);


	/* This function updates the data in the constant buffer by calling the
	* "UpdateSubresource" function of the "DeviceContext" object
	*
	* This function is used to copy data from CPU memory to GPU memory.
	* The CPU copies data from memory to a subresource created in non-mappable memory.
	*
	* deviceContext: Reference to call method UpdateSubresource
	*/
	void
		update(DeviceContext& deviceContext,
			unsigned int DstSubresource,
			const D3D11_BOX* pDstBox,
			const void* pSrcData,
			unsigned int SrcRowPitch,
			unsigned int SrcDepthPitch);

	void
		render();


	// This function releases the pointer m_constantBuffer and sets it equal to NULL.
	void
		destroy();



	/* Sets the constant buffers used by the vertex shader pipeline stage.
	*
	* deviceContext: Reference to call method VSSetConstantBuffers
	*
	* StartSlot: Index into the device's zero-based array to begin setting constant buffers
	*
	* NumBuffers: Number of buffers to set
	*/
	void
		VSSetConstantBuffer(DeviceContext& deviceContext,
			unsigned int StartSlot,
			unsigned int NumBuffers);


	/* Sets the constant buffers used by the pixel shader pipeline stage.
	*
	* deviceContext: Reference to call method PSSetConstantBuffers
	*
	* StartSlot: Index into the device's zero-based array to begin setting constant buffers
	*
	* NumBuffers: Number of buffers to set
	*/
	void
		PSSetConstantBuffers(DeviceContext& deviceContext,
			unsigned int StartSlot,
			unsigned int NumBuffers);


public:

	/* A buffer interface accesses a buffer resource,
	* which is unstructured memory. Buffers typically store vertex or index data.
	*/
	ID3D11Buffer* m_constantBuffer = nullptr;

};