#pragma once
#include "chunk.h"
#include "shader.h"
#include "transform.h"
#include "blocks.h"
#include "display.h"
#include "FastNoise.h"
#include "structures.h"

#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include <glm/glm.hpp> 

class ChunkManager
{
public:
	ChunkManager(Blocks* blocks, Display* display);
	virtual ~ChunkManager();
	void LoadChunkFromFile(int x, int z);
	void LoadWorld();
	void SaveChunkToFile(int x, int z, Chunk* chunk);
	Chunk* GenerateChunk(int x, int z);
	void Draw(float x, float z);

private:
	//Chunk* m_chunk;
	void DrawChunk(int ax, int az);
	void UpdateBuffer(int x, int z);
	void GenerateStructure(int type, int x, int y, int z);
	void GenerateTrees(int x, int z);
	int GetGroudLevel(double x, double z); /*GLOBAL*/
	Blocks* m_blocks;
	Display* m_display;
	std::vector<Chunk*> m_chunks;
	int m_old_xPos = -100;
	int m_old_zPos = -100;
	FastNoise m_mapHeightMin;
	FastNoise m_mapHeightMed;
	FastNoise m_mapHeightMaj;
	FastNoise m_mapHeightContinental;

	FastNoise m_mapTemp;
	FastNoise m_mapVariety;
	FastNoise m_mapSandArea;
	FastNoise m_mapBeachHeight;

	std::thread m_loadingThread;

	bool isTransparent(int idOther, int idThis);
	Structures m_structures;
	bool m_bufferNeedsToBeReAssigned = true;

	char& m_xyzToBlock(int globalX, int globalY, int globalZ);

	enum {
		UP,
		FRONT,
		DOWN,
		LEFT,
		BACK,
		RIGHT
	};
};

