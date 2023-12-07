// Fill out your copyright notice in the Description page of Project Settings.


#include "Table.h"

// Sets default values
ATable::ATable()
{
	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("TableMesh"));
	RootComponent = mesh;
	mesh->bUseAsyncCooking = true;
}

// Called when the game starts or when spawned
void ATable::BeginPlay()
{
	Super::BeginPlay();
}

void ATable::PostActorCreated()
{
	Super::PostActorCreated();
	CreateTable();
}

void ATable::PostLoad()
{
	Super::PostLoad();
	CreateTable();
}

void ATable::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	CreateTable();
}

void ATable::CreateTable()
{
	int index = 0;
	int border = (size * 20) / 100;
	int legLength = (size * 3 / 4) * 2;
	mesh->ClearAllMeshSections();

	GetBoxVertices(vertices, size, border, width, FVector(0, 0, legLength));
	CreateBox(vertices, mesh, index);

	TArray<FVector> backVertices, auxVert;

	CreateCilinder(border / 2, legLength / 2, mesh, FVector(border, border, 0), ++index);

	FTransform F(FVector((size * 2) - border, 0, 0));
	CreateCilinder(border / 2, legLength / 2, mesh, F.TransformPosition(FVector(0, border, 0)), ++index);

	F.SetTranslation(FVector((size * 2) - border, width * 2 - 2 * border, 0));
	CreateCilinder(border / 2, legLength / 2, mesh, F.TransformPosition(FVector(0, border, 0)), ++index);

	F.SetTranslation(FVector(border, width * 2  -  2 * border, 0));
	CreateCilinder(border / 2, legLength / 2, mesh, F.TransformPosition(FVector(0, border, 0)), ++index);

}

// Called every frame
void ATable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

