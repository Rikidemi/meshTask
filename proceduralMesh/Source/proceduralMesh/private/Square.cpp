// Fill out your copyright notice in the Description page of Project Settings.


#include "Square.h"

// Sets default values
ASquare::ASquare()
{
	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	RootComponent = mesh;
	mesh->bUseAsyncCooking = true;
}

void ASquare::PostActorCreated ()
{
	Super::PostActorCreated();
	CreateSquare(100, 100, 1);
}

// This is called when actor is already in level and map is opened
void ASquare::PostLoad ()
{
	Super::PostLoad();
	CreateSquare(100, 100, 1);
}

void ASquare::CreateSquare(int length, int heigth, int norm) {

	TArray<FVector> vertices;
	vertices.Add(FVector(0, 0, 0));
	vertices.Add(FVector(0, length, 0));
	vertices.Add(FVector(0, 0, heigth));
	vertices.Add(FVector( 0, length,heigth));

	TArray<int32> Triangles;
	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(2);
	Triangles.Add(1);
	Triangles.Add(3);
	Triangles.Add(2);

	TArray<FVector> normals;
	normals.Add(FVector(norm, 0, 0));
	normals.Add(FVector(norm, 0, 0));
	normals.Add(FVector(norm, 0, 0));
	normals.Add(FVector(norm, 0, 0));

	TArray<FVector2D> UV0;
	UV0.Add(FVector2D(0, 0));
	UV0.Add(FVector2D(10, 0));
	UV0.Add(FVector2D(0, 10));
	UV0.Add(FVector2D(10, 10));

	TArray<FProcMeshTangent> tangents;
	tangents.Add(FProcMeshTangent(0, norm, 0));
	tangents.Add(FProcMeshTangent(0, norm, 0));
	tangents.Add(FProcMeshTangent(0, norm, 0));
	tangents.Add(FProcMeshTangent(0, norm, 0));

	TArray<FLinearColor> vertexColors;
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));

	mesh->CreateMeshSection_LinearColor(0, vertices, Triangles, normals, UV0, vertexColors, tangents, true);

	// Enable collision data
	mesh->ContainsPhysicsTriMeshData(true);
}

// Called when the game starts or when spawned
void ASquare::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASquare::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

