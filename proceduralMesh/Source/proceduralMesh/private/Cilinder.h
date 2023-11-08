// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.h"
#include "Cilinder.generated.h"

UCLASS()
class ACilinder : public AMyActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACilinder();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void PostActorCreated() override;
	void PostLoad() override;

	void CreateCilinder(const int radius, const int index);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};