// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "MyActor.generated.h"

UCLASS()
class PROCEDURALMESH_API AMyActor : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere)
	UProceduralMeshComponent* mesh;


public:
	// Sets default values for this actor's properties
	AMyActor();

	void PostActorCreated();

protected:
	void PostLoad();
	void CreateTriangle();
	void CreateSquare();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
