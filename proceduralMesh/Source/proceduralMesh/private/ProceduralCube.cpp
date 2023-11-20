// Fill out your copyright notice in the Description page of Project Settings.


#include "ProceduralCube.h"

// Sets default values
ACube::ACube()
{
	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("CubeMesh"));
	RootComponent = mesh;
	mesh->bUseAsyncCooking = true;
}

// Called when the game starts or when spawned


void ACube::PostActorCreated()
{
	int index;
	Super::PostActorCreated();
	vertices.Empty();
	GetBoxVertices(vertices, size, heigth, FVector(0, 0, 0));
	CreateBox(vertices, mesh, index);
}

void ACube::PostLoad()
{
	int index;
	Super::PostLoad();
	vertices.Empty();
	GetBoxVertices(vertices, size, heigth, FVector(0,0,0));
	CreateBox(vertices, mesh,index);
}

void ACube::OnConstruction(const FTransform& Transform)
{
	int index;
	Super::OnConstruction(Transform);
	vertices.Empty();
	GetBoxVertices(vertices, size, heigth, FVector(0, 0, 0));
	CreateBox(vertices, mesh,index);
}

void ACube::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

