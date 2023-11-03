// Fill out your copyright notice in the Description page of Project Settings.


#include "Cilinder.h"

// Sets default values
ACilinder::ACilinder()
{
	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	RootComponent = mesh;
	mesh->bUseAsyncCooking = true;
}

void ACilinder::PostActorCreated()
{
	Super::PostActorCreated();
	CreateCilinder(100, 0);
}

void ACilinder::PostLoad()
{
	Super::PostLoad();
	CreateCilinder(100, 0);
}
void ACilinder::CreateCilinder(const int radius, const int index)
{
	TArray<FVector> BottomVertices;
	TArray<FVector> TopVertices;
	//TArray<FVector> Svertices;

	int heigth = 100;
	int stepAroundCircle = 8;
	int r = radius;
	float angle = T_PI / stepAroundCircle;

	GetCircleVertices(radius, 0, stepAroundCircle, BottomVertices);
	GetCircleVertices(radius, heigth, stepAroundCircle, TopVertices);
	
	int j;
	for (int i = 1; i < stepAroundCircle * 3; i++) {
		j = i+1;
		//if (j%3 == 0) j += 1;
		if (j >= stepAroundCircle * 3 ) {
			j = 1;
		}
		TArray<FVector> SupVertices;
		SupVertices.Add(TopVertices[i]);
		SupVertices.Add(TopVertices[j]);
		SupVertices.Add(BottomVertices[i]);
		SupVertices.Add(BottomVertices[j]);
		CreateSquare(SupVertices, i+2);
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
	mesh->CreateMeshSection_LinearColor(index+1, BottomVertices, BottomTriangles, normals, UV0, vertexColors, tangents, true);
	// Enable collision data
	mesh->ContainsPhysicsTriMeshData(true);
}
// Called when the game starts or when spawned
void ACilinder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACilinder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

