// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.h"
#include "Triang.generated.h"

UCLASS()
class PROCEDURALMESH_API ATriang : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATriang();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay();
	void PostActorCreated();
	void PostLoad();

	void CreateTriangle();

	UPROPERTY(VisibleAnywhere)
	UProceduralMeshComponent* mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int size = 100;
public:
	// Called every frame
	virtual void Tick(float DeltaTime);
};
