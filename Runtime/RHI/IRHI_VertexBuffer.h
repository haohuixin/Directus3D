/*
Copyright(c) 2016-2018 Panos Karabelas

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is furnished
to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

//= INCLUDES ==============
#include "RHI_Definition.h"
#include <vector>
//=========================

namespace Directus
{
	class IRHI_VertexBuffer
	{
	public:
		IRHI_VertexBuffer(RHI_Device* rhiDevice) {};
		~IRHI_VertexBuffer() {};

		virtual bool Create(const std::vector<RHI_Vertex_PosCol>& vertices) = 0;
		virtual bool Create(const std::vector<RHI_Vertex_PosUV>& vertices) = 0;
		virtual bool Create(const std::vector<RHI_Vertex_PosUVTBN>& vertices) = 0;
		virtual bool CreateDynamic(unsigned int stride, unsigned int initialSize) = 0;
		virtual void* Map() = 0;
		virtual bool Unmap() = 0;
		virtual bool Bind() = 0;

		unsigned int GetMemoryUsage() { return m_memoryUsage; }

	protected:
		unsigned int m_memoryUsage;
	};
}