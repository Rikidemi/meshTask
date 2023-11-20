// Fill out your copyright notice in the Description page of Project Settings.


#include "Square.h"

// Sets default values
ASquare::ASquare()
{
	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("SquareMesh"));
	RootComponent = mesh;
	mesh->bUseAsyncCooking = true;
}

void ASquare::PostActorCreated ()
{
	Super::PostActorCreated();
	GetSquareVertices(vertices, FVector(0, 0, 0), FTransform(), size);
	CreateSquare(vertices, mesh, 0);
}

// This is called when actor is already in level and map is opened
void ASquare::PostLoad ()
{
	Super::PostLoad();
	GetSquareVertices(vertices, FVector(0, 0, 0), FTransform(), size);
	CreateSquare(vertices, mesh, 0);
}

void ASquare::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	GetSquareVertices(vertices, FVector(0, 0, 0), FTransform(), size);
	CreateSquare(vertices, mesh, 0);
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

