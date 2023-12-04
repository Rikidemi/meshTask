// Fill out your copyright notice in the Description page of Project Settings.


#include "chair.h"

// Sets default values
Achair::Achair()
{
	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ChairMesh"));
	RootComponent = mesh;
	mesh->bUseAsyncCooking = true;
}

// Called when the game starts or when spawned
void Achair::BeginPlay()
{
	Super::BeginPlay();
}

void Achair::PostActorCreated()
{
	Super::PostActorCreated();
	CreateChair();
}


void Achair::PostLoad()
{
	Super::PostLoad();
	CreateChair();
}

void Achair::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	CreateChair();
}

void Achair::CreateChair()
{
	int size = chairSize;
	int index = 0;
	int border = (size * 20) / 100;
	int legLength = (size * 3 / 4) * 2;

	GetBoxVertices(vertices, size, border, width, FVector(0, 0, legLength));
	CreateBox(vertices, mesh, index);
	
	
	TArray<FVector> backVertices, auxVert;

	//GetBoxVertices(aux, size, border, FVector(500,500,500));
	GetBoxVertices(backVertices, size+50, border, width, FVector(legLength, 0, 0));
	FTransform T(FRotator(90,0,0), FVector(0, 0, 0), FVector(1, 1, 1));
	for (auto v : backVertices) {
		auxVert.Add(T.TransformVector(v));
	}
	
	CreateBox(auxVert, mesh, ++index);
	CreateCilinder(border / 2, legLength / 2, mesh, FVector(0, border, 0), ++index);

	FTransform F(FVector((size * 2) - border, 0, 0));
	CreateCilinder(border / 2, legLength / 2, mesh, F.TransformPosition(FVector(0, border, 0)),++index);
	
	F.SetTranslation(FVector((size * 2) - border, (size * 2) - 2 * border, 0));
	CreateCilinder(border / 2, legLength / 2, mesh, F.TransformPosition(FVector(0, border, 0)), ++index);

	F.SetTranslation(FVector(0, (size * 2) - 2 * border, 0));
	CreateCilinder(border / 2, legLength / 2, mesh, F.TransformPosition(FVector(0, border, 0)), ++index);

	

	}

// Called every frame
void Achair::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

