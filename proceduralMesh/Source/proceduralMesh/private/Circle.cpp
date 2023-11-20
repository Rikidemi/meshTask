// Fill out your copyright notice in the Description page of Project Settings.


#include "Circle.h"

// Sets default values
ACircle::ACircle()
{
	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("CircleMesh"));
	RootComponent = mesh;
	mesh->bUseAsyncCooking = true;
}

void ACircle::PostActorCreated()
{
	int index = 0;
	Super::PostActorCreated();

	GetCircleVertices(size, 100, vertices, FVector(0, 0, 0), FTransform(FRotator(90, 0, 0), FVector(0, 0, 100), FVector(1, 1, 1)));
	CreateCircle(vertices, mesh, index);
}

void ACircle::PostLoad()
{
	int index = 0;
	Super::PostLoad();

	GetCircleVertices(size, 100, vertices, FVector(0, 0, 0), FTransform(FRotator(90, 0, 0), FVector(0, 0, 100), FVector(1, 1, 1)));
	CreateCircle(vertices, mesh, index);
}

void ACircle::OnConstruction(const FTransform& Transform)
{
	int index = 0;
	Super::OnConstruction(Transform);

	GetCircleVertices(size, 100, vertices, FVector(0, 0, 0), FTransform(FRotator(90, 0, 0), FVector(0, 0, 100), FVector(1, 1, 1)));
	CreateCircle(vertices, mesh, index);
}

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

