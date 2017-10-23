#pragma once
#include <vector>
#include <glm/glm.hpp> 
#include "shader.h"
#include "transform.h"
#include "blocks.h"
#include "display.h"
#include <bitset>

#define CHUNKSIZE 8
class Chunk
{
public:
	int chunkSize = 8;
	Chunk(char* ids, glm::vec3 chunkRoot, Shader* shader, Transform* transform, Blocks* blocks, Display* display);
	virtual ~Chunk();

	void DrawChunk();
	void UpdateVisibility();
	
	char* blockIDs;

	glm::vec3 m_chunkRoot = glm::vec3(0, 0, 0);
private:
	char* m_visiblilityArray;	//UP FRONT DOWN RIGHT BACK LEFT NULL NULL
	Shader* m_shader;
	Transform* m_transform;
	Blocks* m_blocks;
	Display* m_display;
};
