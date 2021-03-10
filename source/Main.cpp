#include <Game.hpp>

//Prefer discrete GPU if it is available.
#define SFML_DEFINE_DISCRETE_GPU_PREFERENCE

int main()
{
    Game application;
    application.run();
}