// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.h"
#include "ProceduralCube.generated.h"

UCLASS()
class ACube : public AMyActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void PostActorCreated() override;
	void PostLoad() override;

	void CreateCube(const int);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
