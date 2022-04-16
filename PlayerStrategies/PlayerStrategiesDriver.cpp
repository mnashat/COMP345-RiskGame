#include "PlayerStrategies.h"

// demonstrates part 1: the player strategy pattern
void PlayerStrategiesDriver() {

    // Create several players with different strategies
    auto *benevolentPlayer = new Players::Player("p1");
    auto *benevolentStrategy = new BenevolentPlayerStrategy(benevolentPlayer);

    auto *aggressivePlayer = new Players::Player("p2");
    auto *aggressiveStrategy = new AggressivePlayerStrategy(aggressivePlayer);

    auto *neutralPlayer = new Players::Player("p3");
    auto *neutralStrategy = new NeutralPlayerStrategy(neutralPlayer);

    // Assign strategy to player
    benevolentPlayer->ps = benevolentStrategy;
    aggressivePlayer->ps = aggressiveStrategy;
    neutralPlayer->ps = neutralStrategy;

    auto *engine = new GameEngine();
    engine->startupPhase();
    engine->mainGameLoop();
    engine->winStateChange();

    delete benevolentPlayer;
    delete aggressivePlayer;
    delete neutralPlayer;
    delete engine;
}
