
typedef struct PlayerResources {
    int tree;
    int bronze;
    int rock;
    int food;
} PlayerResources;

typedef struct Player {
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

typedef struct Resource {
    ResourceType resource_type;
    int hp;
    float x, y;
} Resource;

enum BuildingType {
    BuildingType_Grass = 1,
    BuildingType_Wood,
    BuildingType_Brick,
    BuildingType_Steel
};

typedef struct Building {
    BuildingType building_type;
    float x, y;
} Building;

