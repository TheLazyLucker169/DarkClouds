#ifndef _GAME_HPP_
#define _GAME_HPP_

#pragma once

#include <SDL2/SDL.h>
#include "../Utils/WndProps.hpp"

namespace Core
{
    class Game
    {
        private:
            SDL_Window *m_Wnd = nullptr;
            SDL_Renderer *m_Rnd = nullptr;
            SDL_Event m_Evnt;

            WNDPROPS *m_WndProps = nullptr;

            int m_Error = 0;
            bool m_InGame = false;

            void Init();
            void HandleEvents();
            void Update();
            void Render();
            void Clear();

        protected:
        public:
            Game(WNDPROPS *props);
            ~Game();

            void Run();
            int GetLastErrCode();
    };
}

#endif // _GAME_HPP_