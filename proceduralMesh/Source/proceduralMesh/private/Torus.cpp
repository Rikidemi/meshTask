// Fill out your copyright notice in the Description page of Project Settings.


#include "Torus.h"

// Sets default values
ATorus::ATorus()
{
	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("TorusMesh"));
	RootComponent = mesh;
	mesh->bUseAsyncCooking = true;
}

void ATorus::PostActorCreated()
{
	Super::PostActorCreated();
	CreateTorus(0);
}

void ATorus::PostLoad()
{
	Super::PostLoad();
	CreateTorus(0);
}

void ATorus::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	CreateTorus(0);
}

void ATorus::CreateTorus(const int index)
{
	int radius = size;
	TArray<FVector> MidVertices;
	TArray<TArray<FVector>> TorusVertices;
	int meshIndex = index;

	TArray<FVector> CleanVertices;
	GetCircleVertices(radius, 0, MidVertices, FVector(0, 0, 0),FTransform());
	
	for (int i = 0; i < stepAroundCircle; i++) {
		TArray<FVector> AuxVertices;
		float angle = 360 / stepAroundCircle;
		//to be fixed FRotator(0, i * angle, 0)
		
		GetCircleVertices(radius - ((radius*10)/100), 100, AuxVertices, MidVertices[2], FTransform(FRotator(90, i * angle, 0),FVector(0,0,0), FVector(1,1,1)));
		
		TArray<FVector> CleanVerticesAux;
		for (FVector v : AuxVertices) {
			if (!CleanVertices.Contains(v)) {
				CleanVerticesAux.AddUnique(v);
			}
		}
		TorusVertices.Add(AuxVertices);
	}
	
	
	for (int z = 0; z<stepAroundCircle; z++) {
		int j, y;
		y = z + 1;
		if (y >= stepAroundCircle) {
			y = 0;
		}
		for (int i = 0;i<stepAroundCircle*3; i++) {
			j = i + 1;
			if (j>=stepAroundCircle*3) {
				j = 0;
			}
			TArray<FVector> SupVertices;
			SupVertices.Add(TorusVertices[z][j]);
			SupVertices.Add(TorusVertices[z][i]);
			SupVertices.Add(TorusVertices[y][j]);
			SupVertices.Add(TorusVertices[y][i]);
			

			CreateSquare(SupVertices, mesh, meshIndex++);
			SupVertices.Empty();
		}
	}
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

