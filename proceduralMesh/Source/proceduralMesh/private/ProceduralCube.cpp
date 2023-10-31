// Fill out your copyright notice in the Description page of Project Settings.


#include "ProceduralCube.h"

// Sets default values
ACube::ACube()
{
	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	RootComponent = mesh;
	mesh->bUseAsyncCooking = true;
}

// Called when the game starts or when spawned


void ACube::PostActorCreated()
{
	Super::PostActorCreated();
	CreateCube(100);
}

void ACube::PostLoad()
{
	Super::PostLoad();
	CreateCube(100);
}

void ACube::CreateCube(const int l)
{
	TArray<FVector> vert;

	FVector a(l, 0, 0);
	FVector b(0, 0, 0);
	FVector c(0, 0, l);
	FVector d(l, 0, l);
	FVector e(0, l, 0);
	FVector f(l, l, 0);
	FVector g(0, l, l);
	FVector h(l, l, l);
	
	vert.Add(a);
	vert.Add(b);
	vert.Add(d);
	vert.Add(c);
	CreateSquare(vert,0);
	vert.Empty();
	
	vert.Add(f);
	vert.Add(a);
	vert.Add(h);
	vert.Add(d);
	CreateSquare(vert,1);
	vert.Empty();
	
	vert.Add(d);
	vert.Add(c);
	vert.Add(h);
	vert.Add(g);
	CreateSquare(vert,2);
	vert.Empty();
	
	vert.Add(b);
	vert.Add(e);
	vert.Add(c);
	vert.Add(g);
	CreateSquare(vert,3);
	vert.Empty();

	vert.Add(e);
	vert.Add(f);
	vert.Add(g);
	vert.Add(h);
	CreateSquare(vert,4);
	vert.Empty();
	
	vert.Add(b);
	vert.Add(a);
	vert.Add(e);
	vert.Add(f);
	CreateSquare(vert,5);
	vert.Empty();
	
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

