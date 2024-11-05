#ifndef SDL_HANDLER_H
#define SDL_HANDLER_H

#include <SDL2/SDL.h>

#include "log.h"

/// @brief Initializes ev everything related to SDL.
/// @param log_file The pointer to the log file for the current run of the app.
/// @return 1 if unable to initialize else 0.
extern int init_SDL(LogFile log_file) __THROW;

/// @brief Creates a new SDL window.
/// @param title The title of the window to create.
/// @param x The x pos of the window to create.
/// @param y The y pos of the window to create.
/// @param w The width of the window to create.
/// @param h The height of the window to create.
/// @param flags The flags for the window to crete.
/// @param log_file The pointer to the log file for the current run of the app.
/// @return The newly created SDL_Window.
extern SDL_Window* create_SDL_window(char* title, int x, int y, int w, int h, Uint32 flags, LogFile log_file) __THROW;

/// @brief Creates a new SDL renderer for the provided SDL_Window
/// @param window The SDL_Window for which the renderer is to be made.
/// @param log_file The pointer to the log file for the current run of the app.
/// @return The newly created SDL_Renderer
extern SDL_Renderer* create_SDL_renderer(SDL_Window* window, LogFile log_file) __THROW;

/// @brief Renders the given renderer.
/// @param renderer The SDL_Renderer to render.
extern void render(SDL_Renderer* renderer);

/// @brief Destroys the given SDL_Window and SDL_Renderer and sets them to NULL.
/// @param pWindow The pointer to an existing SDL_Window.
/// @param pRenderer The pointer to an existing SDL_Renderer.
/// @param log_file The pointer to the log file for the current run of the app.
extern void destroy_renderer_window(SDL_Window** pWindow, SDL_Renderer** pRenderer, LogFile log_file);

/// @brief Quits SDL and closes the log file.
/// @param pM_window The pointer to the main SDL_Window.
/// @param pM_renderer The pointer to the main SDL_Renderer.
/// @param log_file The pointer to the pointer to the log file for the current run of the app.
extern void quit_SDL(SDL_Window** pM_window, SDL_Renderer** pM_renderer, LogFile* log_file);

#endif // SDL_HANDLER_H