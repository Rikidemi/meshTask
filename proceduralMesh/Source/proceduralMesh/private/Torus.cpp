// Fill out your copyright notice in the Description page of Project Settings.


#include "Torus.h"

// Sets default values
ATorus::ATorus()
{
	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	RootComponent = mesh;
	mesh->bUseAsyncCooking = true;
}

void ATorus::PostActorCreated()
{
	Super::PostActorCreated();
	CreateTorus(100, 0);
}

void ATorus::PostLoad()
{
	Super::PostLoad();
	CreateTorus(100, 0);
}

void ATorus::CreateTorus(const int radius, const int index)
{
}

// Called when the game starts or when spawned
void ATorus::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATorus::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

