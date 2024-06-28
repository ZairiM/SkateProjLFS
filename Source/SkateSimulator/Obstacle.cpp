
#include "Obstacle.h"
#include "Components/BoxComponent.h"
#include "SkateSimulatorCharacter.h"
#include "SkateSimulatorGameMode.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
AObstacle::AObstacle()
{
    PrimaryActorTick.bCanEverTick = true;

    // Crear y configurar un componente de colisión
    UBoxComponent* CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
    RootComponent = CollisionComponent;
    CollisionComponent->SetCollisionProfileName("Trigger");

    // Configurar la función de superposición
    CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AObstacle::OnOverlapBegin);

}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AObstacle::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    // Verificar si el actor superpuesto es el jugador
    ASkateSimulatorCharacter* PlayerCharacter = Cast<ASkateSimulatorCharacter>(OtherActor);
    if (PlayerCharacter)
    {
        // Incrementar el contador de obstáculos saltados
        PlayerCharacter->IncrementJumpedOverObstaclesCount();

        ASkateSimulatorGameMode* GameMode = Cast<ASkateSimulatorGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

        if (GameMode)
        {
            GameMode->IncrementJumpedObstaclesCounter(PlayerCharacter->GetJumpedOverObstaclesCount());
        }
    }
}


