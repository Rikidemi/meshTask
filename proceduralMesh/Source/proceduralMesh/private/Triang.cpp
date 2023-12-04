// Fill out your copyright notice in the Description page of Project Settings.


#include "Triang.h"

ATriang::ATriang()
{
	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("TriangleMesh"));
	RootComponent = mesh;
	mesh->bUseAsyncCooking = true;
}


// This is called when actor is spawned (at runtime or when you drop it into the world in editor)
void ATriang::PostActorCreated()
{
	Super::PostActorCreated();
	CreateTriangle();
}

// This is called when actor is already in level and map is opened
void ATriang::PostLoad()
{
	Super::PostLoad();
	CreateTriangle();
}

void ATriang::CreateTriangle()
{
	TArray<FVector> vertices;
	vertices.Add(FVector(0, 0, 0));
	vertices.Add(FVector(0, 100, 0));
	vertices.Add(FVector(0, 0, 100));

	TArray<int32> Triangles;
	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(2);

	TArray<FVector> normals;
	normals.Add(FVector(0, 0, 1));
	normals.Add(FVector(0, 0, 1));
	normals.Add(FVector(0, 0, 1));

	TArray<FVector2D> UV0;
	UV0.Add(FVector2D(0, 0));
	UV0.Add(FVector2D(10, 0));
	UV0.Add(FVector2D(0, 10));


	TArray<FProcMeshTangent> tangents;
	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));

	TArray<FLinearColor> vertexColors;
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));

	mesh->CreateMeshSection_LinearColor(0, vertices, Triangles, normals, UV0, vertexColors, tangents, true);

	// Enable collision data
	mesh->ContainsPhysicsTriMeshData(true);
}
// Called when the game starts or when spawned
void ATriang::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATriang::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

