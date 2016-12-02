#pragma once

/********************************

Class:		CVertexBufferObject

Purpose:	Wraps OpenGL vertex buffer
			object.

********************************/
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <GL/glew.h>
#include <gl/GL.h>
#include <GL/glut.h>

#include <vector>

class CVertexBufferObject
{
public:
	void CreateVBO(int a_iSize = 0);
	void DeleteVBO();

	void* MapBufferToMemory(int iUsageHint);
	void* MapSubBufferToMemory(int iUsageHint, UINT uiOffset, UINT uiLength);
	void UnmapBuffer();

	void BindVBO(int a_iBufferType = GL_ARRAY_BUFFER);
	void UploadDataToGPU(int iUsageHint);
	
	void AddData(void* ptrData, UINT uiDataSize);

	void* GetDataPointer();
	UINT GetBufferID();

	int GetCurrentSize();

	CVertexBufferObject();

private:
	UINT uiBuffer;
	int iSize;
	int iCurrentSize;
	int iBufferType;
	std::vector<BYTE> data;

	bool bDataUploaded;
};