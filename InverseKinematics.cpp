#include <iostream>
#include <SDL.h>

#include "ArmIK.h"

using namespace std;

int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("IK", 100, 100, 1600, 900, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

	ArmIK* arm = new ArmIK();
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);
	arm->AddJoint(5);

	while (true) {
		SDL_Event ev;
		while (SDL_PollEvent(&ev)) {

		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		int mx, my;
		SDL_GetMouseState(&mx, &my);

		arm->InverseKinematics(mx - 800, my - 450, 1);

		arm->ForwardKinematics(0);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		for (int i = 0; i < arm->joints.size() - 1; i++) {
			SDL_RenderDrawLine(renderer, arm->joints[i].xpos + 800, arm->joints[i].ypos + 450, arm->joints[i + 1].xpos + 800, arm->joints[i + 1].ypos + 450);
		}
		SDL_RenderDrawLine(renderer, arm->joints[arm->joints.size() - 1].xpos + 800, arm->joints[arm->joints.size() - 1].ypos + 450, arm->xEnd + 800, arm->yEnd + 450);

		SDL_RenderPresent(renderer);
	}
}