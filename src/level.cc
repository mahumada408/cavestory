#include "level.h"
#include <iostream>

using namespace tinyxml2;

Level::Level() {}

Level::Level(std::string map_name, 
                MVector2 spawn_point,
                Graphics &graphics) : 
                map_name_(map_name),
                spawn_point_(spawn_point),
                size_(MVector2(0,0)) {

    this->LoadMap(map_name, graphics);
}

Level::~Level() {}

void Level::LoadMap(std::string map_name, Graphics &graphics)
{
    // Parse the .tmx file
    XMLDocument doc;
    std::stringstream map_string;
    // Our map name.
    map_string << "/home/manuel/development/cavestory/content/maps/" << map_name << ".tmx";
    
    // Pass in our map to our doc (needs a c string).
    doc.LoadFile(map_string.str().c_str());

    XMLElement* map_node = doc.FirstChildElement("map");

    // Get the width and height of the map and store it in size_.
    int map_width, map_height;
    map_node->QueryIntAttribute("width", &map_width);
    map_node->QueryIntAttribute("height", &map_height);
    //this->size_ << (double)map_width, (double)map_height;
    this->size_.x = map_width;
    this->size_.y = map_height;

    // Get the width and height of the tile and store in tile_size_.
    int tile_width, tile_height;
    map_node->QueryIntAttribute("tilewidth", &tile_width);
    map_node->QueryIntAttribute("tileheight", &tile_height);
    this->tile_size_.x = tile_width;
    this->tile_size_.y = tile_height;

    // Load the tilesets.
    XMLElement* pTileset = map_node->FirstChildElement("tileset");
    if (pTileset != NULL) {
        while (pTileset) {
            int first_gid;

            // Get source path of the tileset image.
            const char* source = pTileset->FirstChildElement("image")->Attribute("source");

            std::stringstream tileset_path;
            tileset_path << source;
            pTileset->QueryIntAttribute("firstgid", &first_gid);
            SDL_Texture *tex = SDL_CreateTextureFromSurface(graphics.GetRenderer(), graphics.LoadImage(tileset_path.str()));
            this->tile_sets.push_back(TileSet(tex, first_gid));

            pTileset = pTileset->NextSiblingElement("tileset");
        }
    }

    // Same thing as above 
    // Load the layers
    XMLElement* pLayer = map_node->FirstChildElement("layer");
    if (pLayer != NULL) {
        while (pLayer) {
            // Loading the <data> element form the map
            XMLElement* pData = pLayer->FirstChildElement("data");
            // There could be more than one data elemt, so we go through all of them
            if (pData != NULL) {
                while (pData) {
                    // Load the tile elements
                    XMLElement* pTile = pData->FirstChildElement("tile");
                    // Go through all the tiles
                    if (pTile != NULL) {
                        // Counter lets us know what tile we are on.
                        int tile_counter = 0;
                        while (pTile) {
                            // Build each tile. 
                            // If gid = 0, no tile should be drawn.
                            if (pTile->IntAttribute("gid") == 0){
                                // Still need to increment
                                tile_counter++;
                                // Check to see if we are at the end or not.
                                if (pTile->NextSiblingElement("tile")) {
                                    pTile = pTile->NextSiblingElement("tile");
                                    continue;
                                }
                                else {
                                    // Means we are at the end.
                                    break;
                                }
                            }

                            // Get tileset for this gid.
                            int gid = pTile->IntAttribute("gid");
                            TileSet tls;
                            // Loop through the tileset.
                            for (int i=0; i < this->tile_sets.size(); i++) {
                                if (this->tile_sets[i].first_gid <= gid){
                                    // This is the gid we want.
                                    tls = this->tile_sets.at(i);
                                    // Break the loop.
                                    break;
                                }
                            }

                            if (tls.first_gid == -1) {
                                // No tileset was found for this gid.
                                tile_counter++;
                                if (pTile->NextSiblingElement("tile")) {
                                    pTile = pTile->NextSiblingElement("tile");
                                    // Force next iteration of the loop.
                                    continue;
                                }
                                else {
                                    // This means we are done.
                                    break;
                                }
                            }

                            // Get the position of the tile in the level.
                            int xx = 0;
                            int yy = 0;
                            xx = tile_counter % map_width;
                            xx *= tile_width;
                            yy = tile_height * (tile_counter / map_width);
                            MVector2 final_tile_position(xx, yy);

                            // Calculate the position of the tile in the tileset.
                            int tileset_width, tileset_height;
                            SDL_QueryTexture(tls.texture, NULL, NULL, &tileset_width, &tileset_height);
                            int tileset_xx = gid % (tileset_width / tile_width) - 1;
                            tileset_xx *= tile_width;
                            int tileset_yy = 0;
                            tileset_yy = tile_height * (gid / (tileset_width / tile_width));
                            MVector2 final_tileset_position(tileset_xx, tileset_yy);

                            // Build the actual tile and add it to the level's tile list.
                            MVector2 map_tile_size(tile_width, tile_height);
                            Tile tile(tls.texture, map_tile_size, final_tileset_position, final_tile_position);
                            this->tile_list_.push_back(tile);
                            tile_counter++;

                            pTile = pTile->NextSiblingElement("tile");
                        }
                    }

                    pData = pData->NextSiblingElement("data");
                }
            }

            // Same as above for the next iteration. loop though all the layers
            pLayer = pLayer->NextSiblingElement("layer");
        }
    }

    // Parse the object groups such as collisions and spawn points.
    XMLElement* pObjectGroup = map_node->FirstChildElement("objectgroup");
    if (pObjectGroup != NULL) {
        while (pObjectGroup) {
            const char* name = pObjectGroup->Attribute("name");
            std::stringstream ss;
            ss << name;
            // Parse the collisions.
            if (ss.str() == "collisions") {
                XMLElement* pObject = pObjectGroup->FirstChildElement("object");
                if (pObject != NULL) {
                    while (pObject) {
                        double x, y, width, height;
                        x = pObject->DoubleAttribute("x");
                        y = pObject->DoubleAttribute("y");
                        width = pObject->DoubleAttribute("width");
                        height = pObject->DoubleAttribute("height");
                        int id = pObject->IntAttribute("id");
                        this->collision_rectangles_.push_back(MRectangle(
                            std::ceil(x) * Sprite::sprite_scaler_, 
                            std::ceil(y) * Sprite::sprite_scaler_, 
                            std::ceil(width) * Sprite::sprite_scaler_, 
                            std::ceil(height) * Sprite::sprite_scaler_, 
                            id));

                        pObject = pObject->NextSiblingElement("object");
                    }
                }
            } 
            // Get the spawn point for the level.
            else if (ss.str() == "spawn points") {
                XMLElement* pObject = pObjectGroup->FirstChildElement("object");
                if (pObject != nullptr) {
                    while (pObject) {
                        double spawn_x = pObject->DoubleAttribute("x");
                        double spawn_y = pObject->DoubleAttribute("y");
                        const char* name = pObject->Attribute("name");
                        std::stringstream spawn_name;
                        spawn_name << name;
                        if (spawn_name.str() == "player") {
                            this->spawn_point_ = MVector2(std::ceil(spawn_x) * Sprite::sprite_scaler_,
                                                          std::ceil(spawn_y) * Sprite::sprite_scaler_);
                        }
                        pObject = pObject->NextSiblingElement("object");
                    }
                }

            }
            // Other objectgroups go here with an else if (ss.str() == "whateva").

            pObjectGroup = pObjectGroup->NextSiblingElement("objectgroup");
        }
    }

}

