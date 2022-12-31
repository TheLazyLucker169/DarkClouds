#include "Utils/WndProps.hpp"
#include "Core/Game.hpp"

int main (int argc, char **argv)
{
    WNDPROPS *props = new WNDPROPS();

    props->width = 800;
    props->height = 600;
    props->x = 0;
    props->y = 0;
    props->fullscreen = false;

    Core::Game *DarkClouds = new Core::Game(props);
    
    DarkClouds->Run();

    delete(DarkClouds);
    delete(props);

    return 0;
}