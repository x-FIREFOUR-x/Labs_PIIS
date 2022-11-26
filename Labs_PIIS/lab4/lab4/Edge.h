#pragma once

struct Edge {
	int vertices1;
	int vertices2;
	float weight;

	Edge(int ver1, int ver2, float w)
	{
		vertices1 = ver1;
		vertices2 = ver2;
		weight = w;
	}
};

