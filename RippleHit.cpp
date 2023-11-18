// Fill out your copyright notice in the Description page of Project Settings.


#include "RippleHit.h"

// Sets default values
ARippleHit::ARippleHit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RippleObject = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ripple Object"));
	RippleObject->SetupAttachment(RootComponent);
	RippleObject->SetMaterial(0, RippleMaterial);
	
}

// Called when the game starts or when spawned
void ARippleHit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARippleHit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARippleHit::RippleEffect(FVector HitPosition)
{
	//Send hit position from bullet to ripple material
	auto DynamicMaterial = RippleObject->CreateDynamicMaterialInstance(0, RippleMaterial);
	DynamicMaterial->SetVectorParameterValue("Center", HitPosition);
	RippleObject->SetMaterial(0, DynamicMaterial);

}

