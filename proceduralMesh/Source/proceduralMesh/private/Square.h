// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.h"
#include "Square.generated.h"

UCLASS()
class ASquare : public AMyActor
{
	GENERATED_BODY()
private:
	//int length;
	TArray<FVector> vertices;

	
public:	
	// Sets default values for this actor's properties
	ASquare();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void PostActorCreated() override;
	void PostLoad() override;
	void OnConstruction(const FTransform& Transform);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
