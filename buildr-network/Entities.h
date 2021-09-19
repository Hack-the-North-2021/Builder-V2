
struct PlayerResources {
    int tree;
    int bronze;
    int rock;
    int food;
};

struct Player {
    Player(int player_id) : player_id(player_id), hp(100), x(0), y(0), r(0), resources({ 0,0,0,0 }) {}
    int player_id;
    int hp;
    float x, y, r;
    PlayerResources resources;
};

enum ResourceType {
    ResourceType_Tree = 1,
    ResourceType_Bronze,
    ResourceType_Rock,
    ResourceType_Food
};

struct Resource {
    Resource(ResourceType resource_type, int hp, float x, float y) : resource_type(resource_type), hp(hp), x(x), y(y) {}
    ResourceType resource_type;
    int hp;
    float x, y;
};

enum BuildingType {
    BuildingType_Grass = 1,
    BuildingType_Wood,
    BuildingType_Brick,
    BuildingType_Steel
};

struct Building {
    Building(BuildingType building_type, float x, float y) : building_type(building_type), x(x), y(y) {}
    BuildingType building_type;
    float x, y;
};

