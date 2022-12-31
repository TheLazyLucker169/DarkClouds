#include "Game.hpp"

namespace Core
{
    Game::Game(WNDPROPS *props)
    {
        this->m_WndProps = props;
        printf("Dark Clouds\n");

        this->Init();
        printf("Error status: %d\n", this->m_Error);
    }

    Game::~Game()
    {
        this->m_Rnd = nullptr;
        this->m_Wnd = nullptr;
    }

    void Game::Init()
    {
        if(this->m_WndProps != nullptr)
        {
            if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
            {
                printf("SDL wasn't initialized.");
                this->m_Error = -1;
                return;
            }
            else 
            {
                int flags = SDL_WINDOW_HIDDEN;
                if(this->m_WndProps->fullscreen)
                    flags = flags | SDL_WINDOW_FULLSCREEN;

                this->m_Wnd = SDL_CreateWindow("Dark Clouds", this->m_WndProps->x, this->m_WndProps->y, this->m_WndProps->width, this->m_WndProps->height, flags);
                if(this->m_Wnd == nullptr) 
                {
                    printf("Window wasn't created.");
                    this->m_Error = -2;
                    return;
                }

                this->m_Rnd = SDL_CreateRenderer(this->m_Wnd, -1, SDL_RENDERER_ACCELERATED);
                if(this->m_Rnd == nullptr)
                {
                    printf("Renderer wasn't created.");
                    this->m_Error = -3;
                    return;
                }

                SDL_SetRenderDrawColor(this->m_Rnd, 255, 255, 255, 255);
            }
        }
        else
        {
            printf("Window properties not defined.\n");
            this->m_Error = 1;
            return;
        }
    }

    void Game::HandleEvents()
    {
        if(SDL_PollEvent(&this->m_Evnt))
        {
            if(this->m_Evnt.type == SDL_QUIT)
            {
                this->m_InGame = false;
            }

            if(this->m_Evnt.type == SDL_KEYDOWN)
            {
                switch(this->m_Evnt.key.keysym.sym)
                {
                    case SDLK_LEFT:
                        SDL_SetRenderDrawColor(this->m_Rnd, 255, 0, 0, 255);
                        break;

                    case SDLK_RIGHT:
                        SDL_SetRenderDrawColor(this->m_Rnd, 0, 255, 0, 255);
                        break;

                    case SDLK_UP:
                        SDL_SetRenderDrawColor(this->m_Rnd, 0, 0, 255, 255);
                        break;

                    case SDLK_DOWN:
                        SDL_SetRenderDrawColor(this->m_Rnd, 0, 0, 0, 255);
                        break;
                    
                    default:
                        SDL_SetRenderDrawColor(this->m_Rnd, 255, 255, 255, 255);
                        break;
                }
            }
        }
    }

    void Game::Update()
    {
    }

    void Game::Render()
    {
        SDL_RenderClear(this->m_Rnd);
        SDL_RenderPresent(this->m_Rnd);
    }

    void Game::Clear()
    {
        SDL_DestroyRenderer(this->m_Rnd);
        SDL_DestroyWindow(this->m_Wnd);

        SDL_Quit();
    }

    void Game::Run()
    {
        if(this->m_Error == 0)
        {
            this->m_InGame = true;
            SDL_ShowWindow(this->m_Wnd);

            while(this->m_InGame)
            {
                this->HandleEvents();
                this->Update();
                this->Render();
            }

            this->Clear();
        }
    }

    int Game::GetLastErrCode()
    {
        return this->m_Error;
    }
}