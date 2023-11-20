// Fill out your copyright notice in the Description page of Project Settings.


#include "Cilinder.h"

// Sets default values
ACilinder::ACilinder()
{
	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("CilinderMesh"));
	RootComponent = mesh;
	mesh->bUseAsyncCooking = true;
}

void ACilinder::PostActorCreated()
{
	int index = 0;
	Super::PostActorCreated();
	CreateCilinder(size, heigth, mesh, FVector(100, 100, 0),index);
}

void ACilinder::PostLoad()
{
	int index = 0;
	Super::PostLoad();
	CreateCilinder(size, heigth, mesh, FVector(100, 100, 0),index);
}
void ACilinder::OnConstruction(const FTransform& Transform)
{
	int index = 0;
	Super::OnConstruction(Transform);
	CreateCilinder(size,heigth,mesh,FVector(100,100,0), index);
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

