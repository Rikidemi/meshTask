// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"


void GetSquareVertices(TArray<FVector>& vertices,FVector centre , FTransform T, int size)
{
	vertices.Empty();

	int halfSize = size / 2;
	vertices.Add(T.TransformVector(FVector(centre.X + halfSize, 0, centre.Z - halfSize)));
	vertices.Add(T.TransformVector(FVector(centre.X - halfSize, 0, centre.Z - halfSize)));
	
	vertices.Add(T.TransformVector(FVector(centre.X + halfSize, 0, centre.Z + halfSize)));
	vertices.Add(T.TransformVector(FVector(centre.X - halfSize, 0, centre.Z + halfSize)));
}

void CreateSquare(TArray<FVector>& vertices, UProceduralMeshComponent*& mesh, int index) {

	TArray<int32> Triangles;
	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(2);
	Triangles.Add(1);
	Triangles.Add(3);
	Triangles.Add(2);

	TArray<FVector> normals;
	normals.Add(FVector(0, 0, 1));
	normals.Add(FVector(0, 0, 1));
	normals.Add(FVector(0, 0, 1));
	normals.Add(FVector(0, 0, 1));

	TArray<FVector2D> UV0;
	UV0.Add(FVector2D(0, 0));
	UV0.Add(FVector2D(10, 0));
	UV0.Add(FVector2D(0, 10));
	UV0.Add(FVector2D(10, 10));

	TArray<FProcMeshTangent> tangents;
	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));

	TArray<FLinearColor> vertexColors;
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));

	mesh->CreateMeshSection_LinearColor(index, vertices, Triangles, normals, UV0, vertexColors, tangents, true);
	// Enable collision data
	mesh->ContainsPhysicsTriMeshData(true);
}


void GetCircleVertices(const int radius, const int heigth, TArray<FVector>& vertices, FVector centre, FTransform T)
{
	float angle = T_PI / stepAroundCircle;
	for (int i = 0; i < stepAroundCircle; i++)
	{
		vertices.Add(T.TransformVector(FVector(centre.X, centre.Y, centre.Z + heigth)));
		vertices.Add(T.TransformVector(FVector(centre.X + (radius * cos(angle * (i))), centre.Y + (radius * sin(angle * (i))), centre.Z + heigth)));
		vertices.Add(T.TransformVector(FVector(centre.X + (radius * cos(angle * (i + 1))), centre.Y + (radius * sin(angle * (i + 1))), centre.Z + heigth)));
	}
}
void CreateCircle(TArray<FVector> vertices, UProceduralMeshComponent*& mesh, int& index) {
	
	TArray<int32> Triangles;
	for (int i = 0; i < stepAroundCircle * 3; i++)
	{
		Triangles.Add(i);
	}
	TArray<FVector> normals;
	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(1, 0, 0));

	TArray<FVector2D> UV0;
	UV0.Add(FVector2D(0, 0));
	UV0.Add(FVector2D(10, 0));
	UV0.Add(FVector2D(0, 10));
	UV0.Add(FVector2D(10, 10));

	TArray<FProcMeshTangent> tangents;
	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));

	TArray<FLinearColor> vertexColors;
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));

	mesh->CreateMeshSection_LinearColor(index, vertices, Triangles, normals, UV0, vertexColors, tangents, true);
	mesh->ContainsPhysicsTriMeshData(true);
}

void GetBoxVertices(TArray<FVector>& vertices, int l, int h, int w, FVector centre)
{
	vertices.Empty();
	//FVector centre(100, 100, 100);
	FTransform T(FRotator(0), FVector(centre.X/2, centre.Y/2, centre.Z/2), FVector(1, 1, 1));

	vertices.Add(T.TransformPosition(FVector (l, 0, 0)));
	vertices.Add(T.TransformPosition(FVector (0, 0, 0)));
	vertices.Add(T.TransformPosition(FVector (0, 0, h)));
	vertices.Add(T.TransformPosition(FVector (l, 0, h)));
	vertices.Add(T.TransformPosition(FVector (0, w, 0)));
	vertices.Add(T.TransformPosition(FVector (l, w, 0)));
	vertices.Add(T.TransformPosition(FVector (0, w, h)));
	vertices.Add(T.TransformPosition(FVector (l, w, h)));
}

