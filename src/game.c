#include "../include/game.h"

/// @brief Handles the key presses from the user.
/// @param log_file The pointer to the log file for the current run of the app.
/// @param pEvent The pointer to the current event.
static void handle_keyboard(LogFile log_file, SDL_Event* pEvent);

/// @brief Handles the mouse presses from the user.
/// @param log_file The pointer to the log file for the current run of the app.
/// @param pEvent The pointer to the current event.
static void handle_mouse(LogFile log_file, SDL_Event* pEvent);

/// @brief Handles the inputs from the user.
/// @param log_file The pointer to the log file for the current run of the app.
static int handle_events(LogFile log_file);

static void handle_keyboard(LogFile log_file, SDL_Event* pEvent) {
    const Uint8* keyboard_state = SDL_GetKeyboardState(NULL);
    // Used if instead of switch as we need to check for compound event.
    if (keyboard_state[SDL_SCANCODE_ESCAPE]) {
        gen_logs(log_file, DEBUG, "Keyboard press: Esc.");
    } if (keyboard_state[SDL_SCANCODE_W] | keyboard_state[SDL_SCANCODE_UP]) {
        gen_logs(log_file, DEBUG, "Keyboard press: W or UP.");
    } if (keyboard_state[SDL_SCANCODE_A] | keyboard_state[SDL_SCANCODE_LEFT]) {
        gen_logs(log_file, DEBUG, "Keyboard press: A or LEFT.");
    } if (keyboard_state[SDL_SCANCODE_S] | keyboard_state[SDL_SCANCODE_DOWN]) {
        gen_logs(log_file, DEBUG, "Keyboard press: S or DOWN.");
    } if (keyboard_state[SDL_SCANCODE_D] | keyboard_state[SDL_SCANCODE_RIGHT]) {
        gen_logs(log_file, DEBUG, "Keyboard press: D or RIGHT.");
    } if (keyboard_state[SDL_SCANCODE_E]) {
        gen_logs(log_file, DEBUG, "Keyboard press: E.");
    } if (keyboard_state[SDL_SCANCODE_Q]) {
        gen_logs(log_file, DEBUG, "Keyboard press: Q.");
    }
}

static void handle_mouse(LogFile log_file, SDL_Event* pEvent) {
    switch (pEvent->button.button) {
    case SDL_BUTTON_LEFT:
        gen_logs(log_file, DEBUG, "Mouse button press: LEFT.");
        break;
    case SDL_BUTTON_RIGHT:
        gen_logs(log_file, DEBUG, "Mouse button press: RIGHT.");
        break;
    case SDL_BUTTON_MIDDLE:
        gen_logs(log_file, DEBUG, "Mouse button press: MIDDLE.");
        break;
    default:
        break;
    }
}

static int handle_events(LogFile log_file) {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            return 1;
            break;
        case SDL_KEYDOWN:
            handle_keyboard(log_file, &event);
            break;
        case SDL_MOUSEBUTTONDOWN:
            handle_mouse(log_file, &event);
            break;
        default:
            break;
        }
    }
    return 0;
}

void game() {
    LogFile log_file = create_runtime_session_logfile();
    if (init_SDL(log_file) == 1) {
        exit(1);
    }
    SDL_Window* m_window = create_SDL_window("MyGame", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                                             MAIN_SCREEN_WIDTH, MAIN_SCREEN_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI |
                                             SDL_WINDOW_ALWAYS_ON_TOP, log_file);
    SDL_Renderer* m_renderer = create_SDL_renderer(m_window, log_file);

    int running = 1;
    while (running) {
        if (handle_events(log_file) == 1) {
            quit_SDL(&m_window, &m_renderer, &log_file);
            exit(0);
        }
        SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
        render(m_renderer);
    }
}