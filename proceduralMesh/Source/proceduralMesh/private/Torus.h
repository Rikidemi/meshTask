 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.h"
#include "Torus.generated.h"

UCLASS()
class PROCEDURALMESH_API ATorus : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATorus();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay();
	void PostActorCreated();
	void PostLoad();
	void OnConstruction(const FTransform& Transform);

	void CreateTorus(const int index);
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int size = 100;
	UPROPERTY(VisibleAnywhere)
	UProceduralMeshComponent* mesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) ;

};
