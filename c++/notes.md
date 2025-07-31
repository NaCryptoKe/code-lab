# SDL Notes – Your Road to Open Source Fire

## 🚀 What is SDL?

- **SDL** = Simple DirectMedia Layer
- Built for **game dev**, **multimedia apps**, and **low-level graphics/audio/input**
- Handles: Window creation, 2D rendering, audio playback, input devices

---

## 🛠️ SDL2 vs SDL3

| Feature             | SDL2                          | SDL3 (in dev)                            |
|---------------------|-------------------------------|-------------------------------------------|
| Header              | `#include <SDL2/SDL.h>`       | `#include <SDL3/SDL.h>`                  |
| Audio               | Mixer & legacy support        | Modernized backend                        |
| Surfaces            | Used often                    | Mostly deprecated, prefer Renderers       |
| Rendering           | 2D renderer, OpenGL backend    | Vulkan & modern graphics API support      |
| Init                | Manual subsystem flags        | May move toward module-based startup      |
| API Style           | C-style functions              | Similar, but stripped & leaner            |

---

## 💡 Basic SDL2 Lifecycle

```text
1. SDL_Init(SDL_INIT_VIDEO)
2. SDL_CreateWindow
3. SDL_CreateRenderer
4. Game loop (poll events, render)
5. Cleanup (destroy renderer/window, SDL_Quit)
```

## 🧱 SDL Core Concepts
**Window & Renderer**
```cpp
SDL_Window* window = SDL_CreateWindow(...);
SDL_Renderer* renderer = SDL_CreateRenderer(window, ...);
```

**Event Polling**
```cpp
SDL_Event e;
while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) ...
}
```

**Rendering**
```cpp
SDL_SetRenderDrawColor(renderer, r, g, b, a);
SDL_RenderClear(renderer);
SDL_RenderPresent(renderer);
```

## 🧼 SDL Cleanup
Use smart pointers to avoid memory leaks:
```cpp
std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window{nullptr, SDL_DestroyWindow};
```

