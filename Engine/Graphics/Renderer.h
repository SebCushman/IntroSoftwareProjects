#pragma once
#include "Core/System.h"
#include <SDL.h>

namespace nc {
    class Renderer : public System {
    public:

        virtual bool Startup() override;
        virtual void Shutdown() override;
        virtual void Update() override;

        bool Create(const std::string& name, int width, int height);
        void BeginFrame();
        void EndFrame();

        Vector2 GetDimensions() { return { m_width, m_height }; }

        friend class Texture;

    protected:
        int m_width{ 0 };
        int m_height{ 0 };

        SDL_Window* m_window{ nullptr };
        SDL_Renderer* m_renderer{ nullptr };
    };
}