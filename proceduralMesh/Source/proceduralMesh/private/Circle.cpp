// Fill out your copyright notice in the Description page of Project Settings.


#include "Circle.h"
#define T_PI 6.28318530718

// Sets default values
ACircle::ACircle()
{
	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	RootComponent = mesh;
	mesh->bUseAsyncCooking = true;
}

void ACircle::PostActorCreated()
{
	Super::PostActorCreated();
	CreateCircle(100,0);
}

void ACircle::PostLoad()
{
	Super::PostLoad();
	CreateCircle(100, 0);
}

void ACircle::CreateCircle(const int radius, const int index)
{
	TArray<FVector> vertices;

	int stepAroundCircle = 100;
	int r = radius;
	float angle = T_PI / stepAroundCircle;

	for (int i = 0; i < stepAroundCircle; i++) 
	{
		vertices.Add(FVector(0, 0, 0));
		vertices.Add(FVector(0, r * cos(angle*(i)), r * sin(angle*(i))));
		vertices.Add(FVector(0, r * cos(angle * (i + 1)), r * sin(angle * (i + 1))));
	}

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
	// Enable collision data
	mesh->ContainsPhysicsTriMeshData(true);
};

// Called when the game starts or when spawned
void ACircle::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACircle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

