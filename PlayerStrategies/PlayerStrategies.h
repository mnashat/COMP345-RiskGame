
#ifndef COMP345RISKGAME_PLAYERSTRATEGIES_H
#define COMP345RISKGAME_PLAYERSTRATEGIES_H

#include <iostream>
#include <map>
#include <vector>
#include "../Map/Map.h"
#include "../Cards/Cards.h"
#include "../Player/Player.h"
#include <experimental/random>
using namespace Graph;

void PlayerStrategiesDriver();

class PlayerStrategies {
public:
    Players::Player *player;
    std::string strategyType;

    static const std::string BENEVOLENT_TYPE;
    static const std::string CHEATER_TYPE;
    static const std::string HUMAN_TYPE;
    static const std::string AGGRESSIVE_TYPE;
    static const std::string NEUTRAL_TYPE;

    virtual std::multimap<int, Graph::Territory *> toDefend(const std::vector<Graph::Edge *> &mapEdges) = 0;
    virtual std::multimap<int, Graph::Territory *> toAttack(const std::vector<Graph::Edge *> &edges) = 0;
    virtual void issueOrder(const GameEngine &game) = 0;

    PlayerStrategies(const PlayerStrategies &ps);
    PlayerStrategies(Players::Player *p, std::string strategyType);
    virtual ~PlayerStrategies();
};


class BenevolentPlayerStrategy : public PlayerStrategies {
public:
    std::multimap<int, Graph::Territory *> toDefend(const std::vector<Graph::Edge *> &mapEdges) override;
    std::multimap<int, Graph::Territory *> toAttack(const std::vector<Graph::Edge *> &edges) override;
    void issueOrder(const GameEngine &game) override;

    BenevolentPlayerStrategy& operator=(const BenevolentPlayerStrategy &b);
    friend std::ostream& operator<<(std::ostream &out, const BenevolentPlayerStrategy &b);

    BenevolentPlayerStrategy(Players::Player *p);
    BenevolentPlayerStrategy(const BenevolentPlayerStrategy &b);
    ~BenevolentPlayerStrategy() override;
};

class CheaterPlayerStrategy : public PlayerStrategies {
public:
    std::multimap<int, Graph::Territory *> toDefend(const std::vector<Graph::Edge *> &mapEdges) override;
    std::multimap<int, Graph::Territory *> toAttack(const std::vector<Graph::Edge *> &edges) override;
    void issueOrder(const GameEngine &game) override;

    CheaterPlayerStrategy& operator=(const CheaterPlayerStrategy &cheater);
    friend std::ostream& operator<<(std::ostream &out, const CheaterPlayerStrategy &cheater);

    CheaterPlayerStrategy(Players::Player *p);
    CheaterPlayerStrategy(const CheaterPlayerStrategy &cheater);
    ~CheaterPlayerStrategy() override;
};

class AggressivePlayerStrategy: public PlayerStrategies{
public:
    std::multimap<int, Graph::Territory *> toDefend(const std::vector<Graph::Edge *> &mapEdges) override;
    std::multimap<int, Graph::Territory *> toAttack(const std::vector<Graph::Edge *> &edges) override;
    void issueOrder(const GameEngine &game) override;

    AggressivePlayerStrategy& operator=(const AggressivePlayerStrategy &aggressive);
    friend std::ostream& operator<<(std::ostream &out, const AggressivePlayerStrategy &aggressive);

    AggressivePlayerStrategy(Players::Player *p);
    AggressivePlayerStrategy(const AggressivePlayerStrategy &aggressive);
    ~AggressivePlayerStrategy() override;
};

class NeutralPlayerStrategy: public PlayerStrategies{
public:
    std::multimap<int, Graph::Territory *> toDefend(const std::vector<Graph::Edge *> &mapEdges) override;
    std::multimap<int, Graph::Territory *> toAttack(const std::vector<Graph::Edge *> &edges) override;
    void issueOrder(const GameEngine &game) override;

    NeutralPlayerStrategy& operator=(const NeutralPlayerStrategy &neutral);
    friend std::ostream& operator<<(std::ostream &out, const NeutralPlayerStrategy &neutral);

    NeutralPlayerStrategy(Players::Player *p);
    NeutralPlayerStrategy(const NeutralPlayerStrategy &neutral);
    ~NeutralPlayerStrategy() override;
};

// strategy allowing the player to make decisions through the console
class HumanPlayerStrategy : public PlayerStrategies {
public:
    std::multimap<int, Graph::Territory *> toDefend(const std::vector<Graph::Edge *> &edges) override;
    std::multimap<int, Graph::Territory *> toAttack(const std::vector<Graph::Edge *> &edges) override;
    void issueOrder(const GameEngine &game) override;

    HumanPlayerStrategy& operator=(const HumanPlayerStrategy &h);
    friend std::ostream& operator<<(std::ostream &out, const HumanPlayerStrategy &h);

    explicit HumanPlayerStrategy(Players::Player *p);
    [[maybe_unused]] HumanPlayerStrategy(const HumanPlayerStrategy &h);
    ~HumanPlayerStrategy() override;

private:
    static void printTerritories(const multimap<int, Territory *> &territories);
    void printTerritoriesWithNeighbors(const vector<Edge *> &, const multimap<int, Territory *> &) const;
    void printPlayers(const vector<Players::Player *> &players);
    [[nodiscard]] static string readCommand();
    static int flagArgument(const string &command, const string &flag);
    static bool validateDeployCommand(const string &command, const multimap<int, Territory *> &territories);
    bool validateAdvanceCommand(const string &command, const multimap<int, Territory *> &t, const vector<Edge *> &e);
    static bool validateAirliftCommand(string &command, const multimap<int, Territory *> &territories);
    static bool validateIdCommand(const string &command, const multimap<int, Territory *> &territories);
    static bool validateIdCommand(const string &command, size_t vectorSize);
    static bool validateMenuCommand(const string &command);
    static string promptValidDeploy(const multimap<int, Territory *> &territories);
    string promptValidAdvance(const multimap<int, Territory *> &territories, const vector<Edge *> &edges);
    static string promptValidAirlift(const multimap<int, Territory *> &territories);
    static string promptValidId(const multimap<int, Territory *> &territories);
    static string promptValidId(const vector<Players::Player *> &players);
    static string promptValidId(const vector<Cards::Card *> &hand);
    static string promptValidMenuCommand();
    void issueAdvanceOrder(const string &command, const multimap<int, Territory *> &territories, Map *map);
};

#endif //COMP345RISKGAME_PLAYERSTRATEGIES_H
