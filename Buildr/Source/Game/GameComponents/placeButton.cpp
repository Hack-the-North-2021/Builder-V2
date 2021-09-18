#include "placeButton.h"

namespace Game {
	bool debounce = true;

	void placeButton::OnButtonClicked() {
		if (debounce) {
			debounce = false;
			std::cout << "Clicked\n";



			debounce = true;
		}

		
	}
}