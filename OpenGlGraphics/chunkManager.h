#pragma once
#include "chunk.h"
#include "shader.h"
#include "transform.h"
#include "blocks.h"
#include "display.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <glm/glm.hpp> 


class ChunkManager
{
public:
	ChunkManager(Shader* shader, Transform* transform, Blocks* blocks, Display* display);
	virtual ~ChunkManager();
	void LoadChunkFromFile(int x, int z);
	void LoadWorld();
	void SaveChunkToFile(int x, int z, Chunk* chunk);
	Chunk* GenerateChunk(int x, int z);
	void Draw(float x, float z);

private:
	//Chunk* m_chunk;

	Shader* m_shader;
	Transform* m_transform;
	Blocks* m_blocks;
	Display* m_display;
	std::vector<Chunk*> m_chunks;
};
