// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RippleHit.generated.h"

UCLASS()
class CPPPRACTICE_API ARippleHit : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARippleHit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Assign Ripple Material
	UPROPERTY(EditAnywhere, Category="Ripple Hit")
	UMaterial* RippleMaterial = nullptr;

	//Assign Ripple Object
	UPROPERTY(EditAnywhere, Category="Ripple Hit")
	UStaticMeshComponent* RippleObject = nullptr;

	//UPROPERTY()
	//UMaterialInstance* DynamicMaterial = nullptr;

	//Hit event for bullet to trigger
	UFUNCTION(BlueprintCallable, Category = "Ripple Hit")
	void RippleEffect(FVector HitPosition);
};
