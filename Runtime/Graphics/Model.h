/*
Copyright(c) 2016-2017 Panos Karabelas

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

//= INCLUDES ====================
#include <memory>
#include <vector>
#include "../Resource/Resource.h"
#include "../Math/Vector3.h"
#include "../Math/MathHelper.h"
//===============================

namespace Directus
{
	class ResourceManager;
	class GameObject;
	class Mesh;
	struct VertexPosTexNorTan;

	class Model : public Resource
	{
	public:
		Model(Context* context);
		~Model();

		//= RESOURCE INTERFACE ================================
		virtual bool LoadFromFile(const std::string& filePath);
		virtual bool SaveToFile(const std::string& filePath);
		//======================================================

		void SetRootGameObject(std::weak_ptr<GameObject> gameObj) { m_rootGameObj = gameObj; }
		std::weak_ptr<Mesh> AddMesh(const std::string& gameObjID, const std::string& name, std::vector<VertexPosTexNorTan> vertices, std::vector<unsigned int> indices);
		std::weak_ptr<Mesh> GetMeshByID(const std::string& id);
		std::weak_ptr<Mesh> GetMeshByName(const std::string& name);

		std::string CopyFileToLocalDirectory(const std::string& from);

		const Math::Vector3& GetCenter() { return m_center; }
		const Math::Vector3& GetBoundingBox() { return m_extent; }
		float GetBoundingSphereRadius() { return Math::Max(Math::Max(abs(m_extent.x), abs(m_extent.y)), abs(m_extent.z)); }

	private:
		void AddMesh(std::shared_ptr<Mesh> mesh);
		bool LoadFromEngineFormat(const std::string& filePath);
		bool LoadFromForeignFormat(const std::string& filePath);

		void SetScale(float scale);
		float ComputeNormalizeScale();
		std::weak_ptr<Mesh> ComputeLargestBoundingBox();
		void ComputeDimensions();

		std::weak_ptr<GameObject> m_rootGameObj;
		std::vector<std::shared_ptr<Mesh>> m_meshes;
		ResourceManager* m_resourceManager;


		Math::Vector3 m_min;
		Math::Vector3 m_max;
		Math::Vector3 m_extent;
		Math::Vector3 m_center;
		float m_normalizedScale;
	};
}