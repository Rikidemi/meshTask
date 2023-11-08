// Fill out your copyright notice in the Description page of Project Settings.


#include "Square.h"

// Sets default values
ASquare::ASquare()
{
	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	RootComponent = mesh;
	mesh->bUseAsyncCooking = true;
	
	vertices.Add(FVector(0, 0, 0));
	vertices.Add(FVector(0, size, 0));
	vertices.Add(FVector(0, 0, size));
	vertices.Add(FVector(0, size, size));
}

void ASquare::PostActorCreated ()
{
	vertices.Empty();
	vertices.Add(FVector(0, 0, 0));
	vertices.Add(FVector(0, size, 0));
	vertices.Add(FVector(0, 0, size));
	vertices.Add(FVector(0, size, size));
	Super::PostActorCreated();
	CreateSquare(vertices,0);
}

// This is called when actor is already in level and map is opened
void ASquare::PostLoad ()
{
	vertices.Empty();
	vertices.Add(FVector(0, 0, 0));
	vertices.Add(FVector(0, size, 0));
	vertices.Add(FVector(0, 0, size));
	vertices.Add(FVector(0, size, size));
	Super::PostLoad();
	CreateSquare(vertices,0);
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

