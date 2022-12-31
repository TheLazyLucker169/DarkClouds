#include "Core/Game.hpp"
#include "Utils/WndProps.hpp"

int TestInitialization();
int TestWindow();

int main (int argc, char **argv)
{
    if(!strcmp(argv[1], "Init"))
    {
        return TestInitialization();
    }
    else if(!strcmp(argv[1], "Window"))
    {
        return TestWindow();
    }
    return 0;
}

int TestInitialization()
{
    printf("Testing game initialization.\n");
    int ret = -1;

    WNDPROPS *props = new WNDPROPS();
    props->x = 0;
    props->y = 0;
    props->width = 400;
    props->height = 300;
    props->fullscreen = false;

    Core::Game *game = new Core::Game(props);

    if(game)
        ret = 0;

    delete(game);
    delete(props);
    
    return ret;
}

int TestWindow()
{
    printf("Testing game window.\n");
    int ret = -1;

    WNDPROPS *props = new WNDPROPS();
    props->x = 0;
    props->y = 0;
    props->width = 400;
    props->height = 300;
    props->fullscreen = false;

    Core::Game *game = new Core::Game(props);

    game->Run();

    ret = game->GetLastErrCode();

    delete(game);
    delete(props);
    
    return ret;
}