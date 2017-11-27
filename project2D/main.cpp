#include "Application2D.h"
#include <Vector2.h>
int main() {
	
	// allocation
	auto app = new Application2D();

	// initialise and loop
	app->run("AIE", 1500, 720, false);

	// deallocation
	delete app;

	return 0;
}