void CreateBox(TArray<FVector>& vertices, UProceduralMeshComponent*& mesh, int& index)
{
	FVector a, b, c, d, e, f, g, i;
	a = vertices[0];
	b = vertices[1];
	c = vertices[2];
	d = vertices[3];
	e = vertices[4];
	f = vertices[5];
	g = vertices[6];
	i = vertices[7];

	
	TArray<FVector> vert;

	vert.Add(a);
	vert.Add(b);
	vert.Add(d);
	vert.Add(c);
	CreateSquare(vert, mesh, index);
	vert.Empty();

	//FTransform T(rotator, FVector(0, 0, 0), FVector(1, 1, 1));

	vert.Add(f);
	vert.Add(a);
	vert.Add(i);
	vert.Add(d);
	CreateSquare(vert, mesh, ++index);
	vert.Empty();

	vert.Add(d);
	vert.Add(c);
	vert.Add(i);
	vert.Add(g);
	CreateSquare(vert, mesh, ++index);
	vert.Empty();

	vert.Add(b);
	vert.Add(e);
	vert.Add(c);
	vert.Add(g);
	CreateSquare(vert, mesh, ++index);
	vert.Empty();

	vert.Add(e);
	vert.Add(f);
	vert.Add(g);
	vert.Add(i);
	CreateSquare(vert, mesh, ++index);
	vert.Empty();

	vert.Add(b);
	vert.Add(a);
	vert.Add(e);
	vert.Add(f);
	CreateSquare(vert, mesh, ++index);
	vert.Empty();
}

void CreateCilinder(const int radius, const int heigth, UProceduralMeshComponent*& mesh, FVector centre, int& index)
{
	TArray<FVector> BottomVertices, BottomPerimeter;
	TArray<FVector> TopVertices, aux, TopPerimeter;
	//TArray<FVector> Svertices;

	FTransform T(FRotator(0), FVector(centre.X / 2, centre.Y / 2, centre.Z / 2), FVector(1, 1, 1));

	int r = radius;
	float angle = T_PI / stepAroundCircle;

	GetCircleVertices(radius, 0, aux, FVector(0, 0, 0), FTransform());
	for (auto v : aux) {
		BottomVertices.Add(T.TransformPosition(v));
		if (v != aux[0]) BottomPerimeter.AddUnique(T.TransformPosition(v));
	}
	aux.Empty();
	GetCircleVertices(radius, heigth, aux, FVector(0, 0, 0), FTransform());
	for (auto v : aux) {
		TopVertices.Add(T.TransformPosition(v));
		if (v != aux[0]) TopPerimeter.AddUnique(T.TransformPosition(v));
	}
	

	int j;
	for (int i = 0; i < stepAroundCircle+1; i++) {
		j = i + 1;
		//if (j%3 == 0) j += 1;
		if (j >= stepAroundCircle) {
			j = 0;
		}
		TArray<FVector> SupVertices;
		SupVertices.Add(TopPerimeter[i]);
		SupVertices.Add(TopPerimeter[j]);
		SupVertices.Add(BottomPerimeter[i]);
		SupVertices.Add(BottomPerimeter[j]);
		CreateSquare(SupVertices, mesh, index+=i);
		//i = j;
	}

	TArray<int32> TopTriangles;
	for (int i = (stepAroundCircle * 3) - 1; i >= 0; i--)
	{
		TopTriangles.Add(i);
	}

	TArray<int32> BottomTriangles;
	for (int i = 0; i < stepAroundCircle * 3; i++)
	{
		BottomTriangles.Add(i);
	}

	TArray<FVector> normals;
	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(1, 0, 0));

	TArray<FVector2D> UV0;
	UV0.Add(FVector2D(0, 0));
	UV0.Add(FVector2D(10, 0));
	UV0.Add(FVector2D(0, 10));
	UV0.Add(FVector2D(10, 10));

	TArray<FProcMeshTangent> tangents;
	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));

	TArray<FLinearColor> vertexColors;
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));

	mesh->CreateMeshSection_LinearColor(index, TopVertices, TopTriangles, normals, UV0, vertexColors, tangents, true);
	mesh->CreateMeshSection_LinearColor(++index, BottomVertices, BottomTriangles, normals, UV0, vertexColors, tangents, true);
	// Enable collision data
	mesh->ContainsPhysicsTriMeshData(true);
}