void Level::LevelUpdate(double elapsed_time) {}

void Level::LevelDraw(Graphics& graphics)
{
    // Draw the background
    for (int i = 0; i < this->tile_list_.size(); i++) {
        //std::cout << "drawing i: " << i << std::endl;
        this->tile_list_.at(i).TileDraw(graphics);   
    }
}

void Level::CollisionDraw(Graphics& graphics) 
{
    for (int i = 0; i < this->collision_rectangles_.size(); i++)
    {
        SDL_Rect dest_rect = {this->collision_rectangles_.at(i).GetLeft(),
                              this->collision_rectangles_.at(i).GetTop(),
                              this->collision_rectangles_.at(i).GetWidth(),  // width 
                              this->collision_rectangles_.at(i).GetHeight()}; // height
        graphics.DrawRect(&dest_rect);
    }
}

std::vector<MRectangle> Level::CheckTileCollisions(const MRectangle& other_rect) {
    std::vector<MRectangle> other;
    for (int i = 0; i < this->collision_rectangles_.size(); i++) {
        if (this->collision_rectangles_.at(i).CollidesWith(other_rect)) {
            other.push_back(this->collision_rectangles_.at(i));
        }
    }
    return other;
}

const MVector2 Level::GetPlayerSpawnPoint() const { return this->spawn_point_; }
