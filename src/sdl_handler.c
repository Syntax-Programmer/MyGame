#include "../include/sdl_handler.h"

int init_SDL(LogFile log_file) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        gen_logs(log_file, CRITICAL, "Unable to initialize SDL itself.");
        return 1;
    }
    gen_logs(log_file, INFO, "Successfully initialized SDL.");
    return 0;
}

SDL_Window* create_SDL_window(char* title, int x, int y, int w, int h, Uint32 flags, LogFile log_file) {
    SDL_Window* new = SDL_CreateWindow(title, x, y, w, h, flags);
    if (new == NULL) {
        gen_logs(log_file, ERROR, "Unable to create window with title: %s", title);
        return NULL;
    }
    gen_logs(log_file, INFO, "Successfully created window with title: %s", title);
    return new;
}

SDL_Renderer* create_SDL_renderer(SDL_Window* window, LogFile log_file) {
    SDL_Renderer* new = SDL_CreateRenderer(window, -1, 0);
    if (new == NULL) {
        gen_logs(log_file, ERROR, "Unable to create renderer for the window with title: %s", SDL_GetWindowTitle(window));
        return NULL;
    }
    gen_logs(log_file, INFO, "Successfully created renderer for the window with title: %s", SDL_GetWindowTitle(window));
    return new;
}

void render(SDL_Renderer* renderer) {
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void destroy_renderer_window(SDL_Window** pWindow, SDL_Renderer** pRenderer, LogFile log_file) {
    gen_logs(log_file, INFO, "Destroying the renderer and window with title: %s", SDL_GetWindowTitle(*pWindow));
    SDL_DestroyRenderer(*pRenderer);
    *pRenderer = NULL;
    SDL_DestroyWindow(*pWindow);
    *pWindow = NULL;
}

void quit_SDL(SDL_Window** pM_window, SDL_Renderer** pM_renderer, LogFile* pLog_file) {
    gen_logs(*pLog_file, INFO, "Quitting SDL, BYE");
    destroy_renderer_window(pM_window, pM_renderer, *pLog_file);
    SDL_Quit();
    fclose(*pLog_file);
    *pLog_file = NULL;
}